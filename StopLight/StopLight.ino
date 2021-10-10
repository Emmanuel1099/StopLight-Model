/*
    Andrew Vue & Emmanuel Segura
    10/9/21
    Microprocessors II
      This lab is to design a controller for traffic lights that face one traffic direction. There are three
      colors of lights, represented with Red, Yellow, Green LEDs. The traffic lights operate in the
      following patterns:
      (1) At the start of the system (power up), the Red light flashes (1-second on then 1-second
          off) until a button is pressed
      (2) The Red light stays on for 20 seconds before the Green light is turned on
      (3) The Green light stays on for 20 seconds before switching the Yellow light on
      (4) The Yellow light stays on for 3 seconds before switching back to Red light
      (5) The R-G-Y pattern continues until the system is powered off
      (6) An active buzzer beeps for 3 seconds before a light is changed
    Notes:
    - An input pin behaves like a voltmeter returning HIGH/LOW. An input pin is read by digitalRead()...
    - An output pin provides HIGH/LOW w/the digitalWrite() function...
    - When transitioning from "BLINK" state to "R-G-Y" state, hold down push-button for arduino to register (there is no debouncing). 
*/

//Global Variables 
int LED1 = 5;         // red LED
int LED2 = 7;         // green LED
int LED3 = 8;         // yellow LED
int button = 6;       // push button 
int buzzer = 12;      // active buzzer 
  
bool goBlink; // led blink mode
int ledState = HIGH; // state of led


void setup() {

// initialize button and led pins

  pinMode(LED1, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(buzzer,OUTPUT);
  goBlink = true;
}

void loop() {

  if(digitalRead(button) == LOW){
    goBlink = false;
  }

  // Initialize with goBlink as true 
  if(goBlink == true){
    digitalWrite(LED1, ledState);
    delay(1000);
    digitalWrite(LED1, !ledState);
    delay(1000);
  }

  if(goBlink == false){                 
    digitalWrite(LED1, HIGH);     // Red Light stays on for 20s
    delay(20000);
    digitalWrite(LED1, LOW);      // Red->Green
    digitalWrite(buzzer, HIGH);   // buzzer ON for 3s
    delay(3000); 
    digitalWrite(buzzer, LOW);
    digitalWrite(LED2, HIGH);     // Green LED stays on for 20s 
    delay(20000);
    digitalWrite(LED2, LOW);      // Green -> Yellow
    digitalWrite(buzzer, HIGH);   
    delay(3000); 
    digitalWrite(buzzer, LOW);
    digitalWrite(LED3, HIGH);     // Yellow LED stays on for 3s
    delay (3000);
    digitalWrite(LED3, LOW);
    digitalWrite(buzzer, HIGH);   
    delay(3000); 
    digitalWrite(buzzer, LOW);
  //R-G-Y system repeats until Arduino is off
  }

}
