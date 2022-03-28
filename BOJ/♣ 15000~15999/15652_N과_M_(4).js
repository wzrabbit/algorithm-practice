const [n, m] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map(Number);
let result = '';

for (let i = 1; i <= n; i++) {
  dfs(i, []);
}

function dfs(current, arr) {
    arr.push(current);

    // 원하는 길이의 조합을 얻은 경우에는 결과에 값 추가 후 탐색 종료
    if (arr.length === m) {
      result += arr.join(' ') + '\n';
      return;
    }

    // 다음 수를 탐색하기 위한 재귀 호출
    for (let i = current; i <= n; i++) {
      let newArr = arr.slice();
      dfs(i, newArr);
    }
}

console.log(result);
