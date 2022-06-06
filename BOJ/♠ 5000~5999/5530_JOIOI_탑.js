const joiSample = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')[1];
let joi = new Array(joiSample.length);
let answer = 0;

function isPossible(num) {
    for (let i = 0; i < joiSample.length; i++)
        joi[i] = joiSample[i];
    left = num;

    for (let i = joi.length - 1; i >= 0; i--) {
        if (left === 0)
            break;

        if (joi[i] === 'I') {
            joi[i] = 'E';
            left--;
        }
    }

    let a = [];
    let b = [];
    let c = [];

    for (let i = 0; i < joi.length; i++) {
        if (joi[i] === 'E')
            c.push(i);
        else if (joi[i] === 'O')
            b.push(i);
        else
            a.push(i);
    }

    while (true) {
        if (c.length === 0)
            return true;

        if (a.length === 0 || b.length === 0)
            return false;

        if (b[b.length - 1] > c[c.length - 1]) {
            b.pop();
            continue;
        }

        if (a[a.length - 1] > b[b.length - 1]) {
            a.pop();
            continue;
        }

        c.pop();
        b.pop();
        a.pop();
    }
}

let start = 0;
let end = 0;
for (let i = 0; i < joiSample.length; i++) {
    if (joiSample[i] === 'I')
        end++;
}

let mid;
while (start <= end) {
    mid = Math.floor((start + end) / 2);

    if (isPossible(mid))
        start = mid + 1;
    else
        end = mid - 1;
}

console.log(end);