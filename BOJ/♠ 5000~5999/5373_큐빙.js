const initializeDice = () => {
  dice = {
    top: [
      ['w', 'w', 'w'],
      ['w', 'w', 'w'],
      ['w', 'w', 'w'],
    ],
    left: [
      ['g', 'g', 'g'],
      ['g', 'g', 'g'],
      ['g', 'g', 'g'],
    ],
    back: [
      ['o', 'o', 'o'],
      ['o', 'o', 'o'],
      ['o', 'o', 'o'],
    ],
    right: [
      ['b', 'b', 'b'],
      ['b', 'b', 'b'],
      ['b', 'b', 'b'],
    ],
    front: [
      ['r', 'r', 'r'],
      ['r', 'r', 'r'],
      ['r', 'r', 'r'],
    ],
    bottom: [
      ['y', 'y', 'y'],
      ['y', 'y', 'y'],
      ['y', 'y', 'y'],
    ],
  };
};

const getRotatedFace = (face) => {
  return [
    [face[2][0], face[1][0], face[0][0]],
    [face[2][1], face[1][1], face[0][1]],
    [face[2][2], face[1][2], face[0][2]],
  ];
};

const spinTopRing = (index) => {
  const tempSide = dice.front[index].slice();
  dice.front[index] = dice.right[index].slice();
  dice.right[index] = dice.back[index].slice().reverse();
  dice.back[index] = dice.left[index].slice().reverse();
  dice.left[index] = tempSide;
};

const spinRightRing = (index) => {
  const tempSide = [dice.top[0][index], dice.top[1][index], dice.top[2][index]];

  for (let i = 0; i < 3; i++) {
    dice.top[i][index] = dice.front[i][index];
  }

  for (let i = 0; i < 3; i++) {
    dice.front[i][index] = dice.bottom[2 - i][index];
  }

  for (let i = 0; i < 3; i++) {
    dice.bottom[i][index] = dice.back[i][index];
  }

  for (let i = 0; i < 3; i++) {
    dice.back[i][index] = tempSide[2 - i];
  }
};

const spinFrontRing = (index) => {
  const tempSide = dice.top[index].slice();

  for (let i = 0; i < 3; i++) {
    dice.top[index][i] = dice.left[2 - i][index];
  }

  for (let i = 0; i < 3; i++) {
    dice.left[i][index] = dice.bottom[index][i];
  }

  for (let i = 0; i < 3; i++) {
    dice.bottom[index][i] = dice.right[2 - i][2 - index];
  }

  for (let i = 0; i < 3; i++) {
    dice.right[i][2 - index] = tempSide[i];
  }
};

const performCommand = (command) => {
  switch (command) {
    case 'U+':
      dice.top = getRotatedFace(dice.top);
      spinTopRing(0);
      return;
    case 'U-':
      Array.from({ length: 3 }).map(() => {
        dice.top = getRotatedFace(dice.top);
        spinTopRing(0);
      });
      return;
    case 'D+':
      Array.from({ length: 3 }).map(() => {
        dice.bottom = getRotatedFace(dice.bottom);
        spinTopRing(2);
      });
      return;
    case 'D-':
      dice.bottom = getRotatedFace(dice.bottom);
      spinTopRing(2);
      return;
    case 'R+':
      dice.right = getRotatedFace(dice.right);
      spinRightRing(2);
      return;
    case 'R-':
      Array.from({ length: 3 }).map(() => {
        dice.right = getRotatedFace(dice.right);
        spinRightRing(2);
      });
      return;
    case 'L+':
      dice.left = getRotatedFace(dice.left);
      Array.from({ length: 3 }).map(() => {
        spinRightRing(0);
      });
      return;
    case 'L-':
      Array.from({ length: 3 }).map(() => {
        dice.left = getRotatedFace(dice.left);
      });
      spinRightRing(0);
      return;
    case 'F+':
      dice.front = getRotatedFace(dice.front);
      spinFrontRing(2);
      return;
    case 'F-':
      Array.from({ length: 3 }).map(() => {
        dice.front = getRotatedFace(dice.front);
        spinFrontRing(2);
      });
      return;
    case 'B+':
      Array.from({ length: 3 }).map(() => {
        dice.back = getRotatedFace(dice.back);
        spinFrontRing(0);
      });
      return;
    case 'B-':
      dice.back = getRotatedFace(dice.back);
      spinFrontRing(0);
  }
};

const writeAnswer = () => {
  output +=
    [dice.top[0].join(''), dice.top[1].join(''), dice.top[2].join('')].join(
      '\n',
    ) + '\n';
};

const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
let dice;
let output = '';

for (let i = 2; i < N * 2 + 2; i += 2) {
  initializeDice();
  const commands = input[i].split(' ');

  for (const command of commands) {
    performCommand(command);
  }

  writeAnswer();
}

console.log(output);
