const input = require("fs").readFileSync(0, "utf-8").trim().split("\n");
const pin = input[0].slice(15, 26);
const year =
  (input[1].slice(0, 2) <= "24" ? "20" : "19") + input[1].slice(0, 2);
const month = input[1].slice(2, 4);
const day = input[1].slice(4, 6);
const [firstName, lastName] = input[2]
  .match(/[A-z]+/g)
  .map((name) => name[0] + name.slice(1).toLowerCase());

console.log(`Ime: ${firstName}
Prezime: ${lastName}
Datum rodjenja: ${day}-${month}-${year}
OIB: ${pin}`);
