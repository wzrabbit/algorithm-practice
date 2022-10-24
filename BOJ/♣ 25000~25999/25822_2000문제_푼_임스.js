let [coin, N, arr] = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
N = parseInt(N);
arr = arr.split(' ').map(x => parseInt(x));

let l = r = 0;
const maxAbsent = Math.min(Math.floor(parseInt(coin.replace('.', '')) / 99), 2);
let maxStreak = streak = absent = 0;

while (r < N) {
    if (arr[r] === 0 && absent === maxAbsent) {
        streak--;
        if (arr[l] === 0) absent--;
        l++;
    } else {
        streak++;
        if (arr[r] === 0) absent++;
        r++;
        maxStreak = Math.max(maxStreak, streak);
    }
}
console.log(maxStreak);

const maxSolve = arr.reduce((x, y) => Math.max(x, y));
console.log(maxSolve);