const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [ax, ay] = input[0].split(' ').map(Number);
const [bx, by] = input[1].split(' ').map(Number);
const [cx, cy] = input[2].split(' ').map(Number);
const w1 = (ax - bx) ** 2 + (ay - by) ** 2;
const w2 = (bx - cx) ** 2 + (by - cy) ** 2;
const w3 = (cx - ax) ** 2 + (cy - ay) ** 2;
const xSort = [ax, bx, cx].sort((a, b) => a - b);
const ySort = [ay, by, cy].sort((a, b) => a - b);
const wSort = [w1, w2, w3].sort((a, b) => a - b);
let resultChecker = false;

if ((ax - bx) / (ay - by) === (bx - cx) / (by - cy)) {
    resultChecker = true;
    console.log('X');
}

if (wSort[0] === wSort[2] && resultChecker === false) {
    resultChecker = true;
    console.log('JungTriangle');
}

if (resultChecker === false) {
    let result = '';
    if (wSort[0] + wSort[1] > wSort[2]) result += 'Yeahkak';
    else if (wSort[0] + wSort[1] < wSort[2]) result += 'Dunkak';
    else result += 'Jikkak';

    if (wSort[0] === wSort[1] || wSort[1] === wSort[2]) result += '2Triangle';
    else result += 'Triangle';

    console.log(result);
}