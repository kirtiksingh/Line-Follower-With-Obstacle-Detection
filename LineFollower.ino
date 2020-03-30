int left1 = 2, right1 = 7, enable_left = 6; // left1, left2 and enable_left decide the polarity and speed (through PWM) of the left motor;
int left2 = 4, right2 = 8, enable_right = 5; // right1, right2 and enable_right decide the polarity and speed (through PWM) of the right motor;

float direction = 1;     // Direction of movement of the bot: +1 for forward and 0 for backward motion.

int IR_left_pin =10;  // pin connections for left and right IR sensors
int IR_right_pin = 12;
int IR_front_pin = 9;// Output of the left IR sensor goes to pin number 3 and that of the right IR sensor goes to pin 12

int IR_left = 0;
int IR_right = 0;
int IR_front = 0;

void setup() {

 pinMode(left1, OUTPUT);         // modes for the pins connected to the two dc motors.
 pinMode(left2, OUTPUT);
 pinMode(right1, OUTPUT);
 pinMode(right2, OUTPUT);
 pinMode(enable_left, OUTPUT);
 pinMode(enable_right, OUTPUT);
 pinMode(IR_left_pin, INPUT);
 pinMode(IR_right_pin, INPUT);
 pinMode(IR_front_pin, INPUT);

 Serial.begin(9600);

}

void loop()
{
 IR_left = digitalRead(IR_left_pin);     // Reading the output givin by the IR sensors
 IR_right = digitalRead(IR_right_pin);
 IR_front = digitalRead(IR_front_pin);
 
 if (IR_left==0 && IR_right==0 && IR_front == 0)
 {
    halt();  
 }
 
 if (IR_left==1 && IR_right==1 && IR_front == 0)
 {
   forward(135,125);
 }

 if (IR_left==1 && IR_right==0 && IR_front == 0)
 {
   forward(125,0);
 }

 if (IR_left==0 && IR_right==1 && IR_front == 0)
 {
   forward(0,125);
 }
if (digitalRead(IR_front_pin) == 1 )
{
 Serial.println(IR_front);
 forward(120,0);
 delay(900);
 forward(140,130);
 delay(600);
 forward(0,120);
 delay(900);
  forward(105,100);
 delay(500);
 
 
 do{
  
   IR_left = digitalRead(IR_left_pin);     // Reading the output givin by the IR sensors
   IR_right = digitalRead(IR_right_pin);
   forward(70,100);
 } while(IR_left!=0 && IR_right!=0);
 do
 {
  IR_left = digitalRead(IR_left_pin);     // Reading the output givin by the IR sensors
   IR_right = digitalRead(IR_right_pin);
  forward(90,0);
 } while(IR_left!=0);
}
 
}

void forward(int speed_left, int speed_right)  // Moves the bot forward. Takes PWM values (0-255) of left and right motor as input.
{
 analogWrite(enable_left, speed_left);
 analogWrite(enable_right, speed_right);
 digitalWrite(left1, HIGH);
 digitalWrite(left2, LOW);
 digitalWrite(right1, HIGH);
 digitalWrite(right2, LOW); // Forward
}


void halt()
{
 analogWrite(enable_left, 0);
 analogWrite(enable_right, 0);
 digitalWrite(left1, LOW);
 digitalWrite(left2, LOW);
 digitalWrite(right1, LOW);
 digitalWrite(right2, LOW); //Stop

}
