const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

let [kingR, kingC] = input[0].split(' ')[0].split('');
let [stoneR, stoneC] = input[0].split(' ')[1].split('');
kingR = kingR.charCodeAt() - 64;
stoneR = stoneR.charCodeAt() - 64;
kingC = parseInt(kingC);
stoneC = parseInt(stoneC);

for (let i = 1; i < input.length; i++) {
    switch (input[i]) {
        case 'R': moveKing(1, 0); break;
        case 'L': moveKing(-1, 0); break;
        case 'B': moveKing(0, -1); break;
        case 'T': moveKing(0, 1); break;
        case 'RT': moveKing(1, 1); break;
        case 'LT': moveKing(-1, 1); break;
        case 'RB': moveKing(1, -1); break;
        case 'LB': moveKing(-1, -1); break;
    }
}

kingR = String.fromCharCode(kingR + 64);
stoneR = String.fromCharCode(stoneR + 64);

console.log(kingR + kingC + '\n' + stoneR + stoneC);

function moveKing(row, col) {
    if (kingR + row >= 1 && kingR + row <= 8 && kingC + col >= 1 && kingC + col <= 8) {
        if (kingR + row === stoneR && kingC + col === stoneC) {
            if (stoneR + row >= 1 && stoneR + row <= 8 && stoneC + col >= 1 && stoneC + col <= 8) {
                [kingR, kingC, stoneR, stoneC] = [kingR + row, kingC + col, stoneR + row, stoneC + col];
            }
        }
        else {
            [kingR, kingC] = [kingR + row, kingC + col];
        }
    }
}