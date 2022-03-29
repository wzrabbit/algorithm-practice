let [_, ...input] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
input = input.map((x) => x.split(' '));

for (let i = 0; i < input.length; i++) {
    for (let j = 1; j <= 3; j++)
        input[i][j] = parseInt(input[i][j]);
}

input.sort((a, b) => {
    if (a[1] !== b[1])
        return b[1] - a[1];
    else if (a[2] !== b[2])
        return a[2] - b[2];
    else if (a[3] !== b[3])
        return b[3] - a[3];
    else if (a[0] > b[0])
        return 1;
    else
        return -1;
});

let printer = '';
for (let i = 0; i < input.length; i++)
    printer += input[i][0] + '\n';

console.log(printer);