char serIn;
int soilMoistureValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
}
 
void loop() {
  delay(1000); // time to relax
  
  if (Serial.available()){ 
    while(Serial.available()) char c = Serial.read(); // remove trigger data
    soilMoistureValue = analogRead(A0);
    delay(300); // data process simulation
    Serial.print("Solid: 1 ");
    Serial.println(soilMoistureValue);
  }
}
