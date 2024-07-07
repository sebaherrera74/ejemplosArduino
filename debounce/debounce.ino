const int timeThreshold = 200;
const int intPin = 3;
volatile int ISRCounter = 0;
int counter = 0;
long startTime = 0;

void setup()
{
  pinMode(intPin, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(intPin), debounceCount, FALLING);
}

void loop()
{
  if (counter != ISRCounter)
  {
    counter = ISRCounter;
    Serial.println(counter);
  }
}

void debounceCount()
{
  if (millis() - startTime > timeThreshold)
  {
    ISRCounter++;
    startTime = millis();
  }
}
