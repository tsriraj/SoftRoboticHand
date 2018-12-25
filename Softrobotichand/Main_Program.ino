
int flexSensorPin1 = A1;
int flexSensorPin2 = A2;
int flexSensorPin3 = A3;
int flexSensorPin4 = A4;
int flexSensorPin5 = A5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int flexSensorReading1 = analogRead(flexSensorPin1);
  int flexSensorReading2 = analogRead(flexSensorPin2);
  int flexSensorReading3 = analogRead(flexSensorPin3);
  int flexSensorReading4 = analogRead(flexSensorPin4);
  int flexSensorReading5 = analogRead(flexSensorPin5);

  Serial.print(flexSensorReading5);
  Serial.print(",");
  Serial.print(flexSensorReading4);
  Serial.print(",");
  Serial.print(flexSensorReading3);
  Serial.print(","); 
  Serial.print(flexSensorReading1);
  Serial.print(",");
  Serial.print(flexSensorReading2);
  Serial.println(",");

  // Moving Average Filter
  
  // Output filtered values here
  
  
  //To measure Bending angles of 5 fingers
 // float angle5 = map(flexSensorReading5, 740, 680,0, 90.0);
 //Serial.println("Bend Angle for F5 is: "+String(angle5));
  
 // float angle4 = map(flexSensorReading4, 740, 680,0, 90.0);
 // Serial.println("Bend Angle for F4 is: "+String(angle4));
  
 // float angle3 = map(flexSensorReading3, 740, 680,0, 90.0);
 // Serial.println("Bend Angle for F3 is: "+String(angle3));
  
 // float angle1 = map(flexSensorReading1, 740, 680,0, 90.0);
 // Serial.println("Bend Angle for F1 is: "+String(angle1));
  
 // float angle2 = map(flexSensorReading2, 740, 680,0, 90.0);
 // Serial.println("Bend Angle for F2 is: "+String(angle2));
  
  delay(100); //just here to slow down the output for easier reading
}
