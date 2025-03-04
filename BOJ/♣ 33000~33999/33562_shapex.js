const EMPTY_LAYER = '--------';

const cutToHalf = (targetIndex, outputIndex1, outputIndex2) => {
  const leftShapes = [];
  const rightShapes = [];

  register[targetIndex].forEach((shape) => {
    const leftLayer = `----${shape.slice(4)}`;
    const rightLayer = `${shape.slice(0, 4)}----`;

    if (leftLayer !== EMPTY_LAYER) {
      leftShapes.push(leftLayer);
    }

    if (rightLayer !== EMPTY_LAYER) {
      rightShapes.push(rightLayer);
    }
  });

  register[outputIndex1] = leftShapes;
  register[outputIndex2] = rightShapes;
};

const spin = (targetIndex, outputIndex, spinMode) => {
  const spinSize = spinMode * 2;

  const spinnedShapes = register[targetIndex].map((shape) => {
    return `${shape.slice(-spinSize)}${shape.slice(0, -spinSize)}`;
  });

  register[outputIndex] = spinnedShapes;
};

const merge = (targetIndex1, targetIndex2, outputIndex) => {
  if (register[targetIndex1].length === 0 || register[targetIndex2].length === 0) {
    register[outputIndex] = [];
    return;
  }

  const leftShapes = [...register[targetIndex1]];
  const rightShapes = [...new Array(5).fill(EMPTY_LAYER), ...register[targetIndex2]];

  for (let i = 0; i < 5; i++) {
    let success = true;
    rightShapes.shift();
  
    for (let j = 0; j < Math.min(leftShapes.length, rightShapes.length); j++) {
      for (let k = 0; k < 8; k++) {
        if (leftShapes[j][k] !== '-' && rightShapes[j][k] !== '-') {
          success = false;
        }
      }
    }

    if (!success) {
      rightShapes.unshift(EMPTY_LAYER);
      break;
    }
  }

  const mergedShapes = [];

  for (let i = 0; i < Math.max(leftShapes.length, rightShapes.length); i++) {
    if (!leftShapes[i]) {
      mergedShapes.push(rightShapes[i]);
      continue;
    }

    if (!rightShapes[i]) {
      mergedShapes.push(leftShapes[i]);
      continue;
    }

    let shape = '';

    for (let j = 0; j < 8; j++) {
      if (leftShapes[i][j] === '-') {
        shape += rightShapes[i][j];
        continue;
      }

      shape += leftShapes[i][j];
    }

    mergedShapes.push(shape);
  }

  register[outputIndex] = mergedShapes.slice(0, 4);
};

const paint = (targetIndex, outputIndex, color) => {
  const coloredShapes = [];

  register[targetIndex].forEach((shape) => {
    coloredShapes.push(shape.replace(/[a-z]/g, color));
  });

  register[outputIndex] = coloredShapes;
};

const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0].split(' ')[0]);
const shapes = input.slice(1, N + 1);
const queries = input.slice(N + 1).map((query) => query.split(' ').map((value) => isNaN(value) ? value : Number(value)));
const register = Array.from({ length: 101 }).map(() => []);

shapes.forEach((shape, index) => {
  register[index + 1].push(shape);
});

queries.forEach((query) => {
  const [command, ...args] = query;

  switch (command) {
    case 1:
      cutToHalf(...args);
      break;
    case 2:
      spin(...args);
      break;
    case 3:
      merge(...args);
      break;
    case 4:
      paint(...args);
      break;
  }
});

if (register[100].length === 0) {
  console.log('None');
  return;
}

console.log(register[100].join(':'));
