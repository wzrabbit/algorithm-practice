const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const nodes = parseInt(input[0]);
let tree = {};
let parent = new Array(nodes + 1).fill(null);
for (let i = 1; i < nodes; i++) {
  const [left, right] = input[i].split(' ').map((x) => parseInt(x));
  if (tree[left] === undefined) tree[left] = [right];
  else tree[left].push(right);
  if (tree[right] === undefined) tree[right] = [left];
  else tree[right].push(left);
}

let queue = [1];
while (queue.length !== 0) {
  const d = queue.shift();
  if (tree[d] === undefined) continue;
  for (let n = 0; n < tree[d].length; n++) {
    if (parent[tree[d][n]] === null) {
      parent[tree[d][n]] = d;
      queue.push(tree[d][n]);
    }
  }
}

let result = '';
for (let i = 2; i < parent.length; i++) {
  result += parent[i] + '\n';
}

console.log(result);