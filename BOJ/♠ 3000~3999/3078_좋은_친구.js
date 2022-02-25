let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const gap = parseInt(input[0].split(' ')[1]);
input = input.map((x) => x.length);
let len = new Array(21).fill(0);
let total = 0;

// 첫 번째
for (let i = 2; i < gap + 2; i++) {
    len[input[i]]++;
}
total += len[input[1]];

// 두 번째 ~ 마지막
for (let i = 2; i < input.length; i++) {
    len[input[i]]--;
    if (len[input[i + gap]] !== undefined) len[input[i + gap]]++;
    total += len[input[i]];
}

console.log(total);