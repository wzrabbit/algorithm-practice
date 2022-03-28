const [n, m] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map(Number);
let visited = Array(n + 1).fill(false);
let result = '';

for (let i = 1; i <= n; i++) {
  dfs(i, []);
}

function dfs(current, arr) {
    visited[current] = true;
    arr.push(current);

    // 원하는 길이의 조합을 얻은 경우에는 결과에 값 추가 후 탐색 종료
    if (arr.length === m) {
      result += arr.join(' ') + '\n';
      visited[current] = false;
      return;
    }

    // 다음 수를 탐색하기 위한 재귀 호출
    for (let i = 1; i <= n; i++) {
      if (visited[i] === false) {
        let newArr = arr.slice();
        dfs(i, newArr);
      }
    }

    // 탐색을 마친 후에는 방문한 원소에서 자신의 원소 제외
    visited[current] = false;
}

console.log(result);
