let input = require('fs').readFileSync(0, 'utf-8').toString().replace('\n', '');
const SMALL_A_CHARCODE = 97;
const LARGE_A_CHARCODE = 65;
const SHIFT_LENGTH = 13;
const CYCLE = 26;

input = input.replace(/[A-z]/g, (letter) => {
    if (letter.charCodeAt() >= SMALL_A_CHARCODE) {
        const convertedLetter =
            String.fromCharCode(
                (letter.charCodeAt() - SMALL_A_CHARCODE + SHIFT_LENGTH)
                % CYCLE + SMALL_A_CHARCODE);
        return convertedLetter;
    }

    const convertedLetter =
        String.fromCharCode(
            (letter.charCodeAt() - LARGE_A_CHARCODE + SHIFT_LENGTH)
            % CYCLE + LARGE_A_CHARCODE);
    return convertedLetter;
});

console.log(input);
