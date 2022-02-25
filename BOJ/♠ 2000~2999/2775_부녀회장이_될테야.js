const input = require("fs").readFileSync('/dev/stdin').toString().split('\n');
const tests = Number(input.shift());

for (let i = 0; i < tests; i++) {
    const k = +input.shift();
    const n = +input.shift();
    const house = Array.from(Array(k + 1), () => Array(n + 1).fill(0));
    for (let i = 1; i <= n; i++) {
        house[0][i] = i;
    }

    for (let i = 1; i <= k; i++) {
        for (let j = 1; j <= n; j++) {
            house[i][j] = house[i - 1][j] + house[i][j - 1];
        }
    }
    console.log(house[k][n]);
}