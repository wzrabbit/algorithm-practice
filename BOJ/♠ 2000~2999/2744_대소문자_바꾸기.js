let text = require('fs').readFileSync('/dev/stdin').toString().trim();

text = text.replace(/\w/g, (char) => {
    if (char.toLowerCase() === char)
        return char.toUpperCase();
    else
        return char.toLowerCase();
});

console.log(text);