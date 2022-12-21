const bowls = require("fs").readFileSync(0, "utf-8").toString();
let height = 0;

bowls.match(/(.)\1*/g).forEach((unit) => {
  height += unit.length * 5 + 5;
});

console.log(height);
