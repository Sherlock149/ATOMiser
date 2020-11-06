int data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
data = Serial.read();
Serial.println(data);
delay(1000);
}
