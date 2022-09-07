function solve() {
    for (let i = 1; i <= 30000; i++) {
        const num = i.toString();
        for (let j = 0; j < num.length; j++) {
            if (num[j] === frag[idx]) {
                idx++;
                if (idx === frag.length)
                    return i;
            }
        }
    }
}

const frag = require('fs').readFileSync(0, 'utf-8').toString().trim();
let idx = 0;
console.log(solve());