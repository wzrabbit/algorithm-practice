const isMeow = (start, end) => {
  if (dp[start][end] !== null) {
    return dp[start][end];
  }

  if (start > end) {
    return (dp[start][end] = true);
  }

  if (sound[start] !== "m" || sound[end] !== "w") {
    return (dp[start][end] = false);
  }

  for (let mid = start + 1; mid <= end - 1; mid++) {
    if (sound[mid] !== "e") {
      continue;
    }

    const isLeftFragMeow = isMeow(start + 1, mid - 1);
    const isRightFragMeow = isMeow(mid + 1, end - 1);

    if (isLeftFragMeow && isRightFragMeow) {
      return (dp[start][end] = true);
    }
  }

  return (dp[start][end] = false);
};

const sound = require("fs").readFileSync(0, "utf-8").toString().trim();
const soundSize = sound.length;
let dp = Array.from(Array(soundSize), () => Array(soundSize).fill(null));

console.log(isMeow(0, soundSize - 1) ? "Cat" : "Rabbit");
