const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
let result = "SLURPYS OUTPUT\n";

for (let i = 0; i < input.length; i++) {
    if (checkSlurpy(input[i])) result += "YES\n";
    else result += "NO\n";
}

result += "END OF OUTPUT";
console.log(result);

function checkSlurpy(string) {
    if (!(string.match(/^A.*[HC][DE].+G$/))) return false;
    else if (string.replace(/^A.*[HC]/, "").replace(/[DE].+G$/, "") !== "") return false;
    else {
        let slimp = string.match(/^A.*[HC]/)[0];
        let slump = string.replace(/^A.*[HC]/, "").match(/[DE].+G$/)[0];
        return checkSlimp(slimp) && checkSlump(slump);
    }
}

function checkSlump(string) {
    if (string.match(/^[DE]F+G$/)) return true;
    else if (!(string.match(/^[DE]F/))) return false;
    else return checkSlump(string.replace(/^[DE]F/, ""));
}

function checkSlimp(string) {
    if (string.match(/^AH$/)) return true;
    else if (!(string.match(/^A.+C$/))) return false;
    else return checkSlimp(string.replace(/^AB|C$/g, "")) || checkSlump(string.replace(/^A|C$/g, ""));
}
