#include <kipr/wombat.h>
int rightspeed=400;
int leftspeed=400;
int turn=93;
int up=100;
int down=1000;
int open=100;
int closed=1000;
int arm=1;
int claw=3;
int lightsensor=3;
int botguy=200;
int time=1;

int main()
{
    //wait_for_light(lightsensor);
    //shut_down_in(115000);
    create_connect();
    enable_servos();
    set_servo_position(arm,up);
    set_servo_position(claw,open);
    msleep(10);
    disable_servos();
    hit_botguy(arm);
    right(turn);
    forward(100);
    left(turn);
    pick_up_cube(1);
    right(turn);
    go_to_airlock(1);
    right(turn*2);
    forward(100);
    left(turn);
    forward(1000);
    right(turn);
    pick_up_cube(2);
    right(turn);
    forward(1000);
    go_to_airlock(2);
    create_disconnect();   
    return 0;
    
}

void forward(int distance)
{
    set_create_distance(0);
    while(abs(get_create_distance())<distance)
    {
        create_drive_direct(leftspeed,rightspeed);
        msleep(10);
    }
    create_stop();
}

void right(int turn)
{
  set_create_total_angle(0);
    while(abs(get_create_total_angle())<turn)
    {
        create_drive_direct(leftspeed,-rightspeed);
        msleep(10);
    }
    create_stop();
}
 
void left(int turn)
{
  set_create_total_angle(0);
    while(abs(get_create_total_angle())<turn)
    {
        create_drive_direct(-leftspeed,rightspeed);
        msleep(10);
    }
    create_stop();
}

void hit_botguy (int arm)
{
    forward(380);
    right(turn);
    forward(850);
    left(turn);
    enable_servos();
    set_servo_position(arm,botguy);
    msleep(50);
    disable_servos();
    left(turn);
    right(turn);
 }

void go_to_airlock (int time)
{
    forward(100);
    set_servo_position (claw,open);
    enable_servos();
    msleep(10);
    disable_servos();
    time = time+1;
}

void pick_up_cube (int time)
{
   set_servo_position(arm,down);
   set_servo_position(claw,open);
   enable_servos();
   set_servo_position(claw,open);
   msleep(20);
   set_servo_position(claw,closed);
   right(turn);
   forward(100);
   set_servo_position(arm,down);
   set_servo_position(claw,open);
   enable_servos();
   left(turn);
   set_servo_position(claw,open);
   msleep(20);
   set_servo_position(claw,closed);
   right(turn);
}
    
