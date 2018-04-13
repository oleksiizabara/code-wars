const findEvenIndex = a => {
  for(let i = 1, l = a.length; i < l - 1; i++) {
    if (sum(a.slice(0, i)) === sum(a.slice(i+1, l))) {
      return i;
    }
  }
  return -1;
}

const sum = a => a.reduce((s,i) => s + i, (0))