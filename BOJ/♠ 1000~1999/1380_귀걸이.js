const input = require("fs")
  .readFileSync(0, "utf-8")
  .toString()
  .trim()
  .split("\n");

let scenarioNo = 1;
let printer = "";
let lineIndex = 0;
const readLine = () => input[lineIndex++];

while (true) {
  const nameCount = Number(readLine());
  const names = [];
  let hasEarringA = new Array(nameCount).fill(false);
  let hasEarringB = new Array(nameCount).fill(false);

  if (nameCount === 0) {
    break;
  }

  for (let i = 0; i < nameCount; i++) {
    names.push(readLine());
  }

  for (let i = 0; i < nameCount * 2 - 1; i++) {
    let [girlNo, earring] = readLine().split(" ");
    girlNo = Number(girlNo);

    earring === "A"
      ? (hasEarringA[girlNo - 1] = true)
      : (hasEarringB[girlNo - 1] = true);
  }

  for (let i = 0; i < nameCount; i++) {
    if (!hasEarringA[i] || !hasEarringB[i]) {
      printer += `${scenarioNo++} ${names[i]}\n`;
    }
  }
}

console.log(printer);
