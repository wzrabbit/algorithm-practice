let [n, ...input] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
n = parseInt(n);
let [l, r] = [0, n - 1];
let printer = '';

function getPriority(l, r) {
    while (l <= r) {
        if (input[l] > input[r])
            return 'R';
        else if (input[l] < input[r])
            return 'L';

        l++;
        r--;
    }

    return 'L';
}

while (l <= r) {
    if (input[l] > input[r]) {
        printer += input[r];
        r--;
    }
    else if (input[l] < input[r]) {
        printer += input[l];
        l++;
    }
    else {
        if (getPriority(l, r) === 'L') {
            printer += input[l];
            l++;
        }
        else {
            printer += input[r];
            r--;
        }
    }
}

printer = printer.match(/.{1,80}/g).join('\n');
console.log(printer);