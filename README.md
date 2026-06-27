# ESSync Wristband

A gesture-controlled referee wristband that automates match timing in Taekwondo. Using an accelerometer and microcontroller, it detects the referee’s calibrated start and stop gestures and wirelessly updates the central timer visible to everyone. This system removes manual jury control, ensuring accurate, fair, and transparent timekeeping.

---

## How it works

- Referee wants to stop the match.
- They make a swift hand movement used traditionally in Taekwondo.
- Players see this hand movement and stop.
- ESSync senses this swift hand movement and sends a signal to the central timer to stop.
- The central timer stops, and so do all the other sensors.
- Similar process repeats when the referee wants to restart the match.
<img width="420" height="595" alt="zine3" src="https://github.com/user-attachments/assets/90ddc32b-bdd7-4aac-a49e-6c9121ed8df6" />


<br>


<img width="588" height="328" alt="image" src="https://github.com/user-attachments/assets/ddb921ac-2ccd-44aa-aa3c-4f68d9c3d26a" />

<img width="551" height="342" alt="image" src="https://github.com/user-attachments/assets/61bfc489-0fd6-4e77-9425-d20bfbcab55e" />





---

## Why is ESSync Needed?

In Taekwondo matches, round timing is controlled by officials sitting at the jury table rather than by the referee overseeing the bout. This separation often leads to inconsistencies in the start and stop of the timer, whether due to human delay, miscommunication, or, in some cases, bias.
As a result, athletes can be unfairly advantaged or disadvantaged by inaccurate match durations, compromising the fairness and integrity of the competition.
There is a critical need for a referee-operated, automated, and transparent timing system that ensures real-time synchronisation and impartial timekeeping.

---

## So What's the solution?!

- A gesture-controlled wristband worn by referees to automate match timing.
- Uses an accelerometer and microcontroller to detect specific referee gestures.
- The downward "stop" motion of the hand instantly triggers the central arena timer wirelessly.
- Calibrated for each referee to prevent false detections and ensure precision.
- Removes jury dependency, ensuring fair, transparent, and real-time timekeeping.
- The timer part of Taekwondo matches isn’t automated yet and really needs a cheap and effective solution.
- Wristbands are easy to make and reliable.

---

## Components and their uses

| Component | Purpose |
|-----------|---------|
| ESP32-C3 DevKitM-1 | Main MCU, the "brain" of the wristband |
| MPU6050 | Detects referee hand gestures |
| 1.3" 240×240 SPI Display | Displays timer and status |
| MT3608 | Boost converter |
| TP4056 | LiPo battery charger |

---

## Top PCB
<img width="402" height="355" alt="image" src="https://github.com/user-attachments/assets/c3c154cf-ce4e-4047-827a-db1286a75ac4" />

<img width="645" height="350" alt="image" src="https://github.com/user-attachments/assets/74c23aac-74e8-4ab8-a565-1ca242867356" />


---

## Bottom PCB

<img width="485" height="358" alt="image" src="https://github.com/user-attachments/assets/57582eb2-00df-4f75-9e76-06e238837d03" />


<img width="655" height="374" alt="image" src="https://github.com/user-attachments/assets/6d9d1184-c0f3-431e-a021-7065daf4add2" />


The project is made with two PCBs. The upper PCB holds the display, while the bottom PCB contains the MCU and all other components. This approach keeps the wristband compact without making it too wide. In future revisions, I plan to make it even smaller.

---

## Fusion Files

https://a360.co/4gCFWl9

---
## How to Build


## 1. Manufacture the PCBs
Fabricate both the **Top PCB** and **Bottom PCB** using the KiCad Files provided.

---

## 2. Prepare the Components

Purchase all required components listed in the **Bill of Materials (BOM)**.

---

## 3. Solder the Bottom PCB

Assemble the Bottom PCB first.
Solder All components and connectors to the bottom PCB according to the KiCad files given, and attach their respective components.

Refer to the schematic for the correct connector orientation and pin mapping.

---

## 4. Assemble the Top PCB

1. Solder the female headers for the ESP32 connector(on the bottom side).
2. Solder the male headers for the SPI Screen(on the top side).
3. Connect the SPI Screen.

---

## 5. Join the Two PCBs

Carefully align the connector pins and stack the 2 PCBs.

---

## 6. Upload the Firmware

1. Connect the ESP32-C3 to your computer using a USB cable.
2. Open the firmware in the Arduino IDE.
3. Select **ESP32-C3 Dev Module** as the target board.
4. Choose the correct serial port.
5. Compile and upload the firmware.

## 7. Assemble the Enclosure

3D-print the enclosure using the CAD files.

