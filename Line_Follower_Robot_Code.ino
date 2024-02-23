// Define pins for IR sensors and motors
const int irPinLeft = 2;          // Define the pin for the left IR sensor
const int irPinRight = 3;         // Define the pin for the right IR sensor
const int motor1Pin1 = 9;         // Define the pin for motor 1 (forward)
const int motor1Pin2 = 8;         // Define the pin for motor 1 (backward)
const int motor2Pin1 = 7;         // Define the pin for motor 2 (forward)
const int motor2Pin2 = 6;         // Define the pin for motor 2 (backward)

void setup() {
  // Configure pins as inputs or outputs
  pinMode(irPinLeft, INPUT);       // Set left IR sensor pin as input
  pinMode(irPinRight, INPUT);      // Set right IR sensor pin as input
  pinMode(motor1Pin1, OUTPUT);     // Set motor 1 pins as output
  pinMode(motor1Pin2, OUTPUT);     // Set motor 1 pins as output
  pinMode(motor2Pin1, OUTPUT);     // Set motor 2 pins as output
  pinMode(motor2Pin2, OUTPUT);     // Set motor 2 pins as output
  Serial.begin(9600);
}

void loop() {
  // Read IR sensor values
  int irValueLeft = digitalRead(irPinLeft);     // Read left IR sensor value
  int irValueRight = digitalRead(irPinRight);   // Read right IR sensor value
  Serial.print("Value of Left ");
  Serial.println(irValueLeft );
  Serial.print("Value of right ");
  Serial.println( irValueRight);
  //delay(500);

  // If both IR sensors detect an object, stop motors
  if (irValueLeft == 0 && irValueRight == 0) {
    analogWrite(motor1Pin1, 140);       // Rotate motor 1 Forward
    analogWrite(motor1Pin2, 0);       // Rotate motor 1 Backward
    analogWrite(motor2Pin1, 140);       // Rotate motor 2 Forward
    analogWrite(motor2Pin2, 0);       // Rotate motor 2 Backward
  }
  // If only left IR sensor detects an object, turn right
  else if ((irValueLeft == 1) && (irValueRight == 0))  {
    analogWrite(motor1Pin1, 0);       // Stop motor 1
    analogWrite(motor1Pin2, 140);      // Rotate motor 1 backward
    analogWrite(motor2Pin1, 140);      // Rotate motor 2 forward
    analogWrite(motor2Pin2, 0);       // Stop motor 2
  }
  // If only right IR sensor detects an object, turn left
  else if ((irValueLeft == 0) && (irValueRight == 1)) {
    analogWrite(motor1Pin1, 140);      // Rotate motor 1 forward
    analogWrite(motor1Pin2, 0);       // Stop motor 1
    analogWrite(motor2Pin1, 0);       // Stop motor 2
    analogWrite(motor2Pin2, 140);      // Rotate motor 2 backward
  }
  // If no IR sensors detect an object, move forward
  else {
    analogWrite(motor1Pin1, 0);      // Stop motor 1
    analogWrite(motor1Pin2, 0);       // Stop motor 1
    analogWrite(motor2Pin1, 0);      // Stop motor 2 
    analogWrite(motor2Pin2, 0);       // Stop motor 2
  }
}
