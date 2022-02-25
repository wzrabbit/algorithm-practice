const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const repeat = parseInt(input[0].split(" ")[0]);
const limit = parseInt(input[0].split(" ")[1]);
const numbers = input[1].split(" ").map(Number);
let max = 0;

for (let i = 0; i < numbers.length - 2; i++) {
    for (let j = i + 1; j < numbers.length - 1; j++) {
        for (let k = j + 1; k < numbers.length; k++) {
            if (i !== j && i !== k && j != k && numbers[i] + numbers[j] + numbers[k] > max && numbers[i] + numbers[j] + numbers[k] <= limit) {
                max = numbers[i] + numbers[j] + numbers[k];
            }
        }
    }
}

console.log(max);