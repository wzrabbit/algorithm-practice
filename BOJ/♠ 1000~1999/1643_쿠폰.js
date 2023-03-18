const getGcd = (a, b) => {
  if (a === 0) {
    return 1;
  }

  if (a % b === 0) {
    return b;
  }

  return getGcd(b, a % b);
};

const getLcm = (a, b) => {
  return a * b / getGcd(a, b);
};

const getSumOfTwoFractions = (a, b) => {
  const lcm = getLcm(a.bot, b.bot);
  a.top *= lcm / a.bot;
  b.top *= lcm / b.bot;
  const gcd = getGcd(a.top + b.top, lcm);

  return { top: (a.top + b.top) / gcd, bot: lcm / gcd };
};

const printFraction = fraction => {
  if (fraction.top % fraction.bot === 0) {
    printer += fraction.top / fraction.bot + '\n';
    return;
  }

  const quotient = Math.floor(fraction.top / fraction.bot).toString();
  const top = (fraction.top % fraction.bot).toString();
  const bot = fraction.bot.toString();
  const line = '-'.repeat(bot.length);
  const space = ' '.repeat(quotient.length);

  printer += `${space} ${top}\n`;
  printer += `${quotient} ${line}\n`;
  printer += `${space} ${bot}\n`;
};

const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map(Number);

let printer = '';

input.forEach(currentNumber => {
  let answerFraction = { top: 0, bot: 1 };

  for (let i = 1; i <= currentNumber; i++) {
    const newFraction = { top: currentNumber, bot: i };
    answerFraction = getSumOfTwoFractions(answerFraction, newFraction);
  }

  printFraction(answerFraction);
});

console.log(printer);