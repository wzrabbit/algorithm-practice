let [binA, binB] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
binA += binA.slice(0, -1);
let fail = new Array(binA.length).fill(0);
let count = 0;

function makeKMPFail() {
    for (let l = 0, r = 1; r < binB.length; r++) {
        while (l > 0 && binB[l] !== binB[r])
            l = fail[l - 1];
        if (binB[l] === binB[r]) {
            fail[r] = l + 1;
            l++;
        }
    }
}

function doKMP() {
    let pos = 0;
    for (let i = 0; i < binA.length; i++) {
        while (pos > 0 && binA[i] !== binB[pos])
            pos = fail[pos - 1];

        if (binB[pos] === binA[i]) {
            if (pos === binB.length - 1) {
                pos = fail[pos];
                count++;
            }
            else
                pos++;
        }
    }
}

makeKMPFail();
doKMP();
console.log(count);