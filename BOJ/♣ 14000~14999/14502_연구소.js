const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [row, col] = input[0].split(' ').map(Number);
let visited = new Array(row * col).fill(false);
let sampleGraph = [];
let sampleQueue = [];
let max = 0;

// 1. 탐색에 사용할 샘플 그래프, 샘플 큐 생성
for (let i = 1; i < input.length; i++) sampleGraph.push(input[i].split(' ').map(Number));
for (let r = 0; r < row; r++) {
    for (let c = 0; c < col; c++) {
        if (sampleGraph[r][c] === 2) sampleQueue.push([r, c]);
    }
}

// 2. 블록을 놓을 위치를 추첨 (조합 구하기)
for (let i = 0; i <= row * col - 3; i++) pickLocation(i, []);
function pickLocation(current, list) {
    visited[current] = true;
    list.push(current);

    if (list.length === 3) {
        let [r1, c1] = [parseInt(list[0] / col), list[0] % col];
        let [r2, c2] = [parseInt(list[1] / col), list[1] % col];
        let [r3, c3] = [parseInt(list[2] / col), list[2] % col];
        if (sampleGraph[r1][c1] === 0 && sampleGraph[r2][c2] === 0 && sampleGraph[r3][c3] === 0) {
            bfs(sampleGraph, sampleQueue, r1, c1, r2, c2, r3, c3);
        }
        visited[current] = false;
        return;
    }

    if (current - list.length > row * col - 4) {
        visited[current] = false;
        return;
    }

    for (let i = current + 1; i <= row * col - 1; i++) {
        if (visited[i] === false) {
            let newList = list.slice();
            pickLocation(i, newList);
        }
    }

    visited[current] = false;
}

// 3. 구한 조합으로 바이러스 탐색 (BFS)
function bfs(g, q, r1, c1, r2, c2, r3, c3) {
    let graph = g.map(x => x.slice());
    let queue = q.map(x => x.slice());
    graph[r1][c1] = 1;
    graph[r2][c2] = 1;
    graph[r3][c3] = 1;

    while (queue.length !== 0) {
        [r, c] = queue.shift();
        if (r > 0 && graph[r - 1][c] === 0) {
            graph[r - 1][c] = 3;
            queue.push([r - 1, c]);
        }
        if (r < row - 1 && graph[r + 1][c] === 0) {
            graph[r + 1][c] = 3;
            queue.push([r + 1, c]);
        }
        if (c > 0 && graph[r][c - 1] === 0) {
            graph[r][c - 1] = 3;
            queue.push([r, c - 1]);
        }
        if (c < col - 1 && graph[r][c + 1] === 0) {
            graph[r][c + 1] = 3;
            queue.push([r, c + 1]);
        }
    }

    getSafetyArea(graph);
}

// 4. 안전지대 구하고 최댓값 갱신
function getSafetyArea(graph) {
    let safetyArea = 0;
    for (let r = 0; r < row; r++) {
        for (let c = 0; c < col; c++) {
            if (graph[r][c] === 0) safetyArea++;
        }
    }
    if (safetyArea > max) max = safetyArea;
}

console.log(max);