#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <TridentTD_LineNotify.h>
#include <ESP8266WiFi.h>
#include "DHT.h"


// ----------------------------------------------------------------------------------------------
DHT dht;

// ----------------------------------------------------------------------------------------------
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Nt-sice_2.4g"; //เปลี่ยนไวไฟ
char pass[] = "99999999"; //เปลี่ยนรหัสไวไฟ
String GAS_ID = "AKfycbxEZxMyO__kSv3isaHixpEYVVKhpvREFn-KQC4VRoWL4dskf7S45GjiYruTzgMJcl77"; //--> spreadsheet script ID

#define SSID        "Nt-sice_2.4g"      // Wifi ที่จะเชื่อมต่อ 
#define PASSWORD    "99999999"     // รหัส Wifi
#define LINE_TOKEN  "sanm6DQwoj5xxe1l8gYBPeOsfDvWgOETkPeIimXK2wo"   // บรรทัดที่ 13 ใส่ รหัส TOKEN ที่ได้มาจากข้างบน

char ipaddress[20];

WiFiServer server(80);
String header;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

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

  if (Temperature != 2147483647 && Humidity != 2147483647) {
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

  lcd.begin ();
  lcd.backlight();
  lcd.home ();

  lcd.setCursor(0, 0);
  lcd.print("WIFI CONNECTING");
  lcd.setCursor(0, 1);
  lcd.print("PLEASE WAIT.....");


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

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected");
    lcd.clear();
  }

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();

  lcd.setCursor(0, 0);
  lcd.print("    KPS SMART   ");
  lcd.setCursor(0, 1);
  lcd.print("  WEB & STORING ");

  delay(5000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("OUR WEBSITE IP ");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());

}

// ----------------------------------------------------------------------------------------------
unsigned long time_ms;
unsigned long time_1000_ms_buf;
unsigned long time_sheet_update_buf;
unsigned long time_dif;

