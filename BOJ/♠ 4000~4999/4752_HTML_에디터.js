const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
input.pop();
let result = '';

for (let i = 0; i < input.length; i++) {
  let spliter = input[i].split(' ');
  const start = parseInt(spliter.shift());
  const end = parseInt(spliter.shift());
  let word = spliter.join(' ');
  let left = word.slice(0, start);
  let mid = word.slice(start, end);
  let right = word.slice(end, word.length);
  let resultLeft = resultRight = '';

  left = left.replace(/<([a-zA-Z0-9-]+)>.*<\/\1>/g, '');
  right = right.replace(/<([a-zA-Z0-9-]+)>.*<\/\1>/g, '');
  left = left.replace(/<[a-zA-z0-9-]+>/g, (tag) => {
    resultLeft += tag;
    return '';
  });
  right = right.replace(/<\/[a-zA-z0-9-]+>/g, (tag) => {
    resultRight += tag;
    return '';
  });

  result += resultLeft + mid + resultRight + '\n';
}

console.log(result);