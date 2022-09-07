function getVainSimp() {
    let noSolve = 0;
    let allSolve = 0;

    for (let r = 0; r < R; r++) {
        if (board[r][C - 3] === 0)
            noSolve++;
        else if (board[r][C - 3] === C - 3)
            allSolve++;
    }

    return {
        vain: noSolve / R,
        simp: allSolve / R
    };
}

function getEvenness() {
    let solveAmount = [];

    for (let r = 0; r < R; r++) {
        solveAmount.push(board[r][C - 3]);
    }
    solveAmount.sort((a, b) => a - b);

    let skipped = 0;
    for (let i = 0; i < solveAmount.length - 1; i++) {
        const gap = solveAmount[i + 1] - solveAmount[i];
        if (gap >= 2) skipped += gap - 1;
    }

    return skipped / (C - 3);
}

function getUnsolvability() {
    let unsolved = 0;

    for (let c = 0; c < C - 3; c++) {
        let flag = true;
        for (let r = 0; r < R; r++) {
            if (board[r][c] >= 0) flag = false;
        }
        if (flag) unsolved++;
    }

    return unsolved / (C - 3);
}

function getInstability() {
    let result = [];

    for (let c = 0; c < C - 3; c++) {
        let combo = 0;
        let blank = 0;
        let activated = false;
        let lowest;
        for (let r = R - 1; r >= 0; r--) {
            if (board[r][c] >= 0) {
                if (!activated) {
                    activated = true;
                    lowest = board[r][C - 1];
                }
                else {
                    blank += combo;
                    combo = 0;
                }
            }
            else if (activated && board[r][C - 1] !== lowest) combo++;
        }
        blank += combo;
        result.push(blank / R);
    }

    return result;
}

const input = require('fs').readFileSync(0, 'utf-8').toString().trim();
let rawBoard = input.match(/(?<=\n-{2,}\n)[\s\S]*/)[0].split('\n').map((x) => x.trim().split(/ +/g));
const R = rawBoard.length;
const C = input.match(/(?<=Team).+(?==\s*Time\s*R\s*\n-{2,}\n)/)[0].replace(/ +/g, '').length + 3;
let board = new Array(rawBoard.length);
let printer = '';

for (let r = 0; r < R; r++) {
    board[r] = [];
    for (let c = rawBoard[r].length - C; c < rawBoard[r].length; c++) {
        let comp = rawBoard[r][c].replace('+', '');
        if (comp === '') comp = 0;
        else if (comp === '.') comp = -1;
        comp = parseInt(comp);
        board[r].push(parseInt(comp));
    }
}

const vainSimp = getVainSimp();
const vain = vainSimp.vain;
const simp = vainSimp.simp;
const even = getEvenness();
const unsol = getUnsolvability();
const insta = getInstability();
const instaSum = insta.reduce((a, b) => a + b, 0);
const negi = 1.03 * vain + 3.141 * simp + 2.171 * even + 1.414 * unsol + instaSum / (C - 3);

printer += `Vainness = ${vain}
Oversimplification = ${simp}
Evenness = ${even}
Unsolvability = ${unsol}
`;

for (let i = 1; i <= C - 3; i++) {
    printer += `Instability ${i} = ${insta[i - 1]}\n`;
}

printer += `Negidealness = ${negi}\n`;
console.log(printer);