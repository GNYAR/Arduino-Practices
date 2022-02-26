/*
  本實作顯示器為共陽極

        接線  亮   暗
  共陽:  5V  LOW  HIGH
  共陰: GND  HIGH LOW
*/
int BTN_PIN = 12;
int BTN_STATE = 1;
int DOT_PIN = 2;
int NUMBERS[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}};

void showNum(int x)
{
  int start = DOT_PIN + 1;
  for (int i = 0; i < 7; i++)
    digitalWrite(start + i, !NUMBERS[x][i]);
}

void clear()
{
  for (int i = DOT_PIN; i < DOT_PIN + 8; i++)
  {
    digitalWrite(i, HIGH);
  }
}

void setup()
{
  for (int i = DOT_PIN; i < DOT_PIN + 8; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
    delay(500);
  }
  clear();
  delay(1000);
  showNum(0);
  pinMode(BTN_PIN, INPUT_PULLUP);
}

int CNT = 0;
void loop()
{
  if (BTN_STATE == digitalRead(BTN_PIN))
    return;

  delay(50);
  BTN_STATE = digitalRead(BTN_PIN);

  // On button click
  if (!BTN_STATE)
  {
    if (++CNT == 10)
      CNT = 0;
    showNum(CNT);
  }
}
