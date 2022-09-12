const int up = 7;
const int down = 6; //
const int forwards = 4;
const int backwards = 3;//assign relay INx pin to arduino pin
 int IRSensor = 2,statusSensor2;
 int IRSensor2=10,statusSensor;
 int IRSensor3=9,statusSensor3;
const int trigger = 8;
const int echo = 9;
long T;
float distanceCM;


void setup() {
pinMode(up, OUTPUT);//set relay as an output
pinMode(down, OUTPUT);//set relay as an output
pinMode(forwards, OUTPUT);//set relay as an output
pinMode(backwards, OUTPUT);//set relay as an output
pinMode (IRSensor, INPUT);
pinMode (IRSensor2, INPUT);

  Serial.begin(115200);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}
void loop() {
  if(irs_3()==1)
  {
 //dummyup();
//dummydown();
 //delay(10000);
  //ultrasonic();
    if(irs_1()==0)
  {
    UG_1();
    delay(1000);
   }
   else if(irs_2()==0)
    {
      UG_2();
      delay(1000);
    }
    else
    {
      Serial.println("parking lot is full\n");
      }
  }
//exit(0);
}
 // implement ultra sonic functions in UG functions
void UG_2()
{ 
motor1_for2slot();  //vertical down implement ultrasonic here
 delay(1000);
 
 motor2_rev();  //horizontal forward
 delay(1000);
verticaldownP();  //vertical down
 delay(1000);
 
  motor2_for(); // horizontal backward
 delay(1000);
 
 motor1_rev2slot();  //vertical Up
 delay(1000);

}

void UG_1()
{
 motor1_for(); 
 delay(1000);//vertical down implemant ultrasonic functions here
  motor2_rev();  //horizontal forward
 delay(1000);
 verticaldownP();
 delay(1000);
 motor2_for(); // horizontal backward
 delay(1000);
  motor1_rev();  //vertical Up
 delay(1000);
}

void motor1_for()
{
  
 digitalWrite(up, LOW);
 digitalWrite(down, HIGH);//Activate the relay one direction, they must be different to move the motor
 delay(14000); // wait 2 seconds
 digitalWrite(up, HIGH);
 digitalWrite(down, HIGH);//Deactivate both relays to brake the motor
 delay(1000);// wait 2 seconds
}

void motor1_rev()
{
 digitalWrite(up, HIGH);
 digitalWrite(down, LOW);//Activate the relay the other direction, they must be different to move the motor
 delay(15000);// wait 2 seconds
 digitalWrite(up, HIGH);
 digitalWrite(down, HIGH);//Deactivate both relays to brake the motor
 delay(1000);// wait 2 seconds
} 
  
void motor2_for()
{
 digitalWrite(forwards, LOW);
 digitalWrite(backwards, HIGH);//Activate the relay one direction, they must be different to move the motor
 delay(200); // wait 2 seconds
 digitalWrite(forwards, HIGH);
 digitalWrite(backwards, HIGH);//Deactivate both relays to brake the motor
 delay(200);// wait 2 seconds
 }
 void motor2_rev()
 {
  digitalWrite(forwards, HIGH);
 digitalWrite(backwards, LOW);//Activate the relay the other direction, they must be different to move the motor
 delay(200);// wait 2 seconds
 digitalWrite(forwards, HIGH);
 digitalWrite(backwards, HIGH);//Deactivate both relays to brake the motor
 delay(200);// wait 2 seconds
  }
void ultrasonic()
{
  digitalWrite(trigger, LOW);
  delay(1);
  digitalWrite(trigger, HIGH);//In order to generate the ultrasound we need to set the Trigger Pin on a High State for 10 µs. That will send out an 8 cycle sonic burst which will travel at the speed sound and it will be received in the Echo Pin. The Echo Pin will output the time in microseconds the sound wave traveled.
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  T = pulseIn(echo, HIGH);
  distanceCM = T * 0.034;
  distanceCM = distanceCM / 2;
  Serial.print("Distance in cm: ");
  Serial.println(distanceCM);
  delay(1000);
}
int irs_1()
{
   statusSensor = digitalRead (IRSensor);
    if (statusSensor == 1)
  {
    Serial.print("irs1 non-empty slot\n"); // no obstacle detected
    return 1;
  }
    else
  {
    Serial.print("irs1 empty slot\n"); // no obstacle detected
    return 0;
  }
    }
int irs_2()
{
  statusSensor2 = digitalRead (IRSensor2);
    if (statusSensor2 == 1)
  {
    Serial.print("irs2 non-empty slot\n"); // no obstacle detected
    return 1;
  }
    else
  {
    Serial.print("irs2 empty slot\n"); // no obstacle detected
    return 0;
  }
    }
    int irs_3()
{
  statusSensor3 = digitalRead (IRSensor3);
    if (statusSensor3 == 1)
  {
    Serial.print("vechicle is detected\n"); //  obstacle detected
    return 1;
  }
    else
  {
    Serial.print("vechicle is not detected\n"); // no obstacle detected
    return 0;
  }
    }
void verticaldownP()
{
digitalWrite(up, LOW);
 digitalWrite(down, HIGH);//Activate the relay one direction, they must be different to move the motor
 delay(1000); // wait 2 seconds
 digitalWrite(up, HIGH);
 digitalWrite(down, HIGH);//Deactivate both relays to brake the motor
 delay(1000);// wait 2 seconds
}
void motor1_for2slot()
{
  
 digitalWrite(up, LOW);
 digitalWrite(down, HIGH);//Activate the relay one direction, they must be different to move the motor
 delay(29000); // wait 2 seconds
 digitalWrite(up, HIGH);
 digitalWrite(down, HIGH);//Deactivate both relays to brake the motor
 delay(1000);// wait 2 seconds
}
void motor1_rev2slot()
{
 digitalWrite(up, HIGH);
 digitalWrite(down, LOW);//Activate the relay the other direction, they must be different to move the motor
 delay(30000);// wait 2 seconds
 digitalWrite(up, HIGH);
 digitalWrite(down, HIGH);//Deactivate both relays to brake the motor
 delay(1000);// wait 2 seconds
} 
  

    
    void dummyup()
    {
      digitalWrite(up, HIGH);
 digitalWrite(down, LOW);//Activate the relay the other direction, they must be different to move the motor
 delay(50000);// wait 2 seconds
 digitalWrite(up, HIGH);
 digitalWrite(down, HIGH);//Deactivate both relays to brake the motor
 delay(20000);// wait 2 seconds
          
      }
      void dummydown()
      {
    digitalWrite(up, LOW);
 digitalWrite(down, HIGH);//Activate the relay one direction, they must be different to move the motor
 delay(50000); // wait 2 seconds
 digitalWrite(up, HIGH);
 digitalWrite(down, HIGH);//Deactivate both relays to brake the motor
 delay(1000);// wait 2 seconds     
        }
  
