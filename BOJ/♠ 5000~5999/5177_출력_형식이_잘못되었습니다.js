const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let msg = "";

// 문자열 교정 과정
for (let i = 0; i < input.length; i++) {
    let sentence = input[i];
    input[i] = input[i].replace(/[[{]/g, "("); // [, { => (
    input[i] = input[i].replace(/[\]}]/g, ")"); // ], } => )
    input[i] = input[i].replace(/^ +| +$/g, ""); // 앞, 끝부분의 공백 제거
    input[i] = input[i].replace(/(?<=[{[()\]}.,;:]) */g, ""); // 특수문자 뒷쪽 공백 제거
    input[i] = input[i].replace(/ *(?=[{[()\]}.,;:])/g, ""); // 특수문자 앞쪽 공백 제거
    input[i] = input[i].replace(/ {2,}/g, " "); // 2칸 이상의 공백 1칸 공백으로
    input[i] = input[i].replace(/;/g, ","); // ; => ,
    input[i] = input[i].replace(/[A-Z]+/g, (caps) => { // 대문자를 소문자로
        return caps.toLowerCase();
    });
}

for (let i = 0; i < input.length / 2; i++) {
    msg += "Data Set " + (i + 1) + ": ";
    if (input[i * 2] === input[i * 2 + 1]) msg += "equal";
    else msg += "not equal";
    msg += "\n\n";
}

console.log(msg);