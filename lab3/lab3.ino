typedef struct Moves {
  int angleStart;
  int angleEnd;
  int angleStep;
} Move;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0) {
    // TODO
  }
}