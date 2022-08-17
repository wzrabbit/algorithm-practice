const input = require('fs').readFileSync('/dev/stdin')
    .toString().trim().split('\n')[1].split(' ').map((x) => parseInt(x));
let dp = new Array(input.length).fill(0);

function getGap(start, end) {
    let min = 10 ** 10;
    let max = 0;
    for (let i = start; i <= end; i++) {
        if (input[i] < min)
            min = input[i];

        if (input[i] > max)
            max = input[i];
    }

    return max - min;
}

for (let i = 1; i < input.length; i++) {
    dp[i] = getGap(0, i);
    for (let j = 1; j < i; j++)
        dp[i] = Math.max(dp[i], dp[j] + getGap(j + 1, i));
}

console.log(dp[input.length - 1]);