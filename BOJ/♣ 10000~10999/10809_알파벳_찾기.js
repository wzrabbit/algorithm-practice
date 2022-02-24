const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
let alphabet = "abcdefghijklmnopqrstuvwxyz";
let result = new Array(26);

for (let i = 0; i < 26; i++) {
    result[i] = input.indexOf(alphabet[i]);
}

console.log(result.join(" "));