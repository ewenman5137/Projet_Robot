const int motorENA_avant = 10;
const int motorIn1_avant = 8;
const int motorIn2_avant = 9;

const int motorENB_avant = 5;
const int motorIn3_avant = 6;
const int motorIn4_avant = 7;

const int motorENA_arriere = 32;
const int motorIn1_arriere = 30;
const int motorIn2_arriere = 28;

const int motorENB_arriere = 22;
const int motorIn3_arriere = 24;
const int motorIn4_arriere = 26;

void deplacement(int vitesse, int direction) {
  Serial.print("La vitesse est : ");
  Serial.println(vitesse);
  if (vitesse > 50) {
    digitalWrite(motorIn1_avant, HIGH);
    digitalWrite(motorIn2_avant, LOW);
    digitalWrite(motorIn3_avant, HIGH);
    digitalWrite(motorIn4_avant, LOW);
    
    digitalWrite(motorIn1_arriere, HIGH);
    digitalWrite(motorIn2_arriere, LOW);
    digitalWrite(motorIn3_arriere, HIGH);
    digitalWrite(motorIn4_arriere, LOW);
    Serial.print("direction : ");
    Serial.println(direction);
    if((direction<=25000 && direction>=0) || (direction>=-25000 && direction<0)){
      Serial.println(direction<=25000 && direction>=0);
      Serial.println(direction>=-25000 && direction<0);
      if(direction>=0){
        Serial.println("Tourne à gauche");
        analogWrite(motorENA_avant, (vitesse/2));
        analogWrite(motorENB_avant, vitesse);
        analogWrite(motorENA_arriere, (vitesse/2));
        analogWrite(motorENB_arriere, vitesse);
      }else{
        Serial.println("Tourne à droite");
        analogWrite(motorENA_avant, vitesse);
        analogWrite(motorENB_avant, (vitesse/2));
        analogWrite(motorENA_arriere, vitesse);
        analogWrite(motorENB_arriere, (vitesse/2));
      }
    }
    else{
        Serial.print("Avance normalement");
        analogWrite(motorENA_avant, vitesse);
        analogWrite(motorENB_avant, vitesse);
        analogWrite(motorENA_arriere, vitesse);
        analogWrite(motorENB_arriere, vitesse);
    }
  } else {
    digitalWrite(motorIn1_avant, LOW);
    digitalWrite(motorIn2_avant, LOW);
    digitalWrite(motorIn3_avant, LOW);
    digitalWrite(motorIn4_avant, LOW);

    digitalWrite(motorIn1_arriere, LOW);
    digitalWrite(motorIn2_arriere, LOW);
    digitalWrite(motorIn3_arriere, LOW);
    digitalWrite(motorIn4_arriere, LOW);
  }
}

void reculerMoteur(int vitesse, int direction) {
  Serial.print("La vitesse est : ");
  Serial.println(vitesse);
  Serial.println("recule");
  if (vitesse > 50) {
    digitalWrite(motorIn1_avant, LOW);
    digitalWrite(motorIn2_avant, HIGH);
    digitalWrite(motorIn3_avant, LOW);
    digitalWrite(motorIn4_avant, HIGH);
    
    digitalWrite(motorIn1_arriere, LOW);
    digitalWrite(motorIn2_arriere, HIGH);
    digitalWrite(motorIn3_arriere, LOW);
    digitalWrite(motorIn4_arriere, HIGH);
    Serial.print("direction : ");
    Serial.println(direction);
    if((direction<=25000 && direction>=0) || (direction>=-25000 && direction<0)){
      Serial.println(direction<=25000 && direction>=0);
      Serial.println(direction>=-25000 && direction<0);
      if(direction>=0){
        Serial.println("Tourne à gauche");
        analogWrite(motorENA_avant, (vitesse/2));
        analogWrite(motorENB_avant, vitesse);
        analogWrite(motorENA_arriere, (vitesse/2));
        analogWrite(motorENB_arriere, vitesse);
      }else{
        Serial.println("Tourne à droite");
        analogWrite(motorENA_avant, vitesse);
        analogWrite(motorENB_avant, (vitesse/2));
        analogWrite(motorENA_arriere, vitesse);
        analogWrite(motorENB_arriere, (vitesse/2));
      }
    }
    else{
        Serial.print("Avance normalement");
        analogWrite(motorENA_avant, vitesse);
        analogWrite(motorENB_avant, vitesse);
        analogWrite(motorENA_arriere, vitesse);
        analogWrite(motorENB_arriere, vitesse);
    }
  } else {
    digitalWrite(motorIn1_avant, LOW);
    digitalWrite(motorIn2_avant, LOW);
    digitalWrite(motorIn3_avant, LOW);
    digitalWrite(motorIn4_avant, LOW);

    digitalWrite(motorIn1_arriere, LOW);
    digitalWrite(motorIn2_arriere, LOW);
    digitalWrite(motorIn3_arriere, LOW);
    digitalWrite(motorIn4_arriere, LOW);
  }
}

