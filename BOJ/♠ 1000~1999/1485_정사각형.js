const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
input.shift();
let result = '';

for (let i = 0; i < input.length; i += 4) {
    let distance = [];
    let a = input[i].split(' ');
    let b = input[i + 1].split(' ');
    let c = input[i + 2].split(' ');
    let d = input[i + 3].split(' ');

    distance.push(getDistance(a, b));
    distance.push(getDistance(a, c));
    distance.push(getDistance(a, d));
    distance.push(getDistance(b, c));
    distance.push(getDistance(b, d));
    distance.push(getDistance(c, d));

    distance.sort((a, b) => a - b);

    if (distance[0] === distance[3] && distance[4] === distance[5]) result += '1\n';
    else result += '0\n';
}

result = result.slice(0, -1);
console.log(result);

function getDistance([x1, y1], [x2, y2]) {
    return Math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2);
}