#include <Servo.h>
int IR1 = 0;
int IR2 = 0;
Servo servo_3;
int counter;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  servo_3.attach(3, 500, 2500);
  servo_3.write(90);
  delay(300);
  servo_3.detach();
}
void loop()
{
  IR1 = analogRead(A0);
  IR2 = analogRead(A1);
  Serial.print("x: ");
  Serial.print(analogRead(A0));
  Serial.print(", y: ");
  Serial.println(analogRead(A1));
  if (100 < IR1 && 100 < IR2) {
    digitalWrite(2, HIGH);
    delay(3000);
    IR1 = analogRead(A0);
    IR2 = analogRead(A1);
    Serial.print("x: ");
    Serial.print(analogRead(A0));
    Serial.print(", y:");
    Serial.println(analogRead(A1));
    if (100 < IR1 && 100 < IR2) {
      servo_3.attach(3, 500, 2500);
      for (counter = 0; counter < 17; ++counter) {
        servo_3.write(120);
        delay(300);
        servo_3.write(60);
        delay(300);
      }
      servo_3.write(90);
      delay(300);
      servo_3.detach();
    }
    digitalWrite(2, LOW);
    while (!(500 > IR1 && 500 > IR2)) {
      IR1 = analogRead(A0);
      IR2 = analogRead(A1);
      Serial.print("x: ");
      Serial.print(analogRead(A0));
      Serial.print(", y:");
      Serial.println(analogRead(A1));
    }
  }
}
