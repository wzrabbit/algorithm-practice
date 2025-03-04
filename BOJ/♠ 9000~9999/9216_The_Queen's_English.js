const STRING_NUMBERS = {
  1: 'one',
  2: 'two',
  3: 'three',
  4: 'four',
  5: 'five',
  6: 'six',
  7: 'seven',
  8: 'eight',
  9: 'nine',
  10: 'ten',
  11: 'eleven',
  12: 'twelve',
  13: 'thirteen',
  14: 'fourteen',
  15: 'fifteen',
  16: 'sixteen',
  17: 'seventeen',
  18: 'eighteen',
  19: 'nineteen',
  20: 'twenty',
  30: 'thirty',
  40: 'forty',
  50: 'fifty',
  60: 'sixty',
  70: 'seventy',
  80: 'eighty',
  90: 'ninety',
};

const parseInput = (input) => {
  return input.map((line) => line.padStart(9, '0').match(/.{3}/g).map(Number));
};

const convertToStringNumber = (number) => {
  const [hundreds, tens, units] = String(number).padStart(3, '0').split('').map(Number);
  const numberWithoutHundreds = tens * 10 + units;
  let stringNumber = '';

  if (hundreds > 0) {
    if (numberWithoutHundreds > 0) {
      stringNumber += `${STRING_NUMBERS[hundreds]} hundred and `;
    } else {
      stringNumber += `${STRING_NUMBERS[hundreds]} hundred`;
    }
  }

  if (numberWithoutHundreds >= 20) {
    if (units > 0) {
      stringNumber += `${STRING_NUMBERS[tens * 10]}-${STRING_NUMBERS[units]}`;
    } else {
      stringNumber += `${STRING_NUMBERS[tens * 10]}`;
    }
  }

  if (numberWithoutHundreds >= 10 && numberWithoutHundreds < 20) {
    stringNumber += `${STRING_NUMBERS[numberWithoutHundreds]}`;
  }

  if (numberWithoutHundreds > 0 && numberWithoutHundreds < 10) {
    stringNumber += `${STRING_NUMBERS[units]}`;
  }

  return stringNumber;
};

const input = parseInput(require('fs').readFileSync(0, 'utf-8').trim().split('\n'));
input.pop();

let output = '';

input.forEach((numberArray, index) => {
  const [a, b, c] = numberArray;

  output += `Test ${index + 1}: `;
  
  if (a > 0) {
    output += `${convertToStringNumber(a)} million `;
  }

  if (b > 0) {
    output += `${convertToStringNumber(b)} thousand `;
  }

  if (c > 0) {
    if ((a !== 0 || b !== 0) && c < 100) {
      output += 'and ';
      
    }

    output += convertToStringNumber(c);
  }

  output += '\n';
});

console.log(output);
