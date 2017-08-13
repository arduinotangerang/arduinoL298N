#include <L298N.h>

//inisialisasi pin yang digunakan
const int ENA = 6;
const int IN1 = 8;
const int IN2 = 7;
const int IN3 = 2;
const int IN4 = 4;
const int ENB = 3;
L298N driver(ENA,IN1,IN2,IN3,IN4,ENB);

int time_delay = 500; //waktu tunda
int speed = 255; //kecepatan default tutorial ini (max kecepatan) 255

String message; 
String command;

void setup()
{
  Serial.begin(9600); //set baud rate
}
 
void loop()
{
  while(Serial.available())
  {//while there is data available on the serial monitor
    message+=char(Serial.read());//store string from serial command    
  }
  if(!Serial.available())
  {
    if(message!="")
    {
      if(message=="upPressed") {
          command = "U1";         
      } else {
        if(message=="rightPressed") {
            command = "R1";
            
        } else {
          if(message=="leftPressed") {
              command = "L1";              
              } else {
                 if (message=="downPressed") {
                    command = "D1";
                    
                } else {  
                    if (message=="squarePressed") {
                        command = "S0";               
                    } else {
                    command = ""; }
                }
              }
        }
      }
      message=""; //clear the data  
    }
    showcommand();
  }
  delay(50); //delay
}

void showcommand()
{
  if(command=="U1") {
    Serial.println(command);
    driver.full_stop(time_delay); //berhenti keduanya
    driver.forward(speed,time_delay);    
  }
  else {
     if(command=="R1") {
        Serial.println(command);
        driver.full_stop(time_delay); //berhenti
        driver.turn_right(speed,time_delay);
        
     }
     else {
        if(command=="L1") {
           Serial.println(command);
           driver.full_stop(time_delay); //berhenti
           driver.turn_left(speed,time_delay);
           
        }
        else {
           if(command=="D1") {
               Serial.println(command);
               driver.full_stop(time_delay); //berhenti
               driver.backward(speed,time_delay);               
            }
            else {
               if(command=="S0") {
               Serial.println(command);
               driver.full_stop(time_delay); //berhenti                       
               }
            }
        }
     }
  }
}


