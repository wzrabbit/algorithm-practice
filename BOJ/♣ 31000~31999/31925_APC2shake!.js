const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
const data = input.slice(1);
let qualified = [];

for (let i = 0; i < N; i += 1) {
  let [name, state, wasWinner, bestRank, apcScore] = data[i].split(' ');
  bestRank = Number(bestRank);
  apcScore = Number(apcScore);
  
  if (state === 'hewhak' || wasWinner === 'winner' || (bestRank <= 3 && bestRank !== -1)) {
    continue;
  }
  
  qualified.push({ name, apcScore });
}

qualified.sort((a, b) => a.apcScore - b.apcScore);
qualified = qualified.slice(0, 10);
qualified.sort((a, b) => a.name > b.name ? 1 : -1);
qualified = qualified.map(({ name }) => name);

console.log(qualified.length);

if (qualified.length > 0) {
  console.log(qualified.join('\n'));
}
