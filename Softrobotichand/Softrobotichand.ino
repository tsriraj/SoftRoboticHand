
int flexSensorPin1 = A1;
int flexSensorPin2 = A2;
int flexSensorPin3 = A3;
int flexSensorPin4 = A4;
int flexSensorPin5 = A5;

const int numReadings = 20;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;

int readings2[numReadings];      // the readings from the analog input
int readIndex2 = 0;              // the index of the current reading
int total2 = 0;                  // the running total
int average2 = 0;

int readings3[numReadings];      // the readings from the analog input
int readIndex3 = 0;              // the index of the current reading 
int total3 = 0;                  // the running total
int average3 = 0;

int readings4[numReadings];      // the readings from the analog input
int readIndex4 = 0;              // the index of the current reading
int total4 = 0;                  // the running total
int average4 = 0;

int readings5[numReadings];      // the readings from the analog input
int readIndex5 = 0;              // the index of the current reading
int total5 = 0;                  // the running total
int average5 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  int flexSensorReading1 = analogRead(flexSensorPin1);
  int flexSensorReading2 = analogRead(flexSensorPin2);
  int flexSensorReading3 = analogRead(flexSensorPin3);
  int flexSensorReading4 = analogRead(flexSensorPin4);
  int flexSensorReading5 = analogRead(flexSensorPin5);

      
  //  Serial.print(flexSensorReading3);
  //  Serial.print(",");
  //  Serial.print(flexSensorReading1);
  //  Serial.print(",");
  //  Serial.print(flexSensorReading2);
  //  Serial.println(",");

  // Moving Average Filter

  // subtract the last reading:
  
  total = total - readings[readIndex];
  total2 = total2 - readings2[readIndex2];
  total3 = total3 - readings3[readIndex3];
  total4 = total4 - readings4[readIndex4];
  total5 = total5 - readings5[readIndex5];
  
  
  // read from the sensor:
readings[readIndex] = analogRead(flexSensorPin1);
readings2[readIndex2] = analogRead(flexSensorPin2);
readings3[readIndex3] = analogRead(flexSensorPin3);
readings4[readIndex4] = analogRead(flexSensorPin4);
readings5[readIndex5] = analogRead(flexSensorPin5);
  
  // add the reading to the total:
total = total + readings[readIndex];
total2 = total2 + readings2[readIndex2];
total3 = total3 + readings3[readIndex3];
total4 = total4 + readings4[readIndex4];
total5 = total5 + readings5[readIndex5];
  
  // advance to the next position in the array:
  readIndex = readIndex + 1;
  readIndex2 = readIndex2 + 1;
  readIndex3 = readIndex3 + 1;
  readIndex4 = readIndex4 + 1;
  readIndex5 = readIndex5 + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
  
    // ...wrap around to the beginning:
    readIndex = 0;
  }

    if (readIndex2 >= numReadings) {
  
    // ...wrap around to the beginning:
    readIndex2 = 0;
  }
    if (readIndex3 >= numReadings) {
  
    // ...wrap around to the beginning:
    readIndex3 = 0;
  }  
    if (readIndex4 >= numReadings) {
  
    // ...wrap around to the beginning:
    readIndex4 = 0;
  }
     if (readIndex5 >= numReadings) {
  
    // ...wrap around to the beginning:
    readIndex5 = 0;
  } 
  // calculate the average:
  average = total / numReadings;
  average2 = total2 / numReadings;
  average3 = total3 / numReadings;
  average4 = total4 / numReadings;
  average5 = total5 / numReadings;
  Serial.print(average);
  Serial.print(",");
 Serial.print(average2);
   Serial.print(",");
 Serial.print(average3);
   Serial.print(",");
 Serial.print(average4);
   Serial.print(",");
 Serial.println(average5);
  // send it to the computer as ASCII digits

  /*int total1 = 0;                  // the running total
  int average1 = 0;
  total1 = total1 - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(flexSensorReading2);
  // add the reading to the total:
  total1 = total1 + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average1 = total1 / numReadings;


  int total2 = 0;                  // the running total
  int average2 = 0;
  total2 = total2 - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(flexSensorReading3);
  // add the reading to the total:
  total2 = total2 + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average2 = total2 / numReadings;
  Serial.print(average);
  Serial.print(",");
  Serial.print(average1);
  Serial.print(",");
  Serial.print(average2);
  Serial.println(";");
  // Output filtered values here


  //To measure Bending angles of 5 fingers
  
  //float angle5 = map(flexSensorReading5, 740, 680,0, 90.0);
  //Serial.println("Bend Angle for F5 is: "+String(angle5));

  //float angle4 = map(flexSensorReading4, 740, 680,0, 90.0);
  //Serial.println("Bend Angle for F4 is: "+String(angle4));

  //float angle3 = map(flexSensorReading3, 740, 680,0, 90.0);
  //Serial.println("Bend Angle for F3 is: "+String(angle3));

  //float angle1 = map(flexSensorReading1, 740, 680,0, 90.0);
  //Serial.println("Bend Angle for F1 is: "+String(angle1));

  //float angle2 = map(flexSensorReading2, 740, 680,0, 90.0);
  //Serial.println("Bend Angle for F2 is: "+String(angle2));*/

  delay(100); //just here to slow down the output for easier reading

}
