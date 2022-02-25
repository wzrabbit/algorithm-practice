const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let won = parseInt(input[0].split(' ')[1]);
input.shift();
const coins = input.reverse().map(Number);
let count = 0;

coins.forEach((c) => {
    while (won >= c) {
        won -= c;
        count++;
    }
});

console.log(count);