const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const B = BigInt(input[0].split(' ')[0]);
const [N, M] = input[0].split(' ').slice(1).map(Number);
const priceInfos = input.slice(1, N + 1).map((info) => ({
  name: info.split(' ')[0],
  price: BigInt(info.split(' ')[1]),
}));
const shoppingItemNames = input.slice(N + 1, N + M + 1);

let totalPrice = 0n;

shoppingItemNames.forEach((name) => {
  const price = priceInfos.find((info) => info.name === name).price;
  totalPrice += price;
});

if (totalPrice <= B) {
  console.log('acceptable');
} else {
  console.log('unacceptable');
}
