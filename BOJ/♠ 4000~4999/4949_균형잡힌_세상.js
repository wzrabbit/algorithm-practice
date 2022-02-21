let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
input.pop();
result = "";

for (let i = 0; i < input.length; i++) {
  if (checkStack(input[i].match(/[()[\]]/g))) {
    result += "yes\n";
  }
  else {
    result += "no\n";
  }
}

console.log(result);

function checkStack(data) {
  if (data === null) return true;
  let stack = [];
  for (let i = 0; i < data.length; i++) {
    if (data[i] === "(" || data[i] === "[") {
      stack.push(data[i]);
    }
    else {
      let popped = stack.pop();
      if (!((data[i] === ")" && popped === "(") || (data[i] === "]" && popped === "["))) return false;
    }
  }
  if (stack.length === 0) return true;
  else return false;
}