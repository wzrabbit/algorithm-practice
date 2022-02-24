const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const targetLength = parseInt(input[0]);
const targetList = input[1].split(" ").map(Number).sort((a, b) => a - b);
const searchLength = parseInt(input[2]);
const searchList = input[3].split(" ").map(Number);
const targetMap = new Map();
let result = "";

// 값을 찾았을 경우 개수를 알 수 있도록 미리 맵을 만들어 개수를 저장해 두자
for (let i = 0; i < targetLength; i++) {
  let currentValue = targetList[i];
  if (targetMap.has(currentValue)) targetMap.set(currentValue, targetMap.get(currentValue) + 1);
  else targetMap.set(currentValue, 1);
}

for (let i = 0; i < searchLength; i++) {
  let left = 0;
  let right = targetLength - 1;
  let mid;
  let searchSuccess = false;

  while (left <= right && searchSuccess === false) {
    mid = Math.floor((left + right) / 2);
    if (searchList[i] > targetList[mid]) {
      left = mid + 1;
    }
    else if (searchList[i] < targetList[mid]) {
      right = mid - 1;
    }
    else {
      searchSuccess = true;
      result += targetMap.get(searchList[i]) + " ";
    }
  }

  if (searchSuccess === false) {
    result += 0 + " ";
  }
}

result = result.slice(0, -1);
console.log(result);