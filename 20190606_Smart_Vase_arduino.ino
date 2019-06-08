  #include <arduino.h>
 #include <SPI.h>
 #include <SoftwareSerial.h>

int blueTx=3;   //Tx (보내는핀 설정)at
int blueRx=2;   //Rx (받는핀 설정)

SoftwareSerial mySerial(blueTx, blueRx);

unsigned long last_light_check_millis = 0;
int data[100][2]; // 방향, 시간
const int speed_=150;  // 속도 제어
int dataseek=0;   // ★★★★★★★★★★★★★★★★여기 나중에 0으로 바꿔야한다아아악
int printseek=0;
unsigned int light1,light2,light3;
unsigned long prev_time = 0;

void trans_data(){

  int degChange;  // 기울기 각도 변화 
  int angleSum=0; // 기울기 합
  double toTangent;  // 기울기처리(tangent)
  double beforeX = 0;  //x0좌표
  double beforeY = 0;  //Y0좌표    
  double curX=0;       //X1좌표
  double curY=0;     //Y1좌표
  double constant=0; //상수
  
  double a,b,c;
 
 

  

  // 첫동작이 전진이면 y초기좌표 이동
  if(data[0][0] == 0){
    mySerial.print("_");
    mySerial.print(0);
    mySerial.print("_");
    mySerial.print(data[0][1]);
    beforeY=data[0][1];
    for(int tseek=1;tseek<=dataseek;tseek+=2){
      
      //  왼쪽 오른쪽 몇도 꺾을지
      if (data[tseek][0]==1){
        degChange=-data[tseek][1]/2;
      }
      else if(data[tseek][0]==0){
        degChange=0;
      }
      else{
        degChange=data[tseek][1]/2;
      }


      // 기울기 합처리
      angleSum+=degChange;
      if(angleSum>=180){
        angleSum-=360;
      }
      else if(angleSum<=-180){
        angleSum+=360;
      }

      // 기울기처리(tangent)
      if(angleSum>-180 && angleSum<0){
        toTangent = tan(radians(-90-angleSum));
      }
      else if(angleSum>0 && angleSum<180){
        toTangent = tan(radians(90-angleSum));
      }
      else{
        toTangent = tan(radians(angleSum));
      }

      // 상수처리
      if(angleSum==0 || angleSum==180){
        constant=beforeY;
      }
      else if(angleSum==90 || angleSum==270){
        constant = beforeX;
      }
      else{
        constant = beforeY-(toTangent*beforeX);
      }


      // 근의 공식 위한 abc처리
      a = toTangent*toTangent+1;
      b = beforeX + (toTangent*beforeY) - (toTangent*constant);
      c = (beforeX * beforeX) + (constant*constant) + (beforeY *beforeY) - 2*(constant*beforeY) - pow(data[tseek+1][1],2);
      

      // 이동후 x좌표
      if(angleSum==0 || angleSum==-180 || angleSum==180){
        curX=beforeX;
      }
      else if(angleSum == 90){
        curX = beforeX+data[tseek+1][1];
      }
      else if(angleSum == -90){
        curX = beforeX-data[tseek+1][1];
      }
      else if(angleSum>0 && angleSum<180){
        curX = (b + sqrt(b*b - a*c)) / a;
      }
      else{
        curX = (b-sqrt(b*b-a*c))/a;
      }

      // 이동후 y좌표
      if(angleSum==90 || angleSum==-90){
        curY=beforeY;
      }
      else if(angleSum==0){
        curY=beforeY+data[tseek+1][1];
      }
      else if(angleSum==180 || angleSum==-180){
        curY=beforeY-data[tseek+1][1];
      }
      else{
        curY=curX*toTangent+constant;
      }

      // 데이터 대입
      beforeX=curX;
      beforeY=curY;
      
      //Serial.print("X : ");
      mySerial.print("_");
      mySerial.print(curX);
      //Serial.print("\t\tY : ");
      mySerial.print("_");
      mySerial.print(curY);
    }
  }

  
  // 왼쪽이나 오른쪽 시작
  else{  
    mySerial.print("_");
    mySerial.print(0);
    mySerial.print("_");
    mySerial.print(0);
    for(int tseek=0;tseek<=dataseek;tseek+=2){
      Serial.println(data[tseek][0]);
      Serial.println(data[tseek][1]);
      Serial.println(tseek);
      //  왼쪽 오른쪽 몇도 꺾을지
      if (data[tseek][0]==1){
        degChange=-data[tseek][1]/2;
        while(degChange<-360){
          degChange +=360;
        }
      }
      else if(data[tseek][0]==0){
        degChange=0;
      }
      else{
        degChange=data[tseek][1]/2;
        while(degChange>360){
          degChange-=360;
        }
      }
      Serial.println("degChange : ");
      Serial.println(degChange);
      
      // 기울기 합처리
      angleSum+=degChange;
      if(angleSum>=180){
        angleSum-=360;
      }
      else if(angleSum<=-180){
        angleSum+=360;
      }

      Serial.println("angleSum : ");
      Serial.println(angleSum);
      // 기울기처리(tangent)
      if(angleSum>-180 && angleSum<0){
        toTangent = tan(radians(-90-angleSum));
      }
      else if(angleSum>0 && angleSum<180){
        toTangent = tan(radians(90-angleSum));
      }
      else{
        toTangent = tan(radians(angleSum));
      }
      Serial.println("toTangent : ");
      Serial.println(toTangent);
      // 상수처리
      if(angleSum==0 || angleSum==180){
        constant=beforeY;
      }
      else if(angleSum==90 || angleSum==270){
        constant = beforeX;
      }
      else{
        constant = beforeY-(toTangent*beforeX);
      }
      Serial.println("constant : ");
      Serial.println(constant);

      // 근의 공식 위한 abc처리
      a = toTangent*toTangent+1;
      b = beforeX + (toTangent*beforeY) - (toTangent*constant);
      c = (beforeX * beforeX) + (constant*constant) + (beforeY *beforeY) - 2*(constant*beforeY) - pow(data[tseek+1][1],2);
      Serial.println("a,b,c");
      Serial.println(a);
      Serial.println(b);
      Serial.println(c);

           // 이동후 x좌표
      if(angleSum==0 || angleSum==-180 || angleSum==180){
        curX=beforeX;
      }
      else if(angleSum == 90){
        curX = beforeX+data[tseek+1][1];
      }
      else if(angleSum == -90){
        curX = beforeX-data[tseek+1][1];
      }
      else if(angleSum>0 && angleSum<180){
        curX = (b + sqrt(b*b - a*c)) / a;
      }
      else{
        curX = (b-sqrt(b*b-a*c))/a;
      }

      // 이동후 y좌표
      if(angleSum==90 || angleSum==-90){
        curY=beforeY;
      }
      else if(angleSum==0){
        curY=beforeY+data[tseek+1][1];
      }
      else if(angleSum==180 || angleSum==-180){
        curY=beforeY-data[tseek+1][1];
      }
      else{
        curY=curX*toTangent+constant;
      }
      
      // 데이터 대입
      beforeX=curX;
      beforeY=curY;

      //Serial.print("X : ");
      mySerial.print("_");
      mySerial.print(curX/10);
      Serial.print("X : ");
      Serial.println(curX);
      Serial.print("Y : ");
      Serial.println(curY);
      //Serial.print("\t\tY : ");
      mySerial.print("_");
      mySerial.print(curY/10);
      
    }
  }
  Serial.println("데이터 전송 완료");
}


