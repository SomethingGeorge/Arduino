
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
            
       pinMode(firstButton,INPUT);  // Park Button
       pinMode(secondButton,INPUT); // Forward and First Gear (If Park is Enabled and This is Pressed Forward in First)
       pinMode(thirdButton,INPUT);  // Second Gear (Will not Engage if Park or Reverse is Active)
       pinMode(fourthButton,INPUT); // Geardown (Only if Pressed when Second Gear is Active) and Reverse (If Park is Enabled and This is Pressed Reverse)
       pinMode(firstLED,OUTPUT);
       pinMode(secondLED,OUTPUT);
       pinMode(thirdLED,OUTPUT);
       pinMode(fourthLED,OUTPUT);
       Serial.begin(9600);
            }

void loop() {
 
    // Park Enable, when Park Button is Pressed (firstButton) and Fourth Pushed
      if (digitalRead(firstButton)==HIGH && digitalRead(fourthLED)==LOW) {
            digitalWrite(firstLED,LOW);   
      }  
      
      
     // 
      if (digitalRead(secondButton)==HIGH){
            digitalWrite(secondLED,HIGH);
            digitalWrite(firstLED,LOW);
      }   if (digitalRead(thirdButton)==HIGH){
            digitalWrite(thirdLED,HIGH); 
      }   if (digitalRead(fourthButton)==HIGH){
            digitalWrite(fourthLED,HIGH); 
            }
            Serial.println(digitalRead(firstButton));
            //digitalWrite(firstLED,LOW);
            //digitalWrite(secondLED,LOW);
            //digitalWrite(thirdLED,LOW);
            //digitalWrite(fourthLED,LOW);
         }
            
