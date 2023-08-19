const [XK, input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [sockCount, noCount] = XK.split(' ').map(Number);
const socks = input.split(' ').map(Number);
const leftSocks = Array.from({ length: noCount }).map(() => 0);
const rightSocks = Array.from({ length: noCount }).map(() => 0);

socks.forEach((sock, index) => {
  if (index < sockCount) {
    leftSocks[sock - 1] += 1;
  } else {
    rightSocks[sock - 1] += 1;
  }
});

let answer = sockCount ** 2;

leftSocks.forEach((_, index) => {
  answer -= leftSocks[index] * rightSocks[index];
});

console.log(answer);
