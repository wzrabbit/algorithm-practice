const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let width = parseInt(input[0]);
let sea = input.slice(1);
for (let i = 0; i < sea.length; i++) {
    sea[i] = sea[i].split(' ').map(Number);
}
let visitedSample = sea.map((x) => {
    return x.slice().fill('□');
});
let sharkR, sharkC;
let time = 0;
let size = 2;
let exp = 0;
let sos = false;

while (sos === false) {
    if (getEatableFish() > 0) {
        bfs(sharkR, sharkC, visitedSample);
    }
    else sos = true;
}

console.log(time);

// 1. 먹을 수 있는 물고기가 얼마나 있는지 검사, 상어 위치 조사
function getEatableFish() {
    let count = 0;
    for (let r = 0; r < width; r++) {
        for (let c = 0; c < width; c++) {
            let fish = sea[r][c];
            if (fish !== 0 && fish !== 9 && fish < size) count++;
            if (fish === 9) [sharkR, sharkC] = [r, c];
        }
    }
    return count;
}

// 2. 물고기 탐색
function bfs(startR, startC, v) {
    let visited = v.map((x) => x.slice());
    let queue = [[startR, startC, 0]];
    let foundFish = false;
    // 물고기를 찾은 경우에는 더 이상 더 거리가 먼 물고기를 탐색하지 않는다
    let sortMode = 999;
    let foundList = [];

    while (queue.length > 0) {
        let [r, c, t] = queue.shift();
        if (sea[r][c] != 0 && sea[r][c] != 9 && sea[r][c] < size && (sortMode === 999 || sortMode === t)) {
            if (sortMode === 999) {
                sortMode = t;
                foundFish = true;
            }
            foundList.push([r, c]);
        }
        // 먹이를 찾았을 경우, 먹이를 먹고 size 증가, 시간 계산

        // 먹이를 찾지 못 했을 경우, 다른 먹이 탐색
        if (r > 0 && visited[r - 1][c] === '□' && (sea[r - 1][c] === 0 || sea[r - 1][c] <= size) && (t + 1 === sortMode || sortMode === 999)) {
            visited[r - 1][c] = '■';
            queue.push([r - 1, c, t + 1]);
        }
        if (c > 0 && visited[r][c - 1] === '□' && (sea[r][c - 1] === 0 || sea[r][c - 1] <= size) && (t + 1 === sortMode || sortMode === 999)) {
            visited[r][c - 1] = '■';
            queue.push([r, c - 1, t + 1]);
        }
        if (c < width - 1 && visited[r][c + 1] === '□' && (sea[r][c + 1] === 0 || sea[r][c + 1] <= size) && (t + 1 === sortMode || sortMode === 999)) {
            visited[r][c + 1] = '■';
            queue.push([r, c + 1, t + 1]);
        }
        if (r < width - 1 && visited[r + 1][c] === '□' && (sea[r + 1][c] === 0 || sea[r + 1][c] <= size) && (t + 1 === sortMode || sortMode === 999)) {
            visited[r + 1][c] = '■';
            queue.push([r + 1, c, t + 1]);
        }
    }

    if (foundFish) {
        // 찾은 물고기들을 우선순위(상, 좌)에 따라 정렬
        foundList.sort((a, b) => {
            const [r1, c1] = a;
            const [r2, c2] = b;
            if (r1 > r2) return 1;
            else if (r1 < r2) return -1;
            if (c1 > c2) return 1;
            else if (c1 < c2) return -1;
        });
        const [selectR, selectC] = foundList[0];
        sea[selectR][selectC] = 9;
        sea[sharkR][sharkC] = 0;
        time += sortMode;

        exp++;
        if (exp >= size) {
            exp = 0;
            size++;
        }
    }
    else sos = true;
}