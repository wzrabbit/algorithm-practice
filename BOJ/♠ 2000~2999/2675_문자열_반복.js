const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let repeat;
let text;
let data;
let result = "";

for (let i = 0; i < input.length; i++) {
    data = input[i].split(" ");
    repeat = parseInt(data[0]);
    text = data[1];
    for (let j = 0; j < text.length; j++) {
        for (let k = 0; k < repeat; k++) {
            result += text[j];
        }
    }
    console.log(result);
    result = "";
}