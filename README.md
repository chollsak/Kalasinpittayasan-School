<h1>Smart IoT Silkworm House (ศึกษาความสัมพันธ์ระหว่างปัจจัยแวดล้อมกับการกินอาหารของหนอนไหม เพื่อพัฒนา โมเดลโรงเรือนเลี้ยงไหมอัจฉริยะ)</h1>
High School Automation System Advicer and Researcher at Kalasinpittayasan School, Kalasin, Thailand<br>
<br>

***Demo Model***

<img src="/silkiot/lightondemo.jpg">
<hr>

***1. ESP8266 WebServer, Google Sheet, LINE Nofity***

Brief :These are using Node MCU ESP8266 to create WebServer and display local IP address on LCD, Display Temperature and Humidity real-time on WebServer, Notify to user every 2 hours with LINE Notify and Storing on Google Sheet<br><br>

***First step!*** <br>
User must connect to the same as WIFI as ESP8266 for using the WebServer<br>
<img src="/silkiot/serverboxondemo.jpg" width = "600px">

- ***ESP8266 WebServer Realtime Temp&Humidity***<br>
Sample: 

<img src ="/silkiot/mainweb.png" width ="1000px"><br>

<img src ="/silkiot/statusonweb.png" width ="1000px"><br>

- ***LINE Notify***<br>
Sample: 

<img src ="/silkiot/linenoti.png"><br>

- ***Google Sheet Auto Data Storing***<br>
Sample: 

<img src="/silkiot/data.png" width ="600px"><br>

- ***Circuit Diagram***<br>
<img src="/silkiot/circuitserver.png">

<hr>

***2. Automation With Arduino UNO***

- ***Status Panel***
<img src="/silkiot/image.png">

- ***Circuit Diagram***
<img src="/silkiot/circuitmonitor.png">

- ***How does it work?***
  - Reading temperature and humidity values from the DHT11 sensor. If there is no error in reading the values, it will display the values on an LCD screen.
Then it checks if the temperature value is less than or equal to 23 degrees Celsius, if so, it will turn on a relay (Heater) and an LED that indicates the heater is on. If the temperature value is greater than or equal to 27 degrees, it will turn on a relay (cooler) and an LED that indicates the cooler is on. If there is an error reading the values, it will keep trying to read new values until there is no error.
  - Checking if a button is pressed. If it is, it will turn on a LED light, if it is pressed again, it will turn off the LED light.

<h1>Picture Gallery</h1>

***Field Visit***
<img src="/silkiot/fieldvisit.jpg" width = "800px">
<img src="/silkiot/fieldvisit1.png" width="800px">

<img src ="/silkiot/fieldvisit2.png" width = "800px">


***Demo House***

<img src="/silkiot/demo1.png" width = "800px">

<img src = "/silkiot/demo2.jpg" width = "800px">

***How its going!***
<img src="/silkiot/S__17801229_0.jpg" width = "800px">
<img src="/silkiot/price2.jpg" width = "800px">