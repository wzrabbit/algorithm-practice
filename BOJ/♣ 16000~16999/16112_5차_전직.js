let [qs, input] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [q, s] = qs.split(' ').map((x) => BigInt(x));
input = input.split(' ').map((x) => BigInt(x));
let totalStone = 0n;
let totalExp = 0n;

input.sort((a, b) => (a > b) ? 1 : -1);

for (let i = 0; i < q; i++) {
    totalExp += totalStone * input[i];

    if (totalStone < s)
        totalStone++;
}

console.log(totalExp.toString());