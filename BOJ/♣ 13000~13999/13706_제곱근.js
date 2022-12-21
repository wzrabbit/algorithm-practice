const N = BigInt(require('fs').readFileSync(0));

let l = 1n, r = N, mid;

while (l <= r) {
    mid = (l + r) / 2n;
    
    if (mid * mid < N) {
        l = mid + 1n;
    } else if (mid * mid > N) {
        r = mid - 1n;
    } else {
        console.log(mid.toString());
        break;
    }
}