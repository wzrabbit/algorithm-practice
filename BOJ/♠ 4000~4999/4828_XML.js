const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

for (let i = 0; i < input.length; i++) {
    let error = false;
    let text = input[i];
    let context = [];

    // 작업 1: 태그가 올바르게 구성되었는지 확인
    // 태그 내부에 숫자, 영소문자, / 외의 문자가 오면 유효하지 않은 태그로 간주
    if (/<[^0-9a-z/]/.test(text)) error = true;

    // 작업 2: 유효한 &amp, &lt;, &gt;, &xHEX 소거
    // 유효한 &계열 문자가 오면 모두 소거
    text = text.replace(/&((lt|gt|amp)|(x([0-9a-fA-F]{2})+));/g, "");

    // 작업 3: <tag/> 형태의 태그 모두 소거
    // 태그 내부의 문자열이 유효하다면 <tag/>는 스택에도 투입되지 않는 유효한 문자이므로 소거
    text = text.replace(/<[0-9a-z]+\/>/g, "");

    // 작업 4: <tag>, </tag> 소거 및 스택을 통한 유효성 확인
    // replace로 해당 태그를 소거하는 동시에 스택을 통해 태그가 올바르게 열리고 닫혔는지를 검사
    // 유효하지 않을 경우, 소거 대신 이상한 값으로 바꾸어 작업 5에서 실패하도록 유도
    text = text.replace(/<\/?[0-9a-z]+>/g, (tag) => {
        if (tag.startsWith("</")) {
            if (context.pop() !== tag.replace(/[<>/]/g, "")) {
                return "<";
            }
        }
        else {
            context.push(tag.replace(/[<>]/g, ""))
        }
        return "";
    });

    // 작업 5: &, <, > 문자 확인
    // 앞선 작업들에서 유효한 &, <, >는 모두 제거했으므로 아직까지도 이러한 문자가 남아있다면 실패로 간주
    // 작업 4의 스택 단계에서 실패했을 경우 이 단계에서 실패하게 됨
    if (/[&<>]/.test(text)) error = true;

    // 판단: 단 1회의 오류도 없었고, 스택의 길이도 0이라면 성공, 아니면 실패
    if (error === true || context.length > 0) console.log("invalid");
    else console.log("valid");
}