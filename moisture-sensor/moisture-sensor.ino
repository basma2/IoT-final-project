 int sensorPin = A0; // Variable addressed to the analog pin A0 which Will receive the signal from the sensor 
 int sensorValue = 0; // variable that will store the value from  sensorPin
 int ledgreen = 11; // LED addressed to the pin 11
 int ledblue = 10; // LED addressed to the pin 10
 int ledred = 9; // LED addressed to the pin 9
 int BUZZER = 13; // buzzer addressed to the pin 13

  void setup() {

  Serial.begin(9600); // set the baud rate serial with 9600 
  pinMode(ledgreen, OUTPUT); // declares ledgreen as an output
  pinMode(ledblue, OUTPUT);  // declares ledblue as an output
  pinMode(ledred, OUTPUT);   // declares ledred as an output
  pinMode(BUZZER,OUTPUT); // declares BUZZER as an output
 }

 void loop() {
              // read the value from the sensor:
  Serial.print("sensor = " );  //  Prints on the serial the Word serial and the equal sign 
  sensorValue = analogRead(sensorPin); // Reads the value from the sensor and store in sensorValue                                                                                                                         delay(1000); 
  Serial.println(sensorValue); // Prints on the serial the value stored in sensorValue

   if(sensorValue<300 ){
    digitalWrite(ledgreen, HIGH); // Set high logic level to the LED green, turn it on
    digitalWrite(ledblue, LOW); // Set low logic level to the LED blue, turn it off
    digitalWrite(ledred, LOW); // Set low logic level to the LED red, turn it off
    tone(13,392,300); //command tone that creates a sound 
       /* 
       the number 13 indicates  that the buzzer positive pin is located at port 13 
       the number 392 is the  frequency that will play 
       the number 300 is the sound duration                                                                                              below we have the same command repeated but  with different frequencies in order to create a melody.
      */ 
   delay(500); 
   tone(13,523,300); // sound
   delay(500); 
   tone(13,261,300); // sound
   delay(500);
   tone(13,392,300); // sound
   delay(500); 
   tone(13,523,300); // sound
   delay(500); 

  }  

  if(sensorValue >300 &&sensorValue < 500){
   digitalWrite(ledblue, HIGH); // // Set high logic level to the LED blue, turn it on
   digitalWrite(ledgreen, LOW); // Set low logic level to the LED green, turn it off
   digitalWrite(ledred, LOW);  // Set low logic level to the LED red, turn it off
  }
  
  if(sensorValue >500){
   digitalWrite(ledred, HIGH); // // Set high logic level to the LED red, turn it on
   digitalWrite(ledgreen, LOW); // Set low logic level to the LED green, turn it off
   digitalWrite(ledblue, LOW); // Set low logic level to the LED blue, turn it off
   tone(13,300,300); //sound 
   delay(500); 
   tone(13,100,300); //sound
   delay(500); 
   tone(13,900,300); //sound 
   delay(500);

 }

}

