const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();

for (let i = 0; i < input.length; i += 2) {
    console.log(calculate(input[i], input[i + 1]));
}

function calculate(structure, output) {
    // 1. "!" 케이스 체크
    structure = structure.replace("_", ".");
    structure = "^" + structure + "$";
    let regex = new RegExp(structure);
    if (!(output.match(regex))) return "!";
    
    // 2. "_" 케이스 체크
    structure = structure.replace(".", "0");
    regex = new RegExp(structure);
    if (output.match(regex)) return "_";
    
    // 3. 빈칸에 들어가야 하는 문자열 찾기 (노가다)
    let alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let newStructure = structure;
    for (let i = 0; i < 26; i++) {
        let currentStructure = newStructure.replace("0", alphabet[i]);
        regex = new RegExp(currentStructure);
        if (output.match(regex)) return alphabet[i];
    }
}