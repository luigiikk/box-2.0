void setup() {
  pinMode(2, OUTPUT);

  piscarLetra(15); // O
  piscarLetra(12); // L
  piscarLetra(1);  // Á (A)
  delay(1000);     // Espaço entre palavras
  piscarLetra(13); // M
  piscarLetra(21); // U
  piscarLetra(14); // N
  piscarLetra(4);  // D
  piscarLetra(15); // O
}

void loop() {
  // Nada depois disso
}

void piscarLetra(int quantidade) {
  for (int i = 0; i < quantidade; i++) {
    digitalWrite(2, HIGH);
    delay(300);
    digitalWrite(2, LOW);
    delay(300);
  }

  // Pausa entre letras
  delay(800);
}