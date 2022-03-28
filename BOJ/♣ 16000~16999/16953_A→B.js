let [start, end] = require("fs").readFileSync("/dev/stdin").toString().trim().split(' ').map(Number);
let count = 0;
while (isNaN(end) === false && start !== end && ![3, 5, 7, 9].includes(end % 10)) {
    if (end % 10 === 1) end = parseInt(end.toString().slice(0, -1));
    else end /= 2;
    count++;
}

if (isNaN(end) || ([3, 5, 7, 9].includes(end % 10) && start !== end)) console.log(-1);
else console.log(count + 1);