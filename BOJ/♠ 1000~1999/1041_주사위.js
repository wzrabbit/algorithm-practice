const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const width = parseInt(input[0]);
const diceValue = input[1].split(" ").map(Number);
let min1 = 0;
let min2 = 9999;
let min3 = 9999;
let min5 = 0;
let result = 0;

// 주사위에서 서로 인접한 면 리스트
let dice = {
  A : ["B", "C", "D", "E"],
  B : ["A", "C", "D", "F"],
  C : ["A", "B", "E", "F"],
  D : ["A", "B", "E", "F"],
  E : ["A", "C", "D", "F"],
  F : ["B", "C", "D", "E"]
}

// 주사위 한 면짜리의 최솟값
let temp = [];
for (let i = 0; i <= 5; i++) {
  temp.push(diceValue[i]);
}
temp.sort((a, b) => a - b);
min1 = temp[0];

// 주사위 두 면짜리의 최솟값
for (let i = 0; i <= 4; i++) {
  for (let j = i + 1; j <= 5; j++) {
    if (i !== j && checkDiceConnected([i, j]) && diceValue[i] + diceValue[j] < min2) {
      min2 = diceValue[i] + diceValue[j];
    }
  }
}

// 주사위 세 면짜리의 최솟값
for (let i = 0; i <= 3; i++) {
  for (let j = i + 1; j <= 4; j++) {
    for (let k = j + 1; k <= 5; k++) {
      if (i !== j && j !== k && i !== k && checkDiceConnected([i, j, k]) && diceValue[i] + diceValue[j] + diceValue[k] < min3) {
        min3 = diceValue[i] + diceValue[j] + diceValue[k];
      }
    }
  }
}

// 주사위 다섯 면짜리의 최솟값
let temp2 = [];
for (let i = 0; i <= 5; i++) {
  temp2.push(diceValue[i]);
}
temp2.sort((a, b) => a - b);
temp2.pop();
for (let i = 0; i <= 4; i++) {
  min5 += temp2[i];
}

// 길이가 1일 경우
if (width === 1) {
  result += min5;
}

// 길이가 2일 경우
if (width === 2) {
  result += min2 * 4;
  result += min3 * 4;
}

// 길이가 3 이상일 경우
if (width >= 3) {
  result += min1 * (width - 2) * (width - 1) * 4 + min1 * ((width - 2) ** 2);
  result += min2 * (width - 1) * 4 + min2 * (width - 2) * 4;
  result += min3 * 4;
}

console.log(result);

function checkDiceConnected(diceList) {
  for (let i = 0; i < diceList.length; i++) {
    switch(diceList[i]) {
      case 0:
        diceList[i] = "A";
        break;
      case 1:
        diceList[i] = "B";
        break;
      case 2:
        diceList[i] = "C";
        break;
      case 3:
        diceList[i] = "D";
        break;
      case 4:
        diceList[i] = "E";
        break;
      case 5:
        diceList[i] = "F";
        break;
    }
  }

  let a = diceList[0];
  let b = diceList[1];
  let c = diceList[2];

  // 면 3개가 "모두" 서로 연결되어 있는지 확인
  if (diceList.length === 3) {
    if ((dice[a].indexOf(b) != -1 && dice[b].indexOf(c) != -1) && (dice[a].indexOf(c) != -1)) return true;
    else return false;
  }

  // 면 2개가 연결되어 있는지 확인
  else {
    if (dice[a].indexOf(b) != -1) return true;
    else return false;
  }
}
