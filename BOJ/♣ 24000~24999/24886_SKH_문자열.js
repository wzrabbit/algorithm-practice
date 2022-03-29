const [data, text] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let [_, sCount, kCount, hCount] = data.split(' ').map((x) => parseInt(x));

const skh = (text.match(/SKH/g) || []).length;
let count = 0;
let comb;

const sk = (text.match(/SK(?=([^H]|$))/g) || []).length;
const sh = (text.match(/SH/g) || []).length;
const kh = (text.match(/(?<=([^S]|^))KH/g) || []).length;
const s = (text.match(/S(?=(S|$))/g) || []).length;
const k = (text.match(/(?<=([^S]|^))K(?=([^H]|$))/g) || []).length;
const h = (text.match(/(?<=(H|^))H/g) || []).length;

// 1. SKH
count += skh;


// 2. SK, SH, KH
comb = Math.min(sk, hCount);
count += comb;
hCount -= comb;

comb = Math.min(sh, kCount);
count += comb;
kCount -= comb;

comb = Math.min(kh, sCount);
count += comb;
sCount -= comb;

// 3. S, K, H, _
let best = 0;

for (let i = 0; i <= Math.min(s, kCount, hCount); i++) {
    let current = 0;
    let [sc, kc, hc] = [sCount, kCount, hCount];

    kc -= i;
    hc -= i;
    current += i;

    comb = Math.min(h, sc, kc);
    sc -= comb;
    kc -= comb;
    current += comb;

    comb = Math.min(k, sc, hc);
    sc -= comb;
    hc -= comb;
    current += comb;

    current += Math.min(sc, kc, hc);

    if (current > best)
        best = current;
}

for (let i = 0; i <= Math.min(k, sCount, hCount); i++) {
    let current = 0;
    let [sc, kc, hc] = [sCount, kCount, hCount];

    sc -= i;
    hc -= i;
    current += i;

    comb = Math.min(h, sc, kc);
    sc -= comb;
    kc -= comb;
    current += comb;

    comb = Math.min(s, kc, hc);
    kc -= comb;
    hc -= comb;
    current += comb;

    current += Math.min(sc, kc, hc);

    if (current > best)
        best = current;
}

for (let i = 0; i <= Math.min(h, sCount, kCount); i++) {
    let current = 0;
    let [sc, kc, hc] = [sCount, kCount, hCount];

    sc -= i;
    kc -= i;
    current += i;

    comb = Math.min(s, kc, hc);
    kc -= comb;
    hc -= comb;
    current += comb;

    comb = Math.min(k, sc, hc);
    sc -= comb;
    hc -= comb;
    current += comb;

    current += Math.min(sc, kc, hc);

    if (current > best)
        best = current;
}

count += best;

console.log(count);