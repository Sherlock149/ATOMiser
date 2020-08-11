int E1 = 5;
int M1 = 4; 
int E2 = 6; 
int M2 = 7; 

int leftMotorSpeed = 215;
int rightMotorSpeed = 185;

int sensorPinRight = 0; 
int sensorPinCenter = 1; 
int sensorPinLeft = 2; 

int lightReadingRight;
int lightToleranceRight = 1000;

int lightReadingCenter;
int lightToleranceCenter = 1000; 

int lightReadingLeft;
int lightToleranceLeft = 1000; 

int readingDelay = 100;
void setup() {
  // put your setup code here, to run once:
pinMode(M1,OUTPUT);
pinMode(M2,OUTPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

lightReadingRight = analogRead(sensorPinRight);
//Serial.print("Right Sensor Reading :");
//Serial.println(lightReadingRight);


lightReadingCenter = analogRead(sensorPinCenter);
//Serial.print("Center Sensor Reading :");
//Serial.println(lightReadingCenter);


lightReadingLeft = analogRead(sensorPinLeft);
//Serial.print("Left Sensor Reading :");
//Serial.println(lightReadingLeft);


// Move forward
if (lightReadingCenter > lightToleranceCenter)
{
digitalWrite(M1, HIGH);
digitalWrite(M2, HIGH);
analogWrite(E1, leftMotorSpeed);
analogWrite(E2, rightMotorSpeed);
delay(readingDelay);
// Stop
digitalWrite(M1, LOW);
digitalWrite(M2, LOW);
analogWrite(E1, 0);
analogWrite(E2, 0);
}

// Turn right
if (lightReadingRight > lightToleranceRight)
{
digitalWrite(M1, LOW);
digitalWrite(M2, HIGH);
analogWrite(E1, leftMotorSpeed);
analogWrite(E2, rightMotorSpeed);
delay(readingDelay);
// Stop
digitalWrite(M1, LOW);
digitalWrite(M2, LOW);
analogWrite(E1, 0);
analogWrite(E2, 0);
}

// Turn left 
if (lightReadingLeft > lightToleranceLeft)
{
digitalWrite(M1, HIGH);
digitalWrite(M2, LOW);
analogWrite(E1, leftMotorSpeed);
analogWrite(E2, rightMotorSpeed);
delay(readingDelay);
// Stop
digitalWrite(M1, LOW);
digitalWrite(M2, LOW);
analogWrite(E1, 0);
analogWrite(E2, 0);
}
}
