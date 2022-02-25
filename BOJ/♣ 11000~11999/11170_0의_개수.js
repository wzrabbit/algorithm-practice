const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

for (let i = 1; i < input.length; i++) {
    let text = '';
    const [start, end] = input[i].split(' ').map((x) => parseInt(x));
    for (let j = start; j <= end; j++) {
        text += j;
    }
    console.log((text.match(/0/g) || []).length);
}