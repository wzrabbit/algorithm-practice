const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
const history = [];

for (let i = 1; i <= N; i++) {
    const [name, week, day, cost] = input[i].split(' ');
    
    history.push({
      name,
      day: Number(week) * 7 + Number(day),
      cost: Number(cost)
    });
}

for (let i = N + 1; i <= 2 * N; i++) {
  const [name, money] = input[i].split(' ');
  const index = history.findIndex((data) => data.name === name);
  
  history[index].money = Number(money);
};

history.sort((a, b) => a.day - b.day);

let combo = 0;
let maxCombo = 0;
let prevDay = -1234;

for (let i = 0; i < N; i++) {
  const { cost, money, day } = history[i];
  
  if (money >= cost) {
    if (prevDay + 1 === day) {
      combo += 1;
    } else if (prevDay !== day) {
      combo = 1;
    }
    
    maxCombo = Math.max(combo, maxCombo);
    prevDay = day;
  }
}

console.log(maxCombo);
