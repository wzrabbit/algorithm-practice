const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let emailSet = new Set();

for (let i = 1; i < input.length; i++) {
    const current = input[i];
    console.assert(!/[A-Za-z@._-]/.test(current));
}

for (let i = 1; i < input.length; i++) {
    const email = input[i];
    let finalEmail = '';
    if (!/^([A-Za-z0-9._]+)@([A-Za-z0-9.-]+)$/.test(email)) continue;
    if ((email.match(/@/g) || []).length !== 1) continue;
    const [username, domain] = email.split('@');

    if (/^\.|\.\.|\.$/.test(username)) continue;
    const compUsername = username.replace(/\./g, '').toLowerCase();
    if (compUsername.length < 6 || compUsername.length > 30) continue;
    finalEmail += compUsername + '@';

    if (/^\.|\.\.|\.$/.test(domain)) continue;
    const compDomain = domain.toLowerCase();
    if (compDomain.length < 3 || compDomain.length > 30) continue;
    finalEmail += compDomain;
    emailSet.add(finalEmail);
}

console.log(emailSet.size);