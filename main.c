#include <kipr/wombat.h>
int rightspeed=200;
int leftspeed=200;
int turn=93;
int up=1000;
int down=460;
int open=1400;
int closed=700;
int arm=0;
int claw=1;
int lightsensor=3;
int botguy=200;

int main()
{
    //wait_for_light(lightsensor);
    //shut_down_in(115000);
    create_connect();
    enable_servos();
    set_servo_position(arm,down);
    set_servo_position(claw,open);
    msleep(450);
    backward(900);
    turn(right);
    backward(50);
    turn(right);
    backward(400);
    forward(100);
    // Exit Starting box and Grab Blocks
    forward(700);
    right(90);
    forward(400);
   	set_servo_position(claw, closed);
    
    msleep(10);
    disable_servos();
    
    
  	//pick_up_botguy(arm);
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

/*void pick_up_botguy(int arm)
{
	forward(380);
    right(turn);
    forward(850);
    left(turn);
    enable_servos();
    set_servo_position(arm,botguy);
    msleep(50);
    set_servo_position(claw,closed);
    msleep(100);
    set_servo_position(arm,up);
    msleep(10);
    disable_servos();
 }*/

void backward(int dist)
{
    set_create_distance(0);
    while(abs(get_create_distance())<dist)
    {
        create_drive_direct(-leftspeed,-rightspeed);
        msleep(10);
    }
    create_stop();
}

    

    
    
    
