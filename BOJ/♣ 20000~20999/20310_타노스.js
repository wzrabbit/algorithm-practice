let input = require("fs").readFileSync("/dev/stdin").toString().trim().split('');
let amount = [0, 0];
for (let i = 0; i < input.length; i++) {
    if (input[i] === '0') amount[0]++;
    else amount[1]++;
}

for (let i = 0; i < input.length; i++) {
    if (amount[1] === 0) break;
    if (input[i] === '1') {
        input[i] = 'X';
        amount[1] -= 2;
    }
}

for (let i = input.length - 1; i >= 0; i--) {
    if (amount[0] === 0) break;
    if (input[i] === '0') {
        input[i] = 'X';
        amount[0] -= 2;
    }
}

console.log(input.join('').replace(/X/g, ''));