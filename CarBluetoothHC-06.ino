//Programa: Controle 4 motores DC usando Ponte H L298N e Módulo Bluetooth HC-06             
//Descrição: Controle individual dos quatro motores via PWM permitindo ajuste de velocidade e mudança de direção suave.

//Definicoes pinos Arduino ligados a entrada da Ponte H do L298N #1 e #2

#define IN1_1    2        //L298N #1 - IN 1 Motor frente Direita
#define IN1_2    4        //L298N #1 - IN 2 Motor frente Direita
#define IN1_3    7        //L298N #1 - IN 3 Motor traseiro Direito
#define IN1_4    8        //L298N #1 - IN 4 Motor traseiro Direito

#define IN2_1   13        //L298N #2 - IN 1 Motor frente Esquerda 
#define IN2_2   12        //L298N #2 - IN 2 Motor frente Esquerda
#define IN2_3   11        //L298N #2 - IN 3 Motor traseiro Esquerda
#define IN2_4   10        //L298N #2 - IN 4 Motor traseiro Esquerda

#define ENA_1    3        //PWM Motor avanca Direita - ENA L298N #1
#define ENB_1    5        //PWM Motor avanca Direita - ENB L298N #1
#define ENA_2    6        //PWM Motor avanca Direita - ENA L298N #2
#define ENB_2    9        //PWM Motor avanca Direita - ENB L298N #2

#define FAROL_D    14
#define FAROL_E    15
#define LUZ_RE_D   16
#define LUZ_RE_E   17

#define BEEP       18

//DECLARÇÃO DAS VARIÁVEIS
char dado_bt;
int velocidade = 30;
int coeficiente = 4;
boolean farol = false;
boolean luz_re = false;
boolean buzina = false;
  
void setup()
{
  //Define os pinos como saida
 pinMode(IN1_1, OUTPUT);
 pinMode(IN1_2, OUTPUT);
 pinMode(IN1_3, OUTPUT);     
 pinMode(IN1_4, OUTPUT);
 
 pinMode(IN2_1, OUTPUT);
 pinMode(IN2_2, OUTPUT);
 pinMode(IN2_3, OUTPUT);
 pinMode(IN2_4, OUTPUT);

 pinMode(ENA_1, OUTPUT);
 pinMode(ENB_1, OUTPUT);
 pinMode(ENA_2, OUTPUT);
 pinMode(ENB_2, OUTPUT);

 pinMode(FAROL_D, OUTPUT);
 pinMode(FAROL_E, OUTPUT);
 pinMode(LUZ_RE_D, OUTPUT); 
 pinMode(LUZ_RE_E, OUTPUT);

 pinMode(BEEP, OUTPUT);
  
 Serial.begin(9600); 
}//fim do setup

  void avanca()//Avança
 {
  luz_re = false;
  
  digitalWrite(IN1_1,LOW);
  digitalWrite(IN1_2,HIGH);
  analogWrite(ENA_1, velocidade);

  digitalWrite(IN1_3,HIGH);
  digitalWrite(IN1_4,LOW);
  analogWrite(ENB_1, velocidade);

  digitalWrite(IN2_1,HIGH);
  digitalWrite(IN2_2,LOW);
  analogWrite(ENA_2, velocidade);

  digitalWrite(IN2_3,LOW);
  digitalWrite(IN2_4,HIGH);
  analogWrite(ENB_2, velocidade);
 }

  void retrocede()
 {
  luz_re = true;
  
  digitalWrite(IN1_1,HIGH);
  digitalWrite(IN1_2,LOW);
  analogWrite(ENA_1, velocidade);

  digitalWrite(IN1_3,LOW);
  digitalWrite(IN1_4,HIGH);
  analogWrite(ENB_1, velocidade);

  digitalWrite(IN2_1,LOW);
  digitalWrite(IN2_2,HIGH);
  analogWrite(ENA_2, velocidade);

  digitalWrite(IN2_3,HIGH);
  digitalWrite(IN2_4,LOW);
  analogWrite(ENB_2, velocidade);
 }

  void avanca_D()
 {
  luz_re = false;
  
  digitalWrite(IN1_1,LOW);
  digitalWrite(IN1_2,HIGH);
  analogWrite(ENA_1, velocidade/coeficiente);

  digitalWrite(IN1_3,HIGH);
  digitalWrite(IN1_4,LOW);
  analogWrite(ENB_1, velocidade/coeficiente);

  digitalWrite(IN2_1,HIGH);
  digitalWrite(IN2_2,LOW);
  analogWrite(ENA_2, velocidade);

  digitalWrite(IN2_3,LOW);
  digitalWrite(IN2_4,HIGH);
  analogWrite(ENB_2, velocidade);
 }


  void avanca_E()
 {
  luz_re = false;
  
  digitalWrite(IN1_1,LOW);
  digitalWrite(IN1_2,HIGH);
  analogWrite(ENA_1, velocidade);

  digitalWrite(IN1_3,HIGH);
  digitalWrite(IN1_4,LOW);
  analogWrite(ENB_1, velocidade);

  digitalWrite(IN2_1,HIGH);
  digitalWrite(IN2_2,LOW);
  analogWrite(ENA_2, velocidade/coeficiente);

  digitalWrite(IN2_3,LOW);
  digitalWrite(IN2_4,HIGH);
  analogWrite(ENB_2, velocidade/coeficiente);
 }

  void retrocede_D()
 {
  luz_re = true;
  
  digitalWrite(IN1_1,HIGH);
  digitalWrite(IN1_2,LOW);
  analogWrite(ENA_1, velocidade/coeficiente);

  digitalWrite(IN1_3,LOW);
  digitalWrite(IN1_4,HIGH);
  analogWrite(ENB_1, velocidade/coeficiente);

  digitalWrite(IN2_1,LOW);
  digitalWrite(IN2_2,HIGH);
  analogWrite(ENA_2, velocidade);

  digitalWrite(IN2_3,HIGH);
  digitalWrite(IN2_4,LOW);
  analogWrite(ENB_2, velocidade);
 }

  void retrocede_E()
 {
  luz_re = true;
  
  digitalWrite(IN1_1,HIGH);
  digitalWrite(IN1_2,LOW);
  analogWrite(ENA_1, velocidade);

  digitalWrite(IN1_3,LOW);
  digitalWrite(IN1_4,HIGH);
  analogWrite(ENB_1, velocidade);

  digitalWrite(IN2_1,LOW);
  digitalWrite(IN2_2,HIGH);
  analogWrite(ENA_2, velocidade/coeficiente);

  digitalWrite(IN2_3,HIGH);
  digitalWrite(IN2_4,LOW);
  analogWrite(ENB_2, velocidade/coeficiente);
 }


  void direita()//Avança
 {
  luz_re = false;
  
  digitalWrite(IN1_1,LOW);
  digitalWrite(IN1_2,LOW);
  //analogWrite(ENA_1, velocidade);

  digitalWrite(IN1_3,LOW);
  digitalWrite(IN1_4,LOW);
 // analogWrite(ENB_1, velocidade);

  digitalWrite(IN2_1,HIGH);
  digitalWrite(IN2_2,LOW);
  analogWrite(ENA_2, velocidade);

  digitalWrite(IN2_3,LOW);
  digitalWrite(IN2_4,HIGH);
  analogWrite(ENB_2, velocidade);
 }


  void esquerda()//Avança
 {
  luz_re = false;
  
  digitalWrite(IN1_1,LOW);
  digitalWrite(IN1_2,HIGH);
  analogWrite(ENA_1, velocidade);

  digitalWrite(IN1_3,HIGH);
  digitalWrite(IN1_4,LOW);
  analogWrite(ENB_1, velocidade);

  digitalWrite(IN2_1,LOW);
  digitalWrite(IN2_2,LOW);
  analogWrite(ENA_2, velocidade);

  digitalWrite(IN2_3,LOW);
  digitalWrite(IN2_4,LOW);
  analogWrite(ENB_2, velocidade);
 }

