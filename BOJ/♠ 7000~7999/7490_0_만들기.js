const generateZeroExpressions = (size) => {
  for (let i = 0; i < 3 ** (size - 1); i++) {
    const queries = i.toString(3).padStart(size - 1, '0');

    let result = 0;
    let expression = '1';
    let recentOperator = '+';
    let savedNumber = 1;

    for (let j = 2; j <= size; j++) {
      switch (queries[j - 2]) {
        case '0':
          savedNumber = savedNumber * 10 + j;
          expression += ` ${j}`;
          break;
        case '1':
          result += recentOperator === '+' ? savedNumber : -savedNumber;
          savedNumber = j;
          recentOperator = '+';
          expression += `+${j}`;
          break;
        case '2':
          result += recentOperator === '+' ? savedNumber : -savedNumber;
          savedNumber = j;
          recentOperator = '-';
          expression += `-${j}`;
          break;
      }
    }

    result += recentOperator === '+' ? savedNumber : -savedNumber;

    if (result === 0) {
      printer += expression + '\n';
    }
  }
};

const [_, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map(Number);

let printer = '';

input.forEach((testcase) => {
  generateZeroExpressions(testcase);
  printer += '\n';
});

console.log(printer);
