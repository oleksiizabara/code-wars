function pascalsTriangle(n) {
  var allLines = [[1]];
  if (n===1) {
    return allLines[0];
  }
  if (n ===0) {
    return [];
  }
  var index = 1;
  while ( index < n ) {
    var line = [1];
    var prevLen = allLines[index - 1].length;
    var prevIndex = 0;
    while (prevIndex < prevLen - 1) {
      line.push(allLines[index - 1][prevIndex] + allLines[index - 1][prevIndex + 1]);
      prevIndex++;
    }
    line.push(1);
    allLines.push(line);
    index++;
  }
  var result = [];

  for (var i = 0; i < n; i++) {
    result = result.concat(allLines[i]);
  } 
  return result;
}