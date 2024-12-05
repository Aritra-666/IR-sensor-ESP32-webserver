#include <WiFi.h>

const char *ssid = "Aritra();";
const char *password = "undefined";

int ledPin = 2;
int SensorPin = 4;

WiFiServer server(80);
int scan (){
   int SensorState = digitalRead(SensorPin);

  if( SensorState == LOW){
    return 1;
  }else{
    return 0;
  }
}
void homepage(WiFiClient &client)
{
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1>Hello from  Aritra's first ESP32 Web Server!</h1>");
  client.println("<button> <a href=\"/readings\">GET READING</a></button>");
  client.println("</html>");
  client.stop();
  Serial.println("Client Disconnected");
}

void readings(WiFiClient &client)
{
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1>READINGS</h1>");
  if(scan() == 1){
     client.println("<h1>OBJECT FOUND!!</h1>");
  }else if(scan() == 0){
     client.println("<h1> NO OBJECT FOUND!!</h1>");
  }
  client.println("</html>");
  client.stop();
  Serial.println("Client Disconnected");
}

void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(ledPin, OUTPUT);
  pinMode(SensorPin, INPUT);
  WiFi.begin(ssid, password);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
  {

    Serial.print(".");
    delay(200);
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  }
  digitalWrite(ledPin, HIGH);
  Serial.println("IP address is :-");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop()
{

  WiFiClient client = server.available();

  if (client)
  {

    while (client.available())
    {

      String req = client.readStringUntil('\r');

      Serial.print(req);

      if (req.indexOf("GET / HTTP") >= 0)
      {

        homepage(client);
      }
      else if (req.indexOf("GET /readings HTTP") >= 0)
      {

        readings(client);
      }
    }
  }
}
