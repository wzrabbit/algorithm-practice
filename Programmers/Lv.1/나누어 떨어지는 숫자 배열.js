function solution(arr, divisor) {
    const result = arr.filter(num => num % divisor === 0).sort((a, b) => a - b);

    if (result.length > 0)
        return result;
    else
        return [-1];
}