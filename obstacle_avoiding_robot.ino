#include <Servo.h>

Servo myServo;

#define TRIG 2
#define ECHO 4

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 10
#define IN4 11

long duration;
int distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  myServo.attach(12);
  myServo.write(90);

  Serial.begin(9600);
}

int getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH, 30000);

  if (duration == 0)
    return 400;

  return duration * 0.034 / 2;
}

void forward() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 200);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void back() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 200);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 200);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 200);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {

  myServo.write(90);
  delay(100);

  int front = getDistance();

  Serial.print("Front: ");
  Serial.println(front);

  if (front > 20) {
    forward();
  }
  else {

    stopRobot();
    delay(200);

    back();
    delay(300);

    stopRobot();
    delay(200);

    myServo.write(0);
    delay(500);
    int rightDist = getDistance();

    myServo.write(180);
    delay(500);
    int leftDist = getDistance();

    myServo.write(90);
    delay(300);

    if (rightDist > leftDist) {
      right();
      delay(500);
    }
    else {
      left();
      delay(500);
    }

    stopRobot();
    delay(100);
  }
}