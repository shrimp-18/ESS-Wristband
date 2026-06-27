<h2> ESSync Wristband</h2>
A gesture-controlled referee wristband that automates match timing in Taekwondo. Using an accelerometer and microcontroller, it detects the referee’s calibrated start and stop gestures and wirelessly updates the central timer visible to everyone. This system removes manual jury control, ensuring accurate, fair, and transparent timekeeping.<br>
<br>

<b>How it works :</b><br>
-> Referee wants to stop the match.<br>
-> They make a swift hand movement used traditionally in Taekwondo.<br>
-> Players see this hand movement and stop.<br>
-> ESSync senses this swift hand movement and sends a signal to the central timer to stop.<br>
-> The central timer stops, and so do all the other sensors.<br>
-> Similar process repeats when the referee wants to restart the match.<br>

<img width="420" height="595" alt="zinee" src="https://github.com/user-attachments/assets/59e18165-39b0-43ca-adf2-a6b3911683fb" />


<br> <br>
<img width="698" height="349" alt="wristband_cad" src="https://github.com/user-attachments/assets/7207a4ab-dc7d-4716-93c8-1727c195331d" />



<br><br>

<h2>Why is ESSync Neded?</h2>
In Taekwondo matches, round timing is controlled by officials sitting at the jury
table rather than by the referee overseeing the bout. This separation often leads to
inconsistencies in the start and stop of the timer,  whether due to human delay,
miscommunication, or, in some cases, bias. As a result, athletes can be unfairly
advantaged or disadvantaged by inaccurate match durations, compromising the
fairness and integrity of the competition. There is a critical need for a referee-operated,
automated, and transparent timing system that ensures real-time
synchronisation and impartial timekeeping.

<br>
<h2>So Whats the solution?!</h2>
-A gesture-controlled wristband worn by referees to automate match timing.<br>
-Uses an accelerometer and microcontroller to detect specific referee gestures.<br>
-The downward “stop” motion of the hand instantly triggers the central arena timer wirelessly.<br>
-Calibrated for each referee to prevent false detections and ensure precision.<br>
-Removes jury dependency, ensuring fair, transparent, and real-time timekeeping.<br>
-The timer part of taekwondo matches isn’t automated yet and really needs a cheap and
effective solution.<br>
-Wristbands are easy to make and reliable
<br><br>

<h2>Components and their uses</h2>
-ESP 32 C3 DEV KIT M1 :- Main MCU, the 'Brain' of the Wristband.<br>
-MPU6050 :- Accelerometer to sense swift hand gestures. <br>
-1.3I INCH 240X240 DISPLAY :- A colour screen to display timer and other details. <br>
-MT3608 :- Boost converter module to modulate voltage. <br>
-TP4056 :- Charger for LiPo Battery. <br>

<h2>Top PCB</h2>
<img width="404" height="345" alt="image" src="https://github.com/user-attachments/assets/fce5ac67-f28a-49bb-b9c6-673578531011" /><br>
<img width="755" height="405" alt="image" src="https://github.com/user-attachments/assets/78d6440d-ddb2-49bf-ba75-79f2bc257070" /><br>



<h2>Bottom PCB</h2>
<img width="518" height="377" alt="image" src="https://github.com/user-attachments/assets/3b48a4ee-9184-496e-b987-144083d6660e" /> <br>
<img width="659" height="404" alt="image" src="https://github.com/user-attachments/assets/fe39cb69-ffb3-4126-8afb-bab32b30db9e" /><br>


The project is made with 2 PCBs, the upper one holds the screen, and the bottom one holds the MCU and all other components. This
was done to manage the size of the project and not make it too wide, as it's supposed to be worn on your hand. In future, I plan to make
it more compact.