bool get_light_value(){

  unsigned long start_millis = millis();
  while ( ((millis() - start_millis ) < 500) ){// timeout(5초)
    ;
  }
  if ( ( millis() - start_millis ) > 500 ) 
    return false; // timeout인 경우
  
  light1 = analogRead(A1);
  light2 = analogRead(A2);
  light3 = analogRead(A3);
  //Serial.print(light1);
  //Serial.print("     ");
  //Serial.print(light2);
  //Serial.print("     ");
  //Serial.print(light3);
  //Serial.print("\n");
  if(light1 <15 || light1 > 1015){
    return false;
  }
  if(light2 <15 || light2 > 1015){
    return false;
  }
  if(light3 <15 || light3 > 1015){
    return false;
  }
  
  return true;
  
}



void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  // start ,return 버튼 대기
  pinMode(12,INPUT);
  // 오른쪽 바퀴
  pinMode(5, OUTPUT);              
  pinMode(6, OUTPUT);              

  // 왼쪽 바퀴
  pinMode(10, OUTPUT);              
  pinMode(11, OUTPUT);              

// 조도센서
  pinMode(A1, INPUT);              
  pinMode(A2, INPUT);   
  pinMode(A3, INPUT);   
/*
  data[0][0]=1;
  data[0][1]=120;
  data[1][0]=0;
  data[1][1]=200;
  data[2][0]=2;
  data[2][1]=150;
  data[3][0]=0;
  data[3][1]=350;
  data[4][0]=2;
  data[4][1]=200;
  data[5][0]=0;
  data[5][1]=400;  
  data[6][0]=1;
  data[6][1]=550;  
  data[7][0]=0;
  data[7][1]=600;
  data[8][0]=1;
  data[8][1]=250;    
  data[9][0]=0;
  data[9][1]=400;
*/
Serial.println("not start yet");
  
}

