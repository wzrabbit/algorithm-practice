const fs = require("fs");
const input = parseInt(fs.readFileSync("/dev/stdin"));
let result = 99;

if (input >= 100) {
  for (let i = 100; i <= input; i++) {
    let stringNum = i.toString();
    if (stringNum[1] - stringNum[0] === stringNum[2] - stringNum[1]) {
      result++;
    }
  }
  console.log(result);
}
else console.log(input);