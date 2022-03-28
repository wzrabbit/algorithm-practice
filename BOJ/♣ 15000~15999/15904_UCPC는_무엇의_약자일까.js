const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();

let remain = input.replace(/([^UCP])/g, "");

if (remain.match(/U.*C.*P.*C.*/)) console.log("I love UCPC");
else console.log("I hate UCPC");