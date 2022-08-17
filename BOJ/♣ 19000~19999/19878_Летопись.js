function check(day, month, year) {
    if (month > 12 || day > 31 || month === 0 || day === 0)
        return;

    let dayLimit;
    if (year % 4 === 0 && year !== 0 && month === 2)
        dayLimit = 29;
    else if (month === 2)
        dayLimit = 28;
    else if ([1, 3, 5, 7, 8, 10, 12].includes(month))
        dayLimit = 31;
    else
        dayLimit = 30;

    if (day > dayLimit)
        return;

    set.add(
        ((day <= 9) ? '0' + day : day) + '/'
        + ((month <= 9) ? '0' + month : month) + '/'
        + ((year <= 9) ? '0' + year : year));
}

const [A, B, C] = require('fs').readFileSync(0, 'utf-8')
    .toString().trim().split('/').map((x) => parseInt(x));
let set = new Set();

check(A, B, C);
check(A, C, B);
check(B, A, C);
check(B, C, A);
check(C, A, B);
check(C, B, A);

if (set.size === 0)
    console.log('No such date');
else
    console.log([...set].join('\n'));