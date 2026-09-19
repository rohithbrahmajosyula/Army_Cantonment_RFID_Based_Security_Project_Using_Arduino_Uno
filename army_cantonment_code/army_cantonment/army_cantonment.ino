#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

Servo servo;
int servoPos = 0;

#define sensorPin1 A2
#define sensorPin2 A3

int senVal1 = 0;
int senVal2 = 0;

#define RST_PIN 8
#define SS_PIN 10

#define num 7
char Data[num];
byte data_count = 0;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup () {
  Serial.begin(9600);

  servo.attach(9);

  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);

  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println("Army Safety & Security Project");
}

void loop() {
  sensorRead();
  rfid();
}

void sensorRead() {
  senVal1 = digitalRead(sensorPin1);
  senVal2 = digitalRead(sensorPin2);
}

void rfid() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();

  // Check if RFID tag is authorized
  if (content.substring(1) == "63 15 B9 F5" || content.substring(1) == "93 0D A1 C5") {
    // Open the gate
    servo.write(90); // Move servo to open position
    delay(500);     // Keep gate open for 2 seconds
    servo.write(0);  // Move servo to close position
  } else {
    Serial.println("Unauthorized access detected!");
  }

  delay(2000); // Wait for a short time before checking for another RFID tag
}
