int eepromValueRead(int head){
  int value;
  String tempValue ="";
  char c;
  for(int i=0; i<500; i++){
    c = char(EEPROM.read(i+head));
    if( c == '*'){ break; }
    else{ tempValue = tempValue + c; }   
  }
  value = tempValue.toInt();
  return value;
}



void eepromValueWrite(int head, int value){
  String writeValue = String(value);
  int len = writeValue.length();
  for(int i=0; i<len ; i++){
    EEPROM.write(head+i,char(writeValue[i]));    
  }
  EEPROM.write(head+len,'*'); 
}


ICACHE_RAM_ATTR void ISR (void) {                                // Timer reached zero, now re-load it to repeat
  timer0_write(ESP.getCycleCount() + 80000000L); // Reset the timer, do this first for timing accuracy
 
  if(digitalRead(output1)==1){ time1 = time1+1; eepromValueWrite(1,time1); }
  if(digitalRead(output2)==1){ time2 = time2+1; eepromValueWrite(101,time2); }
  if(digitalRead(output3)==1){ time3 = time3+1; eepromValueWrite(201,time3); }
  if(digitalRead(output4)==1){ time4 = time4+1; eepromValueWrite(301,time4); }
}
