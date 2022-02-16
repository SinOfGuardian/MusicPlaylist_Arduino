#include <Arduino.h>
#include <NoteList.h>

#define buzzPin 8
#define led4 5
#define led3 4
#define led2 3
#define led1 2
// #define ELEMENTS(x)   (sizeof(x) / sizeof(x[0])) // Let this stay I want to keep this anyway - Jerr

int ledLevel = 1; // 1(min) to 4(max)

const int high = 510;
const int mid = 300;
const int low = 80;
char r;    




void LED_Visualizer(int pitch, int delayT) { 
  if (pitch > high) {
    ledLevel = 4;
  }else if (pitch > mid) {
    ledLevel = 3;
  }else if (pitch > low) {
    ledLevel = 2;
  }else if (pitch <= low) {
    ledLevel = 1;
    
  }

  int t = ledLevel*20;

  for (int i=1; i <= ledLevel; i++) {
    digitalWrite(i+1, HIGH);
    delay(20);
  }

  delay(delayT-t);
  for (int i=led1; i <= led4; i++) 
    digitalWrite(i, LOW);
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Coffin Dance 
 int melody2[] = {
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, 
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_F4,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,NOTE_G4,0,
 };
// note durations: 4 = quarter note, 8 = eighth note, etc.:

void Coffin_Dance() {
  int noteDuration = 750 / 4;
  for (int i=0; i<1; i++) {
    for (int thisNote = 0; thisNote<sizeof(melody2)/sizeof(melody2[0]); thisNote++) {
      if (readSerialReceive1() == NULL) {
      tone(8, melody2[thisNote], noteDuration);
      LED_Visualizer(melody2[thisNote], noteDuration);

      noTone(8);
      delay(noteDuration*0.30);
      }else {
      playMe(r);
      return;}
    }
  }
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Imperial March - Star Wars
  
  #define REST    0
  // change this to make the song slower or faster
  int tempo = 120;
  // this calculates the duration of a whole note in ms
  
  int melody3[] = {
    NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
    NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
    NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16,
  
    NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,//4
    NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16,
    NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
    
    NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
    NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,
  
    NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
    NOTE_C5,4, NOTE_A4,-8, NOTE_C5,16, NOTE_E5,2,
  
    NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
    NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,
  
    NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
    NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
  };
  
  void Imperial_March() {
    int wholenote = (6000 * 4) /tempo ;
  
      for (int i=0; i<1; i++) {
         for (int thisNote = 0; thisNote<sizeof(melody3)/sizeof(melody3[0]); thisNote++) {
               if (readSerialReceive2() == NULL) {
                  tone(8, melody3[thisNote], wholenote);
                  LED_Visualizer(melody3[thisNote], wholenote);

             noTone(8);
              delay(wholenote*0.1);
      }else {
      playMe(r);
      return;}
    }
  }
  }

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Rick Astley - Never Gonna Give You Up 

volatile int beatlength = 100; // determines tempo
#define rest -1

int INTRO[] = { 
  NOTE_CS5, NOTE_DS5, NOTE_DS5, NOTE_F5, NOTE_GS5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_DS5, rest, NOTE_GS4, NOTE_GS4 };
int INTRO_RYTH[] = {
  6, 10, 6, 6, 1, 1, 1, 1, 6, 10, 4, 2, 10 };

int VERSE[] = { 
  rest, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_DS4, rest, NOTE_C4, NOTE_AS3, NOTE_GS3,
  rest, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_GS3, NOTE_GS4, NOTE_GS4, NOTE_DS4,
  rest, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_AS3, NOTE_CS4, NOTE_DS4, rest, NOTE_C4, NOTE_AS3, NOTE_AS3, NOTE_GS3,
  rest, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_GS3, NOTE_GS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_DS4,
  NOTE_CS4, NOTE_DS4, NOTE_F4, NOTE_CS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_GS3,
  rest, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_GS3, rest, NOTE_DS4, NOTE_F4, NOTE_DS4 };
int VERSE_RYTH[] = {  
  2, 1, 1, 1, 1, 2, 1, 1, 1, 5,
  1, 1, 1, 1, 3, 1, 2, 1, 5,
  1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3,
  1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 4,
  5, 1, 1, 1, 1, 1, 1, 1, 2, 2,
  2, 1, 1, 1, 3, 1, 1, 1, 10 };

int CHORUS[] = { 
  NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4,
  NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_DS5, NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_AS4,
  NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_CS5,
  NOTE_CS5, NOTE_DS5, NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_DS5, NOTE_CS5,
  NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4,
  NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_GS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4,
  NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_CS5,
  NOTE_CS5, NOTE_DS5, NOTE_C5, NOTE_AS4, NOTE_GS4, rest, NOTE_GS4, NOTE_DS5, NOTE_CS5, rest };
int CHORUS_RYTH[] = { 
  1, 1, 1, 1,
  3, 3, 6, 1, 1, 1, 1, 3, 3, 3, 1, 2,
  1, 1, 1, 1,
  3, 3, 3, 1, 2, 2, 2, 4, 8,
  1, 1, 1, 1,
  3, 3, 6, 1, 1, 1, 1, 3, 3, 3, 1, 2,
  1, 1, 1, 1,
  3, 3, 3, 1, 2, 2, 2, 4, 8, 8 };

void playMusic1(int MELODY[], int MELODY_RYTH[], int size) {
  int notelength;
  
  for (int i=0; i<size; i++) {
    if (readSerialReceive() == NULL) {
      notelength = beatlength * MELODY_RYTH[i];
      tone(buzzPin, MELODY[i], notelength);
      LED_Visualizer(MELODY[i], notelength);
  
      noTone(buzzPin);
      delay(notelength*0.3);
    }else {
      playMe(r);
      return;
    }
  }
}

void Never_Gonna_Give_You_Up() {
  
  playMusic1(CHORUS, CHORUS_RYTH,  sizeof(CHORUS) / sizeof(int));
  playMusic1(VERSE, VERSE_RYTH,  sizeof(VERSE) / sizeof(int));
  playMusic1(CHORUS, CHORUS_RYTH,  sizeof(CHORUS) / sizeof(int));
  playMusic1(INTRO, INTRO_RYTH,  sizeof(INTRO) / sizeof(int));
  
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

void playMe(char key) {
  // Music 1
  if (key=='1'){
    Never_Gonna_Give_You_Up();
    }
  // Music 2
  else if (key=='2'){
    Imperial_March();
    Serial.flush();}
  // Music 3
  else if (key=='3'){
    Coffin_Dance();
    }
  else if (key=='0') {
    noTone(buzzPin);
    for (int i=led1; i <= led4; i++) 
      digitalWrite(i, LOW);
  }
}

char readSerialReceive() {
  if (Serial.available() > 0) {
    r = Serial.read();
    return r;
  }else {
    return ;
  }
}   

char readSerialReceive1() {
  if (Serial.available() > 4) {
    r = Serial.read();
    return r;
  }else {
    return ;
  }
} 
char readSerialReceive2() {
  if (Serial.available() > 8) {
    r = Serial.read();
    return r;
  }else {
    return ;
  }
}   
void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  delay(2000);
}

void loop() {
  if (readSerialReceive() != NULL) { 
    playMe(r);
  
  //delay(5000);
  }
  
  
}
