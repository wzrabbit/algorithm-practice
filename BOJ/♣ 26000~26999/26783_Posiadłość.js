const getDigitSum = (number) => {
  const listedNumber = number.split("").map(Number);
  return listedNumber.reduce((acc, cur) => acc + cur);
};

const solveIfDigitsDifferent = () => {
  return Math.max(getDigitSum(B), Number(B[0] - 1) + 9 * B.length - 9);
};

const solveIfDigitsSame = () => {
  let bestDigitSum = 0;

  for (let index = 0; index < A.length; index++) {
    if (A[index] === B[index]) {
      bestDigitSum += Number(A[index]);
      continue;
    }

    const subB = B.slice(index);
    bestDigitSum += Math.max(
      getDigitSum(subB),
      Number(subB[0]) + 9 * subB.length - 10
    );
    break;
  }

  return bestDigitSum;
};

const [A, B] = require("fs").readFileSync(0, "utf-8").trim().split(" ");

if (A.length < B.length) {
  console.log(solveIfDigitsDifferent());
} else {
  console.log(solveIfDigitsSame());
}
