#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN  10

LiquidCrystal_I2C lcd(0x27, 20, 4);
MFRC522 mfrc522(SS_PIN, RST_PIN);
byte readCard[4];

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  SPI.begin();
  mfrc522.PCD_Init();
  delay(4);
  mfrc522.PCD_DumpVersionToSerial();

  lcd.setCursor(2, 0);
  lcd.print("Put your card");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scanned UID:");

  String uidStr = "";
  for (uint8_t i = 0; i < 4; i++) {
    readCard[i] = mfrc522.uid.uidByte[i];
    uidStr += (readCard[i] < 0x10 ? "0" : ""); // Add leading 0
    uidStr += String(readCard[i], HEX);
    uidStr += " ";
  }

  uidStr.toUpperCase(); // Optional: make it all uppercase
  Serial.print("UID: ");
  Serial.println(uidStr);

  lcd.setCursor(0, 1);
  lcd.print(uidStr);

  mfrc522.PICC_HaltA(); // Stop reading

  delay(2000); // Give user time to read display
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Put your card");
}
