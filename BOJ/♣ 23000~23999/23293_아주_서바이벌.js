const [TN, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [_, N] = TN.split(' ').map(Number);
const logs = input.map((line) => {
  const [no, playerNo, code, info, info2] = line.split(' ');

  return [Number(no), Number(playerNo), code, Number(info), info2 ? Number(info2) : null];
});

const players = Array.from({ length: N + 1 }).map(() => ({
  position: 1,
  items: {},
}));
const wrongLogNos = [];
const cheaters = new Set();

const editItemCount = (playerNo, info, value) => {
  if (!players[playerNo].items[info]) {
    players[playerNo].items[info] = 0;
  }

  players[playerNo].items[info] += value;

  if (players[playerNo].items[info] < 0) {
    players[playerNo].items[info] = 0;
    return false;
  }

  return true;
};

const move = (playerNo, info) => {
  players[playerNo].position = info;
}

const farm = (no, playerNo, info) => {
  if (players[playerNo].position !== info) {
    wrongLogNos.push(no);
  }

  editItemCount(playerNo, info, 1);
};

const craft = (no, playerNo, info, info2) => {
  const firstValid = editItemCount(playerNo, info, -1);
  const secondValid = editItemCount(playerNo, info2, -1);

  if (!firstValid || !secondValid) {
    wrongLogNos.push(no);
  }
}

const attack = (no, playerNo, info) => {
  if (players[playerNo].position !== players[info].position) {
    wrongLogNos.push(no);
    cheaters.add(playerNo);
  }
}

logs.forEach((log) => {
  const [no, playerNo, code, info, info2] = log;

  switch (code) {
    case 'M':
      move(playerNo, info);
      break;
    case 'F':
      farm(no, playerNo, info);
      break;
    case 'C':
      craft(no, playerNo, info, info2);
      break;
    case 'A':
      attack(no, playerNo, info);
      break;
  }
});

console.log(wrongLogNos.length);

if (wrongLogNos.length > 0) {
  console.log(wrongLogNos.join(' '));
}

console.log(cheaters.size);

if (cheaters.size > 0) {
  console.log([...cheaters].sort((a, b) => a - b).join(' '));
}