const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
const fileNames = input.slice(1);
const extensionCount = Object.create(null);

fileNames.forEach((fileName) => {
  extension = fileName.split('.')[1];
  
  if (extension in extensionCount) {
    extensionCount[extension] += 1;
  } else {
    extensionCount[extension] = 1;
  }
});

const extensionCountArray = [...Object.entries(extensionCount)].sort((a, b) => a[0] > b[0] ? 1 : -1);
console.log(extensionCountArray.map(([extension, count]) => `${extension} ${count}`).join('\n'));
