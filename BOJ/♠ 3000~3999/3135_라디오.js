let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const end = input[0].split(' ')[1];
input[0] = input[0].split(' ')[0];
input.splice(1, 1);
input = input.map(Number);
let min = 9999;

for (let i = 0; i < input.length; i++) {
    let button = Math.abs(end - input[i]);
    if (i !== 0) button++;
    if (button < min) min = button;
}

console.log(min);