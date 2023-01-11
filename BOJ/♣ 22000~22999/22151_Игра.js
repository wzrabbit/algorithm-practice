const [, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

let printer = '';

input.forEach((testcase) => {
  const [limit, startRow, startCol, endRow, endCol] = testcase.split(' ').map(Number);
  const dist = Math.abs(startRow - endRow) + Math.abs(startCol - endCol);
  
  if (dist <= limit) {
    printer += 'First 1\n';
  } else {
    printer += 'Infinity\n';
  }
});

console.log(printer);
  
