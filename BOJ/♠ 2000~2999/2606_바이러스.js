// BFS 구현 예시 - Node.js(JavaScript)

// 그냥 이건 제가 평소에 구현하던 큐입니다. 여러분은 여러분만의 큐를 사용하세요
class Queue {
  queue = [];
  top = 0;

  push(value) {
    this.queue.push(value);
  }

  pop() {
    return this.queue.pop();
  }

  isEmpty() {
    return this.queue.length - this.top === 0;
  }
}

// 이게 bfs 코드입니다. 이 부분만 집중해서 보셔도 됩니다
const bfs = (startNode) => {
  const queue = new Queue();
  queue.push(startNode);
  visited[startNode] = true;

  while (!queue.isEmpty()) {
    const currentNode = queue.pop();

    infectedCount += 1; // 정점이 방문될 때마다 감염 횟수 + 1

    for (let i = 0; i < graph[currentNode].length; i++) {
      const nextNode = graph[currentNode][i];

      if (!visited[nextNode]) {
        queue.push(nextNode);
        visited[nextNode] = true;
      }
    }
  }
}

let [V, _, ...edges] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const graph = Array.from({ length: V + 1 }).map(() => []);
const visited = Array.from({ length: V + 1 }).map(() => false);
let infectedCount = 0;

edges.forEach((edge) => {
  const [u, v] = edge.split(' ').map(Number);

  graph[u].push(v);
  graph[v].push(u);
});

bfs(1);

console.log(infectedCount - 1); // 1번 컴퓨터는 제외