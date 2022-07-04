const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

for (let i = 1; i < input.length; i++) {
    const text = input[i].trim();

    if (text.match(/^[0-9]+$/))
        printer += BigInt(text) + '\n';
    else
        printer += 'invalid input\n';

}

console.log(printer);