const [A, B, C] = require('fs').readFileSync(0, 'utf-8')
    .toString().trim().split(' ').map(x => parseInt(x))
    .sort((a, b) => a - b);

console.log(A + B + Math.min(C, A + B - 1));