const arr = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')[1]
  .split(' ')
  .map(Number);

arr.sort((a, b) => b - a);

let cowJoinCount = 0;

for (let i = 0; i < arr.length; i++) {
  if (arr[i] >= cowJoinCount) {
    cowJoinCount += 1;
  }
}

console.log(cowJoinCount);
