// #Make_Great_Calculator_Using_Regex

function sqrt(num) {
    let start = 0n;
    let end = num;
    let mid;

    while (start < end) {
        mid = (start + end) / 2n;
        if ((start + end) % 2n === 1n)
            mid++;

        if (mid * mid <= num)
            start = mid;
        else
            end = mid - 1n;
    }

    return end;
}

function getLastIndex(string, regex) {
    const reversed = string.split('').reverse().join('');
    const execResult = regex.exec(reversed);
    const len = execResult[0].length;
    const idx = execResult.index;

    return string.length - len - idx;
}

function calculate(exp) {
    // ()
    while (exp.includes('(')) {
        exp = exp.replace(/\([^()]*?\)/, (x) => {
            return calculate(x.slice(1, x.length - 1))
        });
    }

    // #
    while (exp.includes('#')) {
        const regex = /#\d+/;
        const reversedRegex = /\d+#/;
        const div = getLastIndex(exp, reversedRegex);

        exp = exp.slice(0, div) + exp.slice(div).replace(regex, (x) => {
            return sqrt(BigInt(x.replace('#', '')));
        });
    }

    // ^
    while (exp.includes('^')) {
        const regex = /(\[-)?\d+]?\^\d+/;
        const reversedRegex = /\d+\^]?\d+(-\[)?/;
        const div = getLastIndex(exp, reversedRegex);

        exp = exp.slice(0, div) + exp.slice(div).replace(regex, (x) => {
            const [left, right] = x.replace(/[[\]]/g, '').split('^').map((x) => BigInt(x));

            let result = left ** right;
            if (result < 0n)
                result = '[' + result.toString() + ']';
            result = result.toString();

            return result;
        });
    }

    // *, /
    while (/[*\/]/.test(exp)) {
        exp = exp.replace(/(\[-)?\d+]?(\*|\/)(\[-)?\d+]?/, (x) => {
            const div = x.includes('*') ? '*' : '/';
            let [left, right] = x.split(div).map((y) => BigInt(y.replace(/[[\]]/g, '')));

            let result = ((div === '*') ? left * right : left / right);
            if (result < 0n)
                result = '[' + result.toString() + ']';
            result = result.toString();

            return result;
        });
    }

    // +, -
    while (/[+-]/.test(exp.replace(/\[.+?\]/g, ''))) {
        exp = exp.replace(/(\[-)?\d+]?(\+|-)(\[-)?\d+]?/, (x) => {
            x = x.replace(/\[-/g, '~').replace(/]/g, '');
            const div = x.includes('+') ? '+' : '-';
            let [left, right] = x.split(div).map((y) => BigInt(y.replace('~', '-')));

            let result = ((div === '+') ? left + right : left - right).toString();
            if (result < 0n)
                result = '[' + result + ']';

            return result;
        });
    }

    return exp;
}

let exp = require('fs').readFileSync('/dev/stdin').toString().trim().replace('=', '');
console.log(calculate(exp).replace(/[[\]]/g, ''));