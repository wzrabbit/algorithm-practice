let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
num = parseInt(input[0]);
input[0] = '+0 +0';

input.forEach((x, i) => {
    const [left, right] = x.split(' ');
    input[i] = [
        { 'op': left[0], 'value': parseInt(left[1]) },
        { 'op': right[0], 'value': parseInt(right[1]) }
    ];
});
let dp = new Array(2).fill(0).map((x) => new Array(num + 1).fill(0));
dp[0][0] = 1;

function calc(op, before, add) {
    if (before <= 0)
        return 0;

    switch (op) {
        case '+':
            return before + add;
        case '-':
            return before - add;
        case '*':
            return before * add;
        case '/':
            return Math.floor(before / add);
    }
}

for (let i = 1; i <= num; i++) {
    dp[0][i] = Math.max(
        calc(input[i][0].op, dp[0][i - 1], input[i][0].value),
        calc(input[i][1].op, dp[0][i - 1], input[i][1].value),
    );

    dp[1][i] = Math.max(
        calc(input[i][0].op, dp[1][i - 1], input[i][0].value),
        calc(input[i][1].op, dp[1][i - 1], input[i][1].value),
        (dp[0][i - 1] > 0) ? dp[0][i - 1] : 0
    );
}

const result = Math.max(dp[0][num], dp[1][num]);
if (result > 0)
    console.log(result);
else
    console.log('ddong game');