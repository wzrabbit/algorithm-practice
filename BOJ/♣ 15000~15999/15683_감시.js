const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [row, col] = input[0].split(' ').map(Number);
let visited = new Array(row * col).fill(false);
let sampleGraph = [];
let camera = [];
let location = [];
let min = 99;

// 1. 탐색에 사용할 샘플 그래프 생성
for (let i = 1; i < input.length; i++) sampleGraph.push(input[i].split(' ').map(Number));

// 2. 감시 카메라 조사
for (let r = 0; r < row; r++) {
    for (let c = 0; c < col; c++) {
        if (sampleGraph[r][c] >= 1 && sampleGraph[r][c] <= 5) {
            location.push([r, c]);
            switch (sampleGraph[r][c]) {
                case 1: camera.push([['U'], ['D'], ['L'], ['R']]); break;
                case 2: camera.push([['U', 'D'], ['L', 'R']]); break;
                case 3: camera.push([['U', 'R'], ['R', 'D'], ['D', 'L'], ['L', 'U']]); break;
                case 4: camera.push([['U', 'R', 'D'], ['R', 'D', 'L'], ['D', 'L', 'U'], ['L', 'U', 'R']]); break;
                case 5: camera.push([['U', 'R', 'D', 'L']]); break;
            }
        }
    }
}

// 3. 감시 카메라 비추는 방향 설정
// 감시 카메라가 없을 수도 있음에 주의
if (camera.length !== 0) {
    camera[0].forEach((cam) => {
        chooseCamera(cam, []);
    });
}
else getArea(sampleGraph);

function chooseCamera(current, list) {
    list.push(current);

    if (list.length === camera.length) {
        execute(list, sampleGraph);
        return;
    }

    camera[list.length].forEach((cam) => {
        let newList = list.slice();
        chooseCamera(cam, newList);
    });
}

// 4. 구한 감시 카메라의 비추는 방향으로 시뮬레이션
function execute(camList, g) {
    let graph = g.map((x) => x.slice());
    camList.forEach((cam, index) => {
        if (cam.includes('L')) L(location[index]);
        if (cam.includes('R')) R(location[index]);
        if (cam.includes('U')) U(location[index]);
        if (cam.includes('D')) D(location[index]);
    });

    function L([r, c]) {
        while (c >= 0 && graph[r][c] !== 6) {
            if (graph[r][c] === 0) graph[r][c] = '#';
            c--;
        }
    }
    function R([r, c]) {
        while (c < col && graph[r][c] !== 6) {
            if (graph[r][c] === 0) graph[r][c] = '#';
            c++;
        }
    }
    function U([r, c]) {
        while (r >= 0 && graph[r][c] !== 6) {
            if (graph[r][c] === 0) graph[r][c] = '#';
            r--;
        }
    }
    function D([r, c]) {
        while (r < row && graph[r][c] !== 6) {
            if (graph[r][c] === 0) graph[r][c] = '#';
            r++;
        }
    }

    getArea(graph);
}

// 5. 사각지대 구하고 최솟값 갱신하기
function getArea(graph) {
    let area = 0;
    for (let r = 0; r < row; r++) {
        for (let c = 0; c < col; c++) {
            if (graph[r][c] === 0) area++;
        }
    }
    if (area < min) min = area;
}

console.log(min);