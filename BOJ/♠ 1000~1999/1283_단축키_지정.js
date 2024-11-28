const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const N = Number(input[0]);
const strings = input.slice(1);
let output = '';
const usedLetters = new Set();

const setHotkey = (string, keyIndex) => {
  if (keyIndex === -1) {
    return string;
  }

  return `${string.slice(0, keyIndex)}[${string[keyIndex]}]${string.slice(keyIndex + 1)}`;
};

const getHotkeyIndex = (string) => {
  const words = string.split(' ');
  let index = 0;

  for (let i = 0; i < words.length; i++) {
    const firstLetter = words[i][0].toLowerCase();

    if (!usedLetters.has(firstLetter)) {
      usedLetters.add(firstLetter);
      return index;
    }

    index += words[i].length + 1;
  }

  for (let i = 0; i < string.length; i++) {
    if (string[i] === ' ') {
      continue;
    }

    const currentLetter = string[i].toLowerCase();

    if (!usedLetters.has(currentLetter)) {
      usedLetters.add(currentLetter);
      return i;
    }
  }

  return -1;
};

strings.forEach((string) => {
  const hotkeyIndex = getHotkeyIndex(string);
  output += `${setHotkey(string, hotkeyIndex)}\n`;
});

console.log(output);
