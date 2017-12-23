//******** Documentation Section ***************
// Receives encoded Data from transmitter 
// & Accordingly moves in a particular direction corresponding to that encoded data
// Author : Harshit Srivastava
// Date : 23 May 2017

#include <VirtualWire.h> // library to interface with transmitter & receiver pair

#define led_pin 13 
#define transmit_pin 12  // pin declaration for transmitter receiver pair
#define receive_pin 11
#define transmit_en_pin 3

#define rigthWheel_Front 7 // PIN declaration for Controlling DC Motors  
#define rigthWheel_Back 6
#define leftWheel_Front 5
#define leftWheel_Back 4
 
void setup()
{
    delay(100);
    Serial.begin(9600);  // Debugging only
    Serial.println("setup"); 

    // Initialise the IO and ISR
    vw_set_tx_pin(transmit_pin);
    vw_set_rx_pin(receive_pin);
    vw_set_ptt_pin(transmit_en_pin);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);  // Bits per sec

    vw_rx_start();       // Start the receiver PLL running

    pinMode(led_pin, OUTPUT); // sets the value on register so that GPIO acts as output pin
    pinMode(rigthWheel_Front ,OUTPUT); 
    pinMode(rigthWheel_Back ,OUTPUT);  
    pinMode(leftWheel_Front ,OUTPUT);  
    pinMode(leftWheel_Back ,OUTPUT);
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; // stores the max lenght of the Mesage in buflen.

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
  int i;

        digitalWrite(led_pin, HIGH); // Flash a light to show received good message
  // Message with a good checksum received, dump it.
  Serial.print("Got: ");
   
  for (i = 0; i < buflen; i++)
  {
      if ( buf[i] = '8' ) // checks the message & executes the condition .
     {
      // move forward
        digitalWrite(rigthWheel_Front , HIGH );
        digitalWrite(rigthWheel_Back , LOW );
        digitalWrite(leftWheel_Front ,HIGH);
        digitalWrite(leftWheel_Back , LOW);
      }

      else if ( buf[i] = '2' )
      {
        // move back
        digitalWrite(rigthWheel_Front , LOW );
        digitalWrite(rigthWheel_Back , HIGH );
        digitalWrite(leftWheel_Front , LOW );
        digitalWrite(leftWheel_Back , HIGH );
        delay(100);
      } 

      else if ( buf[i] = '4' )
      {
        // move left   
        digitalWrite(rigthWheel_Front , HIGH );
        digitalWrite(rigthWheel_Back , LOW );
        digitalWrite(leftWheel_Front ,LOW );
        digitalWrite(leftWheel_Back , HIGH );
        delay (100);
      }   

      else if ( buf[i] = '6' )
      {
        // move right
        digitalWrite(rigthWheel_Front , LOW );
        digitalWrite(rigthWheel_Back , HIGH );
        digitalWrite(leftWheel_Front , HIGH );
        digitalWrite(leftWheel_Back , LOW );
        delay(100);  
      }

      else if ( buf[i] = '5' )
      {
        // stops
        digitalWrite(rigthWheel_Front , LOW );
        digitalWrite(rigthWheel_Back , LOW );
        digitalWrite(leftWheel_Front , LOW );
        digitalWrite(leftWheel_Back , LOW );
        delay(100);
        
      }
   }
  
  Serial.println();
        digitalWrite(led_pin, LOW);
    }
}
