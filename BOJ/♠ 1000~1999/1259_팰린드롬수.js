const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.pop();
let result = "";
input = input.map(Number).map(String);

for (let i = 0; i < input.length; i++) {
    switch (input[i].length) {
        case 1:
            result += "yes\n";
            break;
        case 2:
            if (input[i][0] === input[i][1]) result += "yes\n";
            else result += "no\n";
            break;
        case 3:
            if (input[i][0] === input[i][2]) result += "yes\n";
            else result += "no\n";
            break;
        case 4:
            if (input[i][0] === input[i][3] && input[i][1] === input[i][2]) result += "yes\n";
            else result += "no\n";
            break;
        case 5:
            if (input[i][0] === input[i][4] && input[i][1] === input[i][3]) result += "yes\n";
            else result += "no\n";
            break;
    }
}

console.log(result);