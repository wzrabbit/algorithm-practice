function getExactPos(id) {
    const cur = idPos[id];
    if (cur.position === 'absolute')
        return [cur.x, cur.y];

    const ref = cur.position.slice(9);
    const [x, y] = getExactPos(ref);
    return [x + cur.x, y + cur.y];
}

function resetData() {
    image = {};
    idPos = {};
    cssList = [];

    for (let r = 0; r <= boardLimit.y; r++) {
        for (let c = 0; c <= boardLimit.x; c++)
            board[r][c] = ' ';
    }

    boardLimit = { x: 0, y: 0 };
}

const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let l = 0;
let printer = '';
let image = {};
let idPos = {};
let cssList = [];
let board = Array.from(Array(1000), () => new Array(1000).fill(' '));
let boardLimit = { x: 0, y: 0 };

const T = parseInt(input[l++]);

for (let t = 1; t <= T; t++) {
    const N = parseInt(input[l++]);

    for (let i = 0; i < N; i++) {
        const [fileName, row, col] = input[l++].split(' ').map((x) => isNaN(x) ? x : parseInt(x));
        pic = [];

        for (let r = 0; r < row; r++)
            pic.push(input[l++]);

        image[fileName] = { row: row, col: col, pic: pic };
    }

    const C = parseInt(input[l++]);

    for (let i = 0; i < C; i++) {
        let css = '';

        for (let r = 0; r < 7; r++)
            css += input[l++];

        css = css.replace(/ |\t/g, '');
        const id = css.match(/(?<=#).+?(?={)/)[0];
        const x = parseInt(css.match(/(?<=pos-x:).+?(?=px)/)[0]);
        const y = parseInt(css.match(/(?<=pos-y:).+?(?=px)/)[0]);
        const position = css.match(/(?<=position:).+?(?=;)/)[0];
        const src = css.match(/(?<=file:).+?(?=;)/)[0];
        const layer = parseInt(css.match(/(?<=layer:).+?(?=;)/)[0]);

        idPos[id] = { x: x, y: y, position: position };
        cssList.push({
            id: id,
            x: x,
            y: y,
            position: position,
            src: src,
            layer: layer,
            index: i
        });
    }

    cssList.sort((a, b) => {
        if (a.layer < b.layer)
            return -1;
        else if (a.layer > b.layer)
            return 1;

        if (a.index < b.index)
            return -1;
        else
            return 1;
    });

    for (let i = 0; i < C; i++) {
        let width, height, src, pic;
        const [startX, startY] = getExactPos(cssList[i].id);

        src = cssList[i].src;
        pic = image[src].pic;
        width = image[src].col;
        height = image[src].row;

        for (let r = 0; r < height; r++) {
            for (let c = 0; c < width; c++) {
                boardLimit.y = Math.max(boardLimit.y, startY + r);
                boardLimit.x = Math.max(boardLimit.x, startX + c);

                if (pic[r][c] !== '.')
                    board[startY + r][startX + c] = pic[r][c];
            }
        }
    }

    printer += `Scenario #${t}:\n`;
    for (let r = 0; r <= boardLimit.y; r++) {
        for (let c = 0; c <= boardLimit.x; c++)
            printer += board[r][c];
        printer += '\n';
    }
    printer += '\n';

    resetData();
}

console.log(printer);
