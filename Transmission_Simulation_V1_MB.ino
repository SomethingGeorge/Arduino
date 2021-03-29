
//Variables
       int firstButton=2; //Input Address first Button
       int secondButton=3; //Input Address second Button
       int thirdButton=4; //Input Address third Button
       int fourthButton=5; //Input Address fourth Button
       int firstLED=6; //Output Address first LED
       int secondLED=7; //Output Address second LED
       int thirdLED=8; //Output Address third LED
       int fourthLED=9; //Output Address fourth LED

void setup() {
  // put your setup code here, to run once:
            
       pinMode(firstButton,INPUT);
       pinMode(secondButton,INPUT);
       pinMode(thirdButton,INPUT);
       pinMode(fourthButton,INPUT);
       pinMode(firstLED,OUTPUT);
       pinMode(secondLED,OUTPUT);
       pinMode(thirdLED,OUTPUT);
       pinMode(fourthLED,OUTPUT);
       Serial.begin(9600);
            }

void loop() {
  // put your main code here, to run repeatedly:

    
      if (digitalRead(firstButton)==HIGH) {
            digitalWrite(firstLED,HIGH);
      } if (digitalRead(secondButton)==HIGH){
            digitalWrite(secondLED,HIGH);
            digitalWrite(firstLED,LOW);
      } if (digitalRead(thirdButton)==HIGH){
            digitalWrite(thirdLED,HIGH); 
      } if (digitalRead(fourthButton)==HIGH){
            digitalWrite(fourthLED,HIGH); 
            }
            Serial.println(digitalRead(firstButton));
            //digitalWrite(firstLED,LOW);
            //digitalWrite(secondLED,LOW);
            //digitalWrite(thirdLED,LOW);
            //digitalWrite(fourthLED,LOW);
         }
            
