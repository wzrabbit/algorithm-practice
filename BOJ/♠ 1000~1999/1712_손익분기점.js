const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map(Number);

const firstPrice = input[0];
const secondPrice = input[1];
const notebookPrice = input[2];

if (secondPrice < notebookPrice) {
    console.log(Math.floor(firstPrice / (notebookPrice - secondPrice)) + 1);
}
else {
    console.log(-1);
}