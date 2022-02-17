const input = parseInt(require("fs").readFileSync("/dev/stdin"));
let scale = 3;
console.log(duplicateStars("*"));

function duplicateStars(stars) {
  stars = stars.split("\n");

  let regularGroup = stars.slice();
  for (let i = 0; i < regularGroup.length; i++) {
    regularGroup[i] = regularGroup[i] + regularGroup[i] + regularGroup[i];
  }
  regularGroup = regularGroup.join("\n");

  let donutGroup = stars.slice();
  for (let i = 0; i < donutGroup.length; i++) {
    donutGroup[i] = donutGroup[i] + donutGroup[i].replace(/\*/g, " ") + donutGroup[i];
  }
  donutGroup = donutGroup.join("\n");

  let result = regularGroup + "\n" + donutGroup + "\n" + regularGroup;

  if (input <= scale) return result;
  else {
    scale *= 3;
    return duplicateStars(result);
  }
}