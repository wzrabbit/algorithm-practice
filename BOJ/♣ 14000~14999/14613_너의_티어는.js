const [winRate, loseRate, drawRate] = require("fs")
  .readFileSync(0, "utf-8")
  .trim()
  .split(" ")
  .map(Number);

let dp = Array(21)
  .fill("")
  .map(() => Array(41).fill(0));

dp[0][20] = 1;

for (let r = 0; r < 20; r++) {
  for (let c = 0; c <= 40; c++) {
    if (dp[r][c] > 0) {
      dp[r + 1][c - 1] += dp[r][c] * loseRate;
      dp[r + 1][c] += dp[r][c] * drawRate;
      dp[r + 1][c + 1] += dp[r][c] * winRate;
    }
  }
}

[
  [0, 9],
  [10, 19],
  [20, 29],
  [30, 39],
  [40, 40],
].forEach((currentRange) => {
  const start = currentRange[0];
  const end = currentRange[1];
  let probability = 0;

  for (let i = start; i <= end; i++) {
    probability += dp[20][i];
  }

  console.log(probability.toFixed(8));
});
