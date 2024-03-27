const isPossible = (goal, wakeUpTime) => {
  let start = 0;
  let end = N - 1;
  let mid;

  while (start <= end) {
    mid = Math.floor((start + end) / 2);

    if (remainTimes[mid] - wakeUpTime >= 0) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return end + 1 >= goal;
};

const input = require("fs").readFileSync(0, "utf-8").trim().split("\n");
const [N, Q] = input[0].split(" ").map(Number);
const closeTimes = input[1].split(" ").map(Number);
const delayTimes = input[2].split(" ").map(Number);
const remainTimes = Array.from({ length: N }).map(
  (_, index) => closeTimes[index] - delayTimes[index] - 1
);
const queries = input.slice(3).map((query) => query.split(" ").map(Number));
let output = "";

remainTimes.sort((a, b) => b - a);

queries.forEach((query) => {
  const [goal, wakeUpTime] = query;

  output += `${isPossible(goal, wakeUpTime) ? "YES" : "NO"}\n`;
});

console.log(output);
