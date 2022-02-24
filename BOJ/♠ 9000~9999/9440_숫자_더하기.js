const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
input.pop();
let result = '';
for (let i = 0; i < input.length; i++) {
  nums = input[i].split(' ').map((x) => parseInt(x));
  nums.shift();
  nums.sort((a, b) => a - b);
  let a = '';
  let b = '';
  let zero = 0;

  let repeat = nums.length;
  for (let j = 0; j < repeat; j++) {
    if (nums[0] === 0) {
      nums.shift();
      zero++;
    }
    else break;
  }

  let toggle = true;
  let index = 0;
  while (zero > 0 || index < nums.length) {
    if (toggle) {
      if (zero !== 0 && a.length !== 0) {
        a += '0';
        zero--;
      }
      else {
        a += nums[index];
        index++;
      }
    }
    else {
      if (zero !== 0 && b.length !== 0) {
        b += '0';
        zero--;
      }
      else {
        b += nums[index];
        index++;
      }
    }
    toggle = !toggle;
  }

  result += parseInt(a) + parseInt(b) + '\n';
}

console.log(result);