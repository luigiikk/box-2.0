int LED1 = 2;
int LED2 = 7; 
int BOTAO = 3; //Botão conectado ao pino 8
int ESTADO_BOTAO = 0; //Variável para leitura do estado do Botão
int VAR = 0;
int VAR2 = 0;
int VEZES_PISCADA = 0;
int VEZES_CLICADA = 0;
int DELAY_CLIQUE = 0;
int TESTE = 0;

unsigned long tempoUltimoClique = 0;
bool tempoEsgotado = false;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BOTAO, INPUT);

  // Inicializa o gerador de números aleatórios
  randomSeed(analogRead(A0));  // Use um pino analógico flutuante para ruído

  int limite = random(1, 10);  // Valor entre 1 e 9
  
  for (int i = 0; i < limite; i++) {
    digitalWrite(LED1, HIGH);
    delay(1000);
    VEZES_PISCADA++;
    digitalWrite(LED1, LOW);
    delay(1000);
  }

  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED2, LOW);

  tempoUltimoClique = millis();

  Serial.begin(9600);  // No setup
  Serial.print("VEZES_PISCADA: ");
  Serial.println(VEZES_PISCADA);
  Serial.print("LIMITE: ");
  Serial.println(limite);

}

void loop() {
  // Se ainda não passou dos 5 segundos sem clique
  if (!tempoEsgotado) {
    quantidadeClicada();

    // Verifica se 5 segundos passaram desde o último clique
    if (millis() - tempoUltimoClique > 2000) {
      tempoEsgotado = true;
      verificarSequencia(); // Verifica se acertou
    }
  }
 
}

void quantidadeClicada(){
  VAR = digitalRead(BOTAO);
  if (VAR == 1 && VAR2 == 0) 
 {
  ESTADO_BOTAO = 1 - ESTADO_BOTAO;
  VEZES_CLICADA++;
  VAR2 = 1;
  delay(20);
  tempoUltimoClique = millis();
 }

 if (VAR == LOW) {
    VAR2 = 0;
  }

  Serial.print("VEZES_CLICADA: ");
  Serial.println(VEZES_CLICADA);

}

void verificarSequencia(){
   if(VEZES_CLICADA == VEZES_PISCADA){
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED2, HIGH);
  }
}