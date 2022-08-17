function numToTime(num) {
    if (num < 0) num += 86400;

    let hour = Math.floor(num / 3600).toString();
    let minute = (Math.floor(num / 60) % 60).toString();
    let second = Math.floor(num % 60).toString();

    if (hour.length === 1) hour = '0' + hour;
    if (minute.length === 1) minute = '0' + minute;
    if (second.length === 1) second = '0' + second;

    return hour + ':' + minute + ':' + second;
}

function timeToNum(time) {
    const [hour, minute, second] = time.split(':').map((x) => parseInt(x));
    return hour * 3600 + minute * 60 + second;
}

const [before, after] = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

console.log(numToTime(timeToNum(after) - timeToNum(before)));
