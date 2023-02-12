const getAngle = (hour, minute) => {
  const hourAngle = hour % 12 * 300 + minute * 5;
  const minuteAngle = minute * 60;
  const gap = Math.abs(hourAngle - minuteAngle);
  
  return Math.min(gap, 3600 - gap);
}

const angleSort = (timeA, timeB) => {
  const [timeAHour, timeAMinute] = timeA.split(':').map(Number);
  const [timeBHour, timeBMinute] = timeB.split(':').map(Number);
  const timeAAngle = getAngle(timeAHour, timeAMinute);
  const timeBAngle = getAngle(timeBHour, timeBMinute);
  
  if (timeAAngle !== timeBAngle) {
    return timeAAngle - timeBAngle;
  }
  
  return timeAHour === timeBHour ? timeAMinute - timeBMinute : timeAHour - timeBHour;
}

const [, ...input] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');
  
let printer = '';
  
input.forEach(testcase => {
  const times = testcase.split(' ');
  times.sort(angleSort);
  printer += times[2] + '\n';
});

console.log(printer);