const input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
let printer = '';

for (let i = 1; i < input.length; i++) {
    let sent = input[i].split(' ');

    for (let j = 2; j < sent.length; j++)
        printer += sent[j] + ' ';

    printer += sent[0] + ' ' + sent[1] + '\n';
}

console.log(printer);