const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ');
let num = input[0].split('').map((x) => parseInt(x));
const five = parseInt(input[1]);
let first = true;

if (num.length < five) {
    num = '5'.repeat(five);
    num = num.split('').map((x) => parseInt(x));
    first = false;
}

while (true) {
    let f = 0;
    let c = 0;
    let cStart = false;
    for (let i = 0; i < num.length; i++) {
        if (num[i] === 5) {
            f++;
            cStart = true;
        }
        if (num[i] < 5) {
            cStart = true;
        }
        if (cStart === true) c++;
        if (f === five) break;
    }
    if (c < five) {
        carry(0);
        first = false;
        continue;
    }
    else {
        if (first) {
            carry(num.length - 1);
            first = false;
            continue;
        }
        let fail = false;
        f = five - f;
        for (let i = num.length - 1; i >= 0; i--) {
            if (f === 0) break;
            if (num[i] <= 5) {
                if (num[i] !== 5) {
                    num[i] = 5;
                    f--;
                }
            }
            else if (num[i] > 5) {
                carry(i);
                fail = true;
                break;
            }
        }
        if (fail === false) break;
    }

    function carry(digit) {
        for (let d = digit; d >= 0; d--) {
            num[d]++;
            if (num[d] === 10) {
                num[d] = 0;
                if (d === 0) num.unshift(1);
                else continue;
            }
            for (let e = d + 1; e < num.length; e++) {
                num[e] = 0;
            }
            break;
        }
    }
}

console.log(num.join(''));