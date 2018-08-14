    /////////////////////////////////////////////////////////////////
   //             ESP32 Deep Sleep Example 1             v1.00    //
  //       Get the latest version of the code here:              //
 //       http://educ8s.tv/esp32-deep-sleep-tutorial            //
/////////////////////////////////////////////////////////////////

//Example of how we can use timer method to bring ESP back to active mode from deep sleep mode

#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  3        /* Time ESP32 will go to sleep (in seconds) */

RTC_DATA_ATTR int bootCount = 0;


//int YELLOW_LED_PIN = 26;

void setup(){
  Serial.begin(9600);

  pinMode(GREEN_LED_PIN,OUTPUT);
//  pinMode(YELLOW_LED_PIN,OUTPUT);
  delay(500);
  
  if(bootCount == 0) //Run this only the first time
  {
//      digitalWrite(YELLOW_LED_PIN,HIGH);
      bootCount = bootCount+1;
    Serial.println("First print");
        
  }else
  {
//      digitalWrite(GREEN_LED_PIN,HIGH);
    Serial.println("Back from Sleep mode");
    bootCount = bootCount+1;
    Serial.println(bootCount);
  }
  
  delay(3000);

//  digitalWrite(GREEN_LED_PIN,LOW);
//  digitalWrite(YELLOW_LED_PIN,LOW);

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  esp_deep_sleep_start();
  Serial.println("wont print this");
}

void loop(){
  
}


