const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const cases = parseInt(input[0]);
input[0] = '0 0';
for (let i = 0; i <= cases; i++) {
    input[i] = input[i].split(' ').map((x) => parseInt(x));
}
input.sort((a, b) => {
    return b[0] - a[0];
});

time = input[0][0];
for (let i = 0; i < input.length - 1; i++) {
    if (time < input[i][1]) time = input[i][1];
    time += input[i][0] - input[i + 1][0];
}

console.log(time);