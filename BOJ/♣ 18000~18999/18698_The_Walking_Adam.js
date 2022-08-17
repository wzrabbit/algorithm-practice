const input = require('fs').readFileSync('/dev/stdin')
    .toString().trim().split('\n').map((x) => x.match(/^U*/)[0].length);
let printer = '';

for (let i = 1; i < input.length; i++)
    printer += input[i] + '\n';

console.log(printer);