const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.pop();
result = "";

for (let i = 0; i < input.length; i++) {
    if (/[aeiou]/.test(input[i]) && !(/[aeiou]{3}|[b-df-hj-np-tv-z]{3}/.test(input[i])) && !(/([^eo])\1/.test(input[i]))) result += "<" + input[i] + "> is acceptable.\n";
    else result += "<" + input[i] + "> is not acceptable.\n";
}

console.log(result);