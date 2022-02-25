const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const masterWidth = parseInt(input[0]);
input.shift();

console.log(getQuadTree(input, masterWidth));

function getQuadTree(data, width) {
    if (width === 1) {
        return data[0][0];
    }

    if (width === masterWidth) {
        let temp = isOneColor(data);
        if (temp !== '-1') return temp;
    }

    let quad1, quad2, quad3, quad4;

    quad1 = Array(width / 2);
    for (let i = 0; i < width / 2; i++) {
        quad1[i] = data[i].slice(0, width / 2);
    }

    quad2 = Array(width / 2);
    for (let i = 0; i < width / 2; i++) {
        quad2[i] = data[i].slice(width / 2, width);
    }

    quad3 = Array(width / 2);
    for (let i = 0; i < width / 2; i++) {
        quad3[i] = data[i + width / 2].slice(0, width / 2);
    }

    quad4 = Array(width / 2);
    for (let i = 0; i < width / 2; i++) {
        quad4[i] = data[i + width / 2].slice(width / 2, width);
    }

    let result1 = isOneColor(quad1);
    let result2 = isOneColor(quad2);
    let result3 = isOneColor(quad3);
    let result4 = isOneColor(quad4);

    if (result1 === '-1') result1 = getQuadTree(quad1, width / 2);
    if (result2 === '-1') result2 = getQuadTree(quad2, width / 2);
    if (result3 === '-1') result3 = getQuadTree(quad3, width / 2);
    if (result4 === '-1') result4 = getQuadTree(quad4, width / 2);

    return '(' + result1 + result2 + result3 + result4 + ')';

    function isOneColor(frag) {
        let color = frag[0][0];
        for (let i = 0; i < frag.length; i++) {
            for (let j = 0; j < frag.length; j++) {
                if (frag[i][j] !== color) return '-1';
            }
        }
        if (color === '1') return '1';
        else return '0';
    }
}