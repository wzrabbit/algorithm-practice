const alphabet = {
    A: ['.***..', '*...*.', '*****.', '*...*.', '*...*.'],
    B: ['****..', '*...*.', '****..', '*...*.', '****..'],
    C: ['.****.', '*...*.', '*.....', '*.....', '.****.'],
    D: ['****..', '*...*.', '*...*.', '*...*.', '****..'],
    E: ['*****.', '*.....', '***...', '*.....', '*****.'],
    F: ['*****.', '*.....', '***...', '*.....', '*.....'],
    G: ['.****.', '*.....', '*..**.', '*...*.', '.***..'],
    H: ['*...*.', '*...*.', '*****.', '*...*.', '*...*.'],
    I: ['*****.', '..*...', '..*...', '..*...', '*****.'],
    J: ['..***.', '...*..', '...*..', '*..*..', '.**...'],
    K: ['*...*.', '*..*..', '***...', '*..*..', '*...*.'],
    L: ['*.....', '*.....', '*.....', '*.....', '*****.'],
    M: ['*...*.', '**.**.', '*.*.*.', '*...*.', '*...*.'],
    N: ['*...*.', '**..*.', '*.*.*.', '*..**.', '*...*.'],
    O: ['.***..', '*...*.', '*...*.', '*...*.', '.***..'],
    P: ['****..', '*...*.', '****..', '*.....', '*.....'],
    Q: ['.***..', '*...*.', '*...*.', '*..**.', '.****.'],
    R: ['****..', '*...*.', '****..', '*..*..', '*...*.'],
    S: ['.****.', '*.....', '.***..', '....*.', '****..'],
    T: ['*****.', '*.*.*.', '..*...', '..*...', '.***..'],
    U: ['*...*.', '*...*.', '*...*.', '*...*.', '.***..'],
    V: ['*...*.', '*...*.', '.*.*..', '.*.*..', '..*...'],
    W: ['*...*.', '*...*.', '*.*.*.', '**.**.', '*...*.'],
    X: ['*...*.', '.*.*..', '..*...', '.*.*..', '*...*.'],
    Y: ['*...*.', '.*.*..', '..*...', '..*...', '..*...'],
    Z: ['*****.', '...*..', '..*...', '.*....', '*****.'],
    ' ': ['......', '......', '......', '......', '......']
}

function commandP(scale, row, col, text) {
    if (scale === 'C5') {
        for (let i = 0; i < text.length; i++) {
            if (col >= 60)
                return;

            drawLargeAlphabet(text[i], row, col);
            col += 6;
        }
    }
    else
        drawSmallSentence(text, row, col);
}

function commandOther(mode, scale, row, text) {
    let col;

    switch (mode) {
        case '.L':
            col = 0;
            break;
        case '.R':
            if (scale === 'C5')
                col = 60 - text.length * 6;
            else
                col = 60 - text.length;
            break;
        case '.C':
            if (scale === 'C5')
                col = 30 - text.length * 3;
            else if (text.length % 2 === 0)
                col = 30 - text.length / 2;
            else
                col = 30 - Math.floor(text.length / 2);
            break;
    }

    if (scale === 'C5') {
        for (let i = 0; i < text.length; i++) {
            if (col >= 60)
                return;

            drawLargeAlphabet(text[i], row, col);
            col += 6;
        }
    }
    else
        drawSmallSentence(text, row, col);
}

function commandEOP() {
    for (let r = 0; r < 60; r++)
        printer += board[r].join('') + '\n';

    printer += '\n' + '-'.repeat(60) + '\n\n';
    board = Array.from(Array(60), () => new Array(60).fill('.'));
}

function drawSmallSentence(text, startRow, startCol) {
    for (let i = 0; i < text.length; i++) {
        if (startCol >= 60)
            return;

        if (text[i] !== ' ')
            board[startRow][startCol] = text[i];

        startCol++;
    }
}

function drawLargeAlphabet(letter, startRow, startCol) {
    for (let r = 0; r < 5; r++) {
        for (let c = 0; c < 6; c++) {
            if (r >= 0 && r < 60 && c >= 0 && c < 60) {
                let paintR = startRow + r;
                let paintC = startCol + c;

                if (paintR >= 0 && paintR < 60 && paintC >= 0 && paintC < 60 &&
                    alphabet[letter][r][c] === '*')
                    board[paintR][paintC] = '*';
            }
        }
    }
}

const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let board = Array.from(Array(60), () => new Array(60).fill('.'));
let printer = '';

for (let i = 0; i < input.length; i++) {
    let command = input[i].match(/^\.[PLRCEOP]{1,3}|C[15]|\d{1,2}|(?<=\|).+(?=\|)/g);

    switch (command[0]) {
        case '.P':
            commandP(
                command[1],
                parseInt(command[2]) - 1,
                parseInt(command[3]) - 1,
                command[4]
            );
            break;
        case '.L':
        case '.R':
        case '.C':
            commandOther(
                command[0],
                command[1],
                parseInt(command[2]) - 1,
                command[3]
            );
            break;
        case '.EOP':
            commandEOP();
            break;
    }
}

console.log(printer);