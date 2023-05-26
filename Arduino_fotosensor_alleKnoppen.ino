const int numberOfButtons = 5; //set total number of buttons (offset is + 14)
const int buttonNextPin = 2;
const int buttonRepeatPin = 3;
const int buttonBackPin = 4;
int buttonNextState = 0;
int oldButtonNextState=0;
int buttonRepeatState = 0;
int oldButtonRepeatState=0;
int buttonBackState = 0;
int oldButtonBackState=0;

struct buttonRecordType {
   int buttonState = 0;
   int buttonStateRebounce = 0;
   bool buttenPressed = false;
} buttonRecord[numberOfButtons];

void setup() {
  int i = 0;
  for(i=0; i<numberOfButtons; i++) {
      pinMode(i+14, INPUT);
  }
  Serial.begin(9600);
  pinMode(buttonNextPin, INPUT);
  pinMode(buttonRepeatPin, INPUT);
  pinMode(buttonBackPin, INPUT);
}

void HandleButtonAction(int buttonId)
{
  float voltage;
  voltage = analogRead(buttonId+14);//buttonId);
  //Serial.println(voltage);
    
  if (voltage < 500) {
    //Button Detection
    buttonRecord[buttonId].buttonState = buttonRecord[buttonId].buttonState + 1;
    
     if (buttonRecord[buttonId].buttonState == 1 && buttonRecord[buttonId].buttenPressed == false)
     {
        Serial.print("button");
        Serial.println(buttonId+1);
        buttonRecord[buttonId].buttenPressed = true;
     }

     if (buttonRecord[buttonId].buttonState > 65000)
     {
        buttonRecord[buttonId].buttonState = 2;
     }
  }
  else {
    //No Button Detection
     buttonRecord[buttonId].buttonState = 0;
  }

 if (buttonRecord[buttonId].buttenPressed)
 { 
     buttonRecord[buttonId].buttonStateRebounce = buttonRecord[buttonId].buttonStateRebounce + 1;
 }

 if (buttonRecord[buttonId].buttonStateRebounce > 200)
 {
    buttonRecord[buttonId].buttenPressed = false;
    buttonRecord[buttonId].buttonStateRebounce = 0;
 }
}

void loop() {
  int i = 0;
  for(i=0; i<numberOfButtons; i++) {
      HandleButtonAction(i);
  }
  buttonNextState = digitalRead(buttonNextPin);
  buttonRepeatState = digitalRead(buttonRepeatPin);
  buttonBackState = digitalRead(buttonBackPin);
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
  delay(10);
}