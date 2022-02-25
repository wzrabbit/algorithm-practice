const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n").map(Number);
input.shift();
let result = "";

const getPadoValue = (value) => {
    let pado = [1, 1, 1, 2, 2];
    if (value <= 5) return pado[value - 1];

    let count = 6;
    while (count <= value) {
        pado.push(pado[pado.length - 1] + pado[pado.length - 5]);
        count++;
    }

    return pado[value - 1];
}

for (let i = 0; i < input.length; i++) {
    result += getPadoValue(input[i]) + "\n";
}

result = result.slice(0, -1);
console.log(result);