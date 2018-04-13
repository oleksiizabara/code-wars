const tribonacci = (s, n) => {
  if (n < 3){
    return s.slice(0, n);
  }
  s = s.concat(Array(n - 3).fill(0));
  for (var i = 3; i < s.length; i++)
    s[i] =  s[i - 3] + s[i - 2] + s[i - 1];
  return s;
}