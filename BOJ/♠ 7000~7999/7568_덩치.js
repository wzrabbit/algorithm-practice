let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let result = "";

for (let i = 0; i < input.length; i++) {
  input[i] = input[i].split(" ").map(Number);
}

for (let i = 0; i < input.length; i++) {
  let rank = 1;
  for (let j = 0; j < input.length; j++) {
    if (input[i][0] < input[j][0] && input[i][1] < input[j][1]) rank++;
  }
  result += rank + " ";
}

result = result.slice(0, -1);
console.log(result);