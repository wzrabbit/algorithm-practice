const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [k, n] = input[0].split(' ').map((x) => parseInt(x));
input.shift();

input.sort((a, b) => {
  return parseInt(a + b) > parseInt(b + a) ? -1 : 1;
});

let max = input.slice();
max.sort((a, b) => b - a);
max = max[0];
let index = input.indexOf(max);
input[index] = input[index].repeat(n - k + 1);

let result = input.join('');
console.log(result);