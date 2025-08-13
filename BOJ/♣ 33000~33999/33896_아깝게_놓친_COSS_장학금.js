const getResultScore = (score, cost, risk) => {
  return Math.floor(score ** 3 / (cost * (risk + 1)));
};

const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
const infos = input.slice(1).map((info) => {
  let [name, score, risk, cost] = info.split(' ');
  score = Number(score);
  risk = Number(risk);
  cost = Number(cost);

  return { name, score, risk, cost };
});

infos.sort((a, b) => {
  const aResultScore = getResultScore(a.score, a.cost, a.risk);
  const bResultScore = getResultScore(b.score, b.cost, b.risk);

  if (aResultScore !== bResultScore) {
    return bResultScore - aResultScore;
  }

  if (a.cost !== b.cost) {
    return a.cost - b.cost;
  }

  return a.name < b.name ? -1 : 1;
});

console.log(infos[1].name);
