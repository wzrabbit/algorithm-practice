const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [row, col, time] = input[0].split(' ').map(Number);
input.shift();
let min = 999999;
let gram = false;

// 입력된 input값을 배열로
for (let i = 0; i < row; i++) {
    input[i] = input[i].split(' ');
}

bfs();

if (min !== 999999) console.log(min);
else console.log('Fail');

// 탐색
function bfs() {
    let queue = [[0, 0, time, 0, false]];
    input[0][0] = 'V';

    while (queue.length !== 0) {
        // r: 현재 행 , c: 현재 열, t : 현재 시간, d : 현재 거리, g : 그람 칸의 여부
        const [r, c, t, d, g] = queue.shift();
        if (t < 0) continue;
        if (g && gram === false) {
            foundGram(r, c, t, d);
        }
        if (r === row - 1 && c === col - 1) {
            if (d < min) min = d;
            return;
        }

        if (r > 0) {
            if (input[r - 1][c] === '0' || input[r - 1][c] === '2') {
                if (input[r - 1][c] === '0') queue.push([r - 1, c, t - 1, d + 1, false]);
                else queue.push([r - 1, c, t - 1, d + 1, true]);
                input[r - 1][c] = 'V';
            }
        }
        if (r < row - 1) {
            if (input[r + 1][c] === '0' || input[r + 1][c] === '2') {
                if (input[r + 1][c] === '0') queue.push([r + 1, c, t - 1, d + 1, false]);
                else queue.push([r + 1, c, t - 1, d + 1, true]);
                input[r + 1][c] = 'V';
            }
        }
        if (c > 0) {
            if (input[r][c - 1] === '0' || input[r][c - 1] === '2') {
                if (input[r][c - 1] === '0') queue.push([r, c - 1, t - 1, d + 1, false]);
                else queue.push([r, c - 1, t - 1, d + 1, true]);
                input[r][c - 1] = 'V';
            }
        }
        if (c < col - 1) {
            if (input[r][c + 1] === '0' || input[r][c + 1] === '2') {
                if (input[r][c + 1] === '0') queue.push([r, c + 1, t - 1, d + 1, false]);
                else queue.push([r, c + 1, t - 1, d + 1, true]);
                input[r][c + 1] = 'V';
            }
        }
    }
}

function foundGram(r, c, t, d) {
    gram = true;
    input[r][c] = 'V';
    let dist = d + row - 1 - r + col - 1 - c;
    if (dist - d > t) return;
    if (dist < min) min = dist;
}