
String readString;
void setup() {
  // put your setup code here, to run once:
Serial.begin(38400);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()){
  delay(3);
  char c = Serial.read();
  readString+=c;
}

if(readString.length() >0)
{
  Serial.println(readString);
  if(readString == "turn on light")
  {
  digitalWrite(13, HIGH);
  }
 else if(readString == "turn off light")
  {
  digitalWrite(13, LOW);
  }


  
  else if(readString == "turn on fan")
  {
  digitalWrite(12, HIGH);
  }
 else if(readString == "turn off fan")
  {
  digitalWrite(12, LOW);
  }


    else if(readString == "all turn on")
  {
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  }
 else if(readString == "all turn off")
  {
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  }
  readString = "";
}
}

