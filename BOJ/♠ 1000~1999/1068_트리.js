const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const nodes = parseInt(input[0]);
let count = 0;
let tree = input[1].split(' ').map((x) => parseInt(x));
let remove = parseInt(input[2]);
let root;
let found = false;
let visited = new Array(nodes).fill(false);
let graph = new Array(nodes);
for (let i = 0; i < nodes; i++) {
  graph[i] = [];
}

for (let i = 0; i < nodes; i++) {
  if (tree[i] === -1) {
    root = i;
    continue;
  }
  graph[i].push(tree[i]);
  graph[tree[i]].push(i);
}
// 지워질 노드의 부모 노드에서 지워지는 노드의 간선 제거 (단, 루트 노드는 부모가 없으므로 제외)
if (remove !== root) {
  graph[tree[remove]].splice(graph[tree[remove]].indexOf(remove), 1);
  visited[tree[remove]] = true;
}
deleteNode(remove);

for (let i = 0; i < nodes; i++) {
  if (graph[i].length === 1 && i !== root) count++;
}
// 루트 노드만 남았을 경우 루트 노드가 리프 노드이므로 카운트 증가 (99% 오답)
if (root !== remove && count === 0) count++;

console.log(count);

// 제거 함수 : 자신과 하위 노드 제거
function deleteNode(node) {
  visited[node] = true;
  for (let i = 0; i < graph[node].length; i++) {
    if (visited[graph[node][i]] === false) deleteNode(graph[node][i]);
  }
  graph[node] = [];
  visited[node] = false;
}