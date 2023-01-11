const stones = require('fs')
  .readFileSync(0, 'utf-8')
  .trim();

let whiteCount = 0;
let blackCount = 0;

for (let index = 0; index < stones.length; index++) {
  if (stones[index] === 'W') {
    whiteCount += 1;
  } else {
    blackCount += 1;
  }
}

console.log(whiteCount === blackCount ? 1 : 0);