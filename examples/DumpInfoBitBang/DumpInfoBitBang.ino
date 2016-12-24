/*
 * --------------------------------------------------------------------------------------------------------------------
 * Example sketch/program showing how to use multiple card readers
 * --------------------------------------------------------------------------------------------------------------------
 * This is a MFRC522 library example; for further details and other examples see: https://github.com/miguelbalboa/rfid
 * 
 */

#include <MFRC522.h>

#define RST_1_PIN   2
#define SS_1_PIN    3
#define MISO_1_PIN  4
#define SCK_1_PIN   11
#define MOSI_1_PIN  12

#define RST_2_PIN   5
#define SS_2_PIN    6
#define MISO_2_PIN  7
#define SCK_2_PIN   11
#define MOSI_2_PIN  12

#define RST_3_PIN   8
#define SS_3_PIN    9
#define MISO_3_PIN  10
#define SCK_3_PIN   11
#define MOSI_3_PIN  12

MFRC522 mfrc522_1(SS_1_PIN, RST_1_PIN, MISO_1_PIN, MOSI_1_PIN, SCK_1_PIN);  // Create MFRC522 instance
MFRC522 mfrc522_2(SS_2_PIN, RST_2_PIN, MISO_2_PIN, MOSI_2_PIN, SCK_2_PIN);  // Create MFRC522 instance
MFRC522 mfrc522_3(SS_3_PIN, RST_3_PIN, MISO_3_PIN, MOSI_3_PIN, SCK_3_PIN);  // Create MFRC522 instance

void setup() {
    Serial.begin(9600);     // Initialize serial communications with the PC
    while (!Serial);        // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)

    mfrc522_1.PCD_Init();   // Init MFRC522
    Serial.println(F("Reader 1 Details"));
    mfrc522_1.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details

    mfrc522_2.PCD_Init();   // Init MFRC522
    Serial.println(F("Reader 2 Details"));
    mfrc522_2.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details

    mfrc522_3.PCD_Init();   // Init MFRC522
    Serial.println(F("Reader 3 Details"));
    mfrc522_3.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details

    Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {

    if (mfrc522_1.PICC_IsNewCardPresent()) {
        if (mfrc522_1.PICC_ReadCardSerial()) {
            Serial.println(F("Card on Reader 1"));
            mfrc522_1.PICC_DumpToSerial(&(mfrc522_1.uid));
        }
    }

    if (mfrc522_2.PICC_IsNewCardPresent()) {
        if (mfrc522_2.PICC_ReadCardSerial()) {
            Serial.println(F("Card on Reader 2"));
            mfrc522_2.PICC_DumpToSerial(&(mfrc522_2.uid));
        }
    }

    if (mfrc522_3.PICC_IsNewCardPresent()) {
        if (mfrc522_3.PICC_ReadCardSerial()) {
            Serial.println(F("Card on Reader 3"));
            mfrc522_3.PICC_DumpToSerial(&(mfrc522_3.uid));
        }
    }

}
