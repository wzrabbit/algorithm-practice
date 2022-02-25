const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const crane = input[1].split(' ').map((x) => parseInt(x));
let [down, up] = [parseInt(input[2]), 0];
const box = input[3].split(' ').map((x) => parseInt(x));
let time = 0;
const inf = 10 ** 7;

crane.sort((a, b) => b - a);
box.sort((a, b) => b - a);

let skip = false;
if (crane[0] < box[0]) {
    skip = true;
    time = -1;
}

if (skip === false) {
    while (down > up) {
        let c = 0;
        for (let b = 0; b < down; b++) {
            if (crane[c] >= box[b]) {
                box[b] = inf;
                up++;
                c++;
            }
        }
        time++;
    }
}

console.log(time);