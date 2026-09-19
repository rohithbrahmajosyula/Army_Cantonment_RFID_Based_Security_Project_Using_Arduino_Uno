# Army_Cantonment_Rfid_Based_Security_Project_Using_Arduino_Uno
# Overview
This project is an RFID-based security and access control system designed for an army cantonment model. The system uses an Arduino Uno, RFID reader, IR sensors, and a servo motor to control access through a gate.
The system checks RFID cards against authorized card IDs. When an authorized RFID card is detected, the servo motor operates the gate to allow access. IR sensors are used to detect vehicle movement and control the gate sequence.
# Features
- RFID-based access control
- Authorized RFID card identification
- Automatic gate control
- IR-based vehicle detection
- Servo motor controlled gate
- Arduino Uno based implementation
- Unauthorized access prevention
# Hardware Components
- Arduino Uno
- MFRC522 RFID Reader
- RFID Card/Tag
- IR Sensors
- Servo Motor
- Breadboard
- Jumper Wires
- 5V-2A Power Supply

The project report describes the Arduino Uno, RFID reader and tags, IR sensors, servo motor, breadboard, and jumper wires as the main hardware components.
# Software
- Arduino IDE
- Arduino C/C++
- SPI Library
- MFRC522 RFID Library
- Servo Library
- LiquidCrystal Library
Arduino sketches are saved with the `.ino` extension.
# Working
The system operates in the following sequence:
1. The first IR sensor detects vehicle movement.
2. The gate is controlled according to the detection.
3. The RFID card is placed near the RFID reader.
4. The RFID reader reads the card's unique identifier.
5. The Arduino checks the RFID identifier against the authorized list.
6. If the card is authorized, the servo motor opens the gate.
7. If the card is not authorized, the gate remains closed.
8. The second IR sensor is used during the vehicle movement and gate-control sequence.
# System Flow
```text
Vehicle Detection
       |
       v
   IR Sensor
       |
       v
   RFID Reader
       |
       v
Check RFID Card
   /          Authorized   Unauthorized
   |              |
   v              v
Servo Opens    Gate Remains
   Gate           Closed
```
# RFID Interface
The project uses the MFRC522 RFID reader with the Arduino Uno. The SPI library is used for communication between the Arduino and RFID reader.
The RFID tag ID can be obtained using the MFRC522 example sketches and then used in the project code for authorized access.
# Software Setup
1. Install Arduino IDE.
2. Connect the Arduino Uno to the computer.
3. Install the MFRC522 library using the Arduino Library Manager.
4. Connect the RFID reader, IR sensors, and servo motor according to the circuit diagram.
5. Open the project `.ino` file.
6. Select the Arduino Uno board and the correct port.
7. Upload the program to the Arduino Uno.
8. Power the circuit and test the RFID access control system.
# Project Structure
```text
Army_Cantonment_Rfid_Based_Security_Project_Using_Arduino_Uno/
│
├── Army_Cantonment_Rfid_Based_Security_Project_Using_Arduino_Uno.ino
├── README.md
└── circuit/
```
# Result
The implemented prototype demonstrates RFID-based access control for an army cantonment model. The system uses RFID identification, IR sensors, and a servo motor to automate gate access and prevent entry when an unauthorized RFID card is detected.
# Future Scope
The project can be extended with additional security and monitoring features, such as improved access logging, multiple authorized RFID cards, centralized monitoring, and additional sensors.
