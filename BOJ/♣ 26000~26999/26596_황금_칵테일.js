const isGoldRatio = (amountA, amountB) => {
  if (amountA > amountB) {
    return isGoldRatio(amountB, amountA);
  }
  
  const GOLD_RATIO = 1.618;
  
  if (Math.floor(amountA * GOLD_RATIO) === amountB) {
    return true;
  }
  return false;
}

const [, ...input] = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
let mixer = {};
let success = false;

input.forEach((testcase) => {
  let [thing, amount] = testcase.split(' ');
  amount = Number(amount);
  
  if (mixer.hasOwnProperty(thing)) {
    mixer[thing] += amount;
  } else {
    mixer[thing] = amount;
  }
});

mixer = Object.values(mixer);

for (let i = 0; i < input.length; i++) {
  for (let j = 0; j < input.length; j++) {
    if (i !== j && isGoldRatio(mixer[i], mixer[j])) {
      success = true;
    }
  }
}

if (success) {
  console.log('Delicious!');
} else {
  console.log('Not Delicious...');
}