let num = require('fs').readFileSync(0, 'utf-8').toString().trim();
let cnt = 0;

while (parseInt(num) > 0) {
    if (num.indexOf('1') !== -1) {
        num = num.replace('1', '');
    }
    else {
        num = (parseInt(num) - 1).toString();
    }

    cnt++;
}

console.log(cnt);
