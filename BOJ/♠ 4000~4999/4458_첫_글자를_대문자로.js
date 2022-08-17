const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

for (let i = 1; i < input.length; i++)
    printer += input[i][0].toUpperCase() + input[i].slice(1) + '\n';

console.log(printer);