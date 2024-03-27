const assert = require('assert');
const input = require("fs").readFileSync(0, "utf-8").trim().split("\n");

const infos = input.slice(1).map((info) => {
  const [name, priority, date] = info.split(" ");

  assert(/^[A-z]+$/.test(name));

  return {
    name,
    priority: Number(priority),
    date,
  };
});

infos.sort((a, b) => {
  if (a.date !== b.date) {
    return a.date > b.date ? -1 : 1;
  }

  return b.priority - a.priority;
});

const result = [infos[0].name];

for (let i = 1; i < infos.length; i++) {
  if (infos[i].date !== infos[i - 1].date) {
    result.push(infos[i].name);
  }
}

result.sort();

console.log(result.length);
console.log(result.join("\n"));
