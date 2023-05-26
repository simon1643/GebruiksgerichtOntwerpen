const int buttonNextPin = 2;
const int buttonRepeatPin = 3;
const int buttonBackPin = 4;
const int button1Pin = 5;
const int button2Pin = 6;
const int button3Pin = 7;
const int button4Pin = 8;
const int button5Pin = 9;
int buttonNextState = 0;
int oldButtonNextState=0;
int buttonRepeatState = 0;
int oldButtonRepeatState=0;
int buttonBackState = 0;
int oldButtonBackState=0;
int button1State = 0;
int oldButton1State=0;
int button2State = 0;
int oldButton2State=0;
int button3State = 0;
int oldButton3State=0;
int button4State = 0;
int oldButton4State=0;
int button5State = 0;
int oldButton5State=0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonNextPin, INPUT);
  pinMode(buttonRepeatPin, INPUT);
  pinMode(buttonBackPin, INPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);
  Serial.println("start");
}

void loop() {
      buttonNextState = digitalRead(buttonNextPin);
      buttonRepeatState = digitalRead(buttonRepeatPin);
      buttonBackState = digitalRead(buttonBackPin);
      button1State = digitalRead(button1Pin);
      button2State = digitalRead(button2Pin);
      button3State = digitalRead(button3Pin);
      button4State = digitalRead(button4Pin);
      button5State = digitalRead(button5Pin);
      // Serial.println(buttonState);
      if (buttonNextState!=oldButtonNextState) {
        if (buttonNextState == HIGH) {
              Serial.println("buttonNext");
        }
      oldButtonNextState=buttonNextState;
      }
      
      if (buttonRepeatState!=oldButtonRepeatState) {
        if (buttonRepeatState == HIGH) {
              Serial.println("buttonRepeat");
        }
      oldButtonRepeatState=buttonRepeatState;
      }

      if (buttonBackState!=oldButtonBackState) {
        if (buttonBackState == HIGH) {
              Serial.println("buttonBack");
        }
      oldButtonBackState=buttonBackState;
      }

      if (button1State!=oldButton1State) {
        if (button1State == HIGH) {
              Serial.println("button1");
        }
      oldButton1State=button1State;
      }

      if (button2State!=oldButton2State) {
        if (button2State == HIGH) {
              Serial.println("button2");
        }
      oldButton2State=button2State;
      }

      if (button3State!=oldButton3State) {
        if (button3State == HIGH) {
              Serial.println("button3");
        }
      oldButton3State=button3State;
      }

      if (button4State!=oldButton4State) {
        if (button4State == HIGH) {
              Serial.println("button4");
        }
      oldButton4State=button4State;
      }

      if (button5State!=oldButton5State) {
        if (button5State == HIGH) {
              Serial.println("button5");
        }
      oldButton5State=button5State;
      }
    
      delay(50);
}