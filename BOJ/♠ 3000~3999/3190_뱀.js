const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const boardScale = parseInt(input[0]);
const appleCases = parseInt(input[1]) + 1;
const moveCases = appleCases + parseInt(input[appleCases + 1]) + 2;
let queue = [[0, 0]];
let action = [];
let index = 0;
let actionIndex = 0;
let time = 0;
let direction = 90;
let [row, col] = [0, 0];

let board = new Array(boardScale);
for (let i = 0; i < boardScale; i++) {
    board[i] = new Array(boardScale).fill('□');
}
board[0][0] = '■';

for (let i = 2; i <= appleCases; i++) {
    let [r, c] = input[i].split(' ').map(Number);
    board[r - 1][c - 1] = '♥'; // 문제에서 주어진 좌표에서 1을 빼야함
}

for (let i = appleCases + 2; i < moveCases; i++) {
    let act = input[i].split(' ');
    act[0] = parseInt(act[0]);
    act[1] = act[1].replace('\r', ''); // 일부 인터프리터에서 오류
    action.push(act);
}

playGame();

function playGame() {
    while (true) {
        time++;
        // 앞 칸이 맵의 바깥이거나 자신의 몸일 경우, 사망
        switch (direction) {
            case 0:
                if (row - 1 < 0 || board[row - 1][col] === '■') return;
                else[row, col] = [row - 1, col];
                break;
            case 180:
                if (row + 1 > boardScale - 1 || board[row + 1][col] === '■') return;
                else[row, col] = [row + 1, col];
                break;
            case 270:
                if (col - 1 < 0 || board[row][col - 1] === '■') return;
                else[row, col] = [row, col - 1];
                break;
            case 90:
                if (col + 1 > boardScale - 1 || board[row][col + 1] === '■') return;
                else[row, col] = [row, col + 1];
                break;
        }
        // 앞 칸이 사과일 경우 몸길이를 늘리고, 그렇지 않을 경우 이동만
        if (board[row][col] !== '♥') {
            board[queue[index][0]][queue[index][1]] = '□';
            index++;
        }
        queue.push([row, col]);
        board[row][col] = '■';

        // 방향을 바꿔야 하는 지 확인 후 방향 변경
        if (action.length > actionIndex && time === action[actionIndex][0]) {
            if (action[actionIndex][1] === 'L') direction -= 90;
            else direction += 90;
            if (direction === -90) direction = 270;
            if (direction === 360) direction = 0;
            actionIndex++;
        }
    }
}

console.log(time);