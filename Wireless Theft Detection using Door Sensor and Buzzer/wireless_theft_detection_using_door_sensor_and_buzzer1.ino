const int touchPin=2;       
const int buzzerPin = 4;   
int irState = 0;

void setup()
{
  pinMode(touchPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
 int touchState = digitalRead(touchPin);

  if (touchState == HIGH) 
  {
    tone(buzzerPin, 1000, 20); // Beep short
    delay(200);
    Serial.println("Alert! Door opened!");
  }
  else 
  {              
    noTone(buzzerPin);
  }
}