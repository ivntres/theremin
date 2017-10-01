#define MIN_DISTANCIA 50

int echo = 3;     // Pin para echo                          
int trigger = 4; // Pin para trigger                               
int speaker = 11; // Pin para el buzzer


unsigned long tiempoRespuesta;
unsigned long distancia;

unsigned long tiempoRespuesta2;
unsigned long distancia2;

float freqRad;
int tono;

void setup() {
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);                  
  pinMode(trigger, OUTPUT);                     
  pinMode(echo, INPUT);

 } 

void loop() {


  digitalWrite(trigger, HIGH);            // Enviamos pulso de 10 microsegundos
  delayMicroseconds(2);                        
  digitalWrite(trigger, LOW);
  
  tiempoRespuesta = pulseIn(echo, HIGH);  // Y esperamos pulso de vuelta
  distancia = tiempoRespuesta/58;         // Calculo de distancia en cm


  if (distancia < MIN_DISTANCIA) {
    freqRad = sin(distancia*(3.14/180)); // Pasamos frecuencia a radianes
    tono = 2000+(int(freqRad*1000));     // calculamos el tono        
    tone(speaker, tono, 500);
    Serial.write(distancia);
  }

}
