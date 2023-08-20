int fire = 2; 
int motion = 3; 
int gas = 4;
int alarm = 13; 
char data = 0;
int light = 9; 
int fan = 10; 

void setup() {
  pinMode(fire, INPUT); 
  pinMode(motion, INPUT);
  pinMode(gas, INPUT); 
  pinMode(light, OUTPUT);
  pinMode(fan, OUTPUT);
  
  pinMode(alarm, OUTPUT); 
  Serial.begin(9600); 
  
}

void loop() {
  ////////////fire////////////
  int fire_value = digitalRead(fire); 
   int motionValue = digitalRead(motion);
   int gasValue = digitalRead(gas);
  if (fire_value == LOW && motionValue == HIGH && gasValue == HIGH) { 
    digitalWrite(alarm, HIGH); 
    delay(100);
    digitalWrite(alarm, LOW); 
    Serial.println("fire Detected");
  } 
  ////////////motion////////////
   
  else if (fire_value == HIGH && motionValue == LOW && gasValue == HIGH) {
    digitalWrite(alarm, HIGH); 
    delay(500);
    digitalWrite(alarm, LOW);
    Serial.println("Motion Detected"); // print a message to the serial monitor
  }

////////////gas////////////
  else if (fire_value == HIGH && motionValue == HIGH && gasValue == LOW) { // if the PIR sensor detects motion
    digitalWrite(alarm, HIGH); 
    delay(1000);
    digitalWrite(alarm, LOW);
    Serial.println("gas Detected"); // print a message to the serial monitor
  }   else { 
    digitalWrite(alarm, LOW); 
    Serial.println("normal"); 
  }
  delay(100); 
   if(Serial.available() > 0) 
    {
        data = Serial.read(); 
        Serial.print(data);  
        Serial.print("\n");  
        if(data == '1'){
          Serial.println(" Detected"); 
          digitalWrite(light, HIGH);    
          digitalWrite(fan, LOW);  
        }
          
        else if(data == '2'){
          Serial.println(" Detected");
          digitalWrite(light, LOW);    
          digitalWrite(fan, HIGH);   
        }
         else if(data == '0'){
          Serial.println(" Detected");
          digitalWrite(light, HIGH);    
          digitalWrite(fan, HIGH);   
        }
           
    } 
        
}
