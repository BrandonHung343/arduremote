#include <VirtualWire.h>

int f, l, r, b;
int orient = 0;

void setup() {
  vw_set_tx_pin(3);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  // put your setup code here, to run once:
  f = 13;
  l = 12;
  r = 11;
  b = 10;
  pinMode(f, INPUT);
  pinMode(l, INPUT);
  pinMode(r, INPUT);
  pinMode(b, INPUT);
  Serial.begin(9600);
}

void loop() {
  uint8_t c[1] = {0};
  Serial.print("0");
  if (digitalRead(f)) {
    c[0] = 1;
    vw_send(c, 1);
    //Serial.write(1);
  }
  else if (digitalRead(l)) {
    c[0] = 2;
    vw_send(c, 1);
  }
  else if (digitalRead(r)) {
    c[0] = 3;
    Serial.print("3");
    vw_send(c, 1);
  }
  else if(digitalRead(b)) {
    c[0] = 4;
    vw_send(c, 1);
  }
  else {
    
  }
  Serial.print(c[0]);
  delay(100);
  // put your main code here, to run repeatedly:

}
