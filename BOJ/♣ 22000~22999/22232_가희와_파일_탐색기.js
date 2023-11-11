const sortFiles = (a, b) => {
  const [aName, aExt] = a.split('.');
  const [bName, bExt] = b.split('.');

  if (aName !== bName) {
    return aName < bName ? -1 : 1;
  }

  if (gahuiExtensions.has(aExt) && !gahuiExtensions.has(bExt)) {
    return -1;
  }

  if (!gahuiExtensions.has(aExt) && gahuiExtensions.has(bExt)) {
    return 1;
  }

  return aExt < bExt ? -1 : 1;
};

const input = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');

const [N, M] = input[0].split(' ').map(Number);
const files = input.slice(1, N + 1);
const gahuiExtensions = new Set(input.slice(N + 1, N + M + 1));

files.sort(sortFiles);

console.log(files.join('\n'));
