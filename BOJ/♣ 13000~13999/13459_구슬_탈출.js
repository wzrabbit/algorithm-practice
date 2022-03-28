const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [row, col] = input[0].split(' ').map((x) => parseInt(x));
let graph = new Array(row);
let success = false;
let startRed = startBlue = 'NONE';
for (let r = 0; r < row; r++) {
    graph[r] = input[r + 1].split('');
    for (let c = 0; c < col; c++) {
        if (startRed === 'NONE' && graph[r][c] === 'R') {
            graph[r][c] = '.';
            startRed = [r, c];
        }
        else if (startBlue === 'NONE' && graph[r][c] === 'B') {
            graph[r][c] = '.';
            startBlue = [r, c];
        }
    }
}

tilt(startRed[0], startRed[1], startBlue[0], startBlue[1], 'U', 1);
tilt(startRed[0], startRed[1], startBlue[0], startBlue[1], 'D', 1);
tilt(startRed[0], startRed[1], startBlue[0], startBlue[1], 'L', 1);
tilt(startRed[0], startRed[1], startBlue[0], startBlue[1], 'R', 1);

function tilt(rr, rc, br, bc, direction, count) {
    if (success) return;
    let [rr_, rc_, br_, bc_] = [rr, rc, br, bc];
    let r, c;
    switch (direction) {
        case 'U': [r, c] = [-1, 0]; break;
        case 'D': [r, c] = [1, 0]; break;
        case 'L': [r, c] = [0, -1]; break;
        case 'R': [r, c] = [0, 1]; break;
    }
    while (true) {
        if (graph[rr + r][rc + c] === '#') break;
        else if (graph[rr + r][rc + c] === 'O') {
            rr = 'HOLE';
            break;
        }
        else {
            rr += r;
            rc += c;
        }
    }
    while (true) {
        if (graph[br + r][bc + c] === '#') break;
        else if (graph[br + r][bc + c] === 'O') {
            br = 'HOLE';
            break;
        }
        else {
            br += r;
            bc += c;
        }
    }
    if (rr !== 'HOLE' && br !== 'HOLE' && rr === br && rc === bc) {
        switch (direction) {
            case 'U': rr_ > br_ ? rr++ : br++; break;
            case 'D': rr_ < br_ ? rr-- : br--; break;
            case 'L': rc_ > bc_ ? rc++ : bc++; break;
            case 'R': rc_ < bc_ ? rc-- : bc--; break;
        }
    }
    if (rr === 'HOLE') {
        if (br !== 'HOLE') {
            graph[br][bc] = 'B';
            success = true;
        }
        return;
    }
    else if (br === 'HOLE') return;
    else if (count < 10) {
        switch (direction) {
            case 'U': case 'D':
                tilt(rr, rc, br, bc, 'L', count + 1);
                tilt(rr, rc, br, bc, 'R', count + 1);
                break;
            case 'L': case 'R':
                tilt(rr, rc, br, bc, 'U', count + 1);
                tilt(rr, rc, br, bc, 'D', count + 1);
                break;
        }
    }
}

if (success) console.log(1);
else console.log(0);