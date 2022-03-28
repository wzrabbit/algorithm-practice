let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')[1].split(' ').map(Number);
let max = [0, 0];
let total = 0;

for (let i = 0; i < input.length; i++) {
    if (input[i] > max[0]) max = [input[i], i];
}
input[max.pop()] = 0;

for (let i = 0; i < input.length; i++) {
    total += input[i];
}
total /= 2;
total += max.pop();

console.log(total);