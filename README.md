<h1>Smart IoT Silkworm House</h1>
High School Automation System Advicer and Researcher at Kalasinpittayasan School, Kalasin, Thailand<br>



***Demo Model***

<img src="https://scontent.fbkk12-1.fna.fbcdn.net/v/t1.15752-9/325255280_3260279287569938_85300460509142534_n.jpg?_nc_cat=106&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeGXXOor69GAt-H3920Jac5g3MhqeobJbdrcyGp6hslt2kqFoZ_wG9IkM51o4WZJauroaGUG9WCapS0qNE_OvVXM&_nc_ohc=T2hkw6gBzskAX9_p6vE&_nc_ht=scontent.fbkk12-1.fna&oh=03_AdQXY_gJd8RQ24um_1Ne0yAOml5v__ANt6sQFB2BXKT4mQ&oe=63EA5DFF" width="800px">
<hr>

***1. ESP8266 WebServer, Google Sheet, LINE Nofity***

Brief :These are using Node MCU ESP8266 to create WebServer and display local IP address on LCD, Display Temperature and Humidity real-time on WebServer, Notify to user every 2 hours with LINE Notify and Storing on Google Sheet<br><br>

***First step!*** <br>
User must connect to the same as WIFI as ESP8266 for using the WebServer<br>
<img src="https://scontent.fbkk12-2.fna.fbcdn.net/v/t1.15752-9/322278196_685715766588441_8973058714565094357_n.jpg?_nc_cat=104&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeETGknJAlFT2HuheN-liy3vM3TK1OkQcVEzdMrU6RBxUb9sbkPNbML36bgyThY6lpiLiN0Nb6_bPACKCkZNdJ8R&_nc_ohc=yA5Tvo-iKjkAX9E3B2d&_nc_ht=scontent.fbkk12-2.fna&oh=03_AdSAwjQdNCWnf4HAfQ7uzSN8ITgWzqfv3C_fZGS7TOPXbA&oe=63E6656D" width = "600px">

- ***ESP8266 WebServer Realtime Temp&Humidity***<br>
Sample: 

<img src ="https://scontent.fbkk12-1.fna.fbcdn.net/v/t1.15752-9/323544356_566543165032380_4557618639192402392_n.png?_nc_cat=101&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeHex41nJL_Lr4Jwc0ee1vgmoV7el7cowImhXt6XtyjAiU66CXmz19dwYLGks7hCY0qewPHbZCt5zRGqeP2uXBLO&_nc_ohc=-Edy4v_JqSMAX811An3&_nc_ht=scontent.fbkk12-1.fna&oh=03_AdSxu8s6AlJGbVpQPDkYgY6TawIqoduPBnPKeb_dUFqiTA&oe=63E65716" width ="1000px"><br>

<img src ="https://scontent.fbkk12-2.fna.fbcdn.net/v/t1.15752-9/322148751_5924590350937264_6916243048792791185_n.png?_nc_cat=104&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeF1lKMTHvnI3MJrc83lCIAajMNctlYjeU6Mw1y2ViN5TkO9SCqdh1OqBvtv4xEH3d0yg9Rfmmg7G3PfrkA2v5Mb&_nc_ohc=5yh-ByzI-eMAX_wyY4U&_nc_ht=scontent.fbkk12-2.fna&oh=03_AdRnB-OW4HzTOrkBvieIrQX_vP_5KeNxoy06jl2SXTM4pw&oe=63E6521D" width ="1000px"><br>

- ***LINE Notify***<br>
Sample: 

<img src ="https://scontent.fbkk12-4.fna.fbcdn.net/v/t1.15752-9/324476870_1209084013379455_458341458619794550_n.png?_nc_cat=110&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeEShckN8biPtXgzIIpJR3FRPFlxf_9_TbM8WXF__39Ns-zwoES6HBA4hyfZXnxwXZYiZruA3O_CHsTefRYUiS0L&_nc_ohc=OvqRKPChafIAX_DHTE1&tn=4IwdnZHn_HsDQ5r2&_nc_ht=scontent.fbkk12-4.fna&oh=03_AdRsn4vljm-ydsxCGFUFz4GNi0gowgPyxqeScRMlNjkgnQ&oe=63E64D77"><br>

- ***Google Sheet Auto Data Storing***<br>
Sample: 

<img src="https://scontent.fbkk12-1.fna.fbcdn.net/v/t1.15752-9/325057277_899372167763665_7414610991203822715_n.png?_nc_cat=108&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeEFwdVROK2LQSLv0wwezS9aIJiYnPcgWaAgmJic9yBZoGpcXx_P80SZjGRztTLiTHl5xwZp_uvFXOT8RPnxW65N&_nc_ohc=ZQkSRuN3UVkAX-yGkU7&_nc_ht=scontent.fbkk12-1.fna&oh=03_AdQikfVN_ozRmxtbdEcvRmMLScOS_fmyMLk9EquijPu58Q&oe=63E659F2" width ="600px"><br>

- ***Circuit Diagram***<br>
<img src="https://scontent.fbkk8-2.fna.fbcdn.net/v/t1.15752-9/322115536_537882008402935_6612989247889214440_n.png?_nc_cat=107&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeHlk3Qbz21Xim1To9zfDTS-THm8MsR_mS5MebwyxH-ZLgl8QUxKWACEmQ4AXUsdj3hIg9ot_InQT5yXx2zX6GGb&_nc_ohc=cxTihY084IcAX_tuR4U&tn=4IwdnZHn_HsDQ5r2&_nc_ht=scontent.fbkk8-2.fna&oh=03_AdR9MNeOYgmfjskYIuq7h2EcHHp4Ry-6Tf2mqjQgY4EwdA&oe=63E656E6">

