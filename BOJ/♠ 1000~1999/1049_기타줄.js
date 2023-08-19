const [NM, ...priceInfos] = require('fs')
  .readFileSync(0, 'utf-8')
  .toString()
  .trim()
  .split('\n');

const N = Number(NM.split(' ')[0]);
const MAX_PRICE = 1_000;

let bestBundlePrice = MAX_PRICE;
let bestSoloPrice = MAX_PRICE;

priceInfos.forEach((priceInfo) => {
  const [bundlePrice, soloPrice] = priceInfo.split(' ').map(Number);

  bestBundlePrice = Math.min(bestBundlePrice, bundlePrice);
  bestSoloPrice = Math.min(bestSoloPrice, soloPrice);
});

const answer = Math.min(
  bestSoloPrice * N,
  bestBundlePrice * Math.ceil(N / 6),
  bestBundlePrice * Math.floor(N / 6) + bestSoloPrice * (N % 6),
);

console.log(answer);
