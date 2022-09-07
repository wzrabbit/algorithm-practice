let [N, ...grid] = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
N = parseInt(N);
grid = grid.map(x => x.split(''));
let min = 500;

for (let i = 0; i < 2 ** N; i++) {
    let curGrid = grid.map(x => x.slice());
    let score = 0;

    for (let c = 0; c < N; c++) {
        if (i & (2 ** c)) {
            for (let r = 0; r < N; r++)
                curGrid[r][c] = curGrid[r][c] === 'H' ? 'T' : 'H';
        }
    }

    for (let r = 0; r < N; r++) {
        let tCount = 0;
        for (let c = 0; c < N; c++)
            if (curGrid[r][c] === 'T') tCount++;

        score += Math.min(tCount, N - tCount);
    }

    min = Math.min(min, score);
}

console.log(min);