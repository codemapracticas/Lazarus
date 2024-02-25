
int estado = 0;
int vibracion = true;
int fuerza = 130;
int sensibilidad =110;
String cadena = "";

void setup() {
  Serial.begin(19200);
  pinMode(13, OUTPUT);
}

  
void loop() {

  if (Serial.available() > 0) {
    char incomingData = Serial.read();
    if ( incomingData == '1')
      estado = 1;
    else if (incomingData == '2')
      estado = 2;
    else if (incomingData == '3')
      estado = 3;
    else if (incomingData == '4')
      estado = 4;
     else if (incomingData == 'Q'){
      while (Serial.available() > 0){
        int var= Serial.read();
        if (isDigit(var)) {
          cadena += (char)var;
        }
      }
      sensibilidad = cadena.toInt();
     }
      else if (incomingData == 'S'){
        while (Serial.available() > 0){
            int var= Serial.read();
            if (isDigit(var)) {
              cadena += (char)var;
            }
        }
      fuerza = cadena.toInt();
      }
    else
      estado = 0;
  }
  
  if (estado == 1)
    //digitalWrite(13, HIGH);
    analogWrite(11, fuerza);
  else if (estado == 2)
    //digitalWrite(10, HIGH);
    analogWrite(10, sensibilidad);
  else if (estado == 3) {
    //digitalWrite(10, HIGH);
    analogWrite(10,sensibilidad);
    //digitalWrite(11, HIGH);
    analogWrite(11, fuerza);
  }
  else if (estado == 4) {
      vibracion=not(vibracion);
      //digitalWrite(10, vibracion);
      //digitalWrite(11, vibracion);
      if (vibracion == true) {
        analogWrite(10, sensibilidad);
        analogWrite(11, fuerza);
      }
     else {
         analogWrite(10, LOW);
        analogWrite(11, LOW);     
     }
      delay(500);
   }
   else if (estado == 0) {
      //digitalWrite(10, LOW);
      analogWrite(10, LOW);
      //digitalWrite(11, LOW);
      analogWrite(11, LOW);
   }
    
    
}

