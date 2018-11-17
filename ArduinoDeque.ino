/* Test sketch for Deque.h
 *  
 *  Usage : upload sketch to your Arduino and open serial monitor
 *  'b' to pop back
 *  'f' to pop front
 *  'B42' to push back 42
 *  'F-365' to push front -365
 *  
 *  deque is initialized with 5 values:
 *  [0] : 21
 *  [1] : 20
 *  [2] : 19
 *  [3] : -20
 *  [4] : -21
 */


#include "Deque.h"

#define DEQUE_SIZE 20

Deque<int> q = Deque<int>(DEQUE_SIZE);


void printDeque() {
  Serial.println(F("----------------------------"));
  Serial.print("count = ");
  Serial.print(q.count());
  Serial.print(", front is at ");
  Serial.print(q.front());
  Serial.print(", back is at ");
  Serial.println(q.back());
  for(int i=0; i<q.count(); i++) {
    Serial.print("[");
    Serial.print(i);
    Serial.print("] : ");
    Serial.println(q[i]);
  }
  Serial.println(F("----------------------------"));
}

void printDebug() {
  int* data = q.data_array();
  for(int i = 0; i < DEQUE_SIZE+1; i++) {
    Serial.print("data [");
    Serial.print(i);
    Serial.print("] : ");
    Serial.println(data[i]);
  }
}



void setup() {
  Serial.begin(115200);

  q.push_back(-20);
  q.push_back(-21);
  q.push_front(19);
  q.push_front(20);
  q.push_front(21);

  printDeque();
  // will print 
  // count = 5, front is at 3, back is at 2
  // [0] : 21
  // [1] : 20
  // [2] : 19
  // [3] : -20
  // [4] : -21

  Serial.println(F("'b' to pop back"));
  Serial.println(F("'f' to pop front"));
  Serial.println(F("'B42' to push back 42"));
  Serial.println(F("'F-365' to push front -365"));
}



void loop() {
  if(Serial.available()) {
    char c = Serial.read();
    switch(c) {
      case 'B': { // push_back
        if(q.count() >= DEQUE_SIZE) {
          Serial.println(F("Deque is already full, new value is dropped"));
          Serial.parseInt();
          return;
        }
        int val = Serial.parseInt();
        Serial.print("push_back (");
        Serial.print(val);
        Serial.println(")");
        q.push_back(val);
        }
        break;
      case 'b': { // pop_back
        int val = q.pop_back();
        Serial.print("pop_back() : ");
        Serial.println(val);
        }
        break;
      case 'F': { // push_front
        if(q.count() >= DEQUE_SIZE) {
          Serial.println(F("Deque is already full, new value is dropped"));
          Serial.parseInt();
          return;
        }
        int val = Serial.parseInt();
        Serial.print("push_front (");
        Serial.print(val);
        Serial.println(")");
        q.push_front(val);
        }
        break;
      case 'f': { // pop_front
        int val = q.pop_front();
        Serial.print("pop_front() : ");
        Serial.println(val);
        }
        break;
      default:
        printDeque();
        break;
    }
  }
}
