const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const vertex = parseInt(input[0].split(' ')[0]);
const edge = parseInt(input[0].split(' ')[1]);
const start = parseInt(input[0].split(' ')[2]);

// 그래프 정의 및 간선 생성
let graph = {};
for (let i = 1; i < input.length; i++) {
  addValue(parseInt(input[i].split(' ')[0]), parseInt(input[i].split(' ')[1]));
  addValue(parseInt(input[i].split(' ')[1]), parseInt(input[i].split(' ')[0]));
}

// DFS 함수 실행
let dfsResult = '';
let dfsVisited = new Array(vertex + 1).fill(false);
dfs(graph, start, dfsVisited);
dfsVisited = dfsVisited.slice(0, -1);
console.log(dfsResult);

// BFS 함수 실행
let bfsResult = '';
let bfsVisited = new Array(vertex + 1).fill(false);
bfs(graph, start, bfsVisited);
bfsVisited = bfsVisited.slice(0, -1);
console.log(bfsResult);

// DFS 함수
function dfs(graph, current, visited) {
  visited[current] = true;
  dfsResult += current + ' ';

  if (graph[current] !== undefined) graph[current].sort((a, b) => a - b); // 오름차순 탐색을 위한 정렬
  for (let i = 0; i < (graph[current] || []).length; i++) {
    if (visited[graph[current][i]] === false) dfs(graph, graph[current][i], visited);
  }
}

// BFS 함수
function bfs(graph, start, visited) {
  let queue = [start];
  visited[start] = true;

  // BFS는 큐가 빌 때까지 진행됨 (큐가 비었음 = 모든 노드를 탐색했음)
  while (queue.length !== 0) {
    current = queue.shift();
    bfsResult += current + ' ';

    if (graph[current] !== undefined) graph[current].sort((a, b) => a - b); // 오름차순 탐색을 위한 정렬
    for (let i = 0; i < (graph[current] || []).length; i++) {
      if (visited[graph[current][i]] === false) {
        queue.push(graph[current][i]);
        visited[graph[current][i]] = true;
      }
    }
  }
}

function addValue(a, b) {
  if (graph[a] === undefined) graph[a] = [b];
  else graph[a].push(b);
}