const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const len = input[0];
let result = 0;
let line;
input[0] = '1000000001 0';

for (let i = 0; i <= len; i++) {
    input[i] = input[i].split(' ').map(Number);
}

input.sort((a, b) => {
    return a[0] - b[0];
});

line = [input[0][0], input[0][1]];
for (let i = 1; i < len; i++) {
    if (input[i][0] > line[1]) {
        result += line[1] - line[0];
        line = [input[i][0], input[i][1]];
    }
    else if (input[i][1] > line[1]) line[1] = input[i][1];
}
result += line[1] - line[0];

console.log(result);