const input = (require('fs').readFileSync(0, 'utf-8').trim() + 'A').split('').map((letter) => letter.charCodeAt());
const A_CHARCODE = 65;
const Z_CHARCODE = 90;

let previousCode = 65;
let aCount = 0;
let zCount = 0;
let total = 0;

input.forEach((code) => {
  if (code !== previousCode && code !== previousCode + 1) {
    total += aCount * zCount;
    aCount = 0;
    zCount = 0;
    previousCode = 65;
  }
  
  previousCode = code;
  if (code === A_CHARCODE) aCount += 1;
  if (code === Z_CHARCODE) zCount += 1;
});

console.log(total);
