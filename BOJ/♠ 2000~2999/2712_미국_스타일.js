let [T, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map((line) => line.split(' '));

input = input.slice(0, T);

const convert = (value, unit) => {
  switch (unit) {
    case 'kg':
      return `${(value * 2.2046).toFixed(4)} lb`;
    case 'lb':
      return `${(value * 0.4536).toFixed(4)} kg`;
    case 'l':
      return `${(value * 0.2642).toFixed(4)} g`;
    case 'g':
      return `${(value * 3.7854).toFixed(4)} l`;
  }
}

let printer = '';

input.forEach(([value, unit]) => {
  printer += `${convert(Number(value), unit)}\n`;
});

console.log(printer);