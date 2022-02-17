const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();

let sum = 0;
let classes = 0;
let scoreList = {
    "A+" : 4.3, "A0" : 4, "A-" : 3.7,
    "B+" : 3.3, "B0" : 3, "B-" : 2.7,
    "C+" : 2.3, "C0" : 2, "C-" : 1.7,
    "D+" : 1.3, "D0" : 1, "D-" : 0.7,
    "F" : 0
}

for (let i = 0; i < input.length; i++) {
    let data = input[i].split(" ");
    let currentClasses = Number(data[1]);
    let currentGrade = data[2];
    sum += scoreList[currentGrade] * currentClasses;
    classes += currentClasses;
}

console.log((Math.round(sum / classes * 100) / 100).toFixed(2));