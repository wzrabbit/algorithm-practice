const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let [limit, interval, cases] = input[0].split(' ').map(Number);
let [indexL, indexR] = [0, 0];
let left = [];
let right = [];
let boat = 'left';
let time = 0;
let people = new Array(cases);

input.shift();
for (let i = 0; i < cases; i++) {
  input[i] = input[i].split(' ');
  input[i][0] = parseInt(input[i][0]);
}

for (let i = 0; i < cases; i++) {
  input[i][1] = input[i][1].replace('\r', '');
  if (input[i][1] === 'left') left.push([input[i][0], i]);
  else right.push([input[i][0], i]);
}

left.sort((a, b) => a[0] - b[0]);
right.sort((a, b) => a[0] - b[0]);

let counter = 0;
while (indexL < left.length || indexR < right.length) {
  if (counter > 150000) while (true) {console.log('fail')};
  counter++;
  if (boat === 'left') {
    if (indexL >= left.length || left[indexL][0] > time) {
      if (indexL >= left.length || (indexR < right.length && left[indexL][0] > right[indexR][0])) {
        boat = 'right';
        time = Math.max(right[indexR][0] + interval, time + interval);
        continue;
      }
      else {
        time = left[indexL][0];
        continue;
      }
    }
    else {
      for (let i = 1; i <= limit; i++) {
        if (indexL >= left.length || left[indexL][0] > time) break;
        let currentIndex = left[indexL][1];
        people[currentIndex] = time + interval;
        indexL++;
      }
      time += interval;
      boat = 'right';
    }
  }
  else {
    if (indexR >= right.length || right[indexR][0] > time) {
      if (indexR >= right.length || (indexL < left.length && right[indexR][0] > left[indexL][0])) {
        boat = 'left';
        time = Math.max(left[indexL][0] + interval, time + interval);
        continue;
      }
      else {
        time = right[indexR][0];
        continue;
      }
    }
    else {
      for (let i = 1; i <= limit; i++) {
        if (indexR >= right.length || right[indexR][0] > time) break;
        let currentIndex = right[indexR][1];
        people[currentIndex] = time + interval;
        indexR++;
      }
      boat = 'left';
      time += interval;
    }
  }
}
console.log(people.join('\n'));