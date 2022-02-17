let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const gap = parseInt(input[0].split(' ')[1]);
input.shift();
input = input.map((x) => parseInt(x)).sort((a, b) => a - b);

let [l, r] = [0, 0];
let min = 9999999999;

while (r < input.length) {
  if (input[r] - input[l] > gap) {
    if (min > input[r] - input[l]) {
      min = input[r] - input[l];
    }
    if (l === r) {
      r++;
    }
    l++;
  }
  else if (input[r] - input[l] === gap) {
    min = gap;
    break;
  }
  else {
    r++;
  }
}

console.log(min);