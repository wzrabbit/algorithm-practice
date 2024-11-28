const HEXOMINO_FIGURES = [
  [
    '######',
  ],
  [
    '#####', 
    '#....'
  ],
  [
    '#####', 
    '.#...'
  ],
  [
    '#####', 
    '..#..'
  ],
  [
    '.####', 
    '##...'
  ],
  [
    '..###', 
    '###..'
  ],
  [
    '####', 
    '##..'
  ],
  [
    '####', 
    '#.#.'
  ],
  [
    '####', 
    '#..#'
  ],
  [
    '####', 
    '.##.'
  ],
  [
    '####', 
    '#...',
    '#...',
  ],
  [
    '####', 
    '.#..',
    '.#..',
  ],
  [
    '#...',
    '####',
    '#...',
  ],
  [
    '.#..',
    '####',
    '#...',
  ],
  [
    '..#.',
    '####',
    '#...',
  ],
  [
    '...#',
    '####',
    '#...',
  ],
  [
    '..#.',
    '####',
    '.#..',
  ],
  [
    '.#..',
    '####',
    '.#..',
  ],
  [
    '.###',
    '##..',
    '.#..',
  ],
  [
    '.###',
    '##.#',
  ],
  [
    '.###',
    '###.',
  ],
  [
    '.#..',
    '.###',
    '##..',
  ],
  [
    '..#.',
    '.###',
    '##..',
  ],
  [
    '.###',
    '.#..',
    '##..',
  ],
  [
    '.###',
    '##..',
    '#...',
  ],
  [
    '..##',
    '###.',
    '#...',
  ],
  [
    '..##',
    '.##.',
    '##..',
  ],
  [
    '###',
    '###',
  ],
  [
    '#..',
    '###',
    '##.',
  ],
  [
    '###',
    '#..',
    '##.',
  ],
  [
    '###',
    '.#.',
    '##.',
  ],
  [
    '##.',
    '.##',
    '##.',
  ],
  [
    '###',
    '.##',
    '..#',
  ],
  [
    '.##',
    '###',
    '.#.',
  ],
  [
    '.##',
    '.##',
    '##.',
  ],
];

const getRotatedFigure = (figure) => {
  let row = figure[0].length;
  let col = figure.length;
  const rotatedFigure = new Array(row).fill('');

  for (let r = 0; r < row; r++) {
    for (let c = 0; c < col; c++) {
      rotatedFigure[r] += figure[col - c - 1][r];
    }
  }

  return rotatedFigure;
};

const getFlippedFigure = (figure) => {
  return figure.map((row) => row.split('').reverse().join(''));
};

const getMaxScoreBySingleFigure = (figure) => {
  let row = figure.length;
  let col = figure[0].length;
  let maxScore = 0;

  for (let i = 0; i < R - row + 1; i++) {
    for (let j = 0; j < C - col + 1; j++) {
      let currentScore = 0;

      for (let r = 0; r < row; r++) {
        for (let c = 0; c < col; c++) {
          if (figure[r][c] === '#') {
            currentScore += grid[r + i][c + j];
          }
        }
      }

      maxScore = Math.max(maxScore, currentScore);
    }
  }

  return maxScore;
};

const getMaxScoreByFigure = (figure) => {
  let maxScore = 0;
  let currentFigure = figure.slice();

  for (let i = 0; i < 4; i++) {
    currentFigure = getRotatedFigure(currentFigure);
  
    maxScore = Math.max(
      maxScore,
      getMaxScoreBySingleFigure(currentFigure),
      getMaxScoreBySingleFigure(getFlippedFigure(currentFigure)),
    );
  }

  return maxScore;
};

const getMaxScore = () => {
  let maxScore = 0;

  HEXOMINO_FIGURES.forEach((figure) => {
    maxScore = Math.max(maxScore, getMaxScoreByFigure(figure));
  });

  return maxScore;
};

const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
const [R, C] = input[0].split(' ').map(Number);
const grid = input.slice(1).map((row) => row.split(' ').map(Number));

console.log(getMaxScore());
