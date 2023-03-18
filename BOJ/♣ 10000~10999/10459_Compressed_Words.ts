const getExtractedWord = (word: string): string => {
    const trimmedWord: string = word.replace(/ |\$/g, '');
    let extractedWord: string = trimmedWord;
  
    while (/\(/.test(extractedWord)) {
      extractedWord = extractedWord.replace(/\([^()]*\)/, (frag: string) => {
        const matchedString: string = (frag.match(/[a-z]+/) || [''])[0];
        const times: number = Number(frag.match(/\d+/)[0]);
  
        return matchedString.repeat(times);
      });
    }
  
    return extractedWord;
  };
  
  const compressedWords: string[] = require('fs')
    .readFileSync(0, 'utf-8')
    .trim()
    .split('\n');
  compressedWords.pop();
  
  let printer: string = '';
  
  compressedWords.forEach((compressedWord) => {
    printer += `${getExtractedWord(compressedWord)}\n`;
  });
  
  console.log(printer);
  