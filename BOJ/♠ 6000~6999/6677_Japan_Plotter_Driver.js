const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let index = 0;
let board, row, col;
let printer = '';

while (index < input.length - 1) {
    [col, row] = input[index].split(' ').map((x) => parseInt(x));
    index++;
    draw();
}

console.log(printer);

function draw() {
    board = new Array(row + 2).fill(0).map((x) => new Array(col + 2).fill(' '));

    makeFrame(row, col);

    while (true) {
        let command = input[index].split(' ').map((x) => {
            if (isNaN(x)) return x;
            else return parseInt(x);
        });
        let kill = false;

        switch (command[0]) {
            case 'POINT':
                drawPoint(command[2], command[1]);
                break;
            case 'TEXT':
                drawText(command[2], command[1], command[3]);
                break;
            case 'LINE':
                drawLine(command[2], command[1], command[4], command[3]);
                break;
            case 'CLEAR':
                clear(command[2], command[1], command[4], command[3]);
                break;
            case 'PRINT':
                print();
                kill = true;
                break;
        }

        index++;
        if (kill)
            break;
    }
}

function makeFrame() {
    for (let r = 1; r <= row; r++) {
        board[r][0] = '|';
        board[r][col + 1] = '|';
    }
    for (let c = 1; c <= col; c++) {
        board[0][c] = '-';
        board[row + 1][c] = '-';
    }
    board[0][0] = '+';
    board[row + 1][0] = '+';
    board[0][col + 1] = '+';
    board[row + 1][col + 1] = '+';
}

function drawPoint(ro, co) {
    if (board[ro][co] === ' ')
        board[ro][co] = 'o';
    else if (board[ro][co] !== 'o')
        board[ro][co] = '*';
}

function drawText(ro, co, text) {
    text = text.toString();
    for (let c = co; c < Math.min(co + text.length, col + 1); c++) {
        if (board[ro][c] === ' ')
            board[ro][c] = text[c - co];
        else if (board[ro][c] !== text[c - co])
            board[ro][c] = '*';
    }
}

function drawLine(ro1, co1, ro2, co2) {
    [[ro1, co1], [ro2, co2]] = [[ro1, co1], [ro2, co2]].sort((a, b) => {
        if (a[0] !== b[0])
            return a[0] - b[0];
        else
            return a[1] - b[1];
    });

    let move, drawer;

    if (ro1 === ro2) {
        move = [0, 1];
        drawer = '-';
    }
    else if (co1 === co2) {
        move = [1, 0];
        drawer = '|';
    }
    else if (ro1 < ro2 && co1 < co2) {
        move = [1, 1];
        drawer = '\\';
    }
    else {
        move = [1, -1];
        drawer = '/';
    }

    while (true) {
        if (board[ro1][co1] === ' ')
            board[ro1][co1] = drawer;
        else if (
            board[ro1][co1] === '-' && drawer === '|' ||
            board[ro1][co1] === '|' && drawer === '-' ||
            board[ro1][co1] === '+' && drawer === '|' ||
            board[ro1][co1] === '+' && drawer === '-'
        )
            board[ro1][co1] = '+';
        else if (
            board[ro1][co1] === '/' && drawer === '\\' ||
            board[ro1][co1] === '\\' && drawer === '/' ||
            board[ro1][co1] === 'x' && drawer === '\\' ||
            board[ro1][co1] === 'x' && drawer === '/'
        )
            board[ro1][co1] = 'x'
        else if (board[ro1][co1] !== drawer)
            board[ro1][co1] = '*';

        if (ro1 === ro2 && co1 === co2)
            break;

        ro1 += move[0];
        co1 += move[1];
    }
}

function clear(ro1, co1, ro2, co2) {
    if (ro1 > ro2)
        [ro1, ro2] = [ro2, ro1];
    if (co1 > co2)
        [co1, co2] = [co2, co1];

    for (let r = ro1; r <= ro2; r++) {
        for (let c = co1; c <= co2; c++)
            if (r > 0 && r <= row && c > 0 && c <= col)
                board[r][c] = ' ';
    }
}

function print() {
    for (let r = 0; r <= row + 1; r++) {
        printer += board[r].join('') + '\n';
    }
    printer += '\n';
}