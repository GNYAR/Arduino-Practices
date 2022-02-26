/*
  Pin# >> Resistor >> LED(+) >> LED(-) >> GND
*/

int ledPin = 8;

// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  // Arduino 對外輸出電壓 控制 pin, 以此類推
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop()
{
  digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);                // wait for a second
  digitalWrite(ledPin, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);                // wait for a second
}
