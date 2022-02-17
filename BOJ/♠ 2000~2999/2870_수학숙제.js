const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let numbers = [];
let result = "";

for (let i = 0; i < input.length; i++) {
    numbers.push(...(input[i].match(/\d+/g)||[]));
}

for (let i = 0; i < numbers.length; i++) {
    numbers[i] = (numbers[i].slice(0, -1)).replace(/^0+/, "") + numbers[i].slice(numbers[i].length - 1, numbers[i].length);

}

numbers.sort((a, b) => a - b);

for (let i = 0; i < numbers.length; i++) {
    console.log(numbers[i]);
}