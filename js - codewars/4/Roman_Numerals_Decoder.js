const solution = r => {

  var rToA = {
  'I': 1,
  'V': 5,
  'X': 10,
  'L': 50,
  'C': 100,
  'D': 500,
  'M': 1000,
  }

  let nums = [rToA[r[0]]];
  for (let i = 1; i < r.length; i++) {
    let cur = rToA[r[i]];
    let prev = rToA[r[i-1]];
    if( prev < cur) {
      nums[i-1] = (-1)*nums[i-1];
    }
    nums.push(rToA[r[i]])
  }
  return nums.reduce((s,t)=> s+t,(0));
}