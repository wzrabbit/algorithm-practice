const getSubjectInfoByInputIndex = (index) => {
  const subject = input[index];
  const day = input[index + 1].split(' ')[0];
  const time = Number(input[index + 1].split(' ')[1]) - 1;

  return { subject, day, time };
};

const formatSubject = (subject) => {
  let line = '';

  const subjectWords = subject.split(' ');
  let formattedSubject = '';

  subjectWords.forEach((word, index) => {
    if (line !== '') {
      line += ' ';
    }

    if ((`${line}${word}`).length > WORD_LENGTH_LIMIT) {
      formattedSubject += `${line.trim()}\n`;
      line = '';
    }

    line += word;

    if (index === subjectWords.length - 1) {
      formattedSubject += line;
    }
  });

  return formattedSubject;
};

const outputTable = (table) => {
  let output = `${COLUMN}\n`;

  table.forEach((line) => {
    const subjectArray = line.map((subject) => subject.split('\n'));

    const height = Math.max(
      1,
      subjectArray[0].length,
      subjectArray[1].length,
      subjectArray[2].length,
    );

    for (let r = 0; r < height; r++) {
      for (let c = 0; c < 3; c++) {
        output += '|';
        output += (subjectArray[c][r] ?? '').padEnd(WORD_LENGTH_LIMIT);
      }

      output += '|\n';
    }

    output += `${COLUMN}\n`;
  });

  console.log(output);
};

const INDEX_OF_THE_DAY = {
  'Tuesday': 0,
  'Thursday': 1,
  'Saturday': 2,
};

const WORD_LENGTH_LIMIT = 10;
const COLUMN = '+----------+----------+----------+';

const [_, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const table = Array.from({ length: 4 }).map(
  () => Array.from({ length: 3 }).fill('')
);

for (let i = 0; i < input.length; i += 2) {
  const { subject, day, time } = getSubjectInfoByInputIndex(i);
  const formattedSubject = formatSubject(subject);

  table[time][INDEX_OF_THE_DAY[day]] = formattedSubject;
}

outputTable(table);
