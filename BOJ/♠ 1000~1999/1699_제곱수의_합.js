const input = parseInt(require('fs').readFileSync('/dev/stdin'));
let square = [];
let dp = [null, 1];

for (let i = 1; i <= Math.sqrt(input); i++) {
    square.push(i * i);
}

for (let i = 2; i <= input; i++) {
    let min = 999999;
    square.forEach((x) => {
        if (i > x) {
            if (dp[i - x] + 1 < min) min = dp[i - x] + 1;
        }
        else if (i === x) {
            min = 1;
            return;
        }
        else return;
    });
    dp[i] = min;
}

console.log(dp[input]);