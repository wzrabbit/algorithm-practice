let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let maxWord = 0;
let printer = '';

for (let i = 0; i < input.length; i++) {
    input[i] = input[i].trim().split(/ +/g);
    if (input[i].length > maxWord)
        maxWord = input[i].length;
}

let maxLength = new Array(maxWord).fill(0);

for (let i = 0; i < input.length; i++) {
    for (let j = 0; j < input[i].length; j++) {
        if (input[i][j].length > maxLength[j])
            maxLength[j] = input[i][j].length;
    }
}

for (let i = 0; i < input.length; i++) {

    for (let j = 0; j < input[i].length - 1; j++) {
        printer += input[i][j] + ' '.repeat(maxLength[j] + 1 - input[i][j].length);
    }
    printer += input[i][input[i].length - 1] + ' \n';
}


console.log(printer);