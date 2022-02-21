let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let a = b = c = 0;
let pizza = 0;

for (let i = 1; i < input.length; i++) {
  if (input[i] === '1/4') a++;
  else if (input[i] === '1/2') b++;
  else if (input[i] === '3/4') c++;
}

let d = Math.min(a, c);
pizza += d;
a -= d;
c -= d;

if (a >= 2 && b >= 1) {
  d = Math.min(Math.floor(a / 2), b);
  pizza += d;
  a -= d * 2;
  b -= d;
}

d = Math.floor(b / 2);
pizza += d;
b -= d * 2;

d = Math.floor(a / 4);
pizza += d;
a -= d * 4;

if (a >= 1 && b >= 1) {
  a -= 1;
  b -= 1;
  pizza++;
}
if (a !== 0) pizza++;
if (b !== 0) pizza++;
pizza += c;
console.log(pizza);