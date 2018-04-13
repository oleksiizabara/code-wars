const humanReadable = s => {
  let h = parseInt(s/3600);
  let m = parseInt((s - h*3600)/60);
  let ss = s - m*60 - h*3600;
  
  return addZero(h) + ':' + addZero(m) + ':' + addZero(ss);
}

const addZero = i => (i + '').length > 1 ? i : '0' + i;