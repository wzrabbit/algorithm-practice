const input = require('fs').readFileSync('/dev/stdin').toString().trim();

function getOdds(num) {
    num = num.split('').map((x) => parseInt(x));
    let cnt = 0;
    for (let i = 0; i < num.length; i++) {
        if (num[i] % 2 === 1)
            cnt++;
    }
    return cnt;
}

function recursion(num) {
    if (num.length === 1) {
        let odd = getOdds(num);
        return { max: odd, min: odd };
    }

    if (num.length === 2) {
        const res = recursion((parseInt(num[0]) + parseInt(num[1])).toString());
        const odd = getOdds(num);
        return { max: res.max + odd, min: res.min + odd };
    }

    let max = 0;
    let min = 99999999;
    for (let i = 1; i <= num.length - 2; i++) {
        for (let j = i + 1; j <= num.length - 1; j++) {
            const a = num.slice(0, i);
            const b = num.slice(i, j);
            const c = num.slice(j, num.length);
            const res = recursion((parseInt(a) + parseInt(b) + parseInt(c)).toString());
            const odd = getOdds(num);

            const currentMax = res.max + odd;
            const currentMin = res.min + odd;

            if (currentMax > max)
                max = currentMax;
            if (currentMin < min)
                min = currentMin;
        }
    }

    return { max: max, min: min };
}

const result = recursion(input);
console.log(result.min, result.max);