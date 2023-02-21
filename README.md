<h1>Smart IoT Silkworm House (ศึกษาความสัมพันธ์ระหว่างปัจจัยแวดล้อมกับการกินอาหารของหนอนไหม เพื่อพัฒนา โมเดลโรงเรือนเลี้ยงไหมอัจฉริยะ)</h1>
High School Automation System Advicer and Researcher at Kalasinpittayasan School, Kalasin, Thailand<br>
<br>

***Demo Model***

<img src="https://i.ibb.co/g9W5Gbd/324126504-1301291720717573-16178354865982895-n.jpg" width="600px">
<hr>

***1. ESP8266 WebServer, Google Sheet, LINE Nofity***

Brief :These are using Node MCU ESP8266 to create WebServer and display local IP address on LCD, Display Temperature and Humidity real-time on WebServer, Notify to user every 2 hours with LINE Notify and Storing on Google Sheet<br><br>

***First step!*** <br>
User must connect to the same as WIFI as ESP8266 for using the WebServer<br>
<img src="https://i.ibb.co/tmPN76p/322300049-1627821927657238-8228212391730691221-n.jpg" width = "600px">

- ***ESP8266 WebServer Realtime Temp&Humidity***<br>
Sample: 

<img src ="https://i.ibb.co/nzrzLKj/323544356-566543165032380-4557618639192402392-n.png" width ="1000px"><br>

<img src ="https://i.ibb.co/yyXJgbz/322148751-5924590350937264-6916243048792791185-n.png" width ="1000px"><br>

- ***LINE Notify***<br>
Sample: 

<img src ="https://i.ibb.co/Y06Bv61/324476870-1209084013379455-458341458619794550-n.png"><br>

- ***Google Sheet Auto Data Storing***<br>
Sample: 

<img src="https://i.ibb.co/QKy3YRX/325057277-899372167763665-7414610991203822715-n.png" width ="600px"><br>

- ***Circuit Diagram***<br>
<img src="https://i.ibb.co/58gS4VS/322115536-537882008402935-6612989247889214440-n.png">

<hr>

***2. Automation With Arduino UNO***

- ***Status Panel***
<img src="https://i.ibb.co/kQ7P8kT/322397953-701336111729569-6141866807460097480-n.jpg">

- ***Circuit Diagram***
<img src="https://i.ibb.co/VJFTzP9/323100732-5710280379051400-5948429062708771341-n.png">

- ***How does it work?***
  - Reading temperature and humidity values from the DHT11 sensor. If there is no error in reading the values, it will display the values on an LCD screen.
Then it checks if the temperature value is less than or equal to 23 degrees Celsius, if so, it will turn on a relay (Heater) and an LED that indicates the heater is on. If the temperature value is greater than or equal to 27 degrees, it will turn on a relay (cooler) and an LED that indicates the cooler is on. If there is an error reading the values, it will keep trying to read new values until there is no error.
  - Checking if a button is pressed. If it is, it will turn on a LED light, if it is pressed again, it will turn off the LED light.

<h1>Picture Gallery</h1>

***Field Visit***
<img src="https://i.ibb.co/z2m7NmN/322267154-848063973084902-3632468743667342700-n.jpg" width = "800px">
<img src="https://i.ibb.co/7g7x1Fy/324968795-727011102008501-970633332591124266-n.png" width="800px">

<img src ="https://i.ibb.co/wzS0cBs/325136864-971786480466755-774190710644215631-n.png" width = "800px">


***Demo House***

<img src="https://i.ibb.co/GvHwbkn/318212896-552571113256919-2875200899167798168-n.png" width = "800px">

<img src = "https://scontent.fbkk7-3.fna.fbcdn.net/v/t1.15752-9/324904773_910456339981364_983006140400443534_n.jpg?_nc_cat=105&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeGKkReNQY8q-663y48h59VsvpUonst2Ghq-lSiey3YaGinWfPcrdksL28lvjjCGusQbK9cV4_TwBpFQ6ZjaVPtv&_nc_ohc=ZkL3dBO-GM8AX9q2MYR&_nc_ht=scontent.fbkk7-3.fna&oh=03_AdSmWZ_Nf89XKqBd1gQFRDZ02tMD5Y0oq6Mdifdd5rTBkA&oe=63F95DA7" width = "800px">