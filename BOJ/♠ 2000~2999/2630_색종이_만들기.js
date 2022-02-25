const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const length = parseInt(input[0]);
input.shift();
let blue = 0;
let white = 0;

for (let i = 0; i < input.length; i++) {
    input[i] = input[i].split(' ');
}

makePaper(input, true);

function makePaper(paper, isFirst) {
    // 1. 시작하기에 앞서 만약 종이가 1칸이면, 쪼갤 수 없으므로 미리 예외 처리를 한다
    if (paper.length === 1) {
        if (paper[0][0] === '0') white++;
        else if (paper[0][0] === '1') blue++;
        return;
    }

    // 2. 첫 시도일 경우에만 종이를 쪼개야 하는지 먼저 검사한다.
    if (isFirst === true) {
        let x = checkFirstPaper(paper);
        if (x === false) return;
    }

    // 3. 종이를 네 조각으로 쪼갠다
    const paper1 = Array(paper.length / 2).fill([]);
    const paper2 = Array(paper.length / 2).fill([]);
    const paper3 = Array(paper.length / 2).fill([]);
    const paper4 = Array(paper.length / 2).fill([]);

    for (let row = 0; row < paper.length / 2; row++) {
        for (let col = 0; col < paper.length / 2; col++) {
            paper1[row] = [...paper1[row], paper[row][col]];
        }
    }

    for (let row = 0; row < paper.length / 2; row++) {
        for (let col = 0; col < paper.length / 2; col++) {
            paper2[row] = [...paper2[row], paper[row][col + paper.length / 2]];
        }
    }

    for (let row = 0; row < paper.length / 2; row++) {
        for (let col = 0; col < paper.length / 2; col++) {
            paper3[row] = [...paper3[row], paper[row + paper.length / 2][col]];
        }
    }

    for (let row = 0; row < paper.length / 2; row++) {
        for (let col = 0; col < paper.length / 2; col++) {
            paper4[row] = [...paper4[row], paper[row + paper.length / 2][col + paper.length / 2]];
        }
    }

    // 4. 종이가 하나의 색깔로만 구성되었는지 확인한다.
    // 하나의 색깔이면 각 카운터를 더하고, 아니면 그 종이를 다시 쪼개기 위해 재귀
    checkPaper(paper1, 0);
    checkPaper(paper2, 0);
    checkPaper(paper3, 0);
    checkPaper(paper4, 0);

    function checkPaper(fragment) {
        let color = null;
        let needSlice = false;
        for (let row = 0; row < paper.length / 2; row++) {
            for (let col = 0; col < paper.length / 2; col++) {
                if (color === null) {
                    color = fragment[row][col];
                }
                else if (fragment[row][col] !== color) {
                    needSlice = true;
                    break;
                }
            }
        }
        if (needSlice) makePaper(fragment, false);
        else if (color === '0') white++;
        else blue++;
    }

    function checkFirstPaper(fragment) {
        let color = null;
        let needSlice = false;
        for (let row = 0; row < paper.length; row++) {
            for (let col = 0; col < paper.length; col++) {
                if (color === null) {
                    color = fragment[row][col];
                }
                else if (fragment[row][col] !== color) {
                    needSlice = true;
                    break;
                }
            }
        }
        if (needSlice) return true;
        else if (color === '0') white++;
        else blue++;
        return false;
    }
}

console.log(white + '\n' + blue);