void tourne_en_rond(){
  Serial.println("Tourne en rond");
  digitalWrite(motorIn1_avant, HIGH);
  digitalWrite(motorIn2_avant, LOW);
  digitalWrite(motorIn3_avant, LOW);
  digitalWrite(motorIn4_avant, HIGH);
  digitalWrite(motorIn1_arriere, HIGH);
  digitalWrite(motorIn2_arriere, LOW);
  digitalWrite(motorIn3_arriere, LOW);
  digitalWrite(motorIn4_arriere, HIGH);
  analogWrite(motorENA_avant, 200);
  analogWrite(motorENB_avant, 200);
  analogWrite(motorENA_arriere, 200);
  analogWrite(motorENB_arriere, 200);
}

void setup() {
  Serial.begin(115200); // Initialiser le moniteur série pour le débogage
  Serial1.begin(115200); // Initialiser Serial1
  pinMode(motorENA_avant, OUTPUT);
  pinMode(motorIn1_avant, OUTPUT);
  pinMode(motorIn2_avant, OUTPUT);
  pinMode(motorENB_avant, OUTPUT);
  pinMode(motorIn3_avant, OUTPUT);
  pinMode(motorIn4_avant, OUTPUT);

  pinMode(motorENA_arriere, OUTPUT);
  pinMode(motorIn1_arriere, OUTPUT);
  pinMode(motorIn2_arriere, OUTPUT);
  pinMode(motorENB_arriere, OUTPUT);
  pinMode(motorIn3_arriere, OUTPUT);
  pinMode(motorIn4_arriere, OUTPUT);
  Serial.println("Initialisation terminée. Moniteur Série prêt."); // Message de démarrage
}

void loop() {
  if (Serial1.available() > 0) {
      String receivedMessage = Serial1.readStringUntil('\n'); // Lire la chaîne de caractères reçue
      int rightTrigger, leftTrigger, leftJoystickX, leftJoystickY, rightJoystickX, rightJoystickY;
      int buttonA, buttonB, buttonX, buttonY, buttonLB, buttonRB, buttonBack, buttonStart, buttonXbox, buttonLStick, buttonRStick;

      sscanf(receivedMessage.c_str(), "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
            &rightTrigger, &leftTrigger, &leftJoystickX, &leftJoystickY, &rightJoystickX, &rightJoystickY,
            &buttonA, &buttonB, &buttonX, &buttonY, &buttonLB, &buttonRB, &buttonStart, &buttonXbox);
      int valeur_moteur =0;
      if(buttonA==1 || buttonB==1 || buttonX==1 || buttonY==1){
        tourne_en_rond();
      }
      else if(rightTrigger>=leftTrigger && rightTrigger>0){
        int valeur_moteur = ((float)rightTrigger / 1023) * 255;
        deplacement(valeur_moteur,leftJoystickX); // Fonction avancermoteur
      }
      else if(leftTrigger>=rightTrigger && leftTrigger>0){
        int valeur_moteur = ((float)leftTrigger / 1023) * 255;
        reculerMoteur(valeur_moteur,leftJoystickX);
      }
      if(rightTrigger<=10 && leftTrigger<=10 && !(buttonA==1 || buttonB==1 || buttonX==1 || buttonY==1)){
        int valeur_moteur = 0;
        deplacement(valeur_moteur,leftJoystickX);
      }
    }
  delay(100);
}



