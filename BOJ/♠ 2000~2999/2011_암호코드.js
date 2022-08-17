let str = require('fs').readFileSync('/dev/stdin').toString().trim();
let dp = new Array(str.length).fill(0);
let mod = 1000000;

if (/^0|00|[3-9]0/.test(str))
    console.log(0);
else {
    str = str.split('').map((x) => parseInt(x));
    dp[0] = 1;
    for (let i = 1; i < str.length; i++) {
        let calc = str[i - 1] * 10 + str[i];

        if (calc >= 10 && calc <= 26)
            dp[i] += (dp[i - 2] || 1);
        if (str[i] !== 0)
            dp[i] += dp[i - 1];
        dp[i] %= mod;
    }

    console.log(dp[str.length - 1])
}