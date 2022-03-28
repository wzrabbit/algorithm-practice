let [num, arr] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
num = parseInt(num);
arr = arr.split(' ').map((x) => parseInt(x));
let len = new Array(num).fill(1);
let prev = new Array(num).fill(-1);
let longest = { index: 0, value: 1 };
let result = '';

for (let i = 1; i < num; i++) {
    for (let j = 0; j < i; j++) {
        if (arr[j] < arr[i] && len[j] + 1 > len[i]) {
            len[i] = len[j] + 1;
            prev[i] = j;
        }
        if (len[i] > longest.value) {
            longest.index = i;
            longest.value = len[i];
        }
    }
}

function track(current) {
    if (prev[current] !== -1) track(prev[current]);
    result += arr[current] + ' ';
}
result += longest.value + '\n';
track(longest.index);
console.log(result);