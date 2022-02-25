const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')[1].split(' ').map(Number);
let max = -9999;
let sum = 0;

for (let i = 0; i < input.length; i++) {
    // 새로운 값을 더한다 (양수든 음수든)
    sum += input[i];

    // 만약 합이 최댓값보다 클 경우 갱신
    if (sum > max) max = sum;

    // 합이 0 밑으로 떨어지면 차라리 처음부터 다시 하는 게 나으므로 손절
    if (sum < 0) sum = 0;
}

console.log(max);