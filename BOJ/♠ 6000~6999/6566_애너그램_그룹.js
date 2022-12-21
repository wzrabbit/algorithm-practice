const words = require("fs").readFileSync(0, "utf8").trim().split("\n");
let groups = {};
let printer = "";

words.forEach((currentWord) => {
  const key = currentWord.split("").sort().join("");
  if (groups.hasOwnProperty(key)) {
    groups[key].push(currentWord);
  } else {
    groups[key] = [currentWord];
  }
});

groups = Object.values(groups).sort((x, y) =>
  x.length === y.length ? x[0].localeCompare(y[0]) : y.length - x.length
);

for (let index = 0; index < Math.min(groups.length, 5); index++) {
  const groupSize = groups[index].length;
  groups[index] = [...new Set(groups[index])];
  groups[index].sort();
  printer += `Group of size ${groupSize}: ${groups[index].join(" ")} .\n`;
}

console.log(printer);
