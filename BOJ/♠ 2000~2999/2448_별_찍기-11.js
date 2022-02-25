const input = parseInt(require("fs").readFileSync("/dev/stdin"));
let scale = 6;
let triangle = "  *  \n * * \n*****";

if (input !== 3) console.log(duplicateTriangles(triangle));
else console.log(triangle);

function duplicateTriangles(triangles) {
    let top = triangles.slice();
    top = top.split("\n");
    for (let i = 0; i < top.length; i++) {
        top[i] = " ".repeat(scale / 2) + top[i] + " ".repeat(scale / 2);
    }
    top = top.join("\n");

    let bot = triangles.slice();
    bot = bot.split("\n");
    for (let i = 0; i < bot.length; i++) {
        bot[i] = bot[i] + " " + bot[i];
    }
    bot = bot.join("\n");

    let result = top + "\n" + bot;
    if (input <= scale) return result;
    else {
        scale *= 2;
        return duplicateTriangles(result);
    }
}