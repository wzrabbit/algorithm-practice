const [_, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const db = {
  'AE': '[AE]',
  'Ae': '[Ae]',
  'aE': '[aE]',
  'ae': '[ae]',
  'OE': '[OE]',
  'Oe': '[OE]',
  'oE': '[oe]',
  'oe': '[oe]',
  'ct': '[ct]',
  'ff': '[ff]',
  'fi': '[fi]',
  'fl': '[fl]',
  'ffi': '[ffi]',
  'ffl': '[ffl]',
  's': '[longs]',
  'si': '[longsi]',
  'sh': '[longsh]',
  'sl': '[longsl]',
  'ss': '[longss]',
  'st': '[longst]',
  'ssi': '[longssi]',
};

let output = '';

input.forEach((line) => {
  line = line.replace(/s(?=($|[.,"'$;:?()\-<>=!fbk ]))/g, '*');
  line = line.replaceAll('sss', 's*s');

  line = line.replace(/[ao]e/gi, (matched) => {
    return db[matched];
  });

  line = line.replace(/ct|ff?[il]|ff|ssi|s[sihlt]?/g, (matched) => {
    return db[matched];
  });

  line = line.replaceAll('*', 's');

  output += `${line}\n`;
});

console.log(output);
