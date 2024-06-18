// UltraSonic 
const int echo = 13;
const int trig = 4;
// LEDS
const int LED2 = 8;
const int LED1 = 12;


int duration = 0;
int distance = 0;

void setup() {
  // INPUTS
  pinMode(echo, INPUT);
  //OUTPUTS
  pinMode(trig, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration * 0.0343) / 2; // Calculate distance in centimeters

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 28) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1 , LOW);
  }
   delay(100); 
  if (distance < 15) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }
  delay(100); 
}
