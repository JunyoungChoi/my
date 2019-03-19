 #include <arduino.h>
 #include <SPI.h>
 #include <SoftwareSerial.h>

const int trigPin = 4;
const int echoPin = 2;
long duration;
int distance;

unsigned long last_light_check_millis = 0;

bool get_light_value(unsigned int &value1, unsigned int &value2, unsigned int &value3, unsigned int &value4){

  unsigned long start_millis = millis();
while ( ((millis() - start_millis ) < 500) ){// timeout(5초)
  ;
}
if ( ( millis() - start_millis ) > 500 ) return false; // timeout인 경우
{
value1 = analogRead(A1);
value2 = analogRead(A2);
value3 = analogRead(A3);
value4 = analogRead(A4);

if(value1 <15 || value1 > 1015){
  return false;
}
if(value2 <15 || value2 > 1015){
  return false;
}
if(value3 <15 || value3 > 1015){
  return false;
}
if(value4 <15 || value4 > 1015){
  return false;
}
}
return true;


}

int Cal_dist(void){
int temp_distance;
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration = pulseIn(echoPin, HIGH);
temp_distance = duration*0.034/2;
return temp_distance;
}

void setup() {
Serial.begin(9600);
// 오른쪽 바퀴
  pinMode(5, OUTPUT);              
  pinMode(6, OUTPUT);              

  // 왼쪽 바퀴
 pinMode(9, OUTPUT);              
  pinMode(10, OUTPUT);              

// 조도센서
  pinMode(A1, INPUT);              
pinMode(A2, INPUT);   
pinMode(A3, INPUT);   
pinMode(A4, INPUT);

// 초음파센서
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
}

void loop() {

//if ((millis() - last_light_check_millis) > 50){
//    stop();
//    Serial.print("범인");
//}

if ((millis() - last_light_check_millis) < 200) 
  return;

distance = Cal_dist();
if(distance < 20){
 stop();
 return;
}

  unsigned int light1,light2,light3,light4;
if(get_light_value(light1,light2,light3,light4) == true){

  
Serial.print(light1);
Serial.print("     ");
Serial.print(light2);
Serial.print("     ");
Serial.print(light3);
Serial.print("     ");
Serial.print(light4);
Serial.print("     \n");
//Serial.println(distance);

//Serial.println(distance);



 
unsigned int max_value = max(light3, max(light1, light2));
unsigned int min_value = min(light3, min(light1, light2));
if ( ( max_value - min_value ) < 100 ){
  stop();
  return;
}
if ( max_value == light1 ){
  right();
}


else if ( max_value == light2 ){
  stop();
  
if((light2 - light4)>80){
    front(); 
}

}
 
 else if ( max_value == light3 ){
  left();
 }
  else{
    stop();
  }

last_light_check_millis = millis();

 /* 
if(value1 > value2){
  if(value1>value3){
    Serial.println("value1 is the best");
   right();
  }
  else{
    Serial.println("value3 is the best");
   left();
  }
}
else{
  if(value2 > value3){
    Serial.println("value2 is the best");
    stop();
  }
  else{
    Serial.println("value3 is the best");
    left();
  }
}
*/

}
}


void front()
{
    left_go();
    right_go();
}

void back(){
    left_back();
    right_back();
}

void stop(){
    left_off();
    right_off();
}

void left(){
    right_go();
    left_back();
}

void right(){
    right_back();
    left_go();
}

void right_go(){
    //analogWrite(3, 255);
    analogWrite(5, 150);
    analogWrite(6, 0);
    //Serial.println("우바퀴 정회전    ");
}

void right_back(){
    //analogWrite(3, 255);
    analogWrite(5, 0);
    analogWrite(6, 150);
 //   Serial.println("우바퀴 역회전    ");
}

void right_off(){
    //analogWrite(3, 255);
    analogWrite(5, 150);
    analogWrite(6, 150);
   // Serial.println("우바퀴 정지    ");
}

void left_go(){
    //analogWrite(6, 255);
    analogWrite(9, 150);
    analogWrite(10, 0);
    //Serial.println("좌바퀴 정회전    ");
}

void left_back(){
    //analogWrite(6, 255);
    analogWrite(9, 0);
    analogWrite(10, 150);
    //Serial.println("좌바퀴 역회전    ");
}

void left_off(){
    //analogWrite(6, 255);
    analogWrite(9, 150);
    analogWrite(10, 150);
    //Serial.println("좌바퀴 정지    ");
}
