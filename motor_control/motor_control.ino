void motor_init()
{
  pinMode(EnablePin1,OUTPUT);
  pinMode(EnablePin2,OUTPUT);
// H bridge 1
  pinMode(PWMPinA1,OUTPUT);
  pinMode(PWMPinB1,OUTPUT);
// H bridge 2
  pinMode(PWMPinA2,OUTPUT);
  pinMode(PWMPinB2,OUTPUT);
// channels from Transmitter/Receiver
  pinMode(ch1,INPUT);  // X axis
  pinMode(ch2, INPUT); // Y axis
  
  digitalWrite(EnablePin1,HIGH); // Bridge 1
  digitalWrite(EnablePin2,HIGH); // Bridge 2
  }
  
void motor_move()
{
  pwm1hi = pulseIn(ch1,HIGH);
  pwm2hi = pulseIn(ch2,HIGH);
  
  // limit input min 1150
  if(pwm1hi < 1150){
    pwm1hi = 1150;  
  }
  if(pwm2hi < 1150){
    pwm2hi = 1150;  
  }
  
  // limit input max 1850
  if(pwm1hi > 1850){
    pwm1hi = 1850;  
  }
   if(pwm2hi > 1850){
    pwm2hi = 1850;  
  }

  //Remap 1100 - 1900 range to 0 - 511
  pwm1out = map(pwm1hi,1150,1850,0,511);
  pwm2out = map(pwm2hi,1150,1850,0,511);
  // print out pwm value for test
  //Serial.println(pwm2out);
  //deadzone 120 to 130

// Channel 1
   if(pwm1out < 215){
  analogWrite(PWMPinA1,255-pwm1out); // coutner clockwise
  analogWrite(PWMPinB1,0);
  }
  else if(pwm1out > 295){
  analogWrite(PWMPinB1,pwm1out-256); // clockwise
  analogWrite(PWMPinA1,0);
  }
  else{
      analogWrite(PWMPinA1,0); // deadzone
      analogWrite(PWMPinB1,0);
    }
// Channel 2

   if(pwm2out < 215){
  analogWrite(PWMPinA2,255-pwm2out); // coutner clockwise
  analogWrite(PWMPinB2,0);
  }
  else if(pwm2out > 295){
  analogWrite(PWMPinB2,pwm2out-256); // clockwise
  analogWrite(PWMPinA2,0);
  }
  else{
      analogWrite(PWMPinA2,0); // deadzone
      analogWrite(PWMPinB2,0);
    }
    
   
  }
