const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const cases = parseInt(input[0]);
let sour = [];
let bitter = [];
for (let i = 1; i <= cases; i++) {
    const [s, b] = input[i].split(' ').map((x) => parseInt(x));
    sour.push(s);
    bitter.push(b);
}
let min = 10 ** 10;

for (let i = 1; i < 2 ** cases; i++) {
    let s = 1;
    let b = 0;
    let result = '';
    for (let j = cases - 1; j >= 0; j--) {
        if ((i & (1 << j)) > 0) {
            s *= sour[j];
            b += bitter[j];
            result += '1'
        }
        else result += '0'
    }
    if (Math.abs(s - b) < min) min = Math.abs(s - b);
}

console.log(min);