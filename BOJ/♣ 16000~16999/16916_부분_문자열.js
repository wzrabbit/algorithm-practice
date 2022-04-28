const [s, p] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let fail = new Array(p.length).fill(0);

function makeKMPFail() {
    for (let l = 0, r = 1; r < p.length; r++) {
        while (l > 0 && p[l] !== p[r])
            l = fail[l - 1];
        if (p[l] === p[r]) {
            fail[r] = l + 1;
            l++;
        }
    }
}

function doKMP() {
    let pos = 0;
    for (let i = 0; i < s.length; i++) {
        while (pos > 0 && s[i] !== p[pos])
            pos = fail[pos - 1];

        if (p[pos] === s[i]) {
            if (pos === p.length - 1)
                return true;
            else
                pos++;
        }
    }
}

makeKMPFail();
if (doKMP())
    console.log(1);
else
    console.log(0);