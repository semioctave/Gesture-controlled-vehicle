#include<Wire.h>
#include <VirtualWire.h>

const int led_pin = 11;
const int transmit_pin = 12;
const int receive_pin = 2;
const int transmit_en_pin = 3;

const int MPU_addr=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

int minVal=265;
int maxVal=402;

double x;
double y;
double z;
 
void setup() {
  // put your setup code here, to run once:
    Wire.begin(); // join i2c bus
    Wire.beginTransmission(MPU_addr); 
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);
    Serial.begin(9600);// start serial for output
    // Initialise the IO and ISR
    vw_set_tx_pin(transmit_pin);
    vw_set_rx_pin(receive_pin);
    vw_set_ptt_pin(transmit_en_pin);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);       // Bits transmitted per sec
    pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);
  
  AcX=Wire.read()<<8|Wire.read();
  AcY=Wire.read()<<8|Wire.read();
  AcZ=Wire.read()<<8|Wire.read();
  
    int xAng = map(AcX,minVal,maxVal,-90,90);
    int yAng = map(AcY,minVal,maxVal,-90,90);
    int zAng = map(AcZ,minVal,maxVal,-90,90);

       x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
       y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
       z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);

     Serial.print("AngleX= ");
     Serial.println(x);

     Serial.print("AngleY= ");
     Serial.println(y);

     Serial.print("AngleZ= ");
     Serial.println(z);
     Serial.println("-----------------------------------------");
     delay(100);

     if ( x <337.00 && x>280.00 )
     {
      if ( y < 20 && y > 340)
      {
        // move front
          char msg = "8";
          digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
          vw_send((uint8_t *)msg, 1);
          vw_wait_tx(); // Wait until the whole message is gone
          digitalWrite(led_pin, LOW);
          delay(100);   
      }
     }

     else if (x > 30.00 && x < 80.00) 
     {
      if( y < 20.00 && y> 340.00 )
      {//move back
        char msg = "2";
         digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
          vw_send((uint8_t *)msg, 1);
          vw_wait_tx(); // Wait until the whole message is gone
          digitalWrite(led_pin, LOW);
          delay(100);
      } 
     }

     else if ( y > 25.00 && y < 60.00  )
     {
       if ( x < 20.00 && x >340.00 )
       {
        // move left
        char msg = "4";
         digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
          vw_send((uint8_t *)msg, 1);
          vw_wait_tx(); // Wait until the whole message is gone
          digitalWrite(led_pin, LOW);
          delay(100);
        }
     }

     else if (y < 335.00 && y > 280.00 )
     {
      if ( x < 20.00 && x >340.00)
      {
        // move right
        char msg = "6";
         digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
          vw_send((uint8_t *)msg, 1);
          vw_wait_tx(); // Wait until the whole message is gone
          digitalWrite(led_pin, LOW);
          delay(100);
        
      }
     }

     else if (y < 20.00 && y > 340.00 )
     {
        if( x < 20.00 && x > 340.00 )
        {
          // stops!...
          char msg = "5";
          digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
          vw_send((uint8_t *)msg, 1);
          vw_wait_tx(); // Wait until the whole message is gone
          digitalWrite(led_pin, LOW);
          delay(100);
        }
      }
}
