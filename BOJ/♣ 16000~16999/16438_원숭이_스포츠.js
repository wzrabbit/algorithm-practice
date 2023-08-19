const divideStates = () => {
  const newStates = [];

  states.forEach((state) => {
    const half = Math.ceil(state / 2);

    newStates.push(half);
    newStates.push(state - half);
  });

  states = newStates;
}

const constructAnswerLine = () => {
  let answerLine = '';

  states.forEach((state, index) => {
    if (index % 2 === 0) {
      answerLine += 'A'.repeat(state);
    } else {
      answerLine += 'B'.repeat(state);
    }
  });

  if (!answerLine.split('').includes('B')) {
    answerLine = `${answerLine.slice(0, N - 1)}B`;
  }

  printer += `${answerLine}\n`;
}

const N = Number(require('fs').readFileSync(0, 'utf-8'));
let states = [N];
let printer = '';

for (let i = 0; i < 7; i++) {
  divideStates();
  constructAnswerLine();
}

console.log(printer);
