const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
const arr = input[1].split(' ').map(Number);
const verdict = input[2];

const isCorrectSumiArray = (sumiArray) => {
  for (let i = 1; i <= Math.floor(N / 2); i += 1) {
    let success = true;

    for (let j = 0; j < i; j += 1) {
      if (sumiArray[j] !== sumiArray[N - i + j]) {
        success = false;
        break;
      }
    }

    if (success) {
      return true;
    }
  } 

  return false;
};

if (verdict === 'yes') {
  for (let i = 1; i <= Math.floor(N / 2); i += 1) {
    const sumiArray = Array.from(arr);
    success = true;

    for (let j = 0; j < i; j += 1) {
      if (sumiArray[j] !== sumiArray[N - i + j] && sumiArray[j] !== 0 && sumiArray[N - i + j] !== 0) {
        success = false;
        break;
      }

      if (sumiArray[j] === 0) {
        sumiArray[j] = sumiArray[N - i + j];
      }

      if (sumiArray[N - i + j] === 0) {
        sumiArray[N - i + j] = sumiArray[j];
      }
    }

    if (success) {
      console.log(sumiArray.map((value) => value === 0 ? 1 : value).join(' '));
      return;
    }
  }
}

while (true) {
  const sumiArray = Array.from(arr).map((value) => value === 0 ? Math.floor(Math.random() * 2000) + 1 : value);
  if (!isCorrectSumiArray(sumiArray)) {
    console.log(sumiArray.join(' '));
    break;
  }
}
