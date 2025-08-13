const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const numbers = input[1].split(/[.|:#]/).map(Number);

let answer = 0;

numbers.forEach(number => {
  answer += number;
});

console.log(answer);
