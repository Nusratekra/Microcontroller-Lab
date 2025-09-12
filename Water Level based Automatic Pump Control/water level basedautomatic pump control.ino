// Pin configuration
const int TRIG = 13;
const int ECHO = 10;
const int IN1  = 7;
const int IN2  = 6;

long duration;
int distance;

// Distance thresholds
const int minDistance = 40;   // Tank full -> Pump OFF
const int maxDistance = 70;   // Tank empty -> Pump ON

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // --- Ultrasonic trigger pulse ---
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // --- Measure echo time ---
  duration = pulseIn(ECHO, HIGH);

  // --- Convert to cm ---
  distance = duration * 0.034 / 2;

  // --- Print distance ---
  Serial.print("Water Level Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // --- Pump Control Logic ---
  if (distance > maxDistance) {
    // Tank empty -> Pump ON
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    Serial.println("Pump ON");
  } 
  else if (distance < minDistance) {
    // Tank full -> Pump OFF
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    Serial.println("Pump OFF");
  }

  // --- Small delay before next reading ---
  delay(500);
}
