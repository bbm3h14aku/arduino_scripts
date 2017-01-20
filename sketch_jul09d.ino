int pinS = 2;
int pwm = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial init [ OK ]");
  pinMode(pinS, OUTPUT);
  Serial.println("pinS = 2 = OUTPUT [ OK ]");
  pinMode(pwm, OUTPUT);
  Serial.println("pwm = 3 = OUTPUT [ OK ]");
  Serial.println("Start loop");
}

int readLine()
{
  int v;
  Serial.println("Ready to readLine");
  delay(1000);
  if(Serial.available())
  {
    v = Serial.read();
  }
  return v;
}

void kill()
{
  digitalWrite(pinS, LOW);
  digitalWrite(pwm, LOW);
}

void setLED(int v)
{
  digitalWrite(pinS, HIGH);
  analogWrite(pwm, v);
  delay(300);
}

void loop() {
  // put your main code here, to run repeatedly:
  int v = readLine();
  setLED(v);
  kill();
}

