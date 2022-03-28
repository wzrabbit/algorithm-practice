const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();
let remain = input.replace(/(pi|ka|chu)/g, "");

if (remain === "") console.log("YES");
else console.log("NO");