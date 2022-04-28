let input = require('fs').readFileSync('/dev/stdin').toString().trim();
let db = {
    'ZERO': 0, 0: 'ZERO', 'ONE': 1, 1: 'ONE', 'TWO': 2, 2: 'TWO', 'THREE': 3, 3: 'THREE',
    'FOUR': 4, 4: 'FOUR', 'FIVE': 5, 5: 'FIVE', 'SIX': 6, 6: 'SIX', 'SEVEN': 7, 7: 'SEVEN',
    'EIGHT': 8, 8: 'EIGHT', 'NINE': 9, 9: 'NINE', '-': '-'
}

input = input.replace(/ZERO|ONE|TWO|THREE|FOUR|FIVE|SIX|SEVEN|EIGHT|NINE|TEN|[+/x-]{2,}|[+/x-]=/g, (matched) => {
    let found = db[matched];
    if (found === undefined)
        return '!';
    else
        return db[matched];
});

if (input.match(/[^0-9x+/=-]/))
    console.log('Madness!')
else {
    console.log(input);
    input = input.match(/[0-9]+|[+x/=-]/g);
    let left = parseInt(input[0]), right;

    for (let i = 1; i < input.length - 1; i += 2) {
        let opr = input[i];
        right = parseInt(input[i + 1]);

        switch (opr) {
            case '+': left += right; break;
            case '-': left -= right; break;
            case 'x': left *= right; break;
            case '/': left =
                (left / right >= 0) ?
                    Math.floor(left / right) : Math.ceil(left / right); break;
        }
    }

    left = left.toString().split('');

    let result = '';
    for (let i = 0; i < left.length; i++) {
        result += db[left[i]];
    }

    console.log(result);
}