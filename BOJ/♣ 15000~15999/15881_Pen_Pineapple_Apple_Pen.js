const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n")[1];

console.log((input.match(/pPAp/g) || []).length);