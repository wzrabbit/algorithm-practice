const input = require('fs').readFileSync('/dev/stdin').toString().trim() + '00000';
let index = 0;
let count = 0;

while (index < input.length - 5) {
    let checkText = input.substr(index, 5);

    const matched = checkText.match(
        /^(hk|ho|hl|nj|np|nl|ml|[koiOjpuPhynbml])(rt|sw|sg|fr|fa|fq|ft|fx|fv|fg|qt|[rRsefaqtTdwczxvg])(hk|ho|hl|nj|np|nl|ml|[koiOjpuPhynbml])/);

    if (matched) {
        index += matched[0].length - 2;
        count++;
    }
    index++;
}

console.log(count);