byte measureLight() {

  unsigned long measure = 0;

  analogRead(A7);

  for (int i = 0; i < 10; i++)    measure += analogRead(A7);

  return measure / 2.0 * 1000.0 / 1024.0 > 150;

}
