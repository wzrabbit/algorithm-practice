const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const lines = parseInt(input[0]);
let arr = new Array(500001).fill(500001);
let dp = new Array(500001).fill(500001);
dp[0] = 0;
let dpOrigin = new Array(500001).fill(0);
let history = new Array(500001).fill(0);
let longest = {index: 0, len: 0};

for (let i = 1; i <= lines; i++) {
  const [s, e] = input[i].split(' ').map((x) => parseInt(x));
  arr[s] = e;
}

for (let i = 1; i <= 500000; i++) {
  if (arr[i] === 500001) continue;
  let start = 1, end = 500000, mid;
  while (start <= end) {
    mid = Math.floor((start + end) / 2);
    if (arr[i] > dp[mid]) start = mid + 1;
    else end = mid - 1;
  }
  if (arr[i] < dp[start]) {
    dp[start] = arr[i];
    dpOrigin[start] = i;
  }
  if (start > longest.len) {
    longest.index = i;
    longest.len = start;
  }
  history[i] = dpOrigin[start - 1];
}

let next = longest.index;
let left = arr.slice();
while (next !== 0) {
  left[next] = 500001;
  next = history[next];
}

let printer = lines - longest.len + '\n';
for (let i = 1; i <= 500000; i++) {
  if (left[i] !== 500001) printer += i + '\n';
}
console.log(printer);