let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let printer = '';

for (let i = 1; i < input.length; i++) {
    input[i] = input[i].replace(/ |\d+/g, '');
    let sub = input[i].match(/X+/g) || [''];
    sub.sort().reverse();
    printer += `The longest contiguous subsequence of X's is of length ${sub[0].length}\n`;
}

console.log(printer);