void desliga_motores()
{
digitalWrite(IN1_1, LOW);
digitalWrite(IN1_2, LOW);
digitalWrite(IN1_3, LOW);
digitalWrite(IN1_4, LOW);

digitalWrite(IN2_1, LOW);
digitalWrite(IN2_2, LOW);
digitalWrite(IN2_3, LOW);
digitalWrite(IN2_4, LOW);

digitalWrite(LUZ_RE_D,LOW);
digitalWrite(LUZ_RE_D,LOW);
}



void loop()
{
  if (Serial.available() > 0) 
  {
   dado_bt = Serial.read();
   desliga_motores();
      
    switch (dado_bt) {
      case 'F':avanca();break;         
      case 'B':retrocede();break;          
      case 'L':esquerda();break;          
      case 'R':direita();break;         
      case 'I':avanca_D();break;    
      case 'G':avanca_E();break;
      case 'J':{retrocede_D(); luz_re = true;}break;
      case 'H':{retrocede_E(); luz_re = true;}break;
      case '0':velocidade = 40;break;
      case '1':velocidade = 45;break;
      case '2':velocidade = 50;break;
      case '3':velocidade = 55;break;
      case '4':velocidade = 60;break;
      case '5':velocidade = 65;break;
      case '6':velocidade = 70;break;
      case '7':velocidade = 75;break;
      case '8':velocidade = 80;break;
      case '9':velocidade = 85;break;
      case 'q':velocidade = 90;break;
      case 'W':farol = true;break;
      case 'w':farol = false;break;
      case 'U':luz_re = true;break;
      case 'u':luz_re = false;break;
      case 'V':buzina = true;break;
      case 'v':buzina = false;break;
    }//Fim do Switch

    if(farol){digitalWrite(FAROL_D,HIGH); digitalWrite(FAROL_E,HIGH);}
    if(!farol){digitalWrite(FAROL_D,LOW); digitalWrite(FAROL_E,LOW);}  
      
    if(luz_re){digitalWrite(LUZ_RE_D,HIGH); digitalWrite(LUZ_RE_E,HIGH);}
    if(!luz_re){digitalWrite(LUZ_RE_D,LOW); digitalWrite(LUZ_RE_E,LOW);}
    
    if(buzina){digitalWrite(BEEP,HIGH);}
    if(buzina){digitalWrite(BEEP,LOW);}
  
  }//fim do serial

}//FIM DO LOOP



/*
      case '0':velocidade = 100;break;
      case '1':velocidade = 115;break;
      case '2':velocidade = 130;break;
      case '3':velocidade = 145;break;
      case '4':velocidade = 160;break;
      case '5':velocidade = 175;break;
      case '6':velocidade = 190;break;
      case '7':velocidade = 205;break;
      case '8':velocidade = 220;break;
      case '9':velocidade = 235;break;
      case 'q':velocidade = 255;break; 
 */
