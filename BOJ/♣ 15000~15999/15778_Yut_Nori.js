const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
scoreBoard = { 'A': 0, 'B': 0, 'C': 0, 'D': 0, 'a': 0, 'b': 0, 'c': 0, 'd': 0 };
const moves = parseInt(input[0]);
for (let i = 1; i <= moves; i++) {
    const command = input[i].split(' ');
    move(command[0], command[1]);
}
print(scoreBoard);

function move(player, yut) {
    yut = (yut.match(/F/g) || ['F', 'F', 'F', 'F', 'F']).length;
    let score = scoreBoard[player];
    let moveList = [];

    if (score === 0) {
        moveList.push(player);
    }
    else if (['A', 'B', 'C', 'D'].includes(player)) {
        if (scoreBoard['A'] === score) moveList.push('A');
        if (scoreBoard['B'] === score) moveList.push('B');
        if (scoreBoard['C'] === score) moveList.push('C');
        if (scoreBoard['D'] === score) moveList.push('D');
    }
    else {
        if (scoreBoard['a'] === score) moveList.push('a');
        if (scoreBoard['b'] === score) moveList.push('b');
        if (scoreBoard['c'] === score) moveList.push('c');
        if (scoreBoard['d'] === score) moveList.push('d');
    }

    switch (score) {
        case 5:
            score = 21 + yut - 1; break;
        case 10:
            switch (yut) {
                case 1: score = 26; break;
                case 2: score = 27; break;
                case 3: score = 23; break;
                case 4: score = 28; break;
                case 5: score = 29; break;
            }
            break;
        case 21:
            if (yut === 5) score = 15;
            else score += yut;
            break;
        case 22:
            if (yut >= 4) score = 15 + (yut - 3) - 1;
            else score += yut;
            break;
        case 23:
            switch (yut) {
                case 1: score = 28; break;
                case 2: score = 29; break;
                case 3: score = 20; break;
                case 4: case 5: score = 'V'; break;
            }
            break;
        case 24:
            if (yut === 1) score = 25;
            else score = 15 + (yut - 1) - 1;
            break;
        case 25:
            score = 15 + yut - 1;
            break;
        case 26:
            switch (yut) {
                case 1: score = 27; break;
                case 2: score = 23; break;
                case 3: score = 28; break;
                case 4: score = 29; break;
                case 5: score = 20; break;
            }
            break;
        case 27:
            switch (yut) {
                case 1: score = 23; break;
                case 2: score = 28; break;
                case 3: score = 29; break;
                case 4: score = 20; break;
                case 5: score = 'V'; break;
            }
            break;
        case 28:
            switch (yut) {
                case 1: score = 29; break;
                case 2: score = 20; break;
                case 3: case 4: case 5: score = 'V'; break;
            }
            break;
        case 29:
            if (yut === 1) score = 20;
            else score = 'V';
            break;
        default:
            if (score === 'V') break;
            score += yut;
            if (score > 20) score = 'V';
            break;
    }

    for (let i = 0; i < moveList.length; i++) {
        scoreBoard[moveList[i]] = score;
    }

    if (['A', 'B', 'C', 'D'].includes(player)) {
        if (scoreBoard['a'] === score) scoreBoard['a'] = 0;
        if (scoreBoard['b'] === score) scoreBoard['b'] = 0;
        if (scoreBoard['c'] === score) scoreBoard['c'] = 0;
        if (scoreBoard['d'] === score) scoreBoard['d'] = 0;
    }
    else {
        if (scoreBoard['A'] === score) scoreBoard['A'] = 0;
        if (scoreBoard['B'] === score) scoreBoard['B'] = 0;
        if (scoreBoard['C'] === score) scoreBoard['C'] = 0;
        if (scoreBoard['D'] === score) scoreBoard['D'] = 0;
    }

    return scoreBoard;
}

function print(result) {
    let f = new Array(30);
    for (let i = 0; i < 30; i++) {
        f[i] = ['.', '.', '.', '.'];
    }
    let repeat = 'AaBbCcDd';
    for (let i = 0; i < 8; i++) {
        const [player, score] = [repeat[i], scoreBoard[repeat[i]]];
        if (score === 'V' || score === 0) continue;
        const position = parseInt(i / 2);
        f[score][position] = player;
    }
    console.log(`${f[10][0]}${f[10][1]}----${f[9][0]}${f[9][1]}----${f[8][0]}${f[8][1]}----${f[7][0]}${f[7][1]}----${f[6][0]}${f[6][1]}----${f[5][0]}${f[5][1]}
${f[10][2]}${f[10][3]}    ${f[9][2]}${f[9][3]}    ${f[8][2]}${f[8][3]}    ${f[7][2]}${f[7][3]}    ${f[6][2]}${f[6][3]}    ${f[5][2]}${f[5][3]}
| \\                          / |
|  \\                        /  |
|   \\                      /   |
|    ${f[26][0]}${f[26][1]}                  ${f[21][0]}${f[21][1]}    |
${f[11][0]}${f[11][1]}   ${f[26][2]}${f[26][3]}                  ${f[21][2]}${f[21][3]}   ${f[4][0]}${f[4][1]}
${f[11][2]}${f[11][3]}     \\                /     ${f[4][2]}${f[4][3]}
|       \\              /       |
|        \\            /        |
|         ${f[27][0]}${f[27][1]}        ${f[22][0]}${f[22][1]}         |
|         ${f[27][2]}${f[27][3]}        ${f[22][2]}${f[22][3]}         |
${f[12][0]}${f[12][1]}          \\      /          ${f[3][0]}${f[3][1]}
${f[12][2]}${f[12][3]}           \\    /           ${f[3][2]}${f[3][3]}
|             \\  /             |
|              ${f[23][0]}${f[23][1]}              |
|              ${f[23][2]}${f[23][3]}              |
|             /  \\             |
${f[13][0]}${f[13][1]}           /    \\           ${f[2][0]}${f[2][1]}
${f[13][2]}${f[13][3]}          /      \\          ${f[2][2]}${f[2][3]}
|         ${f[24][0]}${f[24][1]}        ${f[28][0]}${f[28][1]}         |
|         ${f[24][2]}${f[24][3]}        ${f[28][2]}${f[28][3]}         |
|        /            \\        |
|       /              \\       |
${f[14][0]}${f[14][1]}     /                \\     ${f[1][0]}${f[1][1]}
${f[14][2]}${f[14][3]}   ${f[25][0]}${f[25][1]}                  ${f[29][0]}${f[29][1]}   ${f[1][2]}${f[1][3]}
|    ${f[25][2]}${f[25][3]}                  ${f[29][2]}${f[29][3]}    |
|   /                      \\   |
|  /                        \\  |
| /                          \\ |
${f[15][0]}${f[15][1]}    ${f[16][0]}${f[16][1]}    ${f[17][0]}${f[17][1]}    ${f[18][0]}${f[18][1]}    ${f[19][0]}${f[19][1]}    ${f[20][0]}${f[20][1]}
${f[15][2]}${f[15][3]}----${f[16][2]}${f[16][3]}----${f[17][2]}${f[17][3]}----${f[18][2]}${f[18][3]}----${f[19][2]}${f[19][3]}----${f[20][2]}${f[20][3]}`);
}