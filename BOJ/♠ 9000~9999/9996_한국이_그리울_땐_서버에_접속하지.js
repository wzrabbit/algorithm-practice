const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
const regexText = "^" + input[0].replace(/\*/g, ".*") + "$";
const regex = new RegExp(regexText);

for (let i = 1; i < input.length; i++) {
    if (input[i].match(regex)) console.log("DA");
    else console.log("NE");
}