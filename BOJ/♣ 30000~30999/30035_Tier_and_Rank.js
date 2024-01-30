const calculatePopulation = (allPopulation, rate) => {
  if (rate.at(-1) === '%') {
    return Math.floor(allPopulation * Number(rate.slice(0, -1)) / 100);
  }

  return Math.min(allPopulation, Number(rate));
};

const calculateSubPopulation = (population) => {
  const subPopulation = [];
  let remainedPopulation = Number(population);

  for (let i = 1; i <= 3; i++) {
    const currentSub = Math.min(remainedPopulation, Math.ceil(population / 4));
    subPopulation.push(currentSub);
    remainedPopulation -= currentSub;
  }

  subPopulation.push(remainedPopulation);

  return subPopulation;
};

const generateTierInfo = (tierName, rawPopulation) => {
  const population = calculatePopulation(unratedCount, rawPopulation);
  const subPopulation = calculateSubPopulation(population);

  unratedCount -= population;

  return {
    tierName,
    population,
    subPopulation,
  };
};

const generateTierInfos = (rawTierInfos) => {
  const generatedTierInfos = rawTierInfos.map((rawTierInfo) => {
    const [tierName, rate] = rawTierInfo.split(' ');
    return generateTierInfo(tierName, rate);
  });

  return generatedTierInfos;
};

const getRankRange = (targetTierName) => {
  if (unratedCount > 0) {
    return 'Invalid System';
  }

  const targetTierNameWithoutSub = targetTierName.replace(/\d/, '');
  const targetTierSub = Number(targetTierName.at(-1)) || 0;
  let previousPopulation = 0;

  for (let i = 0; i < tierInfos.length; i++) {
    const { tierName, population, subPopulation } = tierInfos[i];

    if (tierName !== targetTierNameWithoutSub) {
      previousPopulation += population;
      continue;
    }

    if (targetTierSub === 0) {
      if (population === 0) {
        return 'Liar';
      }

      return `${previousPopulation + 1} ${previousPopulation + population}`;
    }

    for (let i = 1; i <= 3; i++) {
      if (i === targetTierSub) {
        break;
      }

      previousPopulation += subPopulation[i - 1];
    }

    if (subPopulation[targetTierSub - 1] === 0) {
      return 'Liar';
    }

    return `${previousPopulation + 1} ${previousPopulation + subPopulation[targetTierSub - 1]}`;
  }
};

const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

let unratedCount = Number(input[0].split(' ')[0]);
const rawTierInfos = input.slice(1, -1);
const targetTierName = input.at(-1);
const tierInfos = generateTierInfos(rawTierInfos);

console.log(getRankRange(targetTierName));
