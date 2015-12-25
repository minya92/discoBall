#include <IRremote.h>
#include <Stepper.h>

IRrecv irrecv(11);
decode_results results;

int keyMotor = 0;
int keyLight = 0;
int keyBlink = 0;
int timer = 0;

const int M1 = 2; // вход 1 мотора
const int M2 = 3; // вход 2 мотора
const int RED = 7; // красная лампа
const int BLUE  = 5; //синяя лампа


void setup() {
   Serial.begin(9600);
   irrecv.enableIRIn();
   pinMode(M1, OUTPUT); // motor OUT 1
   pinMode(M2, OUTPUT); // motor OUT 2
   pinMode(RED, OUTPUT); // two red lights
   pinMode(BLUE, OUTPUT); // two green lights
}

void initKeys(){
  if (irrecv.decode(&results)) 
  {
    int res = results.value;
    Serial.println(res, HEX);
    if(res==0xFFFFA25D)// Если нажата кнопка "+"
    {
      keyMotor = (keyMotor?0:1);
    }
    else if(res==0x0000629D)// Если нажата кнопка "-" 
    {
      keyLight = (keyLight?0:1);
    }
    else if(res==0xFFFFE21D)
    {
      keyBlink = (keyBlink?0:1);
      //Serial.println(keyBlink);
    } 
    irrecv.resume();
  }
}

void loop() {
  initKeys();
  delay(100);
  timer += 100;
  if(keyMotor == 1 && timer == 6000){
    digitalWrite(M1, HIGH); // запустить мотор
    digitalWrite(M2, HIGH); 
  }
  if(keyLight == 1 && keyBlink == 0){
    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, HIGH);
  } else if(keyBlink == 0) {
    digitalWrite(RED, LOW);
    digitalWrite(BLUE, LOW);
  }
  if(keyBlink == 1 && timer == 1500){
    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, LOW);
  }
  if(keyBlink == 1 && timer == 3000){
    digitalWrite(RED, LOW);
    digitalWrite(BLUE, HIGH);
  }
  if(timer == 1000)
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
  if(timer > 6000)
    timer = 0;
}
