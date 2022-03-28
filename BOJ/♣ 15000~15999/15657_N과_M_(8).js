const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [n, m] = input[0].split(' ').map((x) => parseInt(x));
let num = input[1].split(' ').map((x) => parseInt(x)).sort((x, y) => x - y);
let result = '';
let attempt = [];
for (let i = 0; i < n; i++) {
  dfs(i, 1);
}

function dfs(current, len) {
  attempt.push(num[current]);
  if (len === m) {
    result += attempt.join(' ') + '\n';
    attempt.pop();
    return;
  }
  for (let i = 0; i < num.length; i++) {
    if (num[i] >= num[current]) {
      dfs(i, len + 1);
    }
  }
  attempt.pop();
}

console.log(result);