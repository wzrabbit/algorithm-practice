let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

for (let i = 0; i < input.length - 1; i++) {
    input[i] = input[i].toUpperCase().replace(/[^A-Z]+/g, '');
    alphabetSet = new Set();

    for (let j = 0; j < input[i].length; j++)
        alphabetSet.add(input[i][j]);

    printer += alphabetSet.size + '\n';
}

console.log(printer);