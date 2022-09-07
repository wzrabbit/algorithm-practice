const [T, ...input] = require('fs').readFileSync(0, 'utf-8')
    .toString().trim().split('\n').map(x => parseInt(x));
let printer = '';

for (let t = 0; t < T; t++) {
    const num = input[t];
    if (num === 1)
        printer += 'IMPOSSIBLE';
    else {
        let beforeSum = 1;
        let success = false;

        for (let i = 2; i <= 50000; i++) {
            beforeSum += i;
            const remain = num - beforeSum;

            if (remain >= 0 && remain % i === 0) {
                const plus = remain / i;
                printer += num + ' = ';
                for (let j = 1; j <= i; j++) {
                    printer += j + plus;
                    if (j !== i) printer += ' + ';
                }

                success = true;
                break;
            }
        }

        if (!success)
            printer += 'IMPOSSIBLE';
    }

    printer += '\n';
}

console.log(printer);