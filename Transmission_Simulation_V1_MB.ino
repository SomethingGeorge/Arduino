// This program will simulate the Transmission function of a Front-end Loader which was originally done on a PLC
// it has been replicated onto the Ardunio Uno to demonstrate the differences in programming structure


//Variables
       int firstButton=2; //Input Address first Button
       int secondButton=3;  // Input Address second Button
       int thirdButton=4;   // Input Address third Button
       int fourthButton=5;  // Input Address fourth Button
       int firstLED=6;      // Output Address first LED
       int secondLED=7;     // Output Address second LED
       int thirdLED=8;      // Output Address third LED
       int fourthLED=9;     // Output Address fourth LED

       bool reverseActive;  // Indicate Reverse is Active or Inactive 

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
      
      //Initialize
      Serial.println("You are in Park"); // Message readout
      digitalWrite(firstLED,HIGH); //Program Starts in Park
      reverseActive = LOW;         // Set Reverse Active to False       
         
            }

void loop() {

      
      // Park Enable, when Park Button is Pressed (firstButton) and Fourth button is not Pressed 
      if (digitalRead(firstButton)==HIGH) {
            digitalWrite(firstLED,HIGH);  // Park is Engaged
            digitalWrite(secondLED,LOW);  // First Gear is Disengaged 
            digitalWrite(thirdLED,LOW);   // Second Gear is Disengaged
            digitalWrite(fourthLED,LOW);  // Downshift and Reverse is Disengaged
            reverseActive = LOW;          // Set Reverse Active to False 

            Serial.println("You are in Park"); // Message readout
      }  

      // Reverse Enable, Park Gear is Disengaged and Reverse Gear is Engaged
       if (digitalRead(firstLED)==HIGH && digitalRead(fourthButton)==HIGH){
           digitalWrite(firstLED,LOW);   // Park is Disengaged
           digitalWrite(fourthLED,HIGH); // Reverse Gear is Engaged
           reverseActive = HIGH;         // Set Reverse Active to True
           Serial.println("You are in Reverse"); // Message readout 
      } 

      while(reverseActive==HIGH && digitalRead(firstButton)==LOW){
          digitalWrite(fourthLED,LOW);
          delay(500);
          digitalWrite(fourthLED,HIGH);
          delay(1000);
        }
   
     // First Gear is Engaged and Park is Disengaged
      if (digitalRead(secondButton)==HIGH && digitalRead(firstLED)==HIGH){
            digitalWrite(firstLED,LOW);   // Park is Disengaged
            digitalWrite(secondLED,HIGH); // First Gear is Engaged
            Serial.println("You are in First Gear"); // Message readout      
      } 


     // Second Gear is Engaged and First Gear is Disengaged
      if (digitalRead(thirdButton)==HIGH && digitalRead(secondLED)==HIGH){
            digitalWrite(secondLED,LOW);  // First Gear is Disengaged
            digitalWrite(thirdLED,HIGH);  // Second Gear is Engaged
            Serial.println("You are in Second Gear"); // Message readout       
      } 

   // Downshift Enable, Second Gear is Disengaged and First Gear is Engaged
      if (digitalRead(fourthButton)==HIGH && digitalRead(secondLED)==LOW && digitalRead(thirdLED)==HIGH){
            digitalWrite(thirdLED,LOW);   // Second Gear is Disengaged
            digitalWrite(fourthLED,HIGH); // Downshift Active
            digitalWrite(secondLED,HIGH); // first Gear is Engaged
            delay(3000);                  // Delay for 3 Seconds
            digitalWrite(fourthLED,LOW);  // Downshift LED turned off after 3 seconds (Downshift Complete)
            Serial.println("Downshifted to First Gear"); // Message readout     
      } 
            
            delay(250); //delay program
         }
            
