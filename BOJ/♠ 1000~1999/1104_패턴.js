let [s1, s2, need] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
need = parseInt(need);
let s1s1 = s1 + s1;
let s2s2 = s2 + s2;
let s1Left = s1.indexOf('1');

function solve() {
    // s1, s2 모두 0이라면?
    if (!/1/.test(s1) && !/1/.test(s2)) {
        console.log(0);
        return;
    }

    // s1만 모두 0이라면?
    if (!/1/.test(s1)) {
        if (s1.length * 1000000 + s2.indexOf('1') >= need)
            console.log(0);
        else if (s2.length - 1 - s2.lastIndexOf('1') + s1.length * 1000000 + s2.indexOf('1') >= need)
            console.log(s1.length * 1000000 + );
        else
            console.log(-1);
        return;
    }

    // s2만 모두 0이라면?

}