const int A = 21;
const int B = 23;
const int C = 25;
const int D = 26;
const int E = 24;
const int F = 22;
const int G = 20;
const int H = 29;
const int I = 31;
const int J = 33;
const int K = 34;
const int L = 32;
const int M = 30;
const int N = 28;
const int led = 38;
const int Gameover = 37; 
const int Button = 52;
int tempo = 1000;

void setup() 
{ // definitio des broche en sortie//
pinMode(A, OUTPUT);
pinMode(B, OUTPUT);
pinMode(C, OUTPUT);
pinMode(D, OUTPUT);
pinMode(E, OUTPUT);
pinMode(F, OUTPUT);
pinMode(G, OUTPUT); // Mise a l'etat Haut de ces sortie pour eteindre le Led de l'aficheur//
pinMode(H, OUTPUT);
pinMode(I, OUTPUT);
pinMode(J, OUTPUT);
pinMode(K, OUTPUT);
pinMode(L, OUTPUT);
pinMode(M, OUTPUT);
pinMode(N, OUTPUT);
pinMode(led, OUTPUT);
pinMode(Gameover, INPUT);
pinMode(Button, INPUT);
digitalWrite (A,LOW);
digitalWrite (B,LOW);
digitalWrite (C,LOW);
digitalWrite (D,LOW);
digitalWrite (E,LOW);
digitalWrite (F,LOW);
digitalWrite (G,LOW);
digitalWrite (H,HIGH);
digitalWrite (I,HIGH);
digitalWrite (J,HIGH);
digitalWrite (K,HIGH);
digitalWrite (L,HIGH);
digitalWrite (M,HIGH);
digitalWrite (N,HIGH);
}


void loop() 
{
 int a; 

  if(digitalRead(Button) == HIGH){
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
//chifre 9//
digitalWrite (H,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (I,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (J,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (K,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (L,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (M,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (N,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
delay (tempo);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
//chifre 8//
digitalWrite (H,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (I,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (J,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (K,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (L,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (M,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (N,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
delay (tempo);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
//chifre 7//
digitalWrite (H,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (I,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (J,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (K,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (L,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (M,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (N,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
delay (tempo);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
//chifre 6//
digitalWrite (H,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (I,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (J,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (K,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (L,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (M,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (N,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
delay (tempo);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
// chifre 5//
digitalWrite (H,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (I,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (J,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (K,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (L,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (M,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (N,LOW); 
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
delay (tempo);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
//chifre 4//
digitalWrite (H,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (I,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (J,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (K,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (L,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (M,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (N,LOW); 
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
delay (tempo);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
//chifre 3//
digitalWrite (H,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (I,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (J,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (K,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (L,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (M,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (N,LOW); 
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
delay(tempo); 
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
//chifre 2//
digitalWrite (H,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (I,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (J,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (K,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (L,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (M,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (N,LOW); 
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
delay(tempo);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}

//chifre 1//
digitalWrite (H,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (I,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (J,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (K,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (L,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (M,HIGH);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (N,HIGH); 
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
delay(tempo);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
// chifre 0//
digitalWrite (H,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (I,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (J,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (K,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (L,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (M,LOW);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}
else if(digitalRead(Button) == HIGH){
 return;
}
digitalWrite (N,HIGH);
delay(tempo);
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
}

delay(tempo);
if(digitalRead(Gameover)==HIGH){
digitalWrite (H,HIGH);
digitalWrite (I,LOW);
digitalWrite (J,LOW);
digitalWrite (K,HIGH);
digitalWrite (L,LOW);
digitalWrite (M,LOW);
digitalWrite (N,LOW);
return;
}

}



