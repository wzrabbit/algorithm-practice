const no = Number(require('fs').readFileSync(0));
const START_NUMBER = 57429;
const END_NUMBER = 98765;
let validCount = 0;

for (let i = START_NUMBER; i <= END_NUMBER; i++) {
  if (i % 9 !== 0) {
    continue;
  }
  
  const numbers = (i.toString() + (i / 9).toString().padStart(5, '0')).split('');
  const numberSet = new Set(numbers);
  
  if (numberSet.size === 10) {
    validCount += 1;
    
    if (validCount === no) {
      const answer = numbers.join('').slice(0, 5) + ' ' + numbers.join('').slice(5);
      console.log(answer);
      break;
    }
  }
}