#define trigPin 9
#define echoPin 10
#define buzzerPin 11

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Limpa o trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Envia pulso de 10 microssegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Lê o echoPin
  duration = pulseIn(echoPin, HIGH);
  
  // Calcula a distância
  distance = duration * 0.034 / 2;
  
  Serial.print("Distância: ");
  Serial.println(distance);
  
  // Buzzer apita mais rápido quando mais próximo
  if (distance < 10) {
    tone(buzzerPin, 1000);
    delay(100);
    noTone(buzzerPin);
    delay(100);
  }
  else if (distance < 20) {
    tone(buzzerPin, 800);
    delay(300);
    noTone(buzzerPin);
    delay(300);
  }
  else if (distance < 30) {
    tone(buzzerPin, 600);
    delay(500);
    noTone(buzzerPin);
    delay(500);
  }
  else {
    noTone(buzzerPin);
  }
  
  delay(100);
}