void loop() {
  
  
  
  while(1){
    int startBut = digitalRead(12);
    if(startBut == HIGH){
      Serial.println("Let's start");
      break;
    }
    delay(500);
  }

  while(digitalRead(12)==HIGH){
    if ((millis() - last_light_check_millis) < 200) 
      return;
  
  
    if(get_light_value() == true){
      
      Serial.print(light1);
      Serial.print("     ");
      Serial.print(light2);
      Serial.print("     ");
      Serial.print(light3);
      Serial.print("\n");
      
      unsigned int max_value = max(light3, max(light1, light2));
      unsigned int min_value = min(light3, min(light1, light2));
  
      // 고만고만할 때
      if ( ( max_value - min_value ) < 100 ){
        my_stop();
        delay(3000);
        continue;
      }
  
      // 오른쪽이 빛이 제일 쌜 때
      else if ( min_value == light1 ){
        data[dataseek][0]=2;
        right();
        prev_time=millis();
        while(1){
         
          if(get_light_value()){
            unsigned int min_value2 = min(light3, min(light1, light2));
          
            if(min_value2 == light2){
              my_stop();
              data[dataseek][1]=millis() - prev_time;
              delay(3000);
              break;
            }
          
          }
          delay(1);   // 과부하 방지
        
        }
  
      }
      
      // 전방이 빛이 제일 쌜 때
      else if ( min_value == light2 ){
        my_stop();
        data[dataseek][0]=0;
        front();
        prev_time=millis();
        
        while(1){
         
          if(get_light_value()){
            unsigned int min_value2 = min(light3, min(light1, light2));
          
            if(min_value2 != light2){
              my_stop();
              data[dataseek][1]=millis() - prev_time;
              delay(3000);
              break;
            }
          
          }
          delay(1);   // 과부하 방지
        
        }
      }
  
       // 왼쪽이 빛이 제일 쌜 때
       else if ( min_value == light3 ){
        data[dataseek][0]=1;
        left();
        prev_time=millis();
        while(1){
         
          if(get_light_value()){
            unsigned int min_value2 = min(light3, min(light1, light2));
          
            if(min_value2 == light2){
              my_stop();
              data[dataseek][1]=millis() - prev_time;
              delay(3000);
              break;
            }
          
          }
          delay(1);   // 과부하 방지
        
        }

       }
        dataseek++;      
      last_light_check_millis = millis();
      Serial.println(printseek);
      Serial.println(dataseek);
      Serial.print("direct : ");
      
      Serial.print(data[printseek][0]);
      Serial.print("time : ");
      Serial.println(data[printseek++][1]); 
    }
  }
  my_stop();

  // 데이터 전송
  Serial.println("데이터 전송 시작");
  trans_data();
  delay(3000);
 
  dataseek--;
  Serial.println("복귀합니다");
  while(dataseek!=-1){
    
    if(data[dataseek][0]==0){
      back();
      Serial.println("후진");  
    }

    else if(data[dataseek][0]==1){
      right();
      Serial.println("오른쪽");
    }

    else if(data[dataseek][0]==2){
      left();
      Serial.println("왼쪽");
    }
    delay(data[dataseek][1]);
    my_stop();

    
    delay(3000);
    dataseek--;
  }


  
  while(1){
    Serial.println("무한루프");
    delay(100);
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

void my_stop(){
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
    analogWrite(5, speed_);
    analogWrite(6, 0);
    //Serial.println("우바퀴 정회전    ");
}

void right_back(){
    //analogWrite(3, 255);
    analogWrite(5, 0);
    analogWrite(6, speed_);
    //Serial.println("우바퀴 역회전    ");
}

void right_off(){
    //analogWrite(3, 255);
    analogWrite(5, speed_);
    analogWrite(6, speed_);
    //Serial.println("우바퀴 정지    ");
}

void left_go(){
    //analogWrite(6, 255);
    analogWrite(10, speed_);
    analogWrite(11, 0);
    //Serial.println("좌바퀴 정회전    ");
}

void left_back(){
    //analogWrite(6, 255);
    analogWrite(10, 0);
    analogWrite(11, speed_);
    //Serial.println("좌바퀴 역회전    ");
}

void left_off(){
    //analogWrite(6, 255);
    analogWrite(10, speed_);
    analogWrite(11, speed_);
    //Serial.println("좌바퀴 정지    ");
}
