const [_, ...files] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map((file) => file.split('\\'));

const addWord = (curId, word) => {
  const candidateIds = graph[curId];

  for (let i = 0; i < candidateIds.length; i++) {
    if (db[candidateIds[i]] === word) {
      return candidateIds[i];
    }
  }

  id += 1;

  graph[curId].push(id);
  graph.push([]);
  db[id] = word;

  return id;
};

const traverse = (curId, depth) => {
  if (curId !== 0) {
    printer += `${' '.repeat(depth)}${db[curId]}\n`;
  }

  graph[curId].sort((a, b) => db[a] < db[b] ? -1 : 1);

  for (let i = 0; i < graph[curId].length; i++) {
    traverse(graph[curId][i], depth + 1);
  }
}

let id = 0;
const graph = [[]];
const db = {};
let printer = '';

files.forEach((file) => {
  let prevId = 0;

  for (let i = 0; i < file.length; i++) {
    let curId = addWord(prevId, file[i]);
    prevId = curId;
  }
});

traverse(0, -1);

console.log(printer);
