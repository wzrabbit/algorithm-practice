function solution(s) {
    s = s.replace(/(?<=^| )\w/g, letter => letter.toUpperCase());
    s = s.replace(/(?<=[A-Z\d])\w+/g, letter => letter.toLowerCase());
    return s;
}