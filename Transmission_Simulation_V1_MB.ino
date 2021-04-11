
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
       pinMode(fourthButton,INPUT); // Geardown (Only if Pressed when Second Gear is Active); Reverse (If Park is Enabled and This is Pressed Reverse)
       pinMode(firstLED,OUTPUT);
       pinMode(secondLED,OUTPUT);
       pinMode(thirdLED,OUTPUT);
       pinMode(fourthLED,OUTPUT);
       Serial.begin(9600);
            }

void loop() {
 
      // Park Enable, when Park Button is Pressed (firstButton) and Fourth button is not Pressed 
      if (digitalRead(firstButton)==HIGH && digitalRead(fourthLED)==LOW) {
            digitalWrite(firstLED,HIGH);   // Park is Engaged
            digitalWrite(secondLED,LOW);  // First Gear is Disengaged 
            digitalWrite(thirdLED,LOW);   // Second Gear is Disengaged 
      }  

      // Reverse Enable, Park Gear is Disengaged and Reverse Gear is Engaged
      if (digitalRead(firstButton)==HIGH && digitalRead(fourthLED)==HIGH){
            digitalWrite(firstLED,LOW);   // Park is Disengaged
            digitalWrite(fourthLED,HIGH); // Reverse Gear is Engaged      
      } 
        
      
     // First Gear is Engaged and Park is Disengaged
      if (digitalRead(secondButton)==HIGH && digitalRead(firstLED)==HIGH){
            digitalWrite(firstLED,LOW);   // Park is Disengaged
            digitalWrite(secondLED,HIGH); // First Gear is Engaged      
      } 


     // Second Gear is Engaged and First Gear is Disengaged
      if (digitalRead(thirdButton)==HIGH && digitalRead(secondLED)==HIGH){
            digitalWrite(secondLED,LOW);   // First Gear is Disengaged
            digitalWrite(thirdLED,HIGH); // Second Gear is Engaged      
      } 

   // Downshift Enable, Second Gear is Disengaged and First Gear is Engaged
      if (digitalRead(thirdButton)==HIGH && digitalRead(secondLED)==LOW && digitalRead(fourthLED)==HIGH){
            digitalWrite(thirdLED,LOW);   // Second Gear is Disengaged
            digitalWrite(fourthLED,HIGH); // Downshift Active
            digitalWrite(secondLED,HIGH); // first Gear is Engaged
            delay(3000);
            digitalWrite(fourthLED,LOW); // Downshift LED turned off after 3 seconds (Downshift Complete)    
      } 
        
            
            Serial.println(digitalRead(firstButton));
            //digitalWrite(firstLED,LOW);
            //digitalWrite(secondLED,LOW);
            //digitalWrite(thirdLED,LOW);
            //digitalWrite(fourthLED,LOW);
         }
            
