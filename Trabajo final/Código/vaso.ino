const int pinPulsador = 4; // Pin del botón
const int pinLED  = 2;     // Pin del LED

bool buttonState = false;

unsigned long tiempoInicio = 0;
unsigned long tiempoEsperaProximaDosis = 5000; // Tiempo en milisegundos para el parpadeo
unsigned long tiempoTranscurrido = 0; // Para el contador

enum Estados {
  SUELTO,
  REPOSO
};

Estados state = SUELTO;

void setup() {
  Serial.begin(115200);
  pinMode(pinPulsador, INPUT);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  buttonState = digitalRead(pinPulsador);
  
  Serial.println(state);
  
  
  switch (state) {
      case SUELTO:
        if (buttonState == LOW) {
          // El pulsador no está presionado
          parpadearLED(1000);
        } else {
          digitalWrite(pinLED, LOW);
          state = REPOSO;    
        }

      case REPOSO:
        if (buttonState == HIGH) {
          // El pulsador está presionado
          if (tiempoInicio == 0) {
            // Iniciar el contador cuando el pulsador se presiona por primera vez
            tiempoInicio = millis();
          }

          tiempoTranscurrido = currentMillis - tiempoInicio;

          if (tiempoTranscurrido >= tiempoEsperaProximaDosis) {
            // Parpadear más rápido
            parpadearLED(500);
          }
        }else{
          digitalWrite(pinLED, HIGH);
          tiempoInicio = 0;
          state = SUELTO;
        }
      break;
 

  }
  currentMillis =0;
  
}

void parpadearLED(int miliseg) {
  for (int i = 0; i < 1; i++) {
    digitalWrite(pinLED, HIGH);
    delay(miliseg); // Tiempo de encendido del LED
    digitalWrite(pinLED, LOW);
    delay(miliseg); // Tiempo de apagado del LED
  }
}
