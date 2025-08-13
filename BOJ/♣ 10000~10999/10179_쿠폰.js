const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n').map(Number);
const N = Number(input[0]);
let output = '';

for (let i = 1; i <= N; i++) {
  output += `$${(input[i] * 0.8).toFixed(2)}\n`;
}

console.log(output);
