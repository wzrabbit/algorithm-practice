let tree = {};

function preorder(node) {
  if (node === '.') return '';
  let result = node + preorder(tree[node][0]) + preorder(tree[node][1]);
  return result;
}

function inorder(node) {
  if (node === '.') return '';
  let result = inorder(tree[node][0]) + node + inorder(tree[node][1]);
  return result;
}

function postorder(node) {
  if (node === '.') return '';
  let result = postorder(tree[node][0]) + postorder(tree[node][1]) + node;
  return result;
}

const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const cases = parseInt(input[0]);
for (let i = 1; i <= cases; i++) {
  const [root, left, right] = input[i].split(' ');
  tree[root] = [left, right];
}

console.log(preorder('A'));
console.log(inorder('A'));
console.log(postorder('A'));