const input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('');
const zero = input.filter(x => x == '0').length;
const one = input.length - zero;

if (zero > one) {
    console.log('1'.repeat(input.length));
}
else if (zero < one) {
    console.log('0'.repeat(input.length));
}
else {
    if (input[0] === '0') {
        console.log('1' + '0'.repeat(input.length - 1));
    }
    else {
        console.log('0' + '1'.repeat(input.length - 1));
    }
}