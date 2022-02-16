const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('').map((x) => parseInt(x));
console.log(input.sort((a, b) => b - a).join(''));