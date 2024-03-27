const input = require('fs').readFileSync(0, 'utf-8').trim().split("\n");
const S = input[0];
const N = input[1];
const queries = input.slice(2).map((query) => query.split(' ').map(Number));

let left = 0;
let right = N;

queries.forEach((query) => {
  left += query[0];
  right -= right - left - query[1];
})

console.log(S.slice(left, right));
