let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('');
let isWolf = 0;
let w = 0;
if (input.length === 0) isWolf = 0;
checkWolf(input);

function checkWolf(wolfWord) {
    while (wolfWord.length !== 0) {
        if (wolfWord[0] === 'w') {
            wolfWord.shift();
            w++;
        }
        else {
            if (w === 0) return;
            else {
                for (let i = 0; i < w; i++) {
                    if (wolfWord.shift() !== 'o') return;
                }
                for (let i = 0; i < w; i++) {
                    if (wolfWord.shift() !== 'l') return;
                }
                for (let i = 0; i < w; i++) {
                    if (wolfWord.shift() !== 'f') return;
                }
                w = 0;
                if (wolfWord.length === 0) {
                    isWolf = 1;
                    return;
                }
            }
        }
    }
}

console.log(isWolf);