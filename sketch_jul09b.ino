int pin1 = 1;
int pin2 = 2;
int pin3 = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("HelloWorld");
  int in = Serial.read();
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("HelloWorld");
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
}
