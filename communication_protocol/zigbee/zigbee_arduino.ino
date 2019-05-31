char serIn;
int soilMoistureValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

// From 0 -> 11 analog sensor 
// From 12 -> ? capacitive sensor 
void loop() {
  if (Serial.available()>0){ 
    serIn=Serial.read();
    if (serIn=='A'){ //0
      soilMoistureValue = analogRead(A0); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    if (serIn=='B'){ //1
      soilMoistureValue = analogRead(A1); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    if (serIn=='C'){ //2 
      soilMoistureValue = analogRead(A2); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    if (serIn=='D'){ //3 
      soilMoistureValue = analogRead(A3); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    if (serIn=='E'){ //4 
      soilMoistureValue = analogRead(A4); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    if (serIn=='F'){ //5 
      soilMoistureValue = analogRead(A5); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    if (serIn=='G'){ //6
      soilMoistureValue = analogRead(A6); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    if (serIn=='H'){ //7
      soilMoistureValue = analogRead(A7); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    if (serIn=='I'){ //8
      soilMoistureValue = analogRead(A8); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    if (serIn=='J'){ //9
      soilMoistureValue = analogRead(A9); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    if (serIn=='K'){ //10
      soilMoistureValue = analogRead(A10); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    if (serIn=='L'){ //11
      soilMoistureValue = analogRead(A11); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    if (serIn=='M'){ //12
      soilMoistureValue = analogRead(A12); 
      Serial.print(soilMoistureValue);
      Serial.print("\r");
    }
    
    
}
