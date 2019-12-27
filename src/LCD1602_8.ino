// Eight-digit connection code:
int DI = 12;
int RW = 11;
int DB[] = {3, 4,5, 6,7 ,8, 9, 10};//Use arrays to define pins required by the bus
int Enable = 2;

void LcdCommandWrite(int value) {
  // Define all pins
  int i = 0;
  for (i=DB[0]; i <= DI; i++) //Bus assignment
  {
    digitalWrite(i,value & 01);//Because the 1602 LCD signal recognition is D7-D0 (not D0-D7), here is used to invert the signal.   
    value >>= 1;
  }
  digitalWrite(Enable,LOW);
  delayMicroseconds(1);
  digitalWrite(Enable,HIGH);
  delayMicroseconds(1);  // Delay 1ms
  digitalWrite(Enable,LOW);
  delayMicroseconds(1);  // Delay 1ms
}

void LcdDataWrite(int value) {
  // Define all pins
  int i = 0;
  digitalWrite(DI, HIGH);
  digitalWrite(RW, LOW);
  for (i=DB[0]; i <= DB[7]; i++) {
     digitalWrite(i,value & 01);
     value >>= 1;
  }
  digitalWrite(Enable,LOW);
  delayMicroseconds(1);
  digitalWrite(Enable,HIGH);
  delayMicroseconds(1);
  digitalWrite(Enable,LOW);
  delayMicroseconds(1);  // Delay 1ms
}

void setup (void) {
  int i = 0;
  for (i=Enable; i <= DI; i++) {
     pinMode(i,OUTPUT);
  }
  delay(100);
  // Initialize LCD after a short pause
  // For LCD control needs
  LcdCommandWrite(0x38);  // Set to 8-bit interface, 2 lines display, 5x7 text size                     
  delay(64);                      
  LcdCommandWrite(0x38);  // Set to 8-bit interface, 2 lines display, 5x7 text size                        
  delay(50);                      
  LcdCommandWrite(0x38);  // Set to 8-bit interface, 2 lines display, 5x7 text size                        
  delay(20);                      
  LcdCommandWrite(0x06);  //Input method setting
                          // Auto increment, no shift shown 
  delay(20);   
  LcdCommandWrite(0x0E);  // display setting
                          // Turn on the display screen, the cursor shows, no flashing
  delay(20);     
  LcdCommandWrite(0x01);  // Clear the screen and the cursor position returns to zero  
  delay(100);                      
  LcdCommandWrite(0x80);  // display setting
                          // Turn on the display screen, the cursor shows, no flashing
  delay(20);                      
}

void loop (void) {
  LcdCommandWrite(0x01);  // Clear the screen and the cursor position returns to zero  
  delay(10); 
  LcdCommandWrite(0x80+2); 
  delay(10);                     
  // Write welcome message 
  LcdDataWrite('H');
  LcdDataWrite('e');
  LcdDataWrite('l');
  LcdDataWrite('l');
  LcdDataWrite('o');
  LcdDataWrite(',');
  LcdDataWrite(' ');
  LcdDataWrite('w');
  LcdDataWrite('o');
  LcdDataWrite('r');
  LcdDataWrite('l');
  LcdDataWrite('d');
  LcdDataWrite('!');
  delay(10);
  LcdCommandWrite(0xc0+2);  // Define the cursor position as the second position on the second line  
  delay(10); 
  LcdDataWrite('H');
  LcdDataWrite('e');
  LcdDataWrite('l');
  LcdDataWrite('l');
  LcdDataWrite('o');
  LcdDataWrite(',');
  LcdDataWrite(' ');
  LcdDataWrite('1');
  LcdDataWrite('6');
  LcdDataWrite('0');
  LcdDataWrite('2');
  LcdDataWrite('!');
  LcdDataWrite(' '); 
  delay(5000);
}
