const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);
let result = '';

for (let i = 1; i < input.length; i++) {
    result += input[i] * 23 + '\n';
}

console.log(result);