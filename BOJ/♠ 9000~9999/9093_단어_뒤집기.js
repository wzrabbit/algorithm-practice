const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';
input.shift();

for (let i = 0; i < input.length; i++) {
    printer += input[i].replace(/\w+/g, (word) => {
        return word.split('').reverse().join('');
    }) + '\n';
}

console.log(printer);