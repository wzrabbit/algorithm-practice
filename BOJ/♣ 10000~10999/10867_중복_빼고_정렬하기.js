let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')[1].split(' ').map((x) => parseInt(x));

input = Array(...new Set(input)).sort((a, b) => a - b);
console.log(input.join(' '));