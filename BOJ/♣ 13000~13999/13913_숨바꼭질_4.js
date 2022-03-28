const [start, end] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((x) => parseInt(x));
let visited = Array(100001).fill(false);
let index = 0;
let queue = [[start, 0]];
bfs();

// start보다 end가 더 크거나 같을 경우: 역추적
if (start <= end) {
    queue = queue.slice(0, index);
    let [lastData, lastTime] = queue[queue.length - 1];
    let history = [lastData];

    if (lastTime === 0) {
        history = [history[history.length - 1]];
        lastTime = -1;
    }

    let trackIndex = lastTime - 1;
    for (let i = queue.length - 1; i >= 0; i--) {
        let l = history[history.length - 1];
        if ([l - 1, l + 1, l / 2].includes(queue[i][0]) && queue[i][1] === trackIndex) {
            history.push(queue[i][0]);
            trackIndex--;
            if (trackIndex === -1) break;
        }
    }
    console.log(history.reverse().join(' '));
}

// start보다 end가 더 작을 경우, 무조건 1씩 낮추는 방법 뿐이므로 for문
// (역추적 방식으로 하면 시간 초과)
else {
    let result = '';
    for (let i = start; i >= end; i--) {
        result += i + ' ';
    }
    console.log(result);
}

function bfs() {
    visited[start] = true;
    while (queue.length !== index) {
        const [location, time] = queue[index];
        index++;
        if (location === end) {
            console.log(time);
            return;
        }
        if (location < 100000 && visited[location + 1] === false) {
            visited[location + 1] = true;
            queue.push([location + 1, time + 1]);
        }
        if (location <= 50000 && visited[location * 2] === false) {
            visited[location * 2] = true;
            queue.push([location * 2, time + 1]);
        }
        if (location > 0 && visited[location - 1] === false) {
            visited[location - 1] = true;
            queue.push([location - 1, time + 1]);
        }
    }
}