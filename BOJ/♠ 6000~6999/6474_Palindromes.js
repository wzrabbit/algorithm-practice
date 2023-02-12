const getMirroredLetter = {
  'A': 'A',
  'E': '3',
  'H': 'H',
  'I': 'I',
  'J': 'L',
  'L': 'J',
  'M': 'M',
  'O': 'O',
  'S': '2',
  'T': 'T',
  'U': 'U',
  'V': 'V',
  'W': 'W',
  'X': 'X',
  'Y': 'Y',
  'Z': '5',
  '1': '1',
  '2': 'S',
  '3': 'E',
  '5': 'Z',
  '8': '8',
};

const isPalinDrome = string => {
  let l = 0;
  let r = string.length - 1;
  
  while (l < r) {
    if (string[l] !== string[r]) {
      return false;
    }
    
    l += 1;
    r -= 1;
  }
  
  return true;
};

const isMirror = string => {
  let mirroredString = '';
  
  for (let i = string.length - 1; i >= 0; i--) {
    const mirroredLetter = getMirroredLetter[string[i]];
    
    if (mirroredLetter === undefined) {
      return false;
    }
    
    mirroredString += mirroredLetter;
  }
  
  if (string === mirroredString) {
    return true;
  }
  
  return false;
};

const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');
  
let printer = '';
  
input.forEach(currentWord => {
  const palindromeFlag = isPalinDrome(currentWord);
  const mirroredFlag = isMirror(currentWord);
  
  if (palindromeFlag && mirroredFlag) {
    printer += `${currentWord} -- is a mirrored palindrome.\n\n`;
  } else if (palindromeFlag) {
    printer += `${currentWord} -- is a palindrome.\n\n`;
  } else if (mirroredFlag) {
    printer += `${currentWord} -- is a mirrored string.\n\n`;
  } else {
    printer += `${currentWord} -- is not a palindrome.\n\n`;
  }
});

printer = printer.slice(0, -1);
console.log(printer);