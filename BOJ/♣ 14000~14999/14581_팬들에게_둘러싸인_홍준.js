const input = require("fs").readFileSync("/dev/stdin").toString().trim();

console.log(`:fan::fan::fan:
:fan::${input}::fan:
:fan::fan::fan:`);