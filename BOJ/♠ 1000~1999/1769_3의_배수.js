let input = require('fs').readFileSync('/dev/stdin').toString().trim();
let count = 0;

while (input.length > 1) {
    input = input.split('').map((x) => parseInt(x));
    input = input.reduce((a, b) => a + b, 0);
    input = input.toString();
    count++;
}

console.log(count);
if (parseInt(input) % 3 === 0) console.log("YES")
else console.log("NO");