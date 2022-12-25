let [a, b] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').
    map((x) => x.split(' ').map((y) => parseInt(y)));

let winning = false;
let aTotal = 0;
let bTotal = 0;

for (let i = 0; i < 9; i++) {
    aTotal += a[i];

    if (aTotal > bTotal)
        winning = true;

    bTotal += b[i];

    if (aTotal > bTotal)
        winning = true;
}

if (winning && aTotal < bTotal)
    console.log('Yes');
else
    console.log('No');