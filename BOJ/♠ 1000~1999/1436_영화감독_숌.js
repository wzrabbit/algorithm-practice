const input = parseInt(require("fs").readFileSync("/dev/stdin"));
let num = 665;
let count = 0;

while (count < input) {
    num++;
    if (num.toString().match(/666/)) count++;
}

console.log(num);