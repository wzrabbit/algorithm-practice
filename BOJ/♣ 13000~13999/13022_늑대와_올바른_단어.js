const wolves = require('fs')
  .readFileSync(0, 'utf-8')
  .trim();

let index = 0;
let isValid = true;
let [w, o, l, f] = [0, 0, 0, 0];

while (index < wolves.length) {
  while (wolves[index] === 'w' && index < wolves.length) {
    w += 1;
    index += 1;
  }

  while (wolves[index] === 'o' && index < wolves.length) {
    o += 1;
    index += 1;
  }

  while (wolves[index] === 'l' && index < wolves.length) {
    l += 1;
    index += 1;
  }

  while (wolves[index] === 'f' && index < wolves.length) {
    f += 1;
    index += 1;
  }

  if (w !== o || w !== l || w !== f) {
    isValid = false;
    break;
  }
}

console.log(isValid ? 1 : 0);