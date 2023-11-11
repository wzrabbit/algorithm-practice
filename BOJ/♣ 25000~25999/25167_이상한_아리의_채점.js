const timeToNumber = (time) => {
  const [hh, mm] = time.split(':').map(Number);

  return hh * 60 + mm;
};

const STATE = {
  'NO_RESULT': 0,
  'WRONG_ANSWER': 1,
  'ACCEPTED': 2,
  'CHEATED': -1,
};

const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);
const participants = input[1].split(' ');
const histories = input.slice(2).map((history) => {
  const [problemNo, time, participant, verdict] = history.split(' ');

  return [Number(problemNo), timeToNumber(time), participant, verdict];
});

const infos = {};

participants.forEach((participant) => {
  infos[participant] = {
    firstTime: Array.from({ length: N + 1 }).map(() => -1),
    acceptTime: Array.from({ length: N + 1 }).map(() => -1),
    state: Array.from({ length: N + 1 }).map(() => STATE.NO_RESULT),
  };
});

histories.forEach((history) => {
  const [problemNo, time, participant, verdict] = history;

  if (verdict === 'solve') {
    if (infos[participant].state[problemNo] === STATE.NO_RESULT) {
      infos[participant].state[problemNo] = STATE.CHEATED;
    }

    if (infos[participant].state[problemNo] === STATE.WRONG_ANSWER) {
      infos[participant].state[problemNo] = STATE.ACCEPTED;
      infos[participant].acceptTime[problemNo] = time;
    }
  } else {
    if (infos[participant].state[problemNo] === STATE.NO_RESULT) {
      infos[participant].state[problemNo] = STATE.WRONG_ANSWER;
      infos[participant].firstTime[problemNo] = time;
    }
  }
});

const scores = {};

participants.forEach((participant) => {
  scores[participant] = 0;
});

for (let i = 1; i <= N; i++) {
  const problemResults = [];

  participants.forEach((participant) => {
    if (infos[participant].state[i] === STATE.WRONG_ANSWER) {
      scores[participant] += M;
    } else if (infos[participant].state[i] === STATE.ACCEPTED) {
      const timeGap = infos[participant].acceptTime[i] - infos[participant].firstTime[i];
      problemResults.push([participant, timeGap]);
    } else {
      scores[participant] += M + 1;
    }
  });

  problemResults.sort((a, b) => {
    if (a[1] !== b[1]) {
      return a[1] - b[1];
    }

    return a[0] < b[0] ? -1 : 1;
  });

  problemResults.forEach(([participant], index) => {
    scores[participant] += index + 1;
  });
}

const ranks = [...Object.entries(scores)].sort((a, b) => {
  if (a[1] !== b[1]) {
    return a[1] - b[1];
  }

  return a[0] < b[0] ? -1 : 1;
});

let answer = '';

ranks.forEach(([player]) => {
  answer += `${player}\n`;
});

console.log(answer);
