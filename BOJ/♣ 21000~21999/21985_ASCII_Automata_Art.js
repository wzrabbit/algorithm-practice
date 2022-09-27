const task0 = regex => {
    const L = regex.length;
    let board = Array.from(Array(3), () => new Array(L + 4).fill(' '));

    for (let c = 1; c < L + 3; c++) {
        board[0][c] = '-';
        board[2][c] = '-';
    }

    for (let r = 0; r < 3; r++) {
        board[r][0] = '+';
        board[r][L + 3] = '+';
    }

    for (let c = 2; c < 2 + L; c++) {
        board[1][c] = regex[c - 2];
    }

    storage.push({ row: 3, col: L + 4, data: board });
    return `<${id++}>`;
}

const task1 = (regex, type) => {
    const curId = parseInt(regex.match(/[0-9]+/)[0]);
    const frag = storage[curId];
    let R, C, board;

    if (type === '*') {
        [R, C] = [frag.row + 5, frag.col + 6];
        board = Array.from(Array(R), () => new Array(C).fill(' '));

        for (let c = 0; c < C; c++) {
            board[1][c] = '-';
            board[R - 1][c] = '-';
        }

        for (let r = 1; r < R; r++) {
            board[r][0] = '|';
            board[r][C - 1] = '|';
        }

        board[1][0] = '+';
        board[R - 1][0] = '+';
        board[1][C - 1] = '+';
        board[R - 1][C - 1] = '+';

        board[R - 1][1] = '<';
        board[1][C - 2] = '>';

        board[4][0] = '+';
        board[4][1] = '-';
        board[4][2] = '>';
        board[4][C - 3] = '-';
        board[4][C - 2] = '>';
        board[4][C - 1] = '+';

        for (let r = 3; r < R - 2; r++) {
            for (let c = 3; c < C - 3; c++) {
                board[r][c] = frag.data[r - 3][c - 3];
            }
        }
    }
    else if (type === '+') {
        [R, C] = [frag.row + 2, frag.col + 6];
        board = Array.from(Array(R), () => new Array(C).fill(' '));

        for (let c = 0; c < C; c++) {
            board[1][c] = '-';
            board[R - 1][c] = '-';
        }

        for (let r = 1; r < R; r++) {
            board[r][0] = '|';
            board[r][C - 1] = '|';
        }

        board[1][0] = '+';
        board[R - 1][0] = '+';
        board[1][C - 1] = '+';
        board[R - 1][C - 1] = '+';

        board[R - 1][1] = '<';

        board[1][0] = '+';
        board[1][1] = '-';
        board[1][2] = '>';
        board[1][C - 3] = '-';
        board[1][C - 2] = '>';
        board[1][C - 1] = '+';

        for (let r = 0; r < R - 2; r++) {
            for (let c = 3; c < C - 3; c++) {
                board[r][c] = frag.data[r][c - 3];
            }
        }
    }
    else {
        [R, C] = [frag.row + 3, frag.col + 6];
        board = Array.from(Array(R), () => new Array(C).fill(' '));

        for (let c = 0; c < C; c++) {
            board[1][c] = '-';
            board[4][c] = '-';
        }

        for (let r = 1; r < 4; r++) {
            board[r][0] = '|';
            board[r][C - 1] = '|';
        }

        board[1][0] = '+';
        board[1][C - 1] = '+';

        board[1][C - 2] = '>';

        board[4][0] = '+';
        board[4][1] = '-';
        board[4][2] = '>';
        board[4][C - 3] = '-';
        board[4][C - 2] = '>';
        board[4][C - 1] = '+';

        for (let r = 3; r < R; r++) {
            for (let c = 3; c < C - 3; c++) {
                board[r][c] = frag.data[r - 3][c - 3];
            }
        }
    }

    storage.push({ row: R, col: C, data: board });
    return `<${id++}>`;
}

