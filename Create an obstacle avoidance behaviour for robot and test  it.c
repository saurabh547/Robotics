#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
long cm, duration;
const int echoPin = 7;
const int trigPin = 6;
const int lm1 = 2;
const int lm2 = 3;
const int rm1 = 4;
const int rm2 = 5;

void setup() {
    pinMode(lm1, OUTPUT);
    pinMode(lm2, OUTPUT);
    pinMode(rm1, OUTPUT);
    pinMode(rm2, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    lcd.begin(16, 2);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);

    // converting time into distance in centimeters
    cm = duration * 0.034 / 2;

    if (cm < 20) {
        stop_bot();
        delay(2000);
        go_back();
        delay(2000);
        stop_again();
        delay(1000);
        go_left();
        delay(1000);
    } else {
        go_straight();
        delay(1000);
    }
    Serial.print("Distance: ");
    Serial.print(cm);
    Serial.println(" CM");
}

void go_straight() {
    lcd.setCursor(0, 0);
    lcd.print("NOTHING AHEAD");
    lcd.setCursor(0, 1);
    lcd.print("MOVING FORWARD");
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
}

void go_back() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TAKING REVERSE");
    lcd.setCursor(0, 1);
    lcd.print(cm);
    digitalWrite(lm2, HIGH);
    digitalWrite(lm1, LOW);
    digitalWrite(rm2, HIGH);
    digitalWrite(rm1, LOW);
}

void stop_bot() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SOMETHING AHEAD");
    lcd.setCursor(0, 1);
    lcd.print("STOP!");
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
}

void stop_again() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("BREAK FOR TURN");
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
}

void go_left() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TURNING LEFT");
    lcd.setCursor(0, 1);
    lcd.print(cm);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
}

void go_right() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TURNING RIGHT");
    lcd.setCursor(0, 1);
    lcd.print(cm);
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
}

Part A] 
Take DC Motor and 9 Volt Battery, 2 Dc motors, Ardino UNO R3, 
9V Battery and Breadboard small: Connect wires: 
Take 2 more motors & connect wires: 
Part B] 
Take ultrasonic distance and connect :
Take LCD, Potentiometer and connect devices:
Take resistor and connect: 
