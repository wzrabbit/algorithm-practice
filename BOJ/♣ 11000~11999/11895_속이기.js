const [N, ...numbers] = require("fs")
  .readFileSync(0, "utf-8")
  .replace(/\n/g, " ")
  .trim()
  .split(" ")
  .map(Number);

let xorValue = 0;
let sum = 0;

for (let i = 0; i < N; i++) {
  xorValue ^= numbers[i];
  sum += numbers[i];
}

if (xorValue === 0) {
  console.log(sum - Math.min(...numbers));
} else {
  console.log(0);
}
