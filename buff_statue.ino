/*
  Ping))) Sensor

  This sketch reads a PING))) ultrasonic rangefinder and returns the distance
  to the closest object in range. To do this, it sends a pulse to the sensor to
  initiate a reading, then listens for a pulse to return. The length of the
  returning pulse is proportional to the distance of the object from the sensor.


  created 3 Nov 2008
  by David A. Mellis
  modified 18 September 2021
  by Ryan Geist

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Ping
*/
float x;
float y;
const float distance = 15.5;
const int trigPin[] = {10, 12};
const int echoPin[] = {11, 13};
float d[] = {0, 0};
int led[] = {2,3,6,5,9,8,7,4};
int buff [12][20] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0 },  //buff outline in inches ints are the organization
  {0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 7, 7, 0, 0, 0, 0},
  {0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 0, 0},
  {0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0},
  {0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 2, 2, 2, 2, 5, 5, 0, 0, 0, 0, 0, 6, 6, 6, 6, 0, 0, 0, 0},
  {0, 1, 2, 2, 5, 5, 5, 0, 0, 0, 0, 0, 6, 6, 6, 6, 0, 0, 0, 0},
  {1, 1, 1, 0, 5, 5, 5, 0, 0, 6, 6, 0, 6, 6, 6, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0, 0, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 0, 0, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int org = 0;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  for (int i; i < 2; i++) {
    pinMode(echoPin[i], INPUT);
    pinMode(trigPin[i], OUTPUT);
  }
  for (int j = 0; j < 8; j++) {
    pinMode(led[j], OUTPUT);
  }
}
long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: https://www.parallax.com/package/ping-ultrasonic-distance-sensor-downloads/
  return microseconds / 74 / 2;
}
void loop() {
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  for (int i = 0; i < 2; i++) {
    digitalWrite(trigPin[i], LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin[i], HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin[i], LOW);

    duration = pulseIn(echoPin[i], HIGH);

    // convert the time into a distance
    inches = microsecondsToInches(duration);
    if (inches <= 30) {
      d[i] = inches;
      //uncomment the following lines for debug
//      Serial.print (i);
//      Serial.print (": ");
//      Serial.print(inches);
//      Serial.println("in");

    }
  }
  //heron's formula
  y = 0.5 * sqrt((d[0] + distance + d[1]) * (-d[0] + distance + d[1]) * (d[0] - distance + d[1]) * (d[0] + distance - d[1])) / distance;
  x = sqrt(pow(d[0], 2) - pow(y, 2));
  //uncomment the following lines for debug
//  Serial.print(x);
//  Serial.print(": ");
//  Serial.println(y);
 
  org = buff[12-(int)y+1][(int)x]; //12-y is used to flip the y axis
  for(int k=0; k< 8; k++){
    if(k!= org-1){
      digitalWrite(led[k],LOW);
    }
    
  }
  
  digitalWrite(led[org-1],HIGH);
  switch(org){
    case 1: //AISES
    Serial.write('a');
    break;
    case 2: //CUWIC
    Serial.write('b');
    break;
    case 3: //NSBE
    Serial.write('c');
    break;
    case 4: //oSTEM
    Serial.write('d');
    break;
    case 5: //SAES
    Serial.write('e');
    break;
    case 6: //SHPE/MAES
    Serial.write('f');
    break;
    case 7: //SWE
    Serial.write('g');
    break;
    case 8: //WOAA
    Serial.write('h');
    break;
}
}
