const input = parseInt(require('fs').readFileSync('/dev/stdin'));
let square = [];
let dp = [null, 1];

for (let i = 1; i <= Math.sqrt(input); i++) {
    square.push(i ** 2);
}

for (let i = 2; i <= input; i++) {
    let min = 99999;
    for (let j = 0; j < square.length; j++) {
        let current = i - square[j];
        if (current < 0) break;
        if (dp[current] < min) min = dp[current] + 1;
    }
    dp[i] = min;
}

console.log(dp[input]);
