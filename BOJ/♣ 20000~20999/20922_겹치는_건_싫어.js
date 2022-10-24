let [NK, arr] = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
const [N, K] = NK.split(' ').map(x => parseInt(x));
arr = arr.split(' ').map(x => parseInt(x));
let count = new Array(100001).fill(0);
let maxLength = 0;
let l = 0;
let r = 0;

while (r < N) {
    if (count[arr[r]] < K) {
        count[arr[r]]++;
        r++;
        maxLength = Math.max(maxLength, r - l);
    }
    else {
        count[arr[l]]--;
        l++;
    }
}

console.log(maxLength);