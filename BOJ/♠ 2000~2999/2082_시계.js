const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const numberBoard = [
  '### ..# ### ### #.# ### ### ### ### ###',
  '#.# ..# ..# ..# #.# #.. #.. ..# #.# #.#',
  '#.# ..# ### ### ### ### ### ..# ### ###',
  '#.# ..# #.. ..# ..# ..# #.# ..# #.# ..#',
  '### ..# ### ### ..# ### ### ..# ### ###',
];

const convertNumberToTimeArray = (number) => {
  return [
    Math.floor(number / 600),
    Math.floor(number / 60 % 10),
    Math.floor(number / 10 % 6),
    Math.floor(number % 10),
  ];
};

const isPossible = (timeArray) => {
  for (let i = 0; i < 4; i++) {
    for (let r = 0; r < 5; r++) {
      for (let c = 0; c < 3; c++) {
        if (input[r][c + i * 4] === '#' && numberBoard[r][c + timeArray[i] * 4] === '.') {
          return false;
        }
      }
    }
  }

  return true;
};

for (let i = 0; i < 1440; i++) {
  const timeArray = convertNumberToTimeArray(i);
  if (isPossible(timeArray)) {
    console.log(`${timeArray[0]}${timeArray[1]}:${timeArray[2]}${timeArray[3]}`);
    break;
  }
}
