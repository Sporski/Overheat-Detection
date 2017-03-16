/*Term Project for Chris Sporski
 * Temperature sensor
 * 
 */

const int sensor = A0;
const int blue = 2;
const int green = 3;
const int yellow = 4;
const int red = 5;

void setup() {
  // open a serial connection to display values
  Serial.begin(9600);

  pinMode(blue, OUTPUT);
  digitalWrite(blue, LOW);
  pinMode(green, OUTPUT);
  digitalWrite(green, LOW);
  pinMode(yellow, OUTPUT);
  digitalWrite(yellow, LOW);
  pinMode(red, OUTPUT);
  digitalWrite(red, LOW);

}

void loop() {


  // This chunk of code reads in a value, converts it to volts,
  // then to degrees C, then to degrees F, and displays the value
  // so testing could be accurate.
  int sensorVal = analogRead(sensor);
  double voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(", degrees F: ");
  double temp = (voltage - .5) * 100;
  temp = (temp * 1.8) + 32;
  Serial.println(temp);

  if( temp <= 32.00){         //displays blue light, no sound
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    noTone(8);
  }

  if( temp > 32.00 && temp <= 65.00){   // displays green light, no sound
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    noTone(8);
  }
  if( temp > 65.00 && temp < 100.00){   // displays yellow light, no sound
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(red, LOW);
    noTone(8);
    
  }
 
  if( temp >= 100.00){        //displays red light, tone is played
    tone(8, 300);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
  }
  
  delay(500);     //delays for a little and then loops back
}
