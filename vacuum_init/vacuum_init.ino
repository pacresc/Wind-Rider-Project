void pressureESCinit()
{
  esc1.attach(ESC1_PIN);
  esc1.writeMicroseconds(2000);
  
  }

void vacuum_control()
{
  pwm3hi = pulseIn(ch3,HIGH);
  
  pinMode(ch3, INPUT);

  if(pwm3hi < 1100){
    pwm3hi = 1100;  
  }
  if(pwm3hi > 1900){
    pwm3hi = 1900;  
  }
  // remap
  //pwm3out = (pwm3hi - 1100)*255/800;


  
  pwm3out = map(pwm3hi,1100,1900,1000,3000);
  esc1.writeMicroseconds(pwm3out);
 // Serial.println(pwm3out);
  //delay(0);        // delay in between reads for stability
 }
