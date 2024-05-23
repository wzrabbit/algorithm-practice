const [_, ...input] = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
let output = '';

input.forEach((testcase) => {
  let maxLevel = 0;
  let currentLevel = 0;

  for (let i = 0; i < testcase.length; i++) {
    if (testcase[i] === '[') {
      currentLevel += 1;
    } else {
      currentLevel -= 1;
    }

    maxLevel = Math.max(maxLevel, currentLevel);
  }

  output += `${2 ** maxLevel}\n`;
})

console.log(output);
