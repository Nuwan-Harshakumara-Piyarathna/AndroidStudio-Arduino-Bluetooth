String msg,cmd;

void setup() {
  // Initialization
  Serial.begin(9600); // Communication rate of the Bluetooth Module
  msg = "";
}

void loop() {
  
  // To read message received from Android App
  if (Serial.available() > 0){ // Check if there is data coming
    msg = Serial.readString(); // Read the message as String


    if (msg == "<request>"){
      String str = "";
      //generate 3 random numbers seperated with commas
      for(int i=0;i<2;i++){
        str += randNumber(20);
        str += ",";
      }
      str += randNumber(20);
      str += "\n";
      Serial.println(str); // Then send message to Android
      msg = ""; // reset command
      delay(1000);
    }
  }
}

float randNumber(int limit){
  return random(1,limit*100.0)/100.0;
}

