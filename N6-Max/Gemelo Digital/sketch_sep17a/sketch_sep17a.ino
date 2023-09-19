int pinGiroIzq = 12;
int pinGiroDer = 13;
int pinEnA = 5;
int pinDireccion = 2;
int pinEcho = 7;
int pinTrigger = 8;
int tiempo;
int distancia;
bool obstaculo = false;

void setup() {
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinGiroIzq, OUTPUT);
  pinMode(pinGiroDer, OUTPUT);
  pinMode(pinEnA, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  tiempo = pulseIn(pinEcho, HIGH);
  distancia = tiempo / 58;
  Serial.print(distancia);
  Serial.print(" cm\n");
  delay(100);

  if (distancia <= 10 && distancia >= 0) {
    obstaculo = true;
  } else {
    obstaculo = false;
  }

  if (!obstaculo) {
    digitalWrite(pinEnA, HIGH);
    if(digitalRead(pinDireccion) == HIGH){
      delay(10);
      digitalWrite(pinGiroIzq, LOW);
      delay(10);
      digitalWrite(pinGiroDer, HIGH);
    } else{
      delay(10);
      digitalWrite(pinGiroDer, LOW);
      delay(10);
      digitalWrite(pinGiroIzq, HIGH);
    }
  } else {
    digitalWrite(pinEnA, LOW);
  }
}
