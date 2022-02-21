const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const len = input[0] * 2 + 1;
const word = input[2];
let count = 0;

let findList = word.match(/(IO)+I/g);
findList.forEach((x) => {
  count += ((x.length - len) / 2 + 1) > 0 ? ((x.length - len) / 2 + 1) : 0;
});

console.log(count);