#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Encoder.h>

#define ENCODER_LEFT_A 2
#define ENCODER_LEFT_B 6

#define ENCODER_RIGHT_A 3
#define ENCODER_RIGHT_B 10

Encoder leftEnc(ENCODER_LEFT_A, ENCODER_LEFT_B);
Encoder rightEnc(ENCODER_RIGHT_A, ENCODER_RIGHT_B);

Adafruit_MotorShield motorShield = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = motorShield.getMotor(1);
Adafruit_DCMotor *rightMotor = motorShield.getMotor(2);

struct RobotInfo{
  long int leftTicks;
  long int rightTicks;
};

RobotInfo botInfo;
  
void setup(){
  pinMode(ENCODER_LEFT_A, INPUT_PULLUP);
  pinMode(ENCODER_LEFT_B, INPUT_PULLUP);
  
  pinMode(ENCODER_RIGHT_A, INPUT_PULLUP);
  pinMode(ENCODER_RIGHT_B, INPUT_PULLUP);
  
  motorShield.begin();
  Serial.begin(9600);
}

void loop() {
  botInfo.leftTicks = leftEnc.read();
  botInfo.rightTicks = -rightEnc.read();
  Serial.println((botInfo.leftTicks+botInfo.rightTicks)/2);
}
