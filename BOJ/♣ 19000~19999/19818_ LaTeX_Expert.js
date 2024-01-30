const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim();

const cites = input.match(/(?<=\\cite{).*?(?=})/g);
const bibItemLines = input.match(/\\bibitem.*/g);
const items = [];
const descriptions = {};

bibItemLines.forEach((bibItemLine) => {
  const matchedItem = bibItemLine.match(/(?<=\\bibitem{).*?(?=})/)[0];
  const matchedDescription = bibItemLine.match(/(?<=}).*/)[0];

  items.push(matchedItem);
  descriptions[matchedItem] = matchedDescription;
});

let isCorrect = true;

for (let i = 0; i < cites.length; i++) {
  if (cites[i] !== items[i]) {
    isCorrect = false;
    break;
  }
}

if (isCorrect) {
  console.log('Correct');
  return;
}

console.log(`Incorrect
\\begin{thebibliography}{99}
${cites.map((cite) => `\\bibitem{${cite}}${descriptions[cite]}`).join('\n')}
\\end{thebibliography}`);
