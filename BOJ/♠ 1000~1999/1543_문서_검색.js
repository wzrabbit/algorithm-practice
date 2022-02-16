const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const target = input[0];
const key = input[1];
const regex = new RegExp(key, "g");
const result = target.match(regex);

if (result !== null) console.log(result.length);
else console.log(0);