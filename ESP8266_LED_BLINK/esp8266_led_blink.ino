#include <HCSR04.h>
HCSR04 hc(D0, D1);
#define TRIG_DIST 100
void setup() {
  // put your setup code here, to run once:
  pinMode(D2, OUTPUT);
  Serial.begin(9600);

}

int count_on = 0;
int count_off = 0;
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print( hc.dist());
  Serial.print( '\t');
  Serial.print( count_on);
  Serial.print( '\t');
  Serial.println( count_off);

  if (hc.dist() <= TRIG_DIST)
  { count_on++;
    count_off = 0;
  }
  else
  {
    count_off++;
    count_on = 0;
  }

  if ( count_on > 3  ) {
    digitalWrite(D2, HIGH);
    count_off = 0;
  }
  else if (count_off > 150)
  {
    count_on = 0;
    count_off=151;
    digitalWrite(D2, LOW);
  }
  delay(100);
}
