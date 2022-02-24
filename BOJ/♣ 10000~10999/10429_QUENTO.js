const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let [goal, combo] = input[0].split(' ').map(Number);
combo = combo * 2 - 1;
let board = input.slice(1);
let result = 'none';

for (let i = 0; i <= 2; i++) {
  board[i] = board[i].split('');
}

let visited = board.map((x) => x.slice().fill(false));
let order = [];
let sum = 0;
let success = false;

dfs(0, 0); dfs(0, 2); dfs(1, 1); dfs(2, 0); dfs(2, 2);
if (result !== 'none') console.log(result);
else console.log(0);

function dfs(row, col) {
  if (success === true) return;
  visited[row][col] = true;
  order.push({row: row, col: col, value: isNaN(parseInt(board[row][col])) ? board[row][col] : parseInt(board[row][col])});

  if (order.length % 2 === 1 && order.length !== 1) {
    if (order[order.length - 2].value === '+') sum += parseInt(board[row][col]);
    else if (order[order.length - 2].value === '-') sum -= parseInt(board[row][col]);
  }
  else if (order.length === 1) {
    sum += parseInt(board[row][col]);
  }

  if (order.length === combo) {
    if (sum === goal) {
      success = true;
      result = '1\n';
      for (let i = 0; i < combo; i++) {
        result += order[i].row + ' ' + order[i].col + '\n';
      }
    }
    visited[row][col] = false;
    if (typeof order[order.length - 1].value === 'number') {
      if (order.length >= 3) {
        if (order[order.length - 2].value === '+') sum -= order[order.length - 1].value;
        else sum += order[order.length - 1].value;
      }
      else sum -= order[order.length - 1].value;
    }
    order.pop();
    return;
  }

  if (row > 0 && visited[row - 1][col] === false) dfs(row - 1, col);
  if (row < 2 && visited[row + 1][col] === false) dfs(row + 1, col);
  if (col > 0 && visited[row][col - 1] === false) dfs(row, col - 1);
  if (col < 2 && visited[row][col + 1] === false) dfs(row, col + 1);

  visited[row][col] = false;
  if (typeof order[order.length - 1].value === 'number') {
    if (order.length >= 3) {
      if (order[order.length - 2].value === '+') sum -= order[order.length - 1].value;
      else sum += order[order.length - 1].value;
    }
    else sum -= order[order.length - 1].value;
  }
  order.pop();
}