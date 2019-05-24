char serIn;
int soilMoistureValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()>0){ 
    serIn=Serial.read();
    if (serIn=='D'){
     soilMoistureValue = analogRead(A0); 
     Serial.print(soilMoistureValue);
     Serial.print("\r");
    }
}
