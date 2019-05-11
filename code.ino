#include <RC5.h>
 
#define L_PWM 5
#define L_DIR 4
#define R_PWM 6
#define R_DIR 9
#define PWM_MAX 165
 
#define BUZZER 10
#define LED 13
#define TSOP_PIN 3
#define L_SIDE_SENSOR A0
#define R_SIDE_SENSOR A1

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define NOTE_E8 5274
#define NOTE_F8 5588
#define NOTE_FS8 5920
#define NOTE_G8 6272
#define NOTE_GS8 6644
#define NOTE_A8 7040
#define NOTE_AS8 7458
#define NOTE_B8 7902
#define NOTE_C9 8372

int melody[] = {
  NOTE_E7 ,NOTE_C7, NOTE_E7,
  NOTE_AS7, NOTE_F7,0,0,0,
  NOTE_D7, NOTE_B6, NOTE_D7, NOTE_G7, NOTE_E7,0,
  NOTE_D7, NOTE_C7, 0,0, NOTE_C7, NOTE_A6, NOTE_D7, 0, NOTE_A6, NOTE_G6,0,0,NOTE_D7, NOTE_C7,NOTE_E7,0,NOTE_D7,NOTE_C7
}; //BarbieGirl

int melody2[]= {
    NOTE_G7, NOTE_G7,NOTE_A7, NOTE_A7, NOTE_E7,NOTE_E7,NOTE_G7,
    NOTE_G7, NOTE_G7,NOTE_A7, NOTE_A7, NOTE_E7,NOTE_E7,NOTE_G7,
    NOTE_G7, NOTE_G7,NOTE_A7, NOTE_A7, NOTE_C8,NOTE_C8,NOTE_B7,NOTE_B7,NOTE_A7,NOTE_G7,NOTE_F7,
    NOTE_F7, NOTE_F7,NOTE_G7, NOTE_G7, NOTE_D7,NOTE_D7,NOTE_F7,
    NOTE_F7, NOTE_F7,NOTE_G7, NOTE_G7, NOTE_D7,NOTE_D7,NOTE_F7,
    NOTE_F7, NOTE_F7,NOTE_G7, NOTE_G7, NOTE_B7,NOTE_B7,NOTE_A7,NOTE_A7,NOTE_G7,NOTE_F7,NOTE_E7
}; //Kaczuszki

int melody3[] = {
  NOTE_C7, NOTE_C7, NOTE_D7, NOTE_D7,NOTE_E7, NOTE_E7,NOTE_F7, NOTE_F7, NOTE_G7, NOTE_G7, NOTE_G7, NOTE_AS7,NOTE_D8,NOTE_C8, 0, NOTE_C9
}; //KucezBronksu

int melody4[] = {
  NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_A7,0,
  NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_D7,NOTE_C7,0,
  NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_F7,NOTE_A7,0,
  NOTE_C8,NOTE_C8,NOTE_AS7,NOTE_C8,NOTE_A7,NOTE_F7
}; //Macarena


