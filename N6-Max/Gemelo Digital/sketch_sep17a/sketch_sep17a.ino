int pinEcho = 12;
int pinTrigger = 13;
int tiempo;
int distancia;

void setup() {
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  tiempo= pulseIn(pinEcho, HIGH);
  distancia = tiempo/58;
  Serial.print(distancia);
  Serial.print(" cm\n");
  delay(100);
  if(distancia <= 10 && distancia >=0){
    Serial.println("OBSTACULO");
  }
}
