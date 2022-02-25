const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [things, limit] = input[0].split(' ').map((x) => parseInt(x));
let thingsList = [null];
for (let i = 1; i <= things; i++) {
    thingsList.push(input[i].split(' ').map((x) => parseInt(x)));
}
let dp = new Array(things + 1).fill(0);
for (let i = 0; i <= things; i++) {
    dp[i] = new Array(limit + 1).fill(0);
}
for (let t = 1; t <= things; t++) {
    let [weight, value] = thingsList[t];
    for (let l = 1; l <= limit; l++) {
        if (l - weight >= 0) {
            dp[t][l] = Math.max(dp[t - 1][l - weight] + value, dp[t - 1][l]);
        }
        else {
            dp[t][l] = dp[t - 1][l];
        }
    }
}

console.log(dp[things][limit]);