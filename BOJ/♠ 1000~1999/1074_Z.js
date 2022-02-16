let [maxScale, maxRow, maxCol] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map(Number);
maxScale = 2 ** maxScale;
let num = 0;

z(maxScale, 0, 0);
console.log(num);

function z(scale, startRow, startCol) {
  if (scale === 2) {
    if (startRow === maxRow && startCol < maxCol) num += 1;
    else if (startRow < maxRow && startCol === maxCol) num += 2;
    else if (startRow < maxRow && startCol < maxCol) num += 3;
    return;
  };
  // 1사분면
  if (maxRow < startRow + scale / 2 && maxCol < startCol + scale / 2) {
    z(scale / 2, startRow, startCol);
  }
  // 2사분면
  else if (maxRow < startRow + scale / 2 && maxCol >= startCol + scale / 2) {
    num += (scale / 2) ** 2;
    z(scale / 2, startRow, startCol + scale / 2);
  }
  // 3사분면
  else if (maxRow >= startRow + scale / 2 && maxCol < startCol + scale / 2) {
    num += (scale / 2) ** 2 * 2;
    z(scale / 2, startRow + scale / 2, startCol);
  }
  // 4사분면
  else {
    num += (scale / 2) ** 2 * 3;
    z(scale / 2, startRow + scale / 2, startCol + scale / 2);
  }
}
