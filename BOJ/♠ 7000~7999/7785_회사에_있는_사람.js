const [_, ...input] = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const workingPeople = new Set();

input.forEach((log) => {
  const [employee, command] = log.split(' ');

  if (command === 'enter') {
    workingPeople.add(employee);
  } else {
    workingPeople.delete(employee);
  }
});

const answer = [...workingPeople].sort((a, b) => a > b ? -1 : 1);
console.log(answer.join('\n'));
