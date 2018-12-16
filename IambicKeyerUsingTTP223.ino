/*
 * Iambic Keyer by n0th1n6 - 4G1ZYS
  */

#define ONEMINUTE 60000
#define ELEMPERWORD 50
#define WPM 15 
#define DIT (ONEMINUTE / (ELEMPERWORD*WPM))
#define DAH DIT*3
#define DITPIN 2
#define LEDPIN 1
#define DAHPIN 0                                                                                        
#define SUPPIN 3
#define SPKPIN 4

int toggleD = 1;

int ditSense = 0;
int dahSense = 0;

void setup()                    
{
  pinMode(DAHPIN, INPUT);
  pinMode(DITPIN, INPUT); 
}

void loop()                    
{
  ditSense = digitalRead(DITPIN);
  dahSense = digitalRead(DAHPIN);
  switch(toggleD) {
    case 1:
      if (ditSense) {
        sound(DIT);
      }
      break;
    case 0:
      if (dahSense) {
        digitalWrite(LEDPIN, HIGH);     
        sound(DAH);
      }
      break;
  }
  toggleD ^= 1;
}

void sound(int eDelay) {
  analogWrite(SPKPIN, 127);
  delay(eDelay);
  analogWrite(SPKPIN, 0);
  digitalWrite(LEDPIN, LOW);
  delay(DIT);
}

