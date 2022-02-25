let [num, arr] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
num = parseInt(num);
arr = arr.split(' ').map((x) => parseInt(x));
let sum = arr.slice();
let biggest = arr[0];
let result = '';

for (let i = 1; i < num; i++) {
    for (let j = 0; j < i; j++) {
        if (arr[j] < arr[i] && sum[j] + arr[i] > sum[i]) sum[i] = sum[j] + arr[i];
        if (sum[i] > biggest) biggest = sum[i];
    }
}

console.log(biggest);