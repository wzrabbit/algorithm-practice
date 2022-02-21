let money = 1000 - parseInt(require('fs').readFileSync('/dev/stdin'));
const coins = [500, 100, 50, 10, 5, 1];
let count = 0;

coins.forEach((x) => {
  while (money >= x) {
    money -= x;
    count++;
  }
});

console.log(count);