let [yt, yj] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split(' ')
  .map(Number);

while (true) {
  yj += yt;

  if (yj >= 5) {
    console.log('yt');
    break;
  }

  yt += yj;

  if (yt >= 5) {
    console.log('yj');
    break;
  }
}
