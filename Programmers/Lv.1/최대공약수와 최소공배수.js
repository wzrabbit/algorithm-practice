function gcd(n, m) {
    if (n % m === 0)
        return m;
    return gcd(m, n % m);
}

function lcm(n, m) {
    return n * m / gcd(n, m);
}

function solution(n, m) {
    return [gcd(n, m), lcm(n, m)];
}