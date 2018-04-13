const declareWinner = (f1, f2, fA) => {
  var s, f;
  f1.toString() === fA ? (f = f1, s = f2) : (f = f2, s = f1);

  while(true){
    s.health -= f.damagePerAttack;
    if (s.health <= 0)
      return f.name;
    f.health -= s.damagePerAttack;
    if (f.health <= 0)
      return s.name;
  }
}