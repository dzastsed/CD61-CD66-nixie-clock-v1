#include <MD_DS1307.h>
#include <Wire.h>
#include <math.h>
#include <stdlib.h>
#define A1 3
#define B1 4
#define C1 5
#define D1 6
#define A2 7
#define B2 8
#define C2 9
#define D2 10
#define A3 17
#define B3 12
#define C3 13
#define D3 14
#define A4 15
#define B4 16
#define C4 2
#define D4 1
#define pot 0
char A[4] = {A1, A2, A3, A4};
char B[4] = {B1, B2, B3, B4};
char C[4] = {C1, C2, C3, C4};
char D[4] = {D1, D2, D3, D4};
int zero;
int one;
int two;
int three;
int hour;
int minute;
int second;
int scrambleCounter = 0;
bool scrambleActive = false;
unsigned long previousTime = 0;
const unsigned long interval = 1000; // Delay interval in milliseconds

void setup() {
  pinMode(A1, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(B3, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(B4, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(pot, INPUT);
  for (char i = 0; i < 4; i++) {
    digitalWrite(A[i], HIGH);
    digitalWrite(B[i], HIGH);
    digitalWrite(C[i], HIGH);
    digitalWrite(D[i], HIGH);
  }
  if (!RTC.isRunning())
    RTC.control(DS1307_CLOCK_HALT, DS1307_OFF);
  tubeScramble(30);
}

void loop() {
  RTC.readTime();
  hour = RTC.h;
  minute = RTC.m;
  second = RTC.s;

  unsigned long currentTime = millis();
  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;

    // Check if it's time for a character scramble
    if (minute == 31 && second == 30 && !scrambleActive) {
      scrambleActive = true;
      tubeScramble(30);
      scrambleActive = false;
    }

    // Display the time or scrambled characters
    if (!scrambleActive) {
      zero = (hour / 10) % 10;
      one = hour % 10;
      two =  (minute / 10) % 10;
      three = minute % 10;
    } else {
      // Perform the Nixie tube scramble
      tubeScramble(30);
    }

    writenumber(1, zero);
    writenumber(2, one);
    writenumber(3, two);
    writenumber(0, three);
  }
}

void writenumber(int a, int b) {
  switch (b) {
    case 1:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], LOW);
      break;
    case 2:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], LOW);
      break;
    case 3:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], HIGH);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], LOW);
      break;
    case 4:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], HIGH);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], LOW);
      break;
    case 5:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], HIGH);
      digitalWrite(D[a], LOW);
      break;
    case 6:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], HIGH);
      digitalWrite(D[a], LOW);
      break;
    case 7:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], HIGH);
      digitalWrite(C[a], HIGH);
      digitalWrite(D[a], LOW);
      break;
    case 8:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], HIGH);
      digitalWrite(C[a], HIGH);
      digitalWrite(D[a], LOW);
      break;
    case 9:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], HIGH);
      break;
    case 0:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], HIGH);
      break;
  }
}

void tubeScramble(int timeInSeconds) {
  int n1 = round(sqrt((2 * timeInSeconds)/0.001));
  int n2 = 0;
  
  while (n1 > 0) {
    // Perform the Nixie tube scramble logic here
    // Adjust the code to modify the Nixie tube segment activation patterns during the scramble
    writenumber(1, n2 % 10);
    writenumber(2, n2 % 10);
    writenumber(3, n2 % 10);
    writenumber(0, n2 % 10);
    
    n1--;
    n2++;
    delay(n1);
  }
}

void off(int a) {
  digitalWrite(A[a], HIGH);
  digitalWrite(B[a], HIGH);
  digitalWrite(C[a], HIGH);
  digitalWrite(D[a], HIGH);
}
