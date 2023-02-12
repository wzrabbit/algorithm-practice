const getWordUsingCode = (code) => {
  const CHARCODE_START_NUMBER = 97;
  let remainCode = code;
  let chosenAlphabets = [];

  for (let i = 0; i < 4; i += 1) {
    const currentCode = remainCode % 26;
    remainCode = Math.floor(remainCode / 26);
    chosenAlphabets.push(
      String.fromCharCode(currentCode + CHARCODE_START_NUMBER)
    );
  }

  return chosenAlphabets.join('ab');
};

const input = Number(require('fs').readFileSync(0));
let printer = '';

for (let i = 0; i < input; i += 1) {
  printer += `${getWordUsingCode(i)}\n`;
}

console.log(printer);