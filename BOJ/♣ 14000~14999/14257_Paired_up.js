let [N, ...cow] = require('fs').readFileSync(0, 'utf-8')
    .toString().trim().split('\n').map(x => x.split(' ').map(y => parseInt(y)));
N = parseInt(N);
cow.sort((a, b) => a[1] - b[1]);

let answer = 0;
let l = 0;
let r = N - 1;

while (l <= r) {
    if (cow[l][0] === 0) l++;
    else if (cow[r][0] === 0) r--;
    else if (l === r) {
        answer = Math.max(answer, cow[l][1] * 2);
        break;
    }
    else {
        const smaller = Math.min(cow[l][0], cow[r][0]);
        cow[l][0] -= smaller;
        cow[r][0] -= smaller;
        answer = Math.max(answer, cow[l][1] + cow[r][1]);
    }
}

console.log(answer);