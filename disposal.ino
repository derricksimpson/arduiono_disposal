/*
MIT License

Copyright 2017 Derrick Simpson

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

// This software should be used for good, and not evil (technically not part of the MIT license, but it's good thing)

int led = 13;
int buttonPin = 5;
int relayPin = A1;

void setup() {     
  
  pinMode(led, OUTPUT);     
  pinMode(buttonPin, INPUT);
  pinMode(relayPin, OUTPUT);

  analogWrite(led, 0);
  analogWrite(relayPin, 255);

}

int input;
int i;

// if presssed for a  short time, run for 3 sec
// if press and held behond 500ms, turn off when released

void loop() {
   
  input = digitalRead(buttonPin);
 
  if(input == 1) {

    analogWrite(led,255);
    analogWrite(relayPin, 0);
    
    delay(500);

    if (digitalRead(buttonPin) == 1){
    
        while (digitalRead(buttonPin) == 1){
            delay(100);
        }

    } else {

      if (digitalRead(buttonPin) == 0){
         
         for (int i = 0; i < 15; i++){
            delay(100);
         }
         
      }
      
    }
    
    if (digitalRead(buttonPin) == 0){
        analogWrite(led, 0);
        analogWrite(relayPin, 255);
    }

  }

  i++;

  if (i > 400){
      // turn the board LED on for ~100ms
      analogWrite(led,255);
  }

  if (i > 500){
    analogWrite(led,0);
    i = 0;
  }
  
   delay(10);
}
