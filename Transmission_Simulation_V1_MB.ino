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

            
         }
            
