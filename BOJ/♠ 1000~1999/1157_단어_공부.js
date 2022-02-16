const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
let alphabets = new Array(26).fill(0);
input = input.toLowerCase();
let max = [0, 0]; // 알파벳 번호, 개수

for (let i = 0; i < input.length; i++) {
    alphabets[input[i].charCodeAt() - 97] += 1;
}

for (let i = 0; i < 26; i++) {
    if (alphabets[i] > max[1]) max = [i, alphabets[i]];
}

let regex = new RegExp(max[1], "g");
if (alphabets.join(",").match(regex).length >= 2) {
    console.log("?");
}
else {
    console.log (String.fromCharCode(max[0] + 65));
}