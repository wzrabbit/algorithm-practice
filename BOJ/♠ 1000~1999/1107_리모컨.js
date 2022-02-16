const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const channel = parseInt(input[0]);
let brokenButtons;
if (input.length === 2) {
  brokenButtons = [];
}
else {
  brokenButtons = input[2].split(' ');
}

// 1. 일일이 노가다 하는 방법
let nogada = Math.abs(channel - 100);

// 2. 이전 채널에서의 접근
let previous = 0;
for (let i = channel; i >= 0; i--) {
  if (previous >= nogada) break;
  let fail = false;
  let chString = i.toString();

  for (let j = 0; j < chString.length; j++) {
    if (brokenButtons.includes(chString[j])) {
      fail = true;
      previous++;
      if (i === 0) previous = 999999999999;
      break;
    }
  }
  if (fail === true) continue;

  previous += chString.length;
  break;
}

// 3. 다음 채널에서의 접근
let next = 0;
for (let i = channel; true; i++) {
  if (next >= nogada || next >= previous) break;
  let fail = false;
  let chString = i.toString();

  for (let j = 0; j < chString.length; j++) {
    if (brokenButtons.includes(chString[j])) {
      fail = true;
      next++;
      break;
    }
  }
  if (fail === true) continue;

  next += chString.length;
  break;
}

let result = [nogada, previous, next].sort((a, b) => a - b);
console.log(result[0]);
