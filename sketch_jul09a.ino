int motorPin0 = 2;
int motorPin1 = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorPin0, OUTPUT);
  pinMode(motorPin1, OUTPUT);
}

void motorStop()
{
    digitalWrite(motorPin0, LOW);
    digitalWrite(motorPin1, LOW);
    delay(500);
}

void bR(int v)
{
    Serial.begin(9600);
    for(int i = 0; i < v; i++)
    {
        analogWrite(motorPin0, i);
        delay(200);
        Serial.print("Motor bei " + i);
    }
}

void bL(int v)
{
    for(int i = 0; i < v; i++)
    {
        analogWrite(motorPin1, i);
        delay(20);
    }
}

int readL()
{
  int i = Serial.read();
  delay(300);
  if(i > 0)
  {
    Serial.print(i);
    return i;
  }
}
void entry()
{
      Serial.print("Wilkommen MotorController");
    for(int i = 0; i < 25; i++)
    {
      Serial.print("-");
    }
}
void loop() {
    entry();
    Serial.print("Bitte dimm geschwindigkeit eingeben (MAX: 255)\n>>");
    int v = readL();
    if(v < 255)
    {
      bL(v);
    }
    else
    {
      Serial.print("Fehler groeßer als 255");
    }
    motorStop();
 }

