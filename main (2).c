#include <kipr/wombat.h>

#include <kipr/wombat.h>
int rightspeed=300;
int leftspeed=300;
int slowSpeedR = 100;
int slowSpeedL = 100;
int turn=150;
int up=700;
int down=400;
int open=1700;
int closed=670;
int arm=0;
int claw=1;
int lightsensor=3;
int startingArm = 650;


int main()
{
    wait_for_light(0);
    shut_down_in(119);
    create_connect();
    enable_servos();
    
    //left(150);
    
    set_servo_position(arm,650);
    set_servo_position(claw, open);
    
    while (get_create_lcliff_amt() > 1500 || get_create_rcliff_amt() > 1500)
    {
        create_drive_direct(200, 200);
    }
   	
    left(90);
    
    backwards(1750);
    
    right(90);
       
    backwards(150);
    
    right(90);
    
    backwards(190);
    
    left(90);
    
    forward(500);
    
    set_servo_position(arm, up);
    set_servo_position(claw, open);
    
    while(get_create_lbump() == 0 && get_create_rbump() == 0)
    {
        create_drive_direct(250, 250);
    }
    
    backwards(150);
    msleep(100);
    set_servo_position(arm, down);
    msleep(100);
    
    set_servo_position(claw, closed);
    
    msleep(300);
    set_servo_position(arm, up);
    backwards(500);
    right(90);
    backwards(400);
    
  	
    
    
     
    create_disconnect();
    
}

void forward(int distance)
{
    set_create_distance(0);
    while(abs(get_create_distance())<distance)
    {
        create_drive_direct(leftspeed, rightspeed);
        msleep(10);
    }
    create_stop();
}


void backwards(int distance)
{
    set_create_distance(0);
    while(abs(get_create_distance())<distance)
    {
        create_drive_direct(-leftspeed,-rightspeed);
        msleep(10);
    }
    create_stop();
}

void crawlForward (int distance)
{
    set_create_distance(0);
    while(abs(get_create_distance())<distance)
    {
        create_drive_direct(slowSpeedL,slowSpeedR);
        msleep(10);
    }
    create_stop();
}

void arcRight(int turn)
{
  set_create_total_angle(0);
    while(abs(get_create_total_angle())<turn)
    {
        create_drive_direct(slowSpeedL, 0);
        msleep(10);
    }
    create_stop();
}
void right (int turn)
{
    set_create_total_angle(0); 
    while(abs(get_create_total_angle())<turn)
    {
        
        create_drive_direct(leftspeed, -rightspeed);
        msleep(10);
    }
        
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