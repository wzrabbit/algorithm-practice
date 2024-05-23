const getAlphabetsCount = (word) => {
  const alphabetsCount = Array.from({ length: 26 }).map(() => 0);

  for (let i = 0; i < word.length; i++) {
    alphabetsCount[word[i].charCodeAt() - 65] += 1;
  }

  return alphabetsCount;
};

const isMakingWordPossible = (state) => {
  const binary = state.toString(2).padStart(N, '0');
  const alphabetsCount = Array.from({ length: 26 }).map(() => 0);

  for (let i = 0; i < binary.length; i++) {
    if (binary[i] === '1') {
      const currentAlphabetsCount = getAlphabetsCount(books[i].bookName);

      for (let j = 0; j < 26; j++) {
        alphabetsCount[j] += currentAlphabetsCount[j];
      }
    }
  }

  for (let i = 0; i < 26; i++) {
    if (alphabetsCount[i] < targetWordAlphabetsCount[i]) {
      return false;
    }
  }

  return true;
};

const calculatePrice = (state) => {
  const binary = state.toString(2).padStart(N, '0');
  let totalPrice = 0;

  for (let i = 0; i < binary.length; i++) {
    if (binary[i] === '1') {
      totalPrice += books[i].price;
    }
  }

  return totalPrice;
};

const input = require('fs').readFileSync(0, 'utf-8').trim().split("\n");
const targetWord = input[0];
const N = Number(input[1]);
const books = input.slice(2).map((book) => {
  const price = Number(book.split(' ')[0]);
  const bookName = book.split(' ')[1];
  return { price, bookName };
});
const targetWordAlphabetsCount = getAlphabetsCount(targetWord);
const INF = 5000001;
let bestPrice = INF;

for (let i = 0; i < 2 ** N; i++) {
  if (isMakingWordPossible(i)) {
    bestPrice = Math.min(bestPrice, calculatePrice(i));
  }
}

console.log(bestPrice === INF ? -1 : bestPrice);
