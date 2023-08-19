const generateNumbers = (arr) => {
  const generatedNumbers = [];

  for (let i = 0; i < (1 << arr.length); i++) {
    let cur = 0;

    for (let j = 0; j < arr.length; j++) {
      if ((i & (1 << (arr.length - j - 1))) > 0) {
        cur += arr[j];
      }
    }

    generatedNumbers.push(cur);
  }

  return generatedNumbers;
}

const findPairIndexByLeftNumber = (leftNumber) => {
  let start = 0;
  let end = rightNumbers.length - 1;
  let mid;

  while (start <= end) {
    mid = Math.floor((start + end) / 2);
    const pairSum = leftNumber + rightNumbers[mid][0];

    if (pairSum > goal) {
      end = mid - 1;
    } else if (pairSum < goal) {
      start = mid + 1;
    } else {
      return rightNumbers[mid][1];
    }
  }

  return -1;
}

const [N, ...numbers] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map(Number);

const goal = numbers.pop();
const inputMid = Math.floor(N / 2);
const leftNumbers = generateNumbers(numbers.slice(0, inputMid));
const rightNumbers = generateNumbers(numbers.slice(inputMid, N))
  .map((number, index) => ([number, index]));

rightNumbers.sort((a, b) => a[0] - b[0]);

for (let i = 0; i < leftNumbers.length; i++) {
  const rightIndex = findPairIndexByLeftNumber(leftNumbers[i]);

  if (rightIndex !== -1) {
    const answer = i.toString(2).padStart(inputMid, '0')
      + rightIndex.toString(2).padStart(N - inputMid, '0');

    console.log(answer);
    return;
  }
}