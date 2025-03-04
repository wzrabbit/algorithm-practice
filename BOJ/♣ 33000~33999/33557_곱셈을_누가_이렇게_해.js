const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
const testcases = input.slice(1).map((testcase) => testcase.split(' ').map(Number));
let output = '';

testcases.forEach((testcase) => {
  const [A, B] = testcase;
  const maxLength = Math.max(String(A).length, String(B).length);
  const strA = String(A).padStart(maxLength);
  const strB = String(B).padStart(maxLength);

  const strResult = Number(
    Array.from({ length: maxLength }).map((_, index) => {
      const modifiedA = strA[index] === ' ' ? 1 : Number(strA[index]);
      const modifiedB = strB[index] === ' ' ? 1 : Number(strB[index]);
      
      return String(modifiedA * modifiedB);
    }).join('')
  );

  if (strResult === A * B) {
    output += '1\n';
  } else {
    output += '0\n';
  }
});

console.log(output);
