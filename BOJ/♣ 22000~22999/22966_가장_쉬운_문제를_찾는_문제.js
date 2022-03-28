const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let data;
let foundResult = false;

for (let i = 1; i <= 4; i++) {
    for (let j = 0; j < input.length; j++) {
        data = input[j].split(" ");
        if (data[1] == i) {
            console.log(data[0]);
            foundResult = true;
            break;
        }
    }
    if (foundResult === true) break;
}
