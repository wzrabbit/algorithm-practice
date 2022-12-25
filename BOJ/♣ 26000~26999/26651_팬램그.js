let input = Number(require('fs').readFileSync(0));
let answer = '';

while (input > 0) {
  const aRepeat = Math.floor(Math.sqrt(input));
  const zRepeat = Math.floor(input / aRepeat);
  input -= aRepeat * zRepeat;
  answer += `${'A'.repeat(aRepeat)}BCDEFGHIJKLMNOPQRSTUVWXY${'Z'.repeat(zRepeat)}`;
}
answer += 'SIMSIMHADA';

console.log(answer);
