#include <Servo.h>
#include <Encoder.h>
#include <PID_v1.h>

#define ENCODER_LEFT_A 2
#define ENCODER_LEFT_B 6

#define ENCODER_RIGHT_A 3
#define ENCODER_RIGHT_B 10

#define MOTOR_LEFT 3
#define MOTOR_RIGHT 11

Encoder leftEnc(ENCODER_LEFT_A, ENCODER_LEFT_B);
Encoder rightEnc(ENCODER_RIGHT_A, ENCODER_RIGHT_B);

Servo rightMotor;
Servo leftMotor;

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
  
  leftMotor.attach(MOTOR_LEFT);
  rightMotor.attach(MOTOR_RIGHT);
  
  botInfo.leftTicks = leftEnc.read();
  botInfo.rightTicks = -rightEnc.read();
  
  Serial.begin(9600);
}

void loop() {
  Serial.println((botInfo.leftTicks+botInfo.rightTicks)/2);
}
