// définir broche capteur
#define TRIGGER_PIN_CAPTEUR_ULTRASON = ? // OUTPUT car envoi un signal
#define ECHO_PIN_CAPTEUR_ULTRASON = ? // INPUT car mesure la durée de l'écho

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIGGER_PIN_CAPTEUR_ULTRASON, OUTPUT);
  pinMode(ECHO_PIN_CAPTEUR_ULTRASON, INPUT);
}

void loop() {
  // envoi d'une impulsion ultrasonique
  digitalWrite(TRIGGER_PIN_CAPTEUR_ULTRASON, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN_CAPTEUR_ULTRASON, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_CAPTEUR_ULTRASON, LOW);

  long duration = pulseIn(ECHO_PIN_CAPTEUR_ULTRASON, HIGH); // Mesure de la durée du retour de l'écho
  int distance = duration * 0.34 / 2; // calcul la distance en centimètre 
  // la formule est basée sur vitesse du son dans l'air : 1 centimètre = 34 microsecondes, on divise par deux pour calculer uniquement l'allée ou le retour
  // c = 2*d/t i.e d = c*t/2
  Serial.print("Distance : " + distance + " cm");
  delay(3000); // on attends 3 secondes avant nouvelle mesure

}
