const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim();

const answers = {
  SONGDO: 'HIGHSCHOOL',
  CODE: 'MASTER',
  2023: '0611',
  ALGORITHM: 'CONTEST',
}

console.log(answers[input]);