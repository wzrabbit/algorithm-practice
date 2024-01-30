const [_, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const db = {};

input.forEach((line) => {
  const matchedNumber = line.match(/\d+/g)[0];

  if (matchedNumber in db) {
    db[matchedNumber] += 1;
  } else {
    db[matchedNumber] = 1;
  }
});

let matchedCount = 0;
let matchedSchoolNos = [];

Object.entries(db).forEach(([schoolNo, count]) => {
  if (count <= 5) {
    matchedSchoolNos.push(schoolNo);
    matchedCount += 1;
  }
});

console.log(matchedCount);
console.log(matchedSchoolNos.join('\n'));