void loop()
{
  WiFiClient client = server.available();



  time_ms = millis();
  time_dif = time_ms - time_1000_ms_buf;

  // Read and print serial data every 1 sec
  if ( time_dif >= 1000 ) // 1sec
  {
    time_1000_ms_buf = time_ms;
    Temperature = dht.getTemperature();
    Humidity = dht.getHumidity();

    // Print serial messages
    /*if(Temperature != 2147483647 && Humidity != 2147483647){
      lcd.setCursor(0,0);
      lcd.print("Temperature: " + String(Temperature) + " C");
      lcd.setCursor(0,1);
      lcd.print("Humidity:" + String(Humidity) + " %");  // Print humidity value
      delay(100);
      }*/


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

  // WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();





            // Display the HTML web page
            client.println();
            client.println("<!DOCTYPE html>");
            client.println("<html>");
            client.println("<head>");
            client.println("<title>KPS Smart Silkworm House</title>");
            client.println("<meta charset='UTF-8'>");
            client.println("<meta name='viewport' content='width=device-width, initial-scale=1'>");
            client.println("<link rel='stylesheet' href='https://www.w3schools.com/w3css/4/w3.css'>");
            client.println("<style>");
            client.println("body {font-family: 'Times New Roman', Georgia, Serif;}");
            client.println("h1, h2, h3, h4, h5, h6 {");
            client.println("  font-family: 'Playfair Display';");
            client.println("  letter-spacing: 5px;");
            client.println("}");
            client.println("");
            client.println(".templogo{ margin-right: 200px; width: 50px; }");
            client.println(".humlogo{ margin-right: 200px; width: 50px; }");
            client.println(".auto{ margin-left: 10px; width: 30px; }");
            client.println(".line{ color: green; }");
            client.println(".googlesheet{ color: blueviolet; }");
            client.println(".w3-round{ margin-top: 150px; }");
            client.println("");
            client.println("</style>");
            client.println("<link rel='icon' type='image/x-icon' href='https://cdn-icons-png.flaticon.com/512/2206/2206241.png'>");
            client.println("</head>");
            client.println("<body>");
            client.println("");
            client.println("<!-- Navbar (sit on top) -->");
            client.println("<div class='w3-top'>");
            client.println("  <div class='w3-bar w3-white w3-padding w3-card' style='letter-spacing:4px;'>");
            client.println("    <img class='kpslogo' src='https://kalasinpit.ac.th/wp-content/uploads/2019/12/kps.png' alt='kpslogo' width='70px'>");
            client.println("    <a href='#home' class='w3-bar-item w3-button'>KPS Smart Silkworm House</a>");
            client.println("    <!-- Right-sided navbar links. Hide them on small screens -->");
            client.println("    <div class='w3-right w3-hide-small'>");
            client.println("      <a href='#about' class='w3-bar-item w3-button'>เกี่ยวกับ</a>");
            client.println("      <a href='#menu' class='w3-bar-item w3-button'>เรือนเลี้ยง</a>");
            client.println("      <a href='#contact' class='w3-bar-item w3-button'>ติดต่อ</a>");
            client.println("    </div>");
            client.println("  </div>");
            client.println("</div>");
            client.println("HTTP/1.1 200 OK");

            client.println("<!-- Header -->");
            client.println("<header class='w3-display-container w3-content w3-wide' style='max-width:1600px;min-width:500px' id='home'>");
            client.println("  <img class='w3-image' src='https://scontent.fkkc4-1.fna.fbcdn.net/v/t1.15752-9/322267154_848063973084902_3632468743667342700_n.jpg?_nc_cat=109&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeFs2Xtn-fikTHmNnz0ojL5sWrjkcYt9eYNauORxi315g4S0DIjy4NgfHbFUGegFI3Moy4w9KFf5eR7F7rCSd6ia&_nc_ohc=sSMrzM7Ik5sAX-Nm_SO&tn=4IwdnZHn_HsDQ5r2&_nc_ht=scontent.fkkc4-1.fna&oh=03_AdQUDe-HB27c8J2wN6OUlROC5hGBSaiUP3X_1YJSaKB2hA&oe=63DD368A' alt='Hamburger Catering' width='1800' height='50%'>");
            client.println("  <div class='w3-display-bottomleft w3-padding-large w3-opacity'>");
            client.println("    <h1 style='color: white;' class='w3-xxlarge'>ยินดีต้อนรับ</h1>");
            client.println("  </div>");
            client.println("</header>");

            client.println("<!-- Page content -->");
            client.println("<div class='w3-content' style='max-width:1100px'>");

            client.println("  <!-- About Section -->");
            client.println("  <div class='w3-row w3-padding-64' id='about'>");
            client.println("    <div class='w3-col m6 w3-padding-large w3-hide-small'>");
            client.println("     <img src='https://scontent.fkkc4-2.fna.fbcdn.net/v/t1.15752-9/321778670_533135965437591_5889267133503233823_n.jpg?_nc_cat=102&ccb=1-7&_nc_sid=ae9488&_nc_ohc=ITLtiDZG4h4AX_3qKOm&_nc_ht=scontent.fkkc4-2.fna&oh=03_AdQBC7le3O3GT8Waxon4vDj1T-i2xl7FUvXg6Ix1nAQQYQ&oe=63D8AC15' class='w3-round w3-image w3-opacity-min' alt='Table Setting' width='1800' >");
            client.println("    </div>");

            client.println("    <div class='w3-col m6 w3-padding-large'>");
            client.println("      <h1 class='w3-center'>เรากำลังทำอะไร</h1><br>");
            client.println("      <h5 class='w3-center'>ชื่องานวิจัย</h5>");
            client.println("      <p class='w3-large'>ศึกษาความสัมพันธ์ระหว่างปัจจัยแวดล้อมกับการกินอาหารของหนอนไหม เพื่อพัฒนา โมเดลโรงเรือนเลี้ยงไหมอัจฉริยะ Smart Silkworm House & Smart Web & Storing.<span class='w3-tag w3-light-grey'></span> </p>");
            client.println("<p class='w3-large w3-text-grey w3-hide-medium'>ไหม เป็นผีเสื้อกลางคืนชนิด Bombyx mori อยู่ในวงศ์ Bombycidae ตัวอ่อนเรียกว่า ตัวไหม หรือ หนอนไหม มีความสำคัญทางเศรษฐกิจในการปลูกหม่อนเลี้ยงไหม เนื่องจากมันสามารถให้เส้นใยเป็นเส้นไหม ผีเสื้อไหมไม่ปรากฏในป่าตามธรรมชาติ การสืบพันธุ์และดำรงชีวิตขึ้นอยู่กับการดูแลของมนุษย์เท่านั้น อาหารที่มันชอบก็คือใบหม่อนขาว (Morus alba) แต่อาจกินใบของพืชชนิดอื่นได้ด้วย เช่น Osage Orange หรือ Tree of Heaven เดิมเป็นสัตว์พื้นเมืองของประเทศจีน เส้นใยที่นำมาทอผ้าไหมนั้น เป็นเส้นใยที่ได้จากรังหนอนไหม หนอนไหมเป็นตัวอ่อนของผีเสื้อชนิดหนึ่ง หลังจากผีเสื้อวางไข่ได้ 10 – 12 วัน ไข่จะฟักออกมาเป็นตัวหนอนเรียกว่า “หนอนไหม” หนอนไหมเจริญเติบโตได้เร็วมาก เพาระกินใบหม่อนเป็นอาหาร การเลี้ยงไหมจึงต้องปลูกต้นหม่อนไปด้วยกัน หนอนไหมต้องลอกคราบเป็นระยะ ๆ เมื่อมีอายุ 3 – 4 วัน หนอนไหมจะหยุดกินอาหารและอยู่เฉย ๆ ประมาณ 1 วัน จึงลอกคราบ ระยะนี้เรียกว่า ไหมนอน ต่อไปตัวและหัวจะใหญ่ขึ้นระยะนี้เรียกว่า ไหมตื่น มักจะกินอาหารจุมากในระยะนี้ โดยทั่วไปจะลอกคราบ 4 ครั้ง เมื่อโตเต็มที่อายุประมาณ 9 วัน จะหยุดลอกคราบเรียกระยะนี้ว่าไหมสุก มันหยุดกินอาหาร แล้วเริ่มทำงานโดยพ่นของเหลวชนิดหนึ่งออกมาทางปาก เมื่อของเหลวนี้ถูกอากาศจะแข็งตัวเป็นเส้นไหม ซ้อนกันเป็นชั้น ๆ หุ้มตัวไหมไว้ เรียกว่า รังไหม เราได้เส้นใยไหมจากรังไหมนี้เอง หนอนไหมจะชักใยอยู่สร้างรังอยู่ ประมาณ 2 - 3 วัน จะลอกคราบเป็นดักแด้ แล้วกลายเป็นผีเสื้อต่อไปตามวงจรชีวิตของมัน</p>");
            client.println(" </div>");
            client.println("</div>");
            client.println("<hr>");

            client.println("<!-- Menu Section -->");
            client.println("<div class='w3-row w3-padding-64' id='menu'>");
            client.println("<div class='w3-col l6 w3-padding-large'>");
            client.println("<h1 class='w3-center'>สถานะของเรือนเลี้ยง</h1><br>");
            client.println("<img class='templogo' src='https://i.etsystatic.com/23821301/r/il/dcbcfc/2484217158/il_570xN.2484217158_oi4q.jpg'>");
            client.println("<h4>Temperature</h4>");
            client.print("<p class='w3-text-grey'>ค่าอุณหภูมิปัจจุบันอยู่ที่</p>");

            if (Temperature == 2147483647) {
              client.println("Error from sensor, Please reload the page.");
            } else {
              if (Temperature > 23 && Temperature < 27) {
                client.println(String(Temperature) + " C" + " อุณหภูมิปกติ");
              } else if (Temperature <= 23) {
                client.println(String(Temperature) + " C" + " อุณหภูมิเริ่มต่ำ ระบบกำลังเเก้ไข");
              } else if (Temperature >= 27) {
                client.println(String(Temperature) + " C" + " อุณหภูมิเริ่มสูง ระบบกำลังเเก้ไข");
              }
            }

            //client.print("ค่าอุณหภูมิปัจจุบันอยู่ที่ "+String(Temperature) + " C");
            client.println("");
            client.println("<br><br><img class='humlogo' src='https://media.istockphoto.com/id/899797812/vector/humidity-icon-humidity-weather-sensor-label-sticker-icon.jpg?s=612x612&w=0&k=20&c=5k5kPo781602YBSr3wfCb2irVDxcqPTDj7HO2lousqI='>");
            client.println("<h4>Humidity</h4>");
            client.println("<p class='w3-text-grey'>ค่าความชื้นสัมพัทธ์ปัจจุบันอยู่ที่</p>");

            if (Humidity == 2147483647) {
              client.println("Error from sensor, Please reload the page.");
            } else {
              client.println(String(Humidity) + " %");
            }
            //client.print("ค่าความชื้นสัมพัทธ์ปัจจุบันอยู่ที่ "+String(Humidity) + " %");
            client.println("<br><br><br><img class='auto' src='https://cdn-icons-png.flaticon.com/512/5188/5188372.png'>");
            client.println("<h4>Full Automation</h4>");
            client.println("<p class='w3-text-grey'>ระบบจะทำงานอย่างสมบูรณ์ด้วยระบบอัตโนมัติ</p>");
            client.println("<br><img class='humlogo' src='https://images.assetsdelivery.com/compings_v2/iconscart/iconscart2007/iconscart200704984.jpg' alt=''>");
            client.println("<h4>Data Storing</h4>");
            client.println("<p class='w3-text-grey'>เก็บค่าข้อมูลทุก 2 ชั่วโมงไว้ที่ <a href='https://docs.google.com/spreadsheets/d/1pg8FynOzDpGdC3SYdt7IWZGKFPQHit1iH7p8B-OOBBQ/edit#gid=0' class='googlesheet'>Google Sheet</a></p><br>");
            client.println("<a href='https://line.me/ti/g/hyu93R-7E8'><img class='humlogo' src='https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTSttApzm2yJ9eUg84BSdDdcwJbvhXB3xlZgg&usqp=CAU' alt=''></a>");
            client.println("<h4>LINE Notification</h4>");
            client.println("<p class='line'>Click LINE logo to join us!</p>");
            client.println("<p class='w3-text-grey'>ถ้าหากค่าต่างๆนั้นเกินกำหนด ระบบจะอัติโนมัติจะเริ่มทำงานเเละเเจ้งเตือนผ่านไลน์</p><br>");
            client.println("</div>");
            client.println("");
            client.println("<div class='w3-col l6 w3-padding-large'>");
            client.println("<img src='https://scontent.fkkc4-2.fna.fbcdn.net/v/t1.15752-9/320275922_562047742143817_976145023483011697_n.png?_nc_cat=103&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeGkkU7ZDTNv3qs9ktOuvjWrld3Rsm5Nua-V3dGybk25r7Tj2uvI-WlJ9wQ-2ahSYtII5sjLAguP19v5CDQTExRE&_nc_ohc=oo54Wiv9yzgAX_XLYK4&_nc_ht=scontent.fkkc4-2.fna&oh=03_AdQ915X1Gkplt2Gt_fF5V_PYA8H9ETautuGKUYwSMPI8rA&oe=63DD4F4E' class='w3-round w3-image w3-opacity-min' alt='Menu' style='width:100%' >");
            client.println(" </div>");
            client.println("</div>");
            client.println("");
            client.println("<hr>");
            client.println("</body>");
            client.println("</html>");



            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }

}

void linenotify() {
  if (Temperature != 2147483647 && Humidity != 2147483647) {
    LINE.notify("Humidity: " + String(Humidity) + " %");
    LINE.notify("Temperature: " + String(Temperature) + " C");

  }
}
