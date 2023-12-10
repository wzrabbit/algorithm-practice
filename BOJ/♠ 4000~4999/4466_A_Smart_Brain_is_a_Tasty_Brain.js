const [_, ...lines] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

let output = '';

lines.forEach((line, index) => {
  let [expression, expected] = line.split(' = ');
  expression = expression
    .replaceAll('t', '1')
    .replaceAll('f', '0')
    .replaceAll('|', '||')
    .replaceAll('&', '&&');

  expected = Number(
    expected
      .replace('t', '1')
      .replace('f', '0')
  );

  if (Number(eval(expression)) === expected) {
    output += `${index + 1}: Good brain\n`;
  } else {
    output += `${index + 1}: Bad brain\n`;
  }
});

console.log(output);

