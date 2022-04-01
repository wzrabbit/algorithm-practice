let [elements, ...input] = require('fs').readFileSync("/dev/stdin").toString().trim().split("\n").map((x) => parseInt(x));
input.sort((a, b) => a - b);

const slicer = Math.round(elements * 0.15);
const start = slicer;
const end = elements - slicer - 1;
let result = 0;

for (let i = start; i <= end; i++) {
    result += input[i];
}

result /= (end - start + 1);
result = Math.round(result) || 0;
console.log(result);