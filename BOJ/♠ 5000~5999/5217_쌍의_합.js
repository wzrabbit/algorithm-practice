const input = require('fs').readFileSync('/dev/stdin')
    .toString().trim().split('\n').map((x) => parseInt(x));
let printer = '';

for (let i = 1; i < input.length; i++) {
    printer += `Pairs for ${input[i]}: `;

    let j = 1;
    while (j < input[i] - j) {
        if (j !== 1)
            printer += ', ';

        printer += `${j} ${input[i] - j}`;
        j++;
    }
    printer += '\n';
}

console.log(printer);