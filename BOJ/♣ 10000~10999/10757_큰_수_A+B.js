const [a, b] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map(BigInt);
console.log((a + b).toString());