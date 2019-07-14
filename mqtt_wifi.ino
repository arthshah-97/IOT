#include <PubSubClient.h>

#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspServer.h>
#include <WiFiEspUdp.h>

WiFiEspClient espclient;
PubSubClient client(espclient);
int status=WL_IDLE_STATUS;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
WiFi.init(&Serial);
while(status!=WL_CONNECTED)
{
status=WiFi.begin("Note8","artharth");
delay(8000);
}
client.setServer("iot.eclipse.org",1883);
}

void loop() {
  // put your main code here, to run repeatedly:
if(!client.connected())
{
  pub();
}
client.loop();
}

void pub()
{
  while(!client.connected())
  {
    if(client.connect("arduinoClient"))
    {
      client.publish("mytopic/today","hi");
      
    }
    else
    {Serial.println("");delay(5000);}
  }
}

