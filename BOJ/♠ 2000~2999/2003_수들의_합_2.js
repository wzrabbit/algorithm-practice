const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const target = Number(input[0].split(' ')[1]);
const nums = input[1].split(' ').map(Number);
let start = end = count = 0;
let sum = nums[0];

while (true) {
    if (sum > target) {
        sum -= nums[start];
        start++;
    }
    else if (sum === target) {
        count++;
        sum -= nums[start];
        start++;
    }
    else {
        end++;
        if (end === nums.length) break;
        sum += nums[end];
    }
}

console.log(count);