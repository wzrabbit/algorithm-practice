const isSquareOfTwo = num => {
    while (num >= 2) {
        if (num % 2 === 1) return false;
        else num /= 2;
    }
    return true;
}

const input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n').map(Number);
let printer = '';

for (let index = 1; index < input.length; index += 1) {
    printer += isSquareOfTwo(input[index]) ? '1\n' : '0\n';
}

console.log(printer);
