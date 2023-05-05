const [, ...input] = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
let printer = '';

input.forEach((testcase) => {
  const consonantCount = (testcase.match(/[^aeiou ]/gi) || []).length;
  const vowelCount = (testcase.match(/[aeiou]/gi) || []).length;

  printer += `${consonantCount} ${vowelCount}\n`;
});

console.log(printer);