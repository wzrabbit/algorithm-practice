const printAnswer = (topNumber, bottomNumber) => {
  let resultNumber = (Number(topNumber) + Number(bottomNumber)).toString();

  if (resultNumber.length === 5) {
    resultNumber = ' ' + resultNumber;
  }

  console.log(`  ${topNumber}
+ ${bottomNumber}
-------
 ${resultNumber}`)
};

const isCorrectNumber = (number, goal) => {
  const textNumber = number
    .toString()
    .padStart(7, '0');

  if (/(.).*\1/.test(textNumber)) {
    return false;
  }

  const topNumber = `${textNumber[0]}${textNumber[1]}${textNumber[2]}${textNumber[2]}${textNumber[3]}`;
  const bottomNumber = `${textNumber[4]}${textNumber[3]}${textNumber[5]}${textNumber[2]}${textNumber[6]}`;

  if (textNumber[0] === '0' || textNumber[4] === '0') {
    return false;
  }

  if (Number(topNumber) + Number(bottomNumber) === goal) {
    printAnswer(topNumber, bottomNumber);
    return true;
  }

  return false;

};

const input = Number(require('fs').readFileSync(0));
let success = false;

for (let number = 1_000_000; number <= 9_999_999; number += 1) {
  if (isCorrectNumber(number, input)) {
    success = true;
    break;
  }
}

if (!success) {
  console.log('No Answer');
}