/*
   Robot quadrupède à 2 servomoteurs
   Pour plus d'infos:
   https://electroniqueamateur.blogspot.com/2021/06/robot-quadrupede-2-servomoteurs-arduino.html
*/

// bibliothèque servo
#include <Servo.h>

// numéro des broches utilisées (doivent être des sorties PWM)
#define pin_servo_avant 9
#define pin_servo_arriere 10

// angle de rotation des servos par rapport à leur position d'équilibre
// (vous l'augmentez pour faire de plus grands pas)
#define angle_rotation 20

//position d'équilibre des servos, en degrés
#define angle_avant 90
#define angle_arriere 90

// création de deux objets servo
Servo servo_avant, servo_arriere;

// les 4 phases de la marche avant
char marche_avant[] = {angle_avant - angle_rotation, angle_arriere + angle_rotation,
                       angle_avant + angle_rotation, angle_arriere + angle_rotation,
                       angle_avant + angle_rotation, angle_arriere - angle_rotation,
                       angle_avant - angle_rotation, angle_arriere - angle_rotation
                      };

// les 4 phases de la marche arrière
char marche_arriere[] = {angle_avant - angle_rotation, angle_arriere - angle_rotation,
                         angle_avant + angle_rotation, angle_arriere - angle_rotation,
                         angle_avant + angle_rotation, angle_arriere + angle_rotation,
                         angle_avant - angle_rotation, angle_arriere + angle_rotation
                        };

void setup()
{
  servo_avant.attach(pin_servo_avant);
  servo_arriere.attach(pin_servo_arriere);
}

void loop()
{
  // on avance (10 cycles):
  for (int i = 0; i < 10; i++) {
    for (int n = 0; n < 4; n++) {
      servo_avant.write(marche_avant[2 * n]);
      servo_arriere.write(marche_avant[(2 * n) + 1]);
      delay(300);
    }
  }

  // on recule (10 cycles):
  for (int i = 0; i < 10; i++) {
    for (int n = 0; n < 4; n++) {
      servo_avant.write(marche_arriere[2 * n]);
      servo_arriere.write(marche_arriere[(2 * n) + 1]);
      delay(300);
    }
  }

}
