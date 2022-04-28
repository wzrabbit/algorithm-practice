const [a, b] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ');
console.log(a - b);