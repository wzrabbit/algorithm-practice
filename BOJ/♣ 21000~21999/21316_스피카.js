const edge = require('fs').readFileSync(0, 'utf-8')
    .toString().trim().split('\n')
    .map(x => x.split(' ').map(y => parseInt(y)));

const adj = new Array(13).fill(0);
const graph = Array.from(Array(13), () => []);

for (let i = 0; i < 12; i++) {
    const start = edge[i][0];
    const end = edge[i][1];

    graph[start].push(end);
    graph[end].push(start);
    adj[start]++;
    adj[end]++;
}

for (let i = 1; i <= 12; i++) {
    if (adj[i] !== 3) continue;
    let checker = new Array(4).fill(0);

    for (let j = 0; j < 3; j++) {
        checker[adj[graph[i][j]]]++;
    }

    if (checker[1] === 1 && checker[2] === 1 && checker[3] === 1) {
        console.log(i);
        break;
    }
}