int count;
int ledArray[] = {0,1,2,3,4};
int time= 1000;

void setup(){
  
  for(count=0;count<5;count++){
    pinMode(ledArray[count], OUTPUT);
  }
  
}

void loop(){
  
  for(count=0;count<5;count++){
    digitalWrite(ledArray[count],HIGH);
    delay(time);
    digitalWrite(ledArray[count],LOW);
    delay(time);
  }
  
}
