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
