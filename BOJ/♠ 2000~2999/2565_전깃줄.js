const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const lines = parseInt(input[0]);
let arr = new Array(501).fill(501);
let dp = new Array(501).fill(1);
let longest = 1;

for (let i = 1; i <= lines; i++) {
    const [s, e] = input[i].split(' ').map((x) => parseInt(x));
    arr[s] = e;
}

for (let i = 1; i <= 500; i++) {
    if (arr[i] === 501) continue;
    for (let j = 1; j < i; j++) {
        if (arr[j] === 501) continue;
        if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            longest = Math.max(longest, dp[i]);
        }
    }
}

console.log(lines - longest);