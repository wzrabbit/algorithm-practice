let [len, board, pattern] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
len = parseInt(len);
board = (board + ' ' + board).split(' ');
pattern = pattern.split(' ');
let top = 0;
let bottom = len;

let table = new Array(len).fill(0);
for (let l = 0, r = 1; r < len; r++) {
    while (l > 0 && pattern[l] !== pattern[r]) l = table[l - 1];
    if (pattern[l] === pattern[r]) {
        table[r] = ++l;
    }
}

for (let p = 0, i = 0; p < len * 2 - 1; p++) {
    while (i > 0 && pattern[i] !== board[p]) i = table[i - 1];
    if (pattern[i] === board[p]) {
        if (i === len - 1) {
            i = table[i];
            top++;
        }
        else i++;
    }
}

let [a, b] = [top, bottom];
let temp, div;
while (true) {
    temp = b;
    b = a % b;
    a = temp;
    if (b === 0) {
        div = a;
        break;
    }
}

console.log(top / div + '/' + bottom / div);