#define trigPin 9
#define echoPin 10

#define greenLED 2
#define yellowLED 3
#define redLED 4
#define buzzer 5

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  noTone(buzzer);

  if (distance > 50) {
    digitalWrite(greenLED, HIGH);
  } 
  else if (distance > 20 && distance <= 50) {
    digitalWrite(yellowLED, HIGH);
    tone(buzzer, 1000);
    delay(500);
    noTone(buzzer);
  } 
  else if (distance > 5 && distance <= 20) {
    digitalWrite(redLED, HIGH);
    tone(buzzer, 2000);
    delay(200);
    noTone(buzzer);
  } 
  else if (distance <= 5) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);
    tone(buzzer, 3000); 
  }

  delay(100);
}
