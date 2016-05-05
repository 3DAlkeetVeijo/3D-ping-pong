//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// The Unnamed Circuit
// 
// Made by Zacharias Hellberg
// License: CC-BY-SA 3.0
// Downloaded from: https://123d.circuits.io/circuits/1901973-the-unnamed-circuit

#include <Servo.h>
int motorPin = 0;
int motorPin2 = 5;
int motorPinPlus = 1;
int motorPinMinus = 2;
int motorPinPlus2 = 6;
int motorPinMinus2 = 7;
int forward = 3;
int backward = 4;
int forward2 = 8;
int backward2 = 9;
int y = 0;
int buttonstateFWD = 0;
int buttonstateBWD = 0;
int buttonstateFWD2 = 0;
int buttonstateBWD2 = 0;
int delayTime = 50;
int topSpeed = 200;

void setup() {

  //Sets up the pins that are used. The buttons as inputs and the rest as outputs.
  pinMode(motorPin, OUTPUT);
  pinMode(motorPinMinus, OUTPUT);
  pinMode(motorPinPlus, OUTPUT);
  pinMode(forward, INPUT);
  pinMode(backward, INPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPinMinus2, OUTPUT);
  pinMode(motorPinPlus2, OUTPUT);
  pinMode(forward2, INPUT);
  pinMode(backward2, INPUT);
  Serial.begin(9600);
}


void loop() {

  	//Reads the preset ports in which the two buttons are. Forward for the right one and backward for the left one.
	buttonstateFWD = digitalRead(forward);
  	buttonstateBWD = digitalRead(backward);
  	buttonstateFWD2 = digitalRead(forward2);
  	buttonstateBWD2 = digitalRead(backward2);

  	//The motor runs while the button is pressed in, accelerating slowly over a set time period. When the button is released, the motor decelerates and stops. Note that the integer y is the speed.
    if(buttonstateFWD == HIGH){
      while(y < topSpeed){
        setMotor(true, y);
        delay(delayTime);
        y++;

        //The buttons inputs are read on every tick to make sure that releasing the button will start the deceleration of the motor.
        buttonstateFWD = digitalRead(forward);
  		  buttonstateBWD = digitalRead(backward);
        if(buttonstateFWD == LOW){
          while(y >= 0){
            setMotor(true, y);
            delay(delayTime);
            y--;
          }
          y=0;
          break;
        }	
        buttonstateFWD = digitalRead(forward);
    		buttonstateBWD = digitalRead(backward);

          //Decelerates to a stop from the speed that was reached.
          if(buttonstateFWD == LOW){
            while(y >= 0){
              setMotor(true, y);
              delay(delayTime);
              y--;
            }
          y=0;
          break;
  		}
    }
  }

    //The motor runs while the button is pressed in, accelerating slowly over a set time period. When the button is released, the motor decelerates and stops. Note that the integer y is the speed.
    if(buttonstateFWD2 == HIGH){
      while(y < topSpeed){
        setMotor2(true, y);
        delay(delayTime);
        y++;

        //The buttons inputs are read on every tick to make sure that releasing the button will start the deceleration of the motor.
        buttonstateFWD2 = digitalRead(forward2);
  		  buttonstateBWD2 = digitalRead(backward2);
        if(buttonstateFWD2 == LOW){
          while(y >= 0){
            setMotor2(true, y);
            delay(delayTime);
            y--;
          }
          y=0;
          break;
        }
    }
  }




        //TÄÄLLÄ OLLAAN MENOSSA





      

  	//Works in the same way as the previously explained loop, only in the other direction. The speed at which the motor is run is once again marked by the integer y.
    if(buttonstateBWD == HIGH){
      while(y < topSpeed){
        setMotor(false, y);
        delay(delayTime);
        y++;
        buttonstateFWD = digitalRead(forward);
  		buttonstateBWD = digitalRead(backward);
        if(buttonstateBWD == LOW){
          while(y >= 0){
            setMotor(false, y);
            delay(delayTime);
            y--;
          }
          y=0;
          break;

   		}
        buttonstateFWD = digitalRead(forward);
  		buttonstateBWD = digitalRead(backward);
        if(buttonstateBWD == LOW){
          while(y >= 0){
            setMotor(false, y);
            delay(delayTime);
            y--;
          }
        y=0;
        break;
		}

	}
}

//Works in the same way as the previously explained loop, only in the other direction. The speed at which the motor is run is once again marked by the integer y.
if(buttonstateBWD2 == HIGH){
  while(y < topSpeed){
    setMotor2(false, y);
    delay(delayTime);
    y++;
    buttonstateFWD2 = digitalRead(forward2);
    buttonstateBWD2 = digitalRead(backward2);
    if(buttonstateBWD2 == LOW){
      while(y >= 0){
        setMotor2(false, y);
        delay(delayTime);
        y--;
      }
      y=0;
      break;

  }
    buttonstateFWD2 = digitalRead(forward2);
    buttonstateBWD2 = digitalRead(backward2);
    if(buttonstateBWD2 == LOW){
      while(y >= 0){
        setMotor2(false, y);
        delay(delayTime);
        y--;
      }
    y=0;
    break;
}

}
}
}


//Gives the motor a direction (true -> clockwise, false -> counterclockwise) and a speed on which the motor runs.
void setMotor(boolean forward, int motor_speed){
   digitalWrite(motorPinPlus, forward);
   digitalWrite(motorPinMinus, !forward);
   digitalWrite(motorPin, motor_speed);
}

//Gives the second motor a direction (true -> clockwise, false -> counterclockwise) and a speed on which the motor runs.
void setMotor2(boolean forward, int motor_speed){
   digitalWrite(motorPinPlus2, forward);
   digitalWrite(motorPinMinus2, !forward);
   digitalWrite(motorPin2, motor_speed);
}
