const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let result = '';

for (let i = 0; i < input.length - 1; i++) {
  let height = [...input[i].split(' ').map((x) => parseInt(x)), -1];
  height[0] = -2;
  let stack = [0];
  let max_ = 0;

  for (let j = 1; j < height.length; j++) {
    if (height[j] <= height[stack[stack.length - 1]]) {
      while (height[j] <= height[stack[stack.length - 1]]) {
        let popped = stack.pop();
        let current = (j - 1 - stack[stack.length - 1]) * height[popped];
        if (current > max_) max_ = current;
      }
    }
    stack.push(j);
  }

  result += max_ + '\n';
}

console.log(result);