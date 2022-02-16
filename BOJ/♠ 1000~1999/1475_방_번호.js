const input = require('fs').readFileSync('/dev/stdin').toString().trim();
let num = [0, 0, 0, 0, 0, 0, 0, 0, 0]
for (let i = 0; i < input.length; i++) {
  if (input[i] === '9') num[6]++;
  else num[input[i]]++;
}

num[6] = Math.ceil(num[6] / 2);
console.log(Math.max(...num));