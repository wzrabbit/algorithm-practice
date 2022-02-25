const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let [houseCol, houseRow, pool] = input[0].split(' ').map((x) => parseInt(x));
houseCol += 500;
houseRow += 500;

let graph = new Array(1001);
for (let i = 0; i < 1001; i++) {
    graph[i] = new Array(1001).fill(0);
}

for (let i = 1; i <= pool; i++) {
    const [col, row] = input[i].split(' ').map((x) => parseInt(x));
    graph[row + 500][col + 500] = 1;
}

bfs();

function bfs() {
    let queue = [[500, 500, 0]];

    while (queue.length !== 0) {
        const [r, c, d] = queue.shift();

        if (r === houseRow && c === houseCol) {
            console.log(d);
            return;
        }

        if (r > 0 && graph[r - 1][c] === 0) {
            graph[r - 1][c] = 'V';
            queue.push([r - 1, c, d + 1]);
        }
        if (r < 1000 && graph[r + 1][c] === 0) {
            graph[r + 1][c] = 'V';
            queue.push([r + 1, c, d + 1]);
        }
        if (c > 0 && graph[r][c - 1] === 0) {
            graph[r][c - 1] = 'V';
            queue.push([r, c - 1, d + 1]);
        }
        if (c < 1000 && graph[r][c + 1] === 0) {
            graph[r][c + 1] = 'V';
            queue.push([r, c + 1, d + 1]);
        }
    }
}