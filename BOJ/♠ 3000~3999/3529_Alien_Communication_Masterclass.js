const input = require('fs').readFileSync('/dev/stdin')
    .toString().split('\n')[1].split(' ').map((x) => parseInt(x));
let printer = '';

for (let i = 0; i < input.length; i++) {
    if (i !== 0)
        printer += '*';
    printer += `(10${'-1'.repeat(input[i])})`;
}
printer += '=0';

console.log(printer);