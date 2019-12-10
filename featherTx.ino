// Tx Feather
// Adapted from Radiohead library

#include <SPI.h>
#include <RH_RF69.h>

// for feather m0  
#define RFM69_CS 8
#define RFM69_RST 4
#define RFM69_INT 3

// frequency
#define RF69_FREQ 434.0

// Singleton instance of the radio driver
RH_RF69 rf69(RFM69_CS, RFM69_INT);

int16_t packetnum = 0;  // packet counter, we increment per xmission

void setup() 
{
  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, HIGH);

//  while (!Serial);
//  Serial.begin(9600);
  delay(100);

  // manual reset
  digitalWrite(RFM69_RST, HIGH);
  delay(10);
  digitalWrite(RFM69_RST, LOW);
  delay(10);

  while (!rf69.init()) {
    while (1);
  }
  // Defaults after init are 434.0MHz, modulation GFSK_Rb250Fd250, +13dbM
  rf69.setFrequency(RF69_FREQ);
  // Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
  // The default transmitter power is 13dBm, using PA_BOOST.
  rf69.setTxPower(20, true);
}

void loop()
{ 
  // Send a message   
  char radiopacket[20] = "line67";
//  Serial.print("Sending "); 
//  Serial.println(radiopacket);  
//  Serial.println("Sending..."); 
  delay(10);
  rf69.send((uint8_t *)radiopacket, 20);

//  Serial.println("Waiting for packet to complete..."); delay(10);
  rf69.waitPacketSent();
//  Serial.println("Sent.");
  delay(1000);
}
