let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");

for (let i = 0; i < input.length; i++) {
    input[i] = input[i].split(" ").map(Number);
}

const yLength = input[0][0];
const xLength = input[0][1];
const inventory = input[0][2];
let min = [-1, 0];

const calcBlockAmount = (floor) => {
    let dig = 0;
    let place = 0;

    for (let x = 0; x < xLength; x++) {
        for (let y = 1; y <= yLength; y++) {
            let currentBlock = input[y][x];
            if (currentBlock > floor) {
                dig += currentBlock - floor;
            }
            else if (currentBlock < floor) {
                place += floor - currentBlock;
            }
        }
    }
    if (inventory + dig < place) return false; // 블록이 부족해 설치 불가능
    else return dig * 2 + place;
};

for (let f = 0; f <= 256; f++) {
    let blockAmount = calcBlockAmount(f);
    if (blockAmount !== false) {
        if (blockAmount <= min[0] || min[0] === -1) {
            min[0] = blockAmount;
            min[1] = f;
        }
    }
    else break;
}

console.log(min[0] + " " + min[1]);
