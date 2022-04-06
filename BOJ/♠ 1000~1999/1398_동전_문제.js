const input = require('fs').readFileSync('/dev/stdin')
    .toString().trim().split('\n').map((x) => parseInt(x));
let printer = '';

for (let i = 1; i < input.length; i++)
    printer += solve(input[i]) + '\n';
console.log(printer);

function solve(money) {
    let coin = 0;

    while (money >= 10) {
        let dpSize;

        if (money.toString().length % 2 === 0) {
            dpSize = parseInt(money.toString().substr(0, 2));
            money %= 10 ** (money.toString().length - 2);
        }

        else {
            dpSize = parseInt(money.toString()[0]);
            money %= 10 ** (money.toString().length - 1);
        }

        let dp = new Array(dpSize + 1);
        dp[0] = 0;

        for (let i = 1; i <= dpSize; i++) {
            dp[i] = dp[i - 1] + 1;
            if (i >= 10 && dp[i - 10] + 1 < dp[i])
                dp[i] = dp[i - 10] + 1;
            if (i >= 25 && dp[i - 25] + 1 < dp[i])
                dp[i] = dp[i - 25] + 1;
        }

        coin += dp[dpSize];
    }

    coin += money;
    return coin;
}