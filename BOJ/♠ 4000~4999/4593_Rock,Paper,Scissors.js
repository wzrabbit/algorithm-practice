const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
input.pop();
input.pop();
let result = '';

for (let i = 0; i < input.length; i += 2) {
    const p1 = input[i];
    const p2 = input[i + 1];
    let p1Score = 0;
    let p2Score = 0;

    for (let j = 0; j < p1.length; j++) {
        if ((p1[j] === 'R' && p2[j] === 'S') || (p1[j] === 'S' && p2[j] === 'P') || (p1[j] === 'P' && p2[j] === 'R')) p1Score++;
        else if ((p1[j] === 'S' && p2[j] === 'R') || (p1[j] === 'P' && p2[j] === 'S') || (p1[j] === 'R' && p2[j] === 'P')) p2Score++;
    }

    result += `P1: ${p1Score}\nP2: ${p2Score}\n`;
}

result = result.slice(0, -1);
console.log(result);