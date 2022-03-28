const height = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')[1].split(' ').map(Number);
let leftMax = { index: 0, height: height[0] };
let rightMax = { index: 1, height: height[1] };
let total = 0;
let calc;

updateMax(1);

for (let i = 1; i < height.length - 1; i++) {
    calc = Math.min(leftMax.height, rightMax.height) - height[i];
    total += calc >= 0 ? calc : 0;
    if (height[i] > leftMax.height) leftMax = { index: i, height: height[i] };
    if (i === rightMax.index) updateMax(i);
}

console.log(total);

function updateMax(index) {
    rightMax = { index: index, height: 0 };
    // Right 값 업데이트 (값 초기화 후, 오른쪽에 있는 값 중 최대값을 고른다)
    for (index += 1; index < height.length; index++) {
        if (height[index] > rightMax.height) rightMax = { index: index, height: height[index] };
    }
}