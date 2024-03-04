#define leftsensor 13
#define rightsensor 12
#define leftmotorpin1 7
#define leftmotorpin2 6
#define rightmotorpin1 9
#define rightmotorpin2 8

void setup() {
  // put your setup code here, to run once:
  pinMode(leftsensor, INPUT);
  pinMode(rightsensor, INPUT);
  pinMode(leftmotorpin1, OUTPUT);
  pinMode(leftmotorpin2, OUTPUT);
  pinMode(rightmotorpin1, OUTPUT);
  pinMode(rightmotorpin2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if(!digitalRead(leftsensor) && !digitalRead(rightsensor)) {
  digitalWrite(leftmotorpin1, HIGH);
  digitalWrite(leftmotorpin2, LOW);                    // Move Forward when both sensors detect white
  digitalWrite(rightmotorpin1, HIGH);
  digitalWrite(rightmotorpin2, LOW);
}
if(!digitalRead(leftsensor) && digitalRead(rightsensor)) {
  digitalWrite(leftmotorpin1, LOW);
  digitalWrite(leftmotorpin2, LOW);                    // Turn right when left sensor detects white and right sensor detects black
  digitalWrite(rightmotorpin1, HIGH);
  digitalWrite(rightmotorpin2, LOW);
  }
if(digitalRead(leftsensor) && !digitalRead(rightsensor)) {
  digitalWrite(leftmotorpin1, HIGH);
  digitalWrite(leftmotorpin2, LOW);                    // turn left when left sensor detects black and right sensor detects white
  digitalWrite(rightmotorpin1, LOW);
  digitalWrite(rightmotorpin2, LOW);
}
if(digitalRead(leftsensor) && digitalRead(rightsensor)) {
  digitalWrite(leftmotorpin1, LOW);
  digitalWrite(leftmotorpin2, LOW);                    // stop when both sensors detect black
  digitalWrite(rightmotorpin1, LOW);
  digitalWrite(rightmotorpin2, LOW);
}


}
