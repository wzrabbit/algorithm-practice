const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const board = input[0].replace(/\d+/g, '');
const word = input[1];
let success = false;

// KMP Table
let table = new Array(word.length);
table[0] = 0;
let l = 0;
let r = 1;
for (let i = 1; i < word.length; i++) {
    if (word[l] === word[r]) {
        table[i] = table[i - 1] + 1;
    }
    else {
        while (true) {
            if (l === 0) {
                table[i] = 0;
                break;
            }
            else {
                l = table[l - 1];
                if (word[l] === word[r]) {
                    table[i] = l + 1;
                    break;
                }
            }
        }
    }
    l++; r++;
}

// KMP Search
let index = 0;
for (let i = 0; i < board.length; i++) {
    while (index > 0 && board[i] !== word[index]) {
        index = table[index - 1];
    }
    if (board[i] === word[index]) {
        if (index === word.length - 1) {
            success = true;
            break;
        }
        else index++;
    }
}

if (success === true) console.log(1);
else console.log(0);