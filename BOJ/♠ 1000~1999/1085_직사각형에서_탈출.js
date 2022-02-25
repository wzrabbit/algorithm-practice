const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split(" ");
const minsu = { x: input[0], y: input[1] };
const rect = { x: input[2], y: input[3] };

let cases = [
    minsu["x"],
    Math.abs(minsu["x"] - rect["x"]),
    minsu["y"],
    Math.abs(minsu["y"] - rect["y"])
];

console.log(Math.min(...cases));