let [scale, num] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ');
scale = parseInt(scale);
let printer = '';
let data = [
  [1, 1, 1, 0, 1, 1, 1], [0, 0, 1, 0, 0, 1, 0], [1, 0, 1, 1, 1, 0, 1], [1, 0, 1, 1, 0, 1, 1], [0, 1, 1, 1, 0, 1, 0],
  [1, 1, 0, 1, 0, 1, 1], [1, 1, 0, 1, 1, 1, 1], [1, 0, 1, 0, 0, 1, 0], [1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 0, 1, 1]
];

const printShort = (key) => {
  for (let i = 0; i < num.length; i++) {
    if (data[num[i]][key] === 1) printer += ' ' + '-'.repeat(scale) + '  ';
    else printer += ' ' + ' '.repeat(scale) + '  ';
  }
  printer += '\n';
};

const printLong = (key1, key2) => {
  let subPrinter = '';
  for (let i = 0; i < num.length; i++) {
    if (data[num[i]][key1] === 1) subPrinter += '|' + ' '.repeat(scale);
    else subPrinter += ' ' + ' '.repeat(scale);
    if (data[num[i]][key2] === 1) subPrinter += '| ';
    else subPrinter += '  ';
  }
  subPrinter += '\n';
  for (let i = 0; i < scale; i++) {
    printer += subPrinter;
  }
}

printShort(0);
printLong(1, 2);
printShort(3);
printLong(4, 5);
printShort(6);

console.log(printer);