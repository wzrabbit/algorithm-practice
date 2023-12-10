const chars = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .match(/[-.!?:,;()A-z0-9]/g);

const charCounts = {};
let maxCount = 1;

chars.forEach((char) => {
  if (char in charCounts) {
    charCounts[char] += 1;
    maxCount = Math.max(maxCount, charCounts[char]);
  } else {
    charCounts[char] = 1;
  }
});

const sortedCharCounts = [
  ...Object.entries(charCounts)
    .sort((a, b) => a[0] > b[0] ? 1 : -1)
];

let output = '';

for (let r = 0; r < maxCount; r++) {
  for (let c = 0; c < sortedCharCounts.length; c++) {
    if (sortedCharCounts[c][1] >= maxCount - r) {
      output += '#';
      continue;
    }

    output += ' ';
  }

  output += '\n';
}

for (let c = 0; c < sortedCharCounts.length; c++) {
  output += sortedCharCounts[c][0];
}

console.log(output);