Install the assembled electronics inside the case.
No screws are required to mount as the pcb is snug in the case.
Glue Magnets to the base and lid of the case so that it can remain closed.

---

## 8. Attach a Wrist Strap


The wrist strap is **not** 3D printed </3
It's a DIY thing you need to do with a leather sheet.
Please add a strap to the bottom case through the space given underneath (I will be updating this with a better option in the future).

---

## 9. Power On


If assembled correctly, ESSync should be working! YAY!

---
## How to Use

You'll need to calibrate your hand gestures with the watch so it can record those values and stop/start the timer the next time you use it.


## Bill of Materials

| S.No. | Reference | Value | Product | Notes | Qty | Cost | Link |
|------:|-----------|-------|---------|-------|----:|-----:|------|
| 1 | SPI_SCREEN1 | Conn_01x07 | Connector Pin Socket P2.54mm Vertical 1×7 | Top PCB (Display Connector) | 1 | $0.09 | https://robocraze.com/products/40x1-female-berg-strip |
| 2 | — | — | 1.3" 240×240 SPI Display | External Module | 1 | $9.50 | https://www.waveshare.com/1.3inch-lcd-module.htm |
| 3 | U3 | ESP32-C3-DevKitM-1 | ESP32-C3 DevKitM-1 | Bottom PCB | 1 | $10.11 | https://www.electropi.in/espressif-esp32-c3-devkitm-1-n4x-development-board |
| 4 | J1, J2 | Conn_01x15 | 1×15 Female Pin Socket | Bottom of Top PCB | 2 | $0.09 | https://robocraze.com/products/40x1-female-berg-strip |
| 5 | J7, J8, J9, J10 | Conn_01x01 | 1×01 Pin Header | MT3608 Connection | 4 | $0.06 | https://robocraze.com/products/40x1-pin-2-54mm-pitch-male-berg-strip |
| 6 | — | — | MT3608 Boost Module | External Module | 1 | $0.47 | https://www.flyrobo.in/mt3608-2a-dc-dc-boost-ultra-power-module |
| 7 | MPU6050 | Conn_01x08 | 1×08 Pin Header | MPU6050 Connector | 1 | $0.06 | https://robocraze.com/products/40x1-pin-2-54mm-pitch-male-berg-strip |
| 8 | — | — | MPU6050 Module | External Module | 1 | $1.63 | https://robocraze.com/products/mpu-6050-triple-axis-accelerometer-gyroscope-module |
| 9 | J5, J6, J11, J12 | Conn_01x01 | 1×01 Pin Header | TP4056 Connection | 4 | $0.06 | https://robocraze.com/products/40x1-pin-2-54mm-pitch-male-berg-strip |
| 10 | — | — | TP4056 Charging Module | External Module | 1 | $0.17 | https://quartzcomponents.com/products/tp4056-battery-charging-module |
| 11 | S1 | Tactile Button, 160gf | TS-1088-AR02016 | ESP ON Button | 1 | $0.06 | https://jlcpcb.com/partdetail/XUNPU-TS_1088AR02016/C720477 |
| 12 | SW1 | SW_Slide_DPDT | PCM12 Slide Switch | Power Switch | 1 | $1.20 | https://www.digikey.in/en/products/detail/c-k/PCM12SMTR/1640112 |
| 13 | Battery1 | Conn_01x02 | JST Battery Connector | Battery Connector | 1 | $0.05 | https://robu.in/product/b2b-xh-alfsn-jst-1x2p-2p-xh-tin-2-25%E2%84%8385%E2%84%83-3a-1-2-5mm-brass-direct-insert-pluginp2-5mm-wire-to-board-connector-rohs/ |
| 14 | — | — | 3.7V LiPo Battery | External Module | 1 | $1.69 | https://robocraze.com/products/450mah-3-7v-lipo-rechargeable-battery |
| 15 | C1 | 0.1µF | 0603 Capacitor | Decoupling Capacitor | 1 | $0.04 | https://robu.in/product/0603b104j500nt-fh-50v-100nf-x7r%C2%B15-0603-multilayer-ceramic-capacitors-mlcc-smd-smt-rohs/ |
| 16 | — | — | PCB Fabrication | Two Custom PCBs | 2 | $2.00 | https://cart.jlcpcb.com/quote |
| 17 | — | — | 3D Printed Case | External | 1 | $4.00 | https://zbotic.in/product/online-3d-printing-service |
| 18 | — | — | Leather Strap | External | 1 | $0.40 | https://www.desertcart.in/products/425174482-genuine-leather-strip-1-2-inch-wide-72-inches-long |
| 19 | — | — | Magnets | Externsl | 1 | $0.40 | https://www.prayogindia.in/product/neodymium-magnet-3mm-x-1mm-n35-super-strong-magnets/ |
