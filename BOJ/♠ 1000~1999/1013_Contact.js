const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let remain = "";

for (let i = 0; i < input.length; i++) {
    remain = input[i];
    remain = remain.replace(/^(100+1+|01)+$/, "");
    if (remain === "") console.log("YES");
    else console.log("NO");
    remain = "";
}