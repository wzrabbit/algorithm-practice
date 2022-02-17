const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
let remain = "";

remain = input;
remain = remain.replace(/^(100+1+|01)+$/, "");
if (remain === "") console.log("SUBMARINE");
else console.log("NOISE");
remain = "";