byte txbegindata[] = {0x00,0x03,0x00,0x01,0x00,0x04,0x14,0x18}; 
byte txrefreshdata[] = {0x01,0x03,0x00,0x48,0x00,0x05,0x05,0xDF};
byte rxbegindata[13] = {};
byte rxrefreshdata[15] = {};

void setup()   
    {   
      Serial.begin(4800);  
      Serial2.begin(4800);  
    }   
        
    void loop() // run over and over   
    {   
        Serial2.write(txbegindata,sizeof(txbegindata));
        delay(1000);
//        for (int i=0; i<13; i++) {
//          while(!Serial2.available()); // wait for a character
//          rxbegindata[i] = Serial2.read();
//        }
        while(Serial2.available()){
          Serial2.readBytes(rxbegindata,13);
        }
        for (int i=0; i<13; i++) {
        Serial.print(rxbegindata[i],HEX);
        Serial.print(" ");
        }
        Serial.println();
        delay(2000);  

       while(1){
         Serial2.write(txrefreshdata,sizeof(txrefreshdata));
         delay(1500);
         while(Serial2.available()){
          Serial2.readBytes(rxrefreshdata,15);
        }
        for (int i=0; i<15; i++) {
        Serial.print(rxrefreshdata[i],HEX);
        Serial.print(" ");
        }
        Serial.println();
        short u = (short(rxrefreshdata[3])<<8|rxrefreshdata[4]);
        float U = (float)u/100;
        Serial.print(U);
        Serial.print(" ");
        short i = (short(rxrefreshdata[5])<<8|rxrefreshdata[6]);
        float I = (float)i/1000;
        Serial.print(I);
        Serial.print(" ");
        short p = (short(rxrefreshdata[7])<<8|rxrefreshdata[8]);
        float P = (float)p/10;
        Serial.print(P);
        Serial.println();
        delay(2000);
       }
    }    
