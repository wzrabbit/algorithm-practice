const N = parseInt(require('fs').readFileSync('/dev/stdin'));
let cnt = 0;

for (let i = 1; i <= N; i++)
    cnt += (i.toString().match(/[369]/g) || []).length;

console.log(cnt);