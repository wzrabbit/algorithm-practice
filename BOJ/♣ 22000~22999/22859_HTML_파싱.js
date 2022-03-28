const input = require('fs').readFileSync('/dev/stdin').toString().trim();
let result = '';

let parsed = input.match(/<div title=".*?">|<p>.*?<\/p>/g);

parsed.forEach((frag) => {
    if (frag.startsWith('<div')) {
        result += 'title : ' + frag.match(/(?<=title=").*(?=")/) + '\n';
    }
    else {
        result += frag.replace(/<.*?>|<\/.*?>/g, '').replace(/ {2,}/g, ' ') + '\n';
    }
});

console.log(result);