const task2 = regex => {
    let frags = regex.match(/(?<=<)\d+(?=>)/g).map(x => storage[parseInt(x)]);
    let [R, C] = [0, 0];
    const L = frags.length;
    let cIndex = 0;

    for (let i = 0; i < L; i++) {
        R = Math.max(R, frags[i].row);
        C += frags[i].col;
    }

    C += 2 * (L - 1);

    let board = Array.from(Array(R), () => new Array(C).fill(' '));

    for (let i = 0; i < L; i++) {
        const [fragR, fragC] = [frags[i].row, frags[i].col];
        for (let r = 0; r < fragR; r++) {
            for (let c = 0; c < fragC; c++) {
                board[r][c + cIndex] = frags[i].data[r][c];
            }
        }

        cIndex += frags[i].col;
        if (i < L - 1) {
            board[1][cIndex] = '-';
            board[1][cIndex + 1] = '>';
            cIndex += 2;
        }

    }

    storage.push({ row: R, col: C, data: board });
    return `<${id++}>`;
}

const task3 = regex => {
    let frags = regex.split('|').map(x => storage[parseInt(x.slice(1, x.length - 1))]);
    let [R, C] = [0, 0];
    let line = [];
    const L = frags.length;
    let rIndex = 1;

    for (let i = 0; i < L; i++) {
        R += frags[i].row;
        C = Math.max(C, frags[i].col);
        line.push(rIndex);
        rIndex += frags[i].row + 1;
    }

    R += L - 1;
    C += 6;

    let board = Array.from(Array(R), () => new Array(C).fill(' '));

    for (let r = 1; r <= line[L - 1]; r++) {
        board[r][0] = '|';
        board[r][C - 1] = '|';
    }

    line.forEach((curR, i) => {
        for (let c = 0; c < C; c++) {
            board[curR][c] = '-';
        }

        board[curR][0] = '+';
        board[curR][2] = '>';
        board[curR][C - 2] = '>';
        board[curR][C - 1] = '+';

        const [fragR, fragC] = [frags[i].row, frags[i].col];
        for (let r = 0; r < fragR; r++) {
            for (let c = 0; c < fragC; c++) {
                board[r + curR - 1][c + 3] = frags[i].data[r][c];
            }
        }
    });

    storage.push({ row: R, col: C, data: board });
    return `<${id++}>`;
}

const solve = regex => {
    while (!/^<\d+>$/.test(regex)) {
        // A? -> <>?
        regex = regex.replace(/[A-Z](?=[*+?])/g, x => {
            return task0(x);
        });

        // ABC
        regex = regex.replace(/[A-Z]+/g, x => {
            return task0(x);
        });

        // <>?
        regex = regex.replace(/<\d+>[*+?]/g, x => {
            const L = x.length;
            const core = x.slice(1, L - 2);
            const type = x[L - 1];

            return task1(core, type);
        });

        // (<>) -> <>
        regex = regex.replace(/\(<\d+>\)/g, x => {
            return x.slice(1, x.length - 1);
        });

        // (ABC|DEF)
        regex = regex.replace(/(?<=\()<\d+>(\|<\d+>)+(?=\))/g, x => {
            return task3(x);
        });

        // ^ABC|DEF$
        regex = regex.replace(/^<\d+>(\|<\d+>)+$/g, x => {
            return task3(x);
        });

        // <> + <> (*, +, ? X)
        if (!/<\d+>[*+?]/.test(regex)) {
            regex = regex.replace(/(<\d+>){2,}/g, x => {
                return task2(x);
            });
        }

    }

    const answer = storage[storage.length - 1];
    let printer = `${answer.row} ${answer.col + 6}\n`;

    for (let r = 0; r < answer.row; r++) {
        if (r === 1)
            printer += `S->${answer.data[r].join('')}->F\n`;
        else
            printer += `   ${answer.data[r].join('')}   \n`;
    }

    console.log(printer);
}

const regex = require('fs').readFileSync(0, 'utf-8').toString().trim();
let storage = [];
let id = 0;
solve(regex);