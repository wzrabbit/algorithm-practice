const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let num = parseInt(input[0]);
let fileList = [];
let resultFileName = "";
let fileText = "";
let same = true;

for (let i = 0; i < num; i++) {
    fileList.push(input[i + 1]);
}

for (let i = 0; i < fileList[0].length; i++) {
    fileText = fileList[0][i];
    for (let j = 0; j < num; j++) {
        if (fileList[j][i] !== fileText) {
            resultFileName += "?";
            same = false;
            break;
        }
    }
    if (same === true) {
        resultFileName += fileText;
        fileText = "";
    }
    same = true;
}

console.log(resultFileName);