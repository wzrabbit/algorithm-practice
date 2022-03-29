let [rowcol, ...board] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [row, col] = rowcol.split(' ').map((x) => parseInt(x));
board = board.map((x) => x.split(''));
let count = 0;

function isMBTI(text) {
    if (/((E|I)(S|N)(F|T)(J|P))|((J|P)(F|T)(S|N)(E|I))/.test(text))
        return true;
    else
        return false;
}

for (let r = 0; r < row - 3; r++) {
    for (let c = 0; c < col; c++) {
        if (isMBTI(board[r][c] + board[r + 1][c] + board[r + 2][c] + board[r + 3][c]))
            count++;
    }
}

for (let r = 0; r < row; r++) {
    for (let c = 0; c < col - 3; c++) {
        if (isMBTI(board[r][c] + board[r][c + 1] + board[r][c + 2] + board[r][c + 3]))
            count++;
    }
}

for (let r = 0; r < row - 3; r++) {
    for (let c = 0; c < col - 3; c++) {
        if (isMBTI(board[r][c] + board[r + 1][c + 1] + board[r + 2][c + 2] + board[r + 3][c + 3]))
            count++;
    }
}

for (let r = 0; r < row - 3; r++) {
    for (let c = 0; c < col - 3; c++) {
        if (isMBTI(board[r][c + 3] + board[r + 1][c + 2] + board[r + 2][c + 1] + board[r + 3][c]))
            count++;
    }
}