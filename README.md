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
<img width="796" height="170" alt="image" src="https://github.com/user-attachments/assets/3e92fd21-8b88-4a1d-8f00-98b09eaac4c8" />



