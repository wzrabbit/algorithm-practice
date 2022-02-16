const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let result = '';
input.pop()

for (let i = 0; i < input.length; i++) {
  result += (input[i].match(/[aeiou]/gi) || []).length + '\n';
}

console.log(result);