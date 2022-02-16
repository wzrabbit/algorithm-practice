let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const maxRow = parseInt(input[0].split(' ')[0]);
const maxCol = parseInt(input[0].split(' ')[1]);
input.shift();

for (let i = 0; i < maxRow; i++) {
  input[i] = input[i].split('');
}

let visited = Array(26).fill(false);
let maxCombo = 0;
dfs(0, 0, 1);

console.log(maxCombo);

function dfs(row, col, combo) {
  visited[input[row][col].charCodeAt() - 65] = true;
  if (combo > maxCombo) maxCombo = combo;

  if (row > 0) {
    if (visited[input[row - 1][col].charCodeAt() - 65] === false) dfs(row - 1, col, combo + 1);
  }
  if (col > 0) {
    if (visited[input[row][col - 1].charCodeAt() - 65] === false) dfs(row, col - 1, combo + 1);
  }
  if (row < maxRow - 1) {
    if (visited[input[row + 1][col].charCodeAt() - 65] === false) dfs(row + 1, col, combo + 1);
  }
  if (col < maxCol - 1) {
    if (visited[input[row][col + 1].charCodeAt() - 65] === false) dfs(row, col + 1, combo + 1);
  }

  visited[input[row][col].charCodeAt() - 65] = false;
}