int tempo[] = {
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

int tempo2[]= {
  16,16,16,16,
  16,16,8,
  16,16,16,16,
  16,16,8,
  16,16,16,16,
  16,16,8,
  8,8,8,8,
  16,16,16,16,
  16,16,8,
  16,16,16,16,
  16,16,8,
  16,16,16,16,
  16,16,8,
  8,8,8,8,
};

int tempo3[] = {
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 24, 24,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

int tempo4[]={
  8,16,16,8,16,8,16,16,16,16,8,16,
  8,16,16,8,16,8,16,16,16,16,8,16,
  8,16,16,8,16,8,16,16,16,16,8,16,
  4,16,8,16,16,16
};
 
RC5 rc5(TSOP_PIN); //Informacja o podłączeniu odbiornika TSOP
byte address; 
byte command;
byte toggle;

void setup() {
  //Konfiguracja pinow od mostka H
  pinMode(L_DIR, OUTPUT);
  pinMode(R_DIR, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(R_PWM, OUTPUT);

   //Konfiguracja pinow od czujnikow
  pinMode(L_SIDE_SENSOR, INPUT_PULLUP);
  pinMode(R_SIDE_SENSOR, INPUT_PULLUP);

  //Konfiguracja pozostalych elementow
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, 0); //Wylaczenie buzzera  
  pinMode(LED, OUTPUT); 
  digitalWrite(LED, 0); //Wylaczenie diody


int size = sizeof(melody3) / sizeof(int);
 for (int thisNote = 0; thisNote < size; thisNote++) {

       // to calculate the note duration, take one second
       // divided by the note type.
       //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
       int noteDuration = 1000/tempo3[thisNote];

       buzz(BUZZER, melody3[thisNote],noteDuration);

       // to distinguish the notes, set a minimum time between them.
       // the note's duration + 30% seems to work well:
       int pauseBetweenNotes = noteDuration * 1.30;
       delay(pauseBetweenNotes);

       // stop the tone playing:
       buzz(BUZZER, 0,noteDuration);

    }
}
 
int predkoscObrotu = 30;
int predkoscPrzod = 30;
byte togglePoprzedni = 0;
 
void loop() {
 if (digitalRead(L_SIDE_SENSOR) == LOW || digitalRead(R_SIDE_SENSOR) == LOW) {
    //Jesli przeszkoda po dowolnej stronie
    //Jedz wstecz i wydawaj dzwiek
    stopMotors();
    delay(100);
    leftMotor(-20);
    rightMotor(-20);
    digitalWrite(BUZZER, 1);
     delay(500);
    digitalWrite(BUZZER, 0);
    delay(500);
    digitalWrite(BUZZER, 1);
     delay(500);
    digitalWrite(BUZZER, 0);
    delay(500);
    digitalWrite(BUZZER, 1);
     delay(500);
    digitalWrite(BUZZER, 0);
    stopMotors();
  }
  
 if (rc5.read(&toggle, &address, &command)){
     switch(command) {
       case 32:
       if(predkoscPrzod < 59){
        predkoscPrzod = predkoscPrzod + 2;
       }
        case 2:
        leftMotor(predkoscPrzod);
        rightMotor(predkoscPrzod);
      break; 
      case 4: //Obrót w lewo
        leftMotor(-predkoscObrotu);
        rightMotor(predkoscObrotu);
      break;
      case 5:
       leftMotor(0);
       rightMotor(0);
       predkoscPrzod = 30;
      break;   
        case 6: 
        leftMotor(predkoscObrotu);
        rightMotor(-predkoscObrotu);
      break;
       case 0: 
        leftMotor(-predkoscObrotu);
        rightMotor(predkoscObrotu);
        break;
       
     case 8:
        leftMotor(-predkoscObrotu);
        rightMotor(-predkoscObrotu);
        break;

        /*case 7:
       int size1 = sizeof(melody2) / sizeof(int);
       

        int counter1 = 0;
       for (int thisNote = 0; thisNote < size1; thisNote++) {
      
             // to calculate the note duration, take one second
             // divided by the note type.
             //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
             int noteDuration = 1000/tempo2[thisNote];
      
             buzz(BUZZER, melody2[thisNote],noteDuration);
      
             // to distinguish the notes, set a minimum time between them.
             // the note's duration + 30% seems to work well:
             int pauseBetweenNotes = noteDuration * 1.30;
             delay(pauseBetweenNotes);
      
             // stop the tone playing:
             buzz(BUZZER, 0,noteDuration);
             if(counter1 == 0 )
            {
              leftMotor(-predkoscObrotu);
              rightMotor(predkoscObrotu);
              counter1 = 1;
            }
            else 
            {
              leftMotor(predkoscObrotu);
              rightMotor(-predkoscObrotu);
              counter1 = 0;
            }
          }
          leftMotor(0);
          rightMotor(0);
           break;
           */
      case 9:
        int size = sizeof(melody2) / sizeof(int);
       

        int counter = 0;
       for (int thisNote = 0; thisNote < size; thisNote++) {
      
             // to calculate the note duration, take one second
             // divided by the note type.
             //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
             int noteDuration = 1000/tempo2[thisNote];
      
             buzz(BUZZER, melody2[thisNote],noteDuration);
      
             // to distinguish the notes, set a minimum time between them.
             // the note's duration + 30% seems to work well:
             int pauseBetweenNotes = noteDuration * 1.30;
             delay(pauseBetweenNotes);
      
             // stop the tone playing:
             buzz(BUZZER, 0,noteDuration);
             if(counter == 0 )
            {
              leftMotor(-predkoscObrotu);
              rightMotor(predkoscObrotu);
              counter = 1;
            }
            else 
            {
              leftMotor(predkoscObrotu);
              rightMotor(-predkoscObrotu);
              counter = 0;
            }
          }

           leftMotor(0);
           rightMotor(0);
          
      break;
             
    }
 
     //Jeśli bit toggle jest taki sam jak poprzednio
    if (toggle == togglePoprzedni) {
      predkoscObrotu++; //Zwieksz predkosc obrotu o 1
 
      //Jeśli wartość prędkości przekroczy 90
      if (predkoscObrotu >= 90) {
        predkoscObrotu = 30; //To ustawiamy stadnardowe 30
      }
    } else { //Jeśli bit toggle jest różny
      //Ustaw predkosc na standardową
      predkoscObrotu = 30;    
    }
    //Zapamiętanie poprzedniej wartości toggle
    togglePoprzedni = toggle;
  }
}
 
void leftMotor(int V) {
  if (V > 0) { //Jesli predkosc jest wieksza od 0 (dodatnia)
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(L_DIR, 0); //Kierunek: do przodu
    analogWrite(L_PWM, V); //Ustawienie predkosci 
  } else {
    V = abs(V); //Funkcja abs() zwroci wartosc V  bez znaku
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(L_DIR, 1); //Kierunek: do tyłu
    analogWrite(L_PWM, V); //Ustawienie predkosci    
  }
}
 
void rightMotor(int V) {
  if (V > 0) { //Jesli predkosc jest wieksza od 0 (dodatnia)
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(R_DIR, 0); //Kierunek: do przodu
    analogWrite(R_PWM, V); //Ustawienie predkosci 
  } else {
    V = abs(V); //Funkcja abs() zwroci wartosc V  bez znaku
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(R_DIR, 1); //Kierunek: do tyłu
    analogWrite(R_PWM, V); //Ustawienie predkosci    
  }
}
 
void stopMotors() {
  analogWrite(L_PWM, 0); //Wylaczenie silnika lewego
  analogWrite(R_PWM, 0); //Wylaczenie silnika prawego
}
void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13,HIGH);
  long delayValue = 1000000/frequency/2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length/ 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to 
  //// get the total number of cycles to produce
  for (long i=0; i < numCycles; i++){ // for the calculated length of time...
    digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13,LOW);

}
