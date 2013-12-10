// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo vBall;  // create servo object to control a servo 
Servo vPlayer;

Servo frisbee;
Servo frisbeePlayers;

Servo shark;
Servo surfer;

Servo wave;
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 

int vplayers_low = 100;
int vplayers_high = 120;
int vplayers_dir = 1;
float vplayers_pos = vplayers_low;
float vplayers_speed = .1;

int vball_low = 70;
int vball_high = 120;
int vball_dir = 1;
int vball_pos = vball_low;

int fplayers_low = 95;
int fplayers_high = 110;
int fplayers_dir = -1;
int fplayers_pos = 103;

int frisbee_low = 70;
int frisbee_high = 128;
int frisbee_dir = 1;
int frisbee_pos = 100;

int t_frisbee_pos;

int shark_low = 90;
int shark_high = 135;
int shark_dir = 0;
int shark_pos = shark_high;
int shark_real_dir = -1;

int surfer_low = 100;
int surfer_high = 135;
float surfer_dir = 1;
float surfer_pos = surfer_low;
int surfer_on = 1;

int wave_low = 90;
int wave_high = 90;
int wave_dir = 1;
int wave_pos = wave_low;

//int range = players_high - players_low;
int speed = 40;
int shark_count = 0;

void setup() 
{ 
  
  vPlayer.attach(9);  // attaches the servo on pin 9 to the servo object 
  vBall.attach(10);
  
  frisbee.attach(3);  // attaches the servo on pin 9 to the servo object 
  frisbeePlayers.attach(5);
  
  shark.attach(6);  // attaches the servo on pin 9 to the servo object 
  surfer.attach(11);
  
  
  wave.attach(12);
} 
 

int set_direction(int _pos, int _high, int _low, int _dir)
{
  if (_pos >= _high || _pos <= _low) {
   _dir = _dir * -1; 
  }
  
  return _dir;
}

void loop() 
{ 
  
  vball_pos += vball_dir;
  vball_dir = set_direction(vball_pos, vball_high, vball_low, vball_dir);
  
  //vplayers_pos += vplayers_dir; // map(vball_pos, vball_high, vball_low, vplayers_high, vplayers_low);
  vplayers_pos = map(vball_pos, vball_low, vball_high, vplayers_high, vplayers_low);
  vplayers_dir = set_direction(vplayers_pos, vplayers_high, vplayers_low, vplayers_dir);

  t_frisbee_pos = frisbee_pos + frisbee_dir*3;
  if ( t_frisbee_pos <= 77 ||  t_frisbee_pos >= 121) {
  fplayers_pos += fplayers_dir;
  fplayers_dir = set_direction(fplayers_pos, fplayers_high, fplayers_low, fplayers_dir);
  }
  
  frisbee_pos += frisbee_dir;
  frisbee_dir = set_direction(frisbee_pos, frisbee_high, frisbee_low, frisbee_dir);

  shark_pos += shark_dir;
  shark_dir = set_direction(shark_pos,shark_high, shark_low, shark_dir);
  
  if (surfer_on > 0) {
  surfer_pos += surfer_dir;
  surfer_dir = set_direction(surfer_pos, surfer_high, surfer_low, surfer_dir);
  }
  surfer_on *= -1;
  
  wave_pos += wave_dir*4;
  wave_dir = set_direction(wave_pos, wave_high, wave_low, wave_dir);
  
  if (shark_dir == 0) {
    shark_count += 1;

    if (shark_count > 150) {
      shark_dir = shark_real_dir;
      shark_real_dir *= -1;
      shark_count = 0;
    }
  } else {
    if (shark_pos == shark_high || shark_pos == shark_low) { shark_dir = 0;} 
  }
  
  /*
  for(pos = 0; pos < 50; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servoVPlayer.write(pos+players_low);              // tell servo to go to position in variable 'pos' 
    servoVBall.write(pos+ball_low);
    
    frisbee.write(pos+ball_low);
    frisbeePlayers.write(pos+ball_low);
  
    shark.write(pos+ball_low);
    surfer.write(pos+ball_low);
  
    delay(speed);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 50; pos >= 0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servoVolleyBall.write(pos+players_low);              // tell servo to go to position in variable 'pos' 
    servoBall.write(pos+ball_low);
 
    frisbee.write(pos+ball_low);
    frisbeePlayers.write(pos+ball_low);
  
    shark.write(pos+ball_low);
    surfer.write(pos+ball_low);
    
    delay(speed);                       // waits 15ms for the servo to reach the position 
  }

  */

  
  vPlayer.write(vplayers_pos);              // tell servo to go to position in variable 'pos'   
  vBall.write(vball_pos);
  
  frisbee.write(frisbee_pos);
  frisbeePlayers.write(fplayers_pos);
  
  shark.write(shark_pos);
  surfer.write(surfer_pos);
  wave.write(wave_pos);  
  
  delay(speed);

} 
