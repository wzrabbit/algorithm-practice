const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const repeat = parseInt(input[0]);
let index = 1;
let end = parseInt(input[1]);
let result = '';

for (let i = 0; i < repeat; i++) {
  end = parseInt(input[index]);
  index++;
  let staticIndex = index;
  let clothesMap = new Map();
  let cases = 1;

  for (index; index < staticIndex + end; index++) {
    let currentClothes = input[index].split(' ')[1];
    if (clothesMap.get(currentClothes) === undefined) clothesMap.set(currentClothes, 1);
    else clothesMap.set(currentClothes, clothesMap.get(currentClothes) + 1);
  }
  let clothesArr = [...clothesMap.values()];
  clothesArr.forEach((value) => {
    cases *= value + 1;
  });
  cases--;
  result += cases + '\n';
}

console.log(result);