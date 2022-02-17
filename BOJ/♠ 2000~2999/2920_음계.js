const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

if (input === "1 2 3 4 5 6 7 8") console.log("ascending");
else if (input === "8 7 6 5 4 3 2 1") console.log("descending");
else console.log("mixed");