***2. Automation With Arduino UNO***

- ***Status Panel***
<img src="https://scontent.fbkk12-4.fna.fbcdn.net/v/t1.15752-9/322628812_1163049577906795_8138142499824776287_n.png?_nc_cat=103&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeH9ifjYsWTbtUQuK3oOazo1yDu2vMicq2zIO7a8yJyrbCU1GEr_C6KoPOBHpP9oBwvzNnpE1gBBhlLrGtni7Qad&_nc_ohc=ub04OS1hN2cAX8uQh6I&tn=4IwdnZHn_HsDQ5r2&_nc_ht=scontent.fbkk12-4.fna&oh=03_AdQ_XW4AUHhPdBOxcg28g_rodwlXnL6AYpZli_fqlU_BvA&oe=63E65D97">

- ***Circuit Diagram***
<img src="https://scontent.fbkk12-1.fna.fbcdn.net/v/t1.15752-9/323100732_5710280379051400_5948429062708771341_n.png?_nc_cat=106&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeGugKyWqfLgRmlde4lARX16jU2SAeGbRMSNTZIB4ZtExBoJXrLKjZUGUhsJffxYlk-ziqqWY-JjUTQywxyugZbG&_nc_ohc=ukboG1QxskcAX83qlKo&_nc_ht=scontent.fbkk12-1.fna&oh=03_AdT40FnRouaWie4V78qulfEJunl0q4c55T4jP0mMJzkbZA&oe=63E66CF3">

- ***How does it work?***
  - Reading temperature and humidity values from the DHT11 sensor. If there is no error in reading the values, it will display the values on an LCD screen.
Then it checks if the temperature value is less than or equal to 23 degrees Celsius, if so, it will turn on a relay (Heater) and an LED that indicates the heater is on. If the temperature value is greater than or equal to 27 degrees, it will turn on a relay (cooler) and an LED that indicates the cooler is on. If there is an error reading the values, it will keep trying to read new values until there is no error.
  - Checking if a button is pressed. If it is, it will turn on a LED light, if it is pressed again, it will turn off the LED light.

<h1>Picture Gallery</h1>

***Field Visit***


<img src="https://scontent.fbkk9-2.fna.fbcdn.net/v/t1.15752-9/322267154_848063973084902_3632468743667342700_n.jpg?_nc_cat=109&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeFs2Xtn-fikTHmNnz0ojL5sWrjkcYt9eYNauORxi315g4S0DIjy4NgfHbFUGegFI3Moy4w9KFf5eR7F7rCSd6ia&_nc_ohc=Etx5AxpAGGQAX9xGvL1&tn=4IwdnZHn_HsDQ5r2&_nc_ht=scontent.fbkk9-2.fna&oh=03_AdSCdZrt8YjW9NRmKtedPIJ1_rLzjpjptK8lcxSeBeraoQ&oe=63E6710A" width="800px">

<img src ="https://scontent.fbkk8-4.fna.fbcdn.net/v/t1.15752-9/324968795_727011102008501_970633332591124266_n.png?_nc_cat=100&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeHzmHROmz1GNnC7izjB_qKSgkPS9Sox0h6CQ9L1KjHSHiND4MUbX_46CU73ubsHVOfMqmFOfgfXO6qPCJMkh0q2&_nc_ohc=zO3Sky4UrbIAX_Eu7VD&_nc_ht=scontent.fbkk8-4.fna&oh=03_AdSCxXJ6qQTiQ9kwMrhqQIOaiW4FKxh7xxz4QEpOpwrlxw&oe=63E66C38" width = "800px">

<img src="https://scontent.fbkk12-4.fna.fbcdn.net/v/t1.15752-9/325136864_971786480466755_774190710644215631_n.png?_nc_cat=103&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeHmIWmaABrwBGbbBneyY51ikZGLWqbC6NCRkYtapsLo0CCjsDoWRb6D6wab5TfFbiiwTVWEYJnBPRpaA9yFtlbA&_nc_ohc=NYzfKU92v9wAX-8dAHV&_nc_ht=scontent.fbkk12-4.fna&oh=03_AdSYz0YeZt6NyfMi4daWbQ0Jl-CqS8sE3l4G4_-k9UElyg&oe=63E6801D" width = "800px">

<img src="https://scontent.fbkk12-2.fna.fbcdn.net/v/t1.15752-9/318212896_552571113256919_2875200899167798168_n.png?_nc_cat=104&ccb=1-7&_nc_sid=ae9488&_nc_eui2=AeGNtdVUYpYcrR69Skt8tCMCJ_UBGBpBB98n9QEYGkEH36Ej3bLKUh7djSIVQdlJDzYbTZ2pQU0Ryn7E_9GDHKV7&_nc_ohc=mVKMzInIy5MAX-sj3BZ&tn=4IwdnZHn_HsDQ5r2&_nc_ht=scontent.fbkk12-2.fna&oh=03_AdSkZl3s6e7BoS2oKQi4SVF0S1oe9wkK2qcqX9NOvCDg1w&oe=63EA591D" width = "800px">
