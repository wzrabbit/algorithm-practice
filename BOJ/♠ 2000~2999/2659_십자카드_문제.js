let clockNum = parseInt(require('fs').readFileSync('/dev/stdin').toString().replace(/ /g, ''));
let board = new Array(10000).fill(true);

const rotate = (num) => {
    num = num.toString();
    num = num.slice(-1) + num.slice(0, -1);
    return parseInt(num);
}

let temp = clockNum;
for (let i = 0; i < 3; i++) {
    temp = rotate(temp);
    if (clockNum > temp) clockNum = temp;
}

let count = 1;
for (let i = 1111; i <= 9999; i++) {
    if (board[i] === false || i.toString().includes('0')) continue;
    board[i] = false;
    if (i === clockNum) {
        console.log(count);
        break;
    }
    temp = i;
    for (let j = 0; j < 3; j++) {
        temp = rotate(temp);
        board[temp] = false;
    }
    count++;
}