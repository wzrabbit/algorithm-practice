const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n").map(Number);
input.shift();
result = "";

// 1. 산술 평균
let sum = 0;
for (let i = 0; i < input.length; i++) {
  sum += input[i];
}
result += Math.round(sum / input.length) + "\n";

// 2. 중앙값
input.sort((a, b) => a - b);
result += input[Math.floor(input.length / 2)] + "\n";

// 3. 최빈값
let inputMap = new Map();
for (let i = 0; i < input.length; i++) {
  if (inputMap.has(input[i])) inputMap.set(input[i], inputMap.get(input[i]) + 1);
  else inputMap.set(input[i], 1);
}
let maxValue = [...inputMap.values()].sort((a, b) => a - b);
maxValue = maxValue[maxValue.length - 1];
let valueList = [];

let keys = [...inputMap.keys()];
for (let i = 0; i < keys.length; i++) {
  if (inputMap.get(keys[i]) === maxValue) valueList.push(keys[i]);
}

if (valueList.length === 1) result += valueList[0] + "\n";
else result += valueList[1] + "\n";

// 4. 범위
result += input[input.length - 1] - input[0] + "\n";

result = result.slice(0, -1);
console.log(result);