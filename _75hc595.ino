

const int signalPin = 2;
const int clockPin  = 3;
const int latchPin  = 4;

const int displaySeg[][8] = {
  { 0, 0, 1, 1, 1, 1, 1, 1, },  // 0
  { 0, 0, 0, 0, 0, 1, 1, 0, },  // 1
  { 0, 1, 0, 1, 1, 0, 1, 1, },  // 2
  { 0, 1, 0, 0, 1, 1, 1, 1, },  // 3
  { 0, 1, 1, 0, 0, 1, 1, 0, },  // 4
  { 0, 1, 1, 0, 1, 1, 0, 1, },  // 5
  { 0, 1, 1, 1, 1, 1, 0, 1, },  // 6
  { 0, 0, 0, 0, 0, 1, 1, 1, },  // 7
  { 0, 1, 1, 1, 1, 1, 1, 1, },  // 8
  { 0, 1, 1, 0, 1, 1, 1, 1, },  // 9
};

void setup() {
  pinMode(signalPin, OUTPUT);
  pinMode(clockPin, OUTPUT);  
  pinMode(latchPin, OUTPUT);
}

void loop() {
  for (int i=0; i < (sizeof(displaySeg)/sizeof(displaySeg[0])); i++) {
    for (int j=0; j<8; j++) {
      digitalWrite(clockPin, 0);
      digitalWrite(signalPin, displaySeg[i][j]);
      digitalWrite(clockPin, 1);
      digitalWrite(clockPin, 0);
      digitalWrite(signalPin, 0);
    }
    digitalWrite(latchPin, 1);
    digitalWrite(latchPin, 0);
    delay(1000);
  }
}
