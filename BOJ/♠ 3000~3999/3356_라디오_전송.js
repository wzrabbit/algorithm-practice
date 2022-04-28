const msg = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')[1];
let fail = new Array(msg.length).fill(0);

for (let l = 0, r = 1; r < msg.length; r++) {
    while (l > 0 && msg[l] !== msg[r])
        l = fail[l - 1];
    if (msg[l] === msg[r]) {
        fail[r] = l + 1;
        l++;
    }
}

console.log(msg.length - fail[msg.length - 1]);