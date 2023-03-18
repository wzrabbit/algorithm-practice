const [, loginHistory]: [unknown, number[]] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n')
  .map((line: string) => line.split(' ').map(Number));

const isLoggedIn: boolean[] = new Array(1001).fill(false);
const isSuspicious: boolean[] = new Array(1001).fill(false);

loginHistory.forEach((currentUser: number, index: number) => {
  const absCurrentUser: number = Math.abs(currentUser);

  if (currentUser > 0) {
    if (isLoggedIn[absCurrentUser]) {
      isSuspicious[absCurrentUser] = true;
    }

    isLoggedIn[absCurrentUser] = true;
  } else {
    if (!isLoggedIn[absCurrentUser]) {
      isSuspicious[absCurrentUser] = true;
    }

    isLoggedIn[absCurrentUser] = false;
  }
});

const suspiciousCount: number = isSuspicious.filter(
  (isCurrentSuspicious) => isCurrentSuspicious
).length;

console.log(suspiciousCount);
