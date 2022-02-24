const input = parseInt(require("fs").readFileSync("/dev/stdin"));
sum = 0;

for (let i = 1; i <= input; i++) {
    sum += i;
}

console.log(sum);