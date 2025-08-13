const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
const S = input[1];
let need = 0;

if (!/[a-z]/.test(S)) {
  need += 1;
}

if (!/[A-Z]/.test(S)) {
  need += 1;
}

if (!/[0-9]/.test(S)) {
  need += 1;
}

if (!/[!@#$%^&*()+-]/.test(S)) {
  need += 1;
}

console.log(Math.max(6 - N, need));
