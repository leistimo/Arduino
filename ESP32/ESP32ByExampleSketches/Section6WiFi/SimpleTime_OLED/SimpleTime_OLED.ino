#include <WiFi.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

#include "time.h"
#include "sntp.h"

const char* ssid       = "JamesElektra";
const char* password   = "MontgomeryBurns!";

const char* ntpServer1 = "pool.ntp.org";
const char* ntpServer2 = "time.nist.gov";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

// const char* time_zone = "CET-1CEST,M3.5.0,M10.5.0/3";  // TimeZone rule for Europe/Rome including daylight adjustment rules (optional)
const char* time_zone = "EST5EDT,M3.2.0,M11.1.0";  // TimeZone rule for America/New York including daylight adjustment rules (optional)

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

void printLocalTime()
{
  char dayBuffer[20];
  char weekdayBuffer[10];
  char timeBuffer[10];
  display.clearDisplay();
  display.setCursor(0, 0);
  display.display();
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("No time available (yet)");
    display.println("No time available");
    display.println("...yet");
    display.display();
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  strftime(weekdayBuffer, sizeof(weekdayBuffer), "%A", &timeinfo);
  strftime(dayBuffer, sizeof(dayBuffer), "%B %d %Y", &timeinfo);
  strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", &timeinfo);
  display.println("Current Time:");
  display.println(weekdayBuffer);
  display.println(dayBuffer);
  display.println(timeBuffer);
  display.display();
}

// Callback function (get's called when time adjusts via NTP)
void timeavailable(struct timeval *t)
{
  Serial.println("Got time adjustment from NTP!");
  printLocalTime();
}

void setup()/Users/jjs/EEK Course/TechExplorations/UdemySketches/Section6WiFi/SimpleTime_WiFiManager/SimpleTime_WiFiManager.ino
{
  Serial.begin(115200);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  display.display();
  delay(2000);  // Pause for 2 seconds
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setRotation(0);
  display.clearDisplay();
  display.setCursor(0, 0);

  // set notification call-back function
  sntp_set_time_sync_notification_cb( timeavailable );

  /**
   * NTP server address could be aquired via DHCP,
   *
   * NOTE: This call should be made BEFORE esp32 aquires IP address via DHCP,
   * otherwise SNTP option 42 would be rejected by default.
   * NOTE: configTime() function call if made AFTER DHCP-client run
   * will OVERRIDE aquired NTP server address
   */
  sntp_servermode_dhcp(1);    // (optional)

  /**
   * This will set configured ntp servers and constant TimeZone/daylightOffset
   * should be OK if your time zone does not need to adjust daylightOffset twice a year,
   * in such a case time adjustment won't be handled automagicaly.
   */
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2);

  /**
   * A more convenient approach to handle TimeZones with daylightOffset 
   * would be to specify a environmnet variable with TimeZone definition including daylight adjustmnet rules.
   * A list of rules for your zone could be obtained from https://github.com/esp8266/Arduino/blob/master/cores/esp8266/TZ.h
   */
  configTzTime(time_zone, ntpServer1, ntpServer2);

  String ssidString = String((char *)ssid);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Connecting to:");
  display.println(ssidString);

  //connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      display.print(".");
      display.display();
  }
  Serial.println(" CONNECTED");
  display.println(" CONNECTED");
  display.display();
}

void loop()
{
  delay(5000);
  printLocalTime();     // it will take some time to sync time :)
}
