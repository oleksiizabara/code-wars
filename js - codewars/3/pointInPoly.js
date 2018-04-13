function pointInPoly(poly, point) {
  var xCoords = [], yCoords = [];
  var x = point[0], y = point[1];

  for (var i = 0; i < poly.length; i++ ) {
    xCoords.push(poly[i][0]);
    yCoords.push(poly[i][1]);
  }
  
  var len = xCoords.length;
  var t = len - 1;
  var c = false;
  for (i = 0; i < len; i++) {
      if (( (yCoords[i] <= y && y < yCoords[t]) || (yCoords[t] <= y && y < yCoords[i])) &&
          (x > (xCoords[t] - xCoords[i]) * (y - yCoords[i]) / (yCoords[t] - yCoords[i]) + xCoords[i])) {
            
            c = !c
      }
      t = i;
  }
return c;
}