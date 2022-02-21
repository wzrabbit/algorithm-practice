const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const pattern = input[0];
let printer = '';

for (let t = 2; t < input.length; t++) {
  const word = input[t];
  const row = pattern.length;
  const col = word.length + 1;
  let limit = col - (pattern.match(/[^*]/g) || []).length;
  let dp = Array.from(Array(row), () => new Array(col).fill(false));

  if (limit <= 0) continue;
  dp[0][0] = true;
  if (pattern[0] === '*') {
    for (let c = 1; c < limit; c++) {
      dp[0][c] = true;
    }
  }
  else if (pattern[0] === word[0]) {
    dp[0][1] = true;
    limit++;
  }
  else {
    continue;
  }

  for (let r = 1; r < row; r++) {
    if (pattern[r] === '*') {
      for (let c = 0; c < limit; c++) {
        if (dp[r - 1][c] === true) {
          for (let g = c; g < limit; g++) {
            dp[r][g] = true;
          }
          break;
        }
      }
    }
    else {
      for (let c = 1; c < col; c++) {
        if (dp[r - 1][c - 1] === true && word[c - 1] === pattern[r]) {
          dp[r][c] = true;
          limit++;
        }
      }
    }
  }

  if (dp[row - 1][col - 1] === true) {
    printer += word + '\n';
  }
}

console.log(printer);