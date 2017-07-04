/*
 *      @Name: Test der RTC(Real Time Clock) am Arduino Due (Taijiuino)
 *      @Version: 0.3
 *      @Author:  Jan-Frederic Kurzweil
 *      @Changelog:
 *        -0.1- Adding RTCDue Library
 *        -0.2- Adding Serial Logging
 *        -0.3- Adding Native_usb_Serial & 16U2_Controller
 *     @Description:
 *        Die Realtime Clock wird laut, Arduino Foren über die 16U2 Controller von Atmel versorgt.
 *        Um das System umzustellen auf eine RTC mit BackupBattery muss der 16U2 Controller entfernt werden,
 *        dafür muss _NATIVE_USB_CONTROLLER defeniert werden. Sonst gibt es keine Serielle Ausgabe!!
 *        
 *        ---------------------------------------------------------------------------------------------------------
 *        
 *        TODO:
 *            Hardware:
 *              Anbinden der Backup Battery
 *            Software:
 *              Testen der Backup Battery via NATIVE_USB_CONTROLLER
 */

#include "RTCDue.h"

#define _NATIVE_USB_CONTROLLER
// #define _16U2_USB_CONTROLLER

#ifdef _NATIVE_USB_CONTROLLER
#define SER SerialUSB 
#elif _16U2_USB_CONTROLLER
#define SER Serial
#endif // USB_CONTROLLER

RTCDue rtc(XTAL);

const uint8_t seconds = 0;
const uint8_t minutes = 0;
const uint8_t hours = 0;

const uint8_t day = 0;
const uint8_t month = 0;
const uint8_t year = 0;

void setup()
{
  // Init Serial Baudrate 9600
  SER.begin(9600);

#ifdef NATIVE_USB_CONTROLLER
  while (!SER); // Wait for serial port to connect. Needed only for native USB Port
#endif // NATIVE_USB_CONTROLLER 
  
  // Init RTC
  rtc.begin();
  // Set init Time
  rtc.setTime(hours, minutes, seconds);
  rtc.setDate(day, month, year);
}

void loop()
{
  SER.print(rtc.getDay());
  SER.print("/");
  SER.print(rtc.getMonth());
  SER.print("/");
  SER.print(rtc.getYear());
  SER.print("  ");
  SER.print(rtc.getHours());
  SER.print(":");
  SER.print(rtc.getMinutes());
  SER.print(":");
  SER.print(rtc.getSeconds());
  SER.print("  UNIX Time: ");
  SER.println(rtc.unixtime());

  delay(1000);
}

