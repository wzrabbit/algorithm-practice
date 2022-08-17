function numToTime(num) {
    if (num >= 1440) num -= 1440;
    if (num < 0) num += 1440;

    let h = Math.floor(num / 60).toString();
    if (h.length === 1) h = '0' + h;

    let m = Math.floor(num % 60).toString();
    if (m.length === 1) m = '0' + m;

    return h + ':' + m;
}

function calculateTime(mode, startTime, endTime) {
    let time;

    if (startTime <= endTime)
        time = endTime - startTime;
    else
        time = 1440 - startTime + endTime;

    if (mode === 'event')
        time++;
    else
        time--;

    return time;
}

const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [sleepTime, limit] = input[0].split(' ').map((x) => parseInt(x) * 60);
let raw = [];
let event = [];
let schedule = [];

for (let j = 2; j < input.length; j++) {
    raw.push(input[j].split('-').map((x) => {
        const [h, m] = x.split(':').map((y) => parseInt(y));
        return h * 60 + m;
    }));
}

raw.sort((a, b) => a[0] - b[0]);

for (let i = 0; i < 3; i++) {
    for (let j = 0; j < raw.length; j++) {
        event.push(raw[j]);
    }
}

for (let i = 0; i < event.length - 1; i++) {
    schedule.push({
        type: 'event',
        len: calculateTime('event', event[i][0], event[i][1]),
        text: numToTime(event[i][0]) + '-' + numToTime(event[i][1])
    });

    schedule.push({
        type: 'sleep',
        len: calculateTime('sleep', event[i][1], event[i + 1][0]),
        text: numToTime(event[i][1] + 1) + '-' + numToTime(event[i + 1][0] - 1)
    });
}

let sleepSet = new Set();
let maxAwakeTime = 0;
let curAwakeTime = 0;
for (let i = 0; i < schedule.length; i++) {
    if (schedule[i].type === 'event' || (schedule[i].type === 'sleep' && schedule[i].len < sleepTime)) {
        curAwakeTime += schedule[i].len;
        maxAwakeTime = Math.max(maxAwakeTime, curAwakeTime);
    }
    else {
        curAwakeTime = 0;
        sleepSet.add(schedule[i].text);
    }
}

if (maxAwakeTime > limit)
    console.log('No');
else {
    resultTime = [...sleepSet];
    console.log('Yes');
    console.log(resultTime.length);

    for (let i = 0; i < resultTime.length; i++)
        console.log(resultTime[i]);
}