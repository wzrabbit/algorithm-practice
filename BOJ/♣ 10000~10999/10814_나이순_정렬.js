const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let data = [];
let result = "";

for (let i = 1; i <= 200; i++) {
    for (let j = 0; j < input.length; j++) {
        data = input[j].split(" ");
        if (data[0] == i) result += input[j] + "\n";
    }
}

result.substr(result, result.length - 1);
console.log(result);