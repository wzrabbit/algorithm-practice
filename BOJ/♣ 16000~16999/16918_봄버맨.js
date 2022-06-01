let [rct, ...board] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [row, col, time] = rct.split(' ').map((x) => parseInt(x));
board = board.map((x) => x.split(''));
let printer = '';
dr = [-1, 1, 0, 0];
dc = [0, 0, -1, 1];

function timeFlow() {
    for (let r = 0; r < row; r++) {
        for (let c = 0; c < col; c++) {
            if (board[r][c] !== -1)
                board[r][c]++;
        }
    }
}

function setBomb() {
    for (let r = 0; r < row; r++) {
        for (let c = 0; c < col; c++) {
            if (board[r][c] === -1)
                board[r][c] = 0;
        }
    }
}

function explodeBomb() {
    for (let r = 0; r < row; r++) {
        for (let c = 0; c < col; c++) {
            if (board[r][c] === 3) {
                board[r][c] = -1;

                for (let i = 0; i < 4; i++) {
                    let r_ = r + dr[i];
                    let c_ = c + dc[i];

                    if (r_ >= 0 && r_ < row && c_ >= 0 && c_ < col && board[r_][c_] !== 3)
                        board[r_][c_] = -1;
                }
            }
        }
    }
}

for (let r = 0; r < row; r++) {
    for (let c = 0; c < col; c++) {
        if (board[r][c] === 'O')
            board[r][c] = 0;
        else
            board[r][c] = -1;
    }
}

timeFlow();
for (let i = 2; i <= time; i++) {
    timeFlow();

    if (i % 2 === 0)
        setBomb();
    else
        explodeBomb();
}

for (let r = 0; r < row; r++) {
    for (let c = 0; c < col; c++) {
        if (board[r][c] === -1)
            printer += '.';
        else
            printer += 'O';
    }
    printer += '\n';
}

console.log(printer);