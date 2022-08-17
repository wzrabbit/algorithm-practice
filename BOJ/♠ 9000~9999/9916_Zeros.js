const N = parseInt(require('fs').readFileSync(0, 'utf-8'));
let num = 1n;

for (let i = 1n; i <= N; i++)
    num *= i;

console.log((num.toString().match(/0/g) || []).length);