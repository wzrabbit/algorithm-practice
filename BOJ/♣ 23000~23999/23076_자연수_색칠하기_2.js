const input = parseInt(require('fs').readFileSync('/dev/stdin'));
let printer = Math.floor(input / 2) + '\n1';

for (let i = 2; i <= input; i++)
    printer += ' ' + Math.floor(i / 2);

console.log(printer);