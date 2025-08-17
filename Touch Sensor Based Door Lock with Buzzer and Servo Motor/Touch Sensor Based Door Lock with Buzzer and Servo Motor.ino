#include <Servo.h>

Servo myServo;
bool doorLocked = true; 
// Initially locked

const int touchPin = 2;
const int buzzerPin = 12;


void setup() {
   myServo.attach(9);
   pinMode(buzzerPin, OUTPUT);
   pinMode(touchPin, INPUT);

}

void loop() {
  int touchState = digitalRead(touchPin);

  if (touchState == HIGH) {
    if (doorLocked) {
      // Unlock door
      myServo.write(90);  // Rotate to unlock position
      tone(buzzerPin, 1000, 200); // Beep short
      delay(200);
      noTone(buzzerPin);
      doorLocked = false;
    } else {
      // Lock door
      myServo.write(0);  // Rotate to unlock position
      tone(buzzerPin,500, 300); // Beep short
      delay(300);
      noTone(buzzerPin);
      doorLocked = true;

    }
    delay(1000); // Delay to avoid multiple triggers
  }
}



