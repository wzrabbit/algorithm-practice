let [_, ...input] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
input = input.map((x) => x.split(' ').map((y) => parseInt(y)));
input.sort((a, b) => {
  if (a[1] != b[1]) return a[1] - b[1];
  return a[0] - b[0];
});

let count = 1;
let prev = input[0][1];
for (let i = 1; i < input.length; i++) {
  if (input[i][0] >= prev) {
    count++;
    prev = input[i][1];
  }
}

console.log(count);