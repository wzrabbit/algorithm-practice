function solve(row, col) {
    let r = 0;
    printer += '1\n(0,0)\n'

    while (r < row) {
        if (r % 2 === 0) {
            for (let c = 1; c <= col - 1; c++)
                printer += `(${r},${c})\n`;
        }
        else {
            for (let c = col - 1; c >= 1; c--)
                printer += `(${r},${c})\n`;
        }

        r++;
    }

    for (let r = row - 1; r >= 1; r--)
        printer += `(${r},${0})\n`;
}

const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

for (let i = 1; i < input.length; i++) {
    let [row, col] = input[i].split(' ').map((x) => parseInt(x));
    solve(row, col);
}

console.log(printer);