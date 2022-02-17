const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim();

input = input.replace(/c=|c-|dz=|d-|lj|nj|s=|z=/g, "A");
console.log(input.length);