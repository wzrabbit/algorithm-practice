let input = require("fs")
  .readFileSync(0, "utf-8")
  .toString()
  .trim()
  .replace(/(\n| )+/g, " ")
  .split(" ");

let printer = "";
let stats = {};
let tasks = ["Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"];
let taskCount = 0;

tasks.forEach((task) => {
  stats[task] = 0;
});

input.forEach((task) => {
  stats[task] += 1;
  taskCount += 1;
});

tasks.forEach((task) => {
  printer += `${task} ${stats[task]} ${(stats[task] / taskCount).toFixed(2)}\n`;
});

printer += `Total ${taskCount} 1.00`;
console.log(printer);
