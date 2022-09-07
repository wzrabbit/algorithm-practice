const cut = interval => {
    let start = L;
    let chance = C;
    let first;

    for (let i = K; i >= 1; i--) {
        if (start - location[i] > interval)
            return false;

        if (start - location[i - 1] > interval) {
            if (chance === 0)
                return false;

            if (chance === 1)
                first = location[i];

            chance--;
            start = location[i];
        }
    }

    if (location[1] > interval)
        return false;

    if (chance > 0)
        first = location[1];

    if (interval < answer.interval || interval === answer.interval && first < answer.first) {
        answer.interval = interval;
        answer.first = first;
    }

    return true;
};

let [LKC, location] = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
const [L, K, C] = LKC.split(' ').map((x) => parseInt(x));
const INF = 1000000001;
location = location.split(' ').map((x) => parseInt(x));
location.push(0);
location.sort((a, b) => a - b);
answer = { interval: INF, first: INF };

let l = 1;
let r = INF;
let mid;
while (l <= r) {
    mid = Math.floor((l + r) / 2);
    if (cut(mid))
        r = mid - 1;
    else
        l = mid + 1;
}

console.log(answer.interval, answer.first);