<br>
<h2>Fusion Files:</h2>
https://a360.co/4gCFWl9
<br> <br>
<h2>Bill Of Materials:</h2>
| S No. | Reference     | Value                 | Product Name                                        | Note                                | Quantity | Cost     | Link                                                                                                                                                                                                                                                                                                                     |
| ----- | ------------- | --------------------- | --------------------------------------------------- | ----------------------------------- | -------- | -------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| 1     | SPI_SCREEN1   | Conn_01x07            | Connector PinSocket P2.54mm Vertical 1x7            | On Top PCB, for SPI Screen          | 1        | 0.09US$  | [https://robocraze.com/products/40x1-female-berg-strip](https://robocraze.com/products/40x1-female-berg-strip)                                                                                                                                                                                                           |
| 2     |               |                       | 1.3 Inch 240X240 SPI SCREEN                         | Not on PCB, External                | 1        | 9.5 US$  | [https://www.waveshare.com/1.3inch-lcd-module.htm](https://www.waveshare.com/1.3inch-lcd-module.htm)                                                                                                                                                                                                                     |
| 3     | U3            | ESP32-C3-DevKitM-1    | ESP 32 C3 DEVKIT M1                                 | On Bottom PCB                       | 1        | 10.11US$ | [https://www.electropi.in/espressif-esp32-c3-devkitm-1-n4x-development-board](https://www.electropi.in/espressif-esp32-c3-devkitm-1-n4x-development-board)                                                                                                                                                               |
| 4     | J1, J2        | Conn_01x15            | Connector PinSocket 1x15_P2.54mmVertical            | On Lower side of Top PCB, for ESP   | 2        | 0.09US$  | https://robocraze.com/products/40x1-female-berg-strip?_pos=3&_sid=d12dcc8d2&_ss=r                                                                                                                                                                                                                                        |
| 5     | J7,J8,J9,J10  | Conn_01x01            | Connector PinHeader1x01_P1mm_Vertical               | On Bottom PCB, for MT3608           | 4        | 0.06US$  | [https://robocraze.com/products/40x1-pin-2-54mm-pitch-male-berg-strip](https://robocraze.com/products/40x1-pin-2-54mm-pitch-male-berg-strip)                                                                                                                                                                             |
| 6     |               |                       | MT3608                                              | Not on PCB, External                | 1        | 0.47US$  | [https://www.flyrobo.in/mt3608-2a-dc-dc-boost-ultra-power-module](https://www.flyrobo.in/mt3608-2a-dc-dc-boost-ultra-power-module)                                                                                                                                                                                       |
| 7     | MPU6050       | Conn_01x08            | Connector PinHeader1x08_P2.54mmVertical             | On Bottom PCB, for MPU6050          | 1        | 0.06US$  | [https://robocraze.com/products/40x1-pin-2-54mm-pitch-male-berg-strip](https://robocraze.com/products/40x1-pin-2-54mm-pitch-male-berg-strip)                                                                                                                                                                             |
| 8     |               |                       | MPU6050                                             | Not on PCB, External                | 1        | 1.63US$  | [https://robocraze.com/products/mpu-6050-triple-axis-accelerometer-gyroscope-module](https://robocraze.com/products/mpu-6050-triple-axis-accelerometer-gyroscope-module)                                                                                                                                                 |
| 9     | J5,J6,J11,J12 | Conn_01x01            | Connector PinHeader1x01_P1mm Vertical               | On Bottom PCB, for TP4056           | 4        | 0.06US$  | [https://robocraze.com/products/40x1-pin-2-54mm-pitch-male-berg-strip](https://robocraze.com/products/40x1-pin-2-54mm-pitch-male-berg-strip)                                                                                                                                                                             |
| 10    |               |                       | TP4056                                              | Not on PCB, External                | 1        | 0.17US$  | [https://quartzcomponents.com/products/tp4056-battery-charging-module](https://quartzcomponents.com/products/tp4056-battery-charging-module)                                                                                                                                                                             |
| 11    | S1            | Tactile Button, 160gf | PCM_JLCPCB:SW_TS-1088-AR02016                       | On Bottom PCB, ESP ON Switch        | 1        | 0.06US$  | [https://jlcpcb.com/partdetail/XUNPU-TS_1088AR02016/C720477](https://jlcpcb.com/partdetail/XUNPU-TS_1088AR02016/C720477)                                                                                                                                                                                                 |
| 12    | SW1           | SW_Slide_DPDT         | Button_Switch_SMD:SW_SPDT_PCM12                     | On Bottom PCB, Power ON/OFF         | 1        | 1.2US$   | [https://www.digikey.in/en/products/detail/c-k/PCM12SMTR/1640112](https://www.digikey.in/en/products/detail/c-k/PCM12SMTR/1640112)                                                                                                                                                                                       |
| 13    | Battery1      | Conn_01x02            | Connector_JST:JST_PH_B2B-PH-K_1x02_P2.00mm_Vertical | On Bottom PCB, for Battery          | 1        | 0.05US$  | [https://robu.in/product/b2b-xh-alfsn-jst-1x2p-2p-xh-tin-2-25%E2%84%8385%E2%84%83-3a-1-2-5mm-brass-direct-insert-pluginp2-5mm-wire-to-board-connector-rohs/](https://robu.in/product/b2b-xh-alfsn-jst-1x2p-2p-xh-tin-2-25%E2%84%8385%E2%84%83-3a-1-2-5mm-brass-direct-insert-pluginp2-5mm-wire-to-board-connector-rohs/) |
| 14    |               |                       | Battery                                             | Not on PCB, External                | 1        | 1.69US$  | [https://robocraze.com/products/450mah-3-7v-lipo-rechargeable-battery](https://robocraze.com/products/450mah-3-7v-lipo-rechargeable-battery)                                                                                                                                                                             |
| 15    | C1            | 0.1uF                 | Capacitor_SMD:C_0603_1608Metric                     | On Bottom PCB, Decoupling Capacitor | 1        | 0.04US$  | [https://robu.in/product/0603b104j500nt-fh-50v-100nf-x7r%C2%B15-0603-multilayer-ceramic-capacitors-mlcc-smd-smt-rohs/](https://robu.in/product/0603b104j500nt-fh-50v-100nf-x7r%C2%B15-0603-multilayer-ceramic-capacitors-mlcc-smd-smt-rohs/)                                                                             |
| 16    |               |                       | PCBs                                                |                                     | 2        | 2US$     | [https://cart.jlcpcb.com/quote](https://cart.jlcpcb.com/quote)                                                                                                                                                                                                                                                           |
| 17    |               |                       | 3D-Printing Case                                    |                                     | 1        | 4US$     | [https://zbotic.in/product/online-3d-printing-service](https://zbotic.in/product/online-3d-printing-service)                                                                                                                                                                                                             |




