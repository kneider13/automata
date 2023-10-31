//                      ##                                  ##
//                      ##                                  ##
//   ####    ##  ##    #####    ####    ##  ##    ####     #####    ####
//      ##   ##  ##     ##     ##  ##   #######      ##     ##         ##
//   #####   ##  ##     ##     ##  ##   ## # ##   #####     ##      #####
//  ##  ##   ##  ##     ## ##  ##  ##   ##   ##  ##  ##     ## ##  ##  ##
//   #####    ######     ###    ####    ##   ##   #####      ###    #####

// Motor izquierdo
const int IN1 = 13; 
const int IN2 = 12; 

// Motor derecho
const int IN3 = 11;
const int IN4 = 10;

int left_sensor;
int right_sensor;
const int left_sensor_PIN = A1;
const int right_sensor_PIN = A0;

void setup() {
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode(left_sensor_PIN, INPUT);
  pinMode(right_sensor_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {

  sensor_reading_IR();

  if (left_sensor == 0 && right_sensor == 0) {
    stop_robot();
    delay(1000);
    reverse_robot();
    delay(1000);
  }
  if (left_sensor == 0 && right_sensor == 1) {
    robot_right(); 
  }
  if (left_sensor == 1 && right_sensor == 0) {
   robot_left();
  }
  if (left_sensor == 1 && right_sensor == 1) {
    forward_robot();
  }

}

void sensor_reading_IR()
{
  left_sensor = digitalRead(left_sensor_PIN); // Almacena la lectura del sensor izquierdo
  right_sensor = digitalRead(right_sensor_PIN); // Almacena la lectura del sensor derecho
 
  Serial.println("El valor del sensor izquierdo es: ");
  Serial.println(left_sensor);

  Serial.println("El valor del sensor derecho es: ");
  Serial.println(right_sensor);
 
}

void forward_robot() {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);

  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void reverse_robot() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
 
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void robot_right() {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
 
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void robot_left () {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
 
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void stop_robot() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);

  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
}
