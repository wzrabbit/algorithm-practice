const getFactor = (word) => {
  if (word.match(/meow/)) {
    return 0;
  }

  if (word.match(/meo|me.?w|m.?ow|eow|emow|moew|mewo|me.ow/)) {
    return 1;
  }

  if (word.match(/me|m.?o|m.{0,2}w|eo|e.?w|ow/)) {
    return 2;
  }

  if (word.match(/[meow]/)) {
    return 3;
  }

  return 4;
};

const input = 'xxxx' + require('fs')
  .readFileSync(0, 'utf-8')
  .trim() + 'xxxx';

let bestFactor = 4;

for (let i = 0; i < input.length - 4; i++) {
  bestFactor = Math.min(bestFactor, getFactor(input.slice(i, i + 5)));
}

console.log(bestFactor);
