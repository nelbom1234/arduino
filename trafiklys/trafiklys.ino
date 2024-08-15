const byte green1 = 13;
const byte yellow1 = 12;
const byte red1 = 11;
const byte green2 = 10;
const byte yellow2 = 9;
const byte red2 = 8;
const byte button = 2;

bool stop = true;
unsigned long time;

void timer(int delayTime) {
  time = millis();
  while(millis()-time < delayTime) {
    if (!stop) {
      switchPressed();
      continue;
    }
    delay(50);
    break;
  }
}

void switchPressed() {
  if (digitalRead(button) == HIGH) {
    if (stop) {
      stop = false;
      digitalWrite(red1, HIGH);
      digitalWrite(red2, LOW);
      digitalWrite(yellow1, LOW);
      digitalWrite(yellow2, HIGH);
      digitalWrite(green1, LOW);
      digitalWrite(green2, LOW);
      delay(1000);
      digitalWrite(yellow2, LOW);
      digitalWrite(green2, HIGH);
      delay(1000);
    }
    else {
      stop = true;
      digitalWrite(red1, HIGH);
      digitalWrite(red2, HIGH);
      digitalWrite(yellow1, LOW);
      digitalWrite(yellow2, LOW);
      digitalWrite(green1, LOW);
      digitalWrite(green2, LOW);
      delay(100);
    }
  }
}

void swapLeftGreen() {
  if (!stop) {
    digitalWrite(green1, LOW);
    digitalWrite(yellow1, HIGH);
  }

  timer(1000);

  if (!stop) {
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red1, HIGH);
  }

  timer(1000);

  if (!stop) {
    digitalWrite(red2, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(green2, HIGH);
  }

  timer(1000);
}

void swapRightGreen() {
  if (!stop) {
    digitalWrite(green2, LOW);
    digitalWrite(yellow2, HIGH);
  }
  
  timer(1000);

  if (!stop) {
    digitalWrite(yellow2, LOW);
    digitalWrite(yellow1, HIGH);
    digitalWrite(red2, HIGH);
  }

  timer(1000);

  if (!stop) {
    digitalWrite(red1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(green1, HIGH);
  }

  timer(1000);
}

void setup ()
{
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
}  

void loop ()
{
  switchPressed();
  if (!stop) {
    swapRightGreen();
    swapLeftGreen();
  }
} 