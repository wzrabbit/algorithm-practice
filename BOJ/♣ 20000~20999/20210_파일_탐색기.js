const numberSort = (aFrag, bFrag) => {
  const aNumberFrag = BigInt(aFrag);
  const bNumberFrag = BigInt(bFrag);
  
  if (aNumberFrag !== bNumberFrag) {
    return Number(aNumberFrag - bNumberFrag);
  }

  return aFrag.split('').filter(x => x === '0').length - bFrag.split('').filter(x => x === '0').length;
}

const alphabetSort = (aFrag, bFrag) => {
  if (aFrag.toLowerCase() !== bFrag.toLowerCase()) {
    return aFrag.toLowerCase().localeCompare(bFrag.toLowerCase());
  }
  
  return bFrag.localeCompare(aFrag);
}

const naturalSort = (a, b) => {
  const aFrags = a.match(/[A-z]|\d+/g);
  const bFrags = b.match(/[A-z]|\d+/g);
  
  for (let i = 0; i < Math.min(aFrags.length, bFrags.length); i++) {
    const aFrag = aFrags[i];
    const bFrag = bFrags[i];
    
    if (!isNaN(aFrags[i]) && !isNaN(bFrags[i])) {
      const sortResult = numberSort(aFrag, bFrag);
      if (sortResult !== 0) {
        return sortResult;
      }
    }
    
    if (/[A-z]/.test(aFrag) && /[A-z]/.test(bFrag)) {
      const sortResult = alphabetSort(aFrag, bFrag);
      if (sortResult !== 0) {
        return sortResult;
      }
    }
    
    if (aFrag.localeCompare(bFrag) !== 0) {
      return aFrag.localeCompare(bFrag);
    }
  }

  return aFrags.length < bFrags.length ? -1 : 1;
};

const [, ...strings] = require('fs')
  .readFileSync(0, 'utf-8')
  .trim()
  .split('\n');
  
strings.sort(naturalSort);
console.log(strings.join('\n'));