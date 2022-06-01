const num = require('fs').readFileSync('/dev/stdin').toString().trim().split('').map((x) => parseInt(x));
let success = true;

if (num.length > 2) {
    const d = num[0] - num[1];

    for (let i = 1; i < num.length - 1; i++) {
        if (num[i] - num[i + 1] !== d) {
            success = false;
            break;
        }
    }
}

if (success)
    console.log('◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!');
else
    console.log('흥칫뿡!! <(￣ ﹌ ￣)>');