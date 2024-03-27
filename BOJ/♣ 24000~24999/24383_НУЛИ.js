console.log(new Set(require('fs').readFileSync(0, 'utf-8').trim().match(/0+/g) || []).size);
