const height = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((x) => BigInt(x));
height[0] = -2;
height.push(-1);
let stack = [0];
let max_ = 0;

for (let i = 1; i < height.length; i++) {
  if (height[i] <= height[stack[stack.length - 1]]) {
    while (height[i] <= height[stack[stack.length - 1]]) {
      let popped = stack.pop();
      let current = BigInt(i - 1 - stack[stack.length - 1]) * height[popped];
      if (current > max_) max_ = current;
    }
  }
  stack.push(i);
}

console.log(max_.toString());