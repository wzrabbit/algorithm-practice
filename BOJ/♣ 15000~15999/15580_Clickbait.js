function getNo(r, c) {
    let result = '';

    while (!isNaN(grid[r][c])) {
        result += grid[r][c];
        c++;
    }

    return parseInt(result);
}

function convertToPiped(r, c) {
    while (true) {
        if (grid[r][c] === '|') {
            grid[r][c] = 'X';

            if (grid[r + 1][c] === '-')
                return [r + 1, c];
            r++;
        }
        else if (grid[r][c] === '-') {
            grid[r][c] = 'X';

            if (grid[r][c - 1] === '-' || grid[r][c - 1] === '+')
                c--;
            else
                c++;
        }
        else {
            grid[r][c] = 'X';

            if (c > 0 && grid[r][c - 1] === '-' || grid[r][c - 1] === '+')
                c--;
            else if (c < col && grid[r][c + 1] === '-' || grid[r][c + 1] === '+')
                c++;
            else
                r++;
        }
    }
}

function getInfo(rawR, rawC) {
    if (isNaN(grid[rawR][rawC]))
        [rawR, rawC] = convertToPiped(rawR, rawC);
    let ro = co = 1;

    while (grid[rawR][rawC] !== '-')
        rawR--;

    while (grid[rawR][rawC] !== '+')
        rawC--;

    while (grid[rawR + ro][rawC] !== '+')
        ro++;

    while (grid[rawR][rawC + co] !== '+')
        co++;

    let knowNo = false;
    let no;
    for (let r = rawR + 1; r < rawR + ro; r++) {
        for (let c = rawC + 1; c < rawC + co; c++) {
            if (!isNaN(grid[r][c])) {
                no = getNo(r, c);
                knowNo = true;
                break;
            }

            if (knowNo)
                break;
        }
    }

    return {
        no: no,
        coreR: rawR + ro - 1,
        leftC: rawC,
        rightC: rawC + co
    };
}

function traverse(no, coreR, leftC, rightC) {
    while (true) {
        if (grid[coreR][leftC] === '+')
            break;

        if (leftC !== 0 && (['-', '+'].includes(grid[coreR][leftC - 1]))) {
            const info = getInfo(coreR, leftC - 1);
            traverse(info.no, info.coreR, info.leftC, info.rightC);
        }
        else if (rightC !== col - 1 && (['-', '+'].includes(grid[coreR][rightC + 1]))) {
            const info = getInfo(coreR, rightC + 1);
            traverse(info.no, info.coreR, info.leftC, info.rightC);
        }

        coreR--;
    }

    printer += no + '\n';
}

function findFirst() {
    for (let r = 0; r < row; r++) {
        for (let c = 0; c < col; c++) {
            if (!isNaN(grid[r][c]) && getNo(r, c) === 1)
                return [r, c];
        }
    }
}

const rl = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});
let input = '';
let rowcol, grid, row, col, printer;

rl.on('line', (line) => {
    input += line + '\n';
}).on('close', () => {
    [rowcol, ...grid] = input.trim().split('\n');
    [row, col] = rowcol.split(' ').map((x) => parseInt(x));
    grid = grid.map((x) => x.split(''));
    printer = '';

    const [startR, startC] = findFirst();
    const startInfo = getInfo(startR, startC);
    traverse(1, startInfo.coreR, startInfo.leftC, startInfo.rightC);

    console.log(printer);
});