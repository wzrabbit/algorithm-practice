const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let cases = parseInt(input[0]) - 3;
let expression = input[1];
let combinationList = [[]];
let max = -9999999999;

for (let c = 0; c <= cases; c += 2) {
    for (let l = 1; l <= 5; l++) {
        getCombination(c, l, []);
    }
}
calculate();
console.log(max);

// 괄호가 들어가는 조합을 구한다
function getCombination(current, len, list) {
    list.push(current);

    if (list.length === len) {
        combinationList.push(list);
        return;
    }

    for (let i = current + 4; i <= cases; i += 2) {
        let newList = list.slice();
        getCombination(i, len, newList);
    }
}

// 위에서 구한 조합을 적용하고 나머지 수식을 연산한다
function calculate() {
    combinationList.forEach((eraser) => {
        let ex = expression.split('');
        for (let i = 0; i < ex.length; i++) {
            if (eraser.includes(i)) ex[i] = 'V' + ex[i];
        }
        ex = ex.join('');

        while (ex.includes('V')) {
            ex = ex.replace(/V.../g, (x) => {
                x = x.replace('V', '').split('');
                switch (x[1]) {
                    case '+': return parseInt(x[0]) + parseInt(x[2]);
                    case '-': return (parseInt(x[0]) - parseInt(x[2]) >= 0) ? parseInt(x[0]) - parseInt(x[2]) : '(' + (parseInt(x[0]) - parseInt(x[2])) + ')';
                    case '*': return parseInt(x[0]) * parseInt(x[2]);
                    case '/': return parseInt(x[0]) / parseInt(x[2]);
                }
            });
        }

        while (ex.replace(/\(.+?\)/g, '').match(/[-+*\/]/)) {
            ex = ex.replace(/^(\(.+?\)|\d+)[\/+*-](\(.+?\)|\d+)/, (x) => {
                x = x.replace(/(?<=\()-/g, 'A');
                x = x.replace(/[()]/g, '');
                let mode = x.match(/[\/+*-]/).toString();
                x = x.split(/[\/+*-]/);
                x[0] = x[0].replace(/A/g, '-');
                x[1] = x[1].replace(/A/g, '-');
                x[0] = parseInt(x[0]);
                x[1] = parseInt(x[1]);

                switch (mode) {
                    case '+': return (x[0] + x[1] >= 0) ? x[0] + x[1] : '(' + (x[0] + x[1]) + ')';
                    case '-': return (x[0] - x[1] >= 0) ? x[0] - x[1] : '(' + (x[0] - x[1]) + ')';
                    case '*': return (x[0] * x[1] >= 0) ? x[0] * x[1] : '(' + (x[0] * x[1]) + ')';
                    case '/': return (x[0] / x[1] >= 0) ? x[0] / x[1] : '(' + (x[0] / x[1]) + ')';
                }
            });
        }
        ex = parseInt(ex.replace(/[()]/g, ''));
        if (max < ex) max = ex;
    });
}