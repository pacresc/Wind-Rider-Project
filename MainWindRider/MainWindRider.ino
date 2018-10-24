/*
 * Parts
 * Arduino Mega
 * AT9 Transmitter (Remote controller)
 * R9DS Receiver
 * [2] Megamoto H - bridges
 *  Megamoto notes:
 *    D8 jumper for enable
 *    A0 current sense
 *    D11 PWMA
 *    D3 PWMB
 *    
 * 12 Power supply (Pb-Acid Battery)
 */
#include <Servo.h>

Servo esc1;

//ESC power
int ESC1_PIN = 9;

//Motor
int EnablePin1 = 8;
int EnablePin2 = 8;

//Transmitter connect
int ch1 = 2; //right stick horizontal movement (+) right
int ch2 = 4; //right stick vertical (+) down
int ch3 = 10; // left stick vertical movement(+)


long int pwm1hi; // hi side pwm of r/c control (1100 - 1900)
long int pwm2hi;

long int pwm3hi;

//first bridge Megamoto
// A0 Current Sense
int PWMPinA1 = 11; // Drive Motors (Axis 1)
int PWMPinB1 = 3;  // Drive Motors (Axis 1) Reverse

//second bridge Megamoto
int PWMPinA2 = 5; // Drive Motors (Axis 2)
int PWMPinB2 = 6; // Drive Motors (Axis 2) Reverse


long int pwm1out; //converted pwm1hi signal (0 - 255)
long int pwm2out;
long int pwm3out;

void setup() {

  Serial.begin(9600);
  pressureESCinit();
  motor_init();



}

void loop() {

  vacuum_control();
  motor_move();
  delayMicroseconds(1);


  // put your main code here, to run repeatedly:

}
