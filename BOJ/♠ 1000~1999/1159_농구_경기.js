const [, ...input] = require("fs")
  .readFileSync(0, "utf-8")
  .toString()
  .trim()
  .split("\n")
  .map((name) => name[0]);
let db = {};

input.forEach((letter) => {
  if (db.hasOwnProperty(letter)) db[letter]++;
  else db[letter] = 1;
});

const result = Object.entries(db)
  .filter((property) => property[1] >= 5)
  .map((property) => property[0])
  .sort();

if (result.length > 0) console.log(result.join(""));
else console.log("PREDAJA");
