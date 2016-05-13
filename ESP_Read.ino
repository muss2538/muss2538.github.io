#define Count D2
#define Spart D3 
#define ledpo D6
#define sMode D5
#define ledMo D4

int Data[3];


void setup() {
  pinMode(D10,OUTPUT);//TX
  pinMode(D9,OUTPUT);//RX
  
  pinMode(Count,INPUT);
  pinMode(Spart,INPUT);
  pinMode(ledpo,OUTPUT);
  pinMode(sMode,INPUT);
  pinMode(ledMo,OUTPUT);

  
  digitalWrite(ledMo,LOW);
}

void loop() {
  Data[0] = digitalRead(sMode);
  Data[1] = digitalRead(Count);
  Data[2] = digitalRead(Spart);
  
//Manual
  if(Data[0]==1){
    digitalWrite(D9,1);
    digitalWrite(ledMo,1);
    }
//Auto
  if(Data[0]==0){
    if(Data[2]==1){
    digitalWrite(ledMo,0); 
    digitalWrite(D9,0);
    }
    else if(Data[2]==0){
    digitalWrite(ledMo,1); 
    digitalWrite(D9,1);
    
        }
    }
    
  if(Data[1]==0){
    digitalWrite(D10,0);
    digitalWrite(ledpo,LOW);
    }
  if(Data[1]==1){
    digitalWrite(D10,1);
    digitalWrite(ledpo,HIGH);
    delay(1000);

    }


  }

