/*
  ESP8266 needs to have an AT firmware and be set at 9600 bauds
*/

#include <SoftwareSerial.h>
#include <U8glib.h>

SoftwareSerial softSerial(10, 11); // RX, TX

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);

const uint8_t bm[] PROGMEM = {
  0b00011000,
  0b00111100,
  0b01111110,
  0b11111111,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000
};

String tsapikey = "38C3XS8ZC6J97GIE";

int count;

void setup()
{
  uint32_t baud = 9600;
  Serial.begin(baud);
  softSerial.begin(baud);
  Serial.print("SETUP!! @");
  Serial.println(baud);

  //Setup ESP
  Serial.println("ESP Reset");
  softSerial.print("AT+RST\r\n");
  delay(1000);
  Serial.println("ESP Mode");
  softSerial.print("AT+CWMODE=1\r\n");
  delay(100);
  Serial.println("ESP Join AP");
  softSerial.print("AT+CWJAP=\"GCTDA-Employes\",\"1Tda21959\"\r\n");
  delay(5000);
  Serial.println("ESP Config done.");
}

void loop()
{
  count++;
  char buf[10];
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "api.thingspeak.com";
  cmd += "\",80";
  softSerial.println(cmd);

  if(softSerial.find("Error")) {
    Serial.println("CIPSTART Error!");
  }

  // prepare GET string
  String getStr = "GET /update?api_key=";
  getStr += tsapikey;
  getStr +="&field1=";
  getStr += String(60);
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  softSerial.println(cmd);

  if(softSerial.find(">")){
    softSerial.print(getStr);
    Serial.println("ok from TS");
  }
  else{
    softSerial.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }

  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr( 0, 20, "Hello World!");
    sprintf(buf, "%d", count);
    u8g.drawStr( 0, 40, buf);
    Serial.println("oled written.");
  } while(u8g.nextPage());

  // thingspeak needs 15 sec delay between updates
  delay(16000);
}
