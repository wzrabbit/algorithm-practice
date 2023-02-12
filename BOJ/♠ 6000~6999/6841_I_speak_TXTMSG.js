const emojiConverter = {
    'CU': 'see you',
    ':-)': 'I’m happy',
    ':-(': 'I’m unhappy',
    ';-)': 'wink',
    ':-P': 'stick out my tongue',
    '(~.~)': 'sleepy',
    'TA': 'totally awesome',
    'CCC': 'Canadian Computing Competition',
    'CUZ': 'because',
    'TY': 'thank-you',
    'YW': 'you’re welcome',
    'TTYL': 'talk to you later',
};

const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
let printer = '';

input.forEach(emoji => {
    printer += (emojiConverter[emoji] || emoji) + '\n';
});

console.log(printer);