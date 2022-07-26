const [kind, len, _] =
    require('fs').readFileSync('/dev/stdin').
        toString().trim().split('\n')[0].split(' ').map((x) => parseInt(x));

const alphabet = 'aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz';
let printer = '';
let index = 0;

for (let i = 0; i < len; i++) {
    printer += alphabet[index];
    index = (index + 1) % (kind * 2);
}

console.log(printer);