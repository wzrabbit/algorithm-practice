const fs = require("fs");
const input = parseInt(fs.readFileSync("/dev/stdin"));

let board = [];
board[0] = '0';
board[1] = '1';

for (let i = 2; i <= input; i++) {
    board[i] = plus(board[i - 2], board[i - 1]);
}

// 너무 큰 수를 더하면 수가 e+n 형태로 저장되어 실제 값과 달라짐
// 자릿수를 분할해 더한 후 문자열 형태로 반환하는 것이 필요
function plus(numA, numB) {
    numA = ("0" + numA).split("").map(Number);
    numB = ("0" + numB).split("").map(Number);
    let sum = new Array(numB.length);
    
    // 자릿수를 맞추기 위해 numB와 길이가 같아질 때까지 numA 앞쪽에 0을 추가
    while (numA.length !== numB.length) {
        numA.unshift(0);
    }
   
    
    for (let i = numB.length - 1; i > 0; i--) {
        let aplusb = numA[i] + numB[i];
        sum[i] = aplusb;
        if (aplusb >= 10) carry(i); // i번째 자리에서 받아올림 발생
    }
    
    function carry(level) {
        sum[level] -= 10;
        if (level !== 1) {
            numB[level - 1] += 1;
        }
        else {
            sum[0] = 1;
        }
    }
    let result = sum.toString().replace(/,/g, "");
    return result;
}

if (input !== 0) console.log(board[board.length - 1]);
else console.log(0); // 0 입력 고려