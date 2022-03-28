const nums = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')[1].split(' ');

nums.sort((a, b) => {
    return parseInt(a + b) > parseInt(b + a) ? -1 : 1;
});

if (nums[0] === '0') console.log(0);
else console.log(nums.join(''));