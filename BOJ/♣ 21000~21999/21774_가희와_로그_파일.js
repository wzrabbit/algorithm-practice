const [num, ...raw] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [n, m] = num.split(' ').map((x) => parseInt(x));
let data = [['1999-12-31 23:59:59', 0, 0, 0, 0, 0, 0]];
let printer = '';

const startBinarySearch = (date, logNo) => {
    logNo = parseInt(logNo);
    let start = 0, end = data.length - 1, mid;
    while (start < end) {
        mid = Math.ceil((start + end) / 2);
        if (date <= data[mid][0]) end = mid - 1;
        else start = mid;
    }
    return data[end][logNo];
}

const endBinarySearch = (date, logNo) => {
    logNo = parseInt(logNo);
    let start = 0, end = data.length - 1, mid;
    while (start < end) {
        mid = Math.ceil((start + end) / 2);
        if (date < data[mid][0]) end = mid - 1;
        else start = mid;
    }
    return data[end][logNo];
}

for (let i = 0; i < n; i++) {
    let currentData = raw[i].split('#');
    data.push(data[data.length - 1].slice());
    data[data.length - 1][0] = currentData[0];
    for (let j = 1; j <= parseInt(currentData[1]); j++) {
        data[data.length - 1][j]++;
    }
}

for (let i = n; i < n + m; i++) {
    let [start, end, logLevel] = raw[i].split('#');
    printer += (endBinarySearch(end, logLevel) - startBinarySearch(start, logLevel)) + '\n';
}

console.log(printer);