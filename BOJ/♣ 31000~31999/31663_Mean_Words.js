const [_, ...words] = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const sum = Array.from({ length: 45 }).fill(0);
const elementCount = Array.from({ length: 45 }).fill(0);

words.forEach((word) => {
  for (let i = 0; i < word.length; i++) {
    const asciiCode = word[i].charCodeAt();
    sum[i] += asciiCode;
    elementCount[i] += 1;
  }
});

let output = '';

for (let i = 0; i < 45; i++) {
  if (elementCount[i] === 0) {
    break;
  }

  output += String.fromCharCode(Math.floor(sum[i] / elementCount[i]));
}

console.log(output);
