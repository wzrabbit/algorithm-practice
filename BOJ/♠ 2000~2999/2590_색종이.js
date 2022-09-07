let [a, b, c, d, e, f] = require('fs').readFileSync(0, 'utf-8')
    .toString().trim().split('\n').map((x) => parseInt(x));
let cnt = 0;

// 6
cnt += f;
f = 0;

// 5
cnt += e;
a = Math.max(0, a - e * 11);
e = 0;

// 4
while (d > 0) {
    cnt++;
    d--;
    let space = 20;

    space -= Math.min(b, 5) * 4;
    b -= Math.min(b, 5);
    a = Math.max(0, a - space);
}

// 3
cnt += Math.ceil(c / 4);
c %= 4;

if (c === 1) {
    let space = 27;
    space -= Math.min(b, 5) * 4;
    b -= Math.min(b, 5);
    a = Math.max(0, a - space);
}
else if (c === 2) {
    let space = 18;
    space -= Math.min(b, 3) * 4;
    b -= Math.min(b, 3);
    a = Math.max(0, a - space);
}
else if (c === 3) {
    let space = 9;
    space -= Math.min(b, 1) * 4;
    b -= Math.min(b, 1);
    a = Math.max(0, a - space);
}

// 2
cnt += Math.ceil(b / 9);
b %= 9;

if (b !== 0) {
    let space = 36 - (b * 4);
    b = 0;
    a = Math.max(0, a - space);
}

// 1
cnt += Math.ceil(a / 36);

console.log(cnt);