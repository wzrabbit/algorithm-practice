const input = require("fs").readFileSync("/dev/stdin").toString().trim();
let maxLevel = input.length - 1;
let numbers = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];

for (let i = 0; i <= maxLevel; i++) {
  let level = maxLevel - i;

  // 일반 자릿수의 등장 숫자 계산
  if (level !== 0 && level !== maxLevel) {
    for (let j = 0; j <= 9; j++) {
      numbers[j] += parseInt(input.slice(0, i)) * (10 ** level);
    }
    let rightNum = parseInt(input.slice(i));
    for (let j = 0; j <= 9; j++) {
      if (rightNum - 10 ** level >= 0) {
        numbers[j] += 10 ** level;
        rightNum = rightNum - 10 ** level;
      }
      else if (rightNum >= 0) {
        numbers[j] += rightNum + 1;
        break;
      }
      else break;
    }
  }

  // 마지막 자릿수의 등장 숫자 계산
  else if (level === 0) {
    let leftNum = parseInt(input.slice(0, -1));
    // 일의 자리 수 왼쪽을 읽어오되, NaN이면 수가 한 자리인 것이므로
    // 그럴 경우에는 이 단계를 건너뛴다
    if (isNaN(leftNum) === false) {
      for (let j = 0; j <= 9; j++) {
        numbers[j] += leftNum;
      }
    }
    for (let j = 0; j <= 9; j++) {
      if (input[i] >= j) {
        numbers[j]++;
      }
      else break;
    }
  }

  // 가장 높은 자릿수의 등장 숫자 계산
  else {
    let j;
    for (j = 0; j < input[0]; j++) {
      numbers[j] += 10 ** level;
    }
    numbers[j] += parseInt(input.slice(i + 1)) + 1;
  }

  // 공통 연산 : 최고 자리의 숫자가 0이었을 때의 횟수는 빼 준다
  numbers[0] -= 10 ** level;
}

console.log(numbers.join(" "));