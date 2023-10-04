const isVPS = (brackets) => {
  const stack = [];

  for (let i = 0; i < brackets.length; i++) {
    if (brackets[i] === '(') {
      stack.push(brackets[i]);
      continue;
    }

    if (stack.length === 0) {
      return false;
    }

    stack.pop();
  }

  return stack.length === 0;
}

const [_, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

let answer = '';

input.forEach((testcase) => {
  answer += `${isVPS(testcase) ? 'YES' : 'NO'}\n`;
});

console.log(answer);