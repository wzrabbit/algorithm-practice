const kkrkk = require('fs').readFileSync('/dev/stdin').toString().trim();
const len = kkrkk.length;
let l = 0, r = len - 1;
let rCount = 0, kCount = 0;

for (let i = 0; i < len; i++)
    if (kkrkk[i] === 'R')
        rCount++;
let answer = rCount;

while (true) {
    let success = 0;

    while (l <= r) {
        if (kkrkk[l] === 'R') {
            rCount--;
            l++;
        }
        else {
            kCount++;
            success++;
            l++;
            break;
        }
    }

    while (l <= r) {
        if (kkrkk[r] === 'R') {
            rCount--;
            r--;
        }
        else {
            kCount++;
            success++;
            r--;
            break;
        }
    }

    if (success === 2 && rCount > 0) {
        const calc = kCount + rCount;
        answer = Math.max(answer, calc);
    }
    else
        break;
}

console.log(answer);