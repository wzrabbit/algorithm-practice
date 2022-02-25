const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
input.shift();
result = "";

for (let i = 0; i < input.length; i++) {
    let url = input[i];
    let protocol = host = port = path = "";

    url = url.split("://");
    protocol = url[0];
    url.shift();
    url = url.join("://");

    url = url.replace(/:\d+/, (search) => {
        port = search.replace(":", "");
        return "";
    });

    url = url.split("/");
    host = url[0];
    url.shift();

    path = url.join("/");

    if (port === "") port = "<default>";
    if (path === "") path = "<default>";

    result += `URL #${i + 1}
Protocol = ${protocol}
Host     = ${host}
Port     = ${port}
Path     = ${path}

`
}

result = result.slice(0, -1);
console.log(result);