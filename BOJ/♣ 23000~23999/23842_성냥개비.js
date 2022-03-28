const input = parseInt(require('fs').readFileSync('/dev/stdin')) - 4;
let stick = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6];
let found = false;

for (let i = 0; i <= 99; i++) {
    for (let j = i; j <= 99; j++) {
        if (i + j > 99) continue;
        let sum = i + j;
        let need = stick[Math.floor(i / 10)] + stick[i % 10] + stick[Math.floor(j / 10)] + stick[j % 10] + stick[Math.floor(sum / 10)] + stick[sum % 10];
        if (input === need) {
            found = true;
            console.log((i < 10 ? '0' + i : i) + '+' + (j < 10 ? '0' + j : j) + '=' + (sum < 10 ? '0' + sum : sum));
            break;
        }
    }
    if (found) break;
}

if (!found) console.log('impossible');