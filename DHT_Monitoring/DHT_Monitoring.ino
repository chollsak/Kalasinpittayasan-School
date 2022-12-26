#include <TridentTD_LineNotify.h>
#include <ESP8266WiFi.h>
#include "DHT.h"

// ----------------------------------------------------------------------------------------------
DHT dht;

// ----------------------------------------------------------------------------------------------
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Chollada AIS_2.4G";
char pass[] = "0997122060";
String GAS_ID = "AKfycbxEZxMyO__kSv3isaHixpEYVVKhpvREFn-KQC4VRoWL4dskf7S45GjiYruTzgMJcl77"; //--> spreadsheet script ID

#define SSID        "Chollada AIS_2.4G"      // บรรทัดที่ 11 ให้ใส่ ชื่อ Wifi ที่จะเชื่อมต่อ
#define PASSWORD    "0997122060"     // บรรทัดที่ 12 ใส่ รหัส Wifi
#define LINE_TOKEN  "sanm6DQwoj5xxe1l8gYBPeOsfDvWgOETkPeIimXK2wo"   // บรรทัดที่ 13 ใส่ รหัส TOKEN ที่ได้มาจากข้างบน

//Your Domain name with URL path or IP address with path
const char* host = "script.google.com"; // only google.com not https://google.com

// ----------------------------------------------------------------------------------------------
#define DHT_PIN               D4
#define UPDATE_INTERVAL_HOUR  (1)
#define UPDATE_INTERVAL_MIN   (0)
#define UPDATE_INTERVAL_SEC   (0)

#define UPDATE_INTERVAL_MS    ( ((UPDATE_INTERVAL_HOUR*60*60) + (UPDATE_INTERVAL_MIN * 60) + UPDATE_INTERVAL_SEC ) * 1000 )

// ----------------------------------------------------------------------------------------------
int Temperature = 0;
int Humidity = 0;

// ----------------------------------------------------------------------------------------------
void update_google_sheet()
{
   
    Serial.print("connecting to ");
    Serial.println(host);
  
    // Use WiFiClient class to create TCP connections
    WiFiClientSecure client;
    const int httpPort = 443; // 80 is for HTTP / 443 is for HTTPS!
    
    client.setInsecure(); // this is the magical line that makes everything work
    
    if (!client.connect(host, httpPort)) { //works!
      Serial.println("connection failed");
      return;
    }   

    if(Temperature != 2147483647 && Humidity != 2147483647){
    //----------------------------------------Processing data and sending data

    
    String url = "/macros/s/" + GAS_ID + "/exec?temperature=";

    
    url += String(Temperature);
    
    url += "&humidity=";
    url += String(Humidity);
    
    Serial.print("Requesting URL: ");
    Serial.println(url);
  
    // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" + 
                 "Connection: close\r\n\r\n");
  
    Serial.println();
    Serial.println("closing connection"); 
   }
    
}

// ----------------------------------------------------------------------------------------------
void setup()
{
  // Debug console
  Serial.begin(115200);

  Serial.println();
  Serial.println(LINE.getVersion());

  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());

  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);

  LINE.notify("ระบบถูกเปิดเเล้ว");

  // Digital output pin
  pinMode(LED_BUILTIN, OUTPUT);



  // DHT Setup
  dht.setup(DHT_PIN); 

//----------------------------------------Wait for connection
  Serial.print("Connecting");
  WiFi.begin(ssid, pass); //--> Connect to your WiFi router
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
  }

}

// ----------------------------------------------------------------------------------------------
unsigned long time_ms;
unsigned long time_1000_ms_buf;
unsigned long time_sheet_update_buf;
unsigned long time_dif;

void loop()
{
  time_ms = millis();
  time_dif = time_ms - time_1000_ms_buf;

  // Read and print serial data every 1 sec
  if ( time_dif >= 1000 ) // 1sec 
  {
    time_1000_ms_buf = time_ms;
    Temperature = dht.getTemperature();
    Humidity = dht.getHumidity();
  
    // Print serial messages
   if(Temperature != 2147483647 && Humidity != 2147483647){
    Serial.print("Humidity: " + String(Humidity) + " %");
    Serial.print("\t");
    Serial.println("Temperature: " + String(Temperature) + " C");
    }

    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
   
  }

  // Update data to google sheet in specific period
  time_ms = millis();
  time_dif = time_ms - time_sheet_update_buf;  
  if ( time_dif >= UPDATE_INTERVAL_MS ) // Specific period
  {
    time_sheet_update_buf = time_ms;
   
    update_google_sheet();
    linenotify();
    
  }
 
}

void linenotify(){
   if(Temperature != 2147483647 && Humidity != 2147483647){
    LINE.notify("Humidity: " + String(Humidity) + " %");
    LINE.notify("Temperature: " + String(Temperature) + " C");
    
  }
}
