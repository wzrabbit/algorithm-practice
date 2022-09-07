function solution(arr) {
    let result = [-1];
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] !== result[result.length - 1])
            result.push(arr[i]);
    }

    result.shift();
    return result;
}