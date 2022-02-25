const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

for (let i = 0; i < input.length - 1; i++) {
    printer += input[i].split('').reverse().join('') + '\n';
}

console.log(printer);