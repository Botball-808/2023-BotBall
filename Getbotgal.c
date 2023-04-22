#include <kipr/wombat.h>
#include <kipr/botball.h>
#include <kipr/create.h>

create_drive_connect();
create_drive_disconnect();

create_drive_connect();
enable_servos();

create_drive(100, 100);
msleep(1000);
create_drive(-100, -100)
mav(0, 100);
mav(0, -100);

wait_for_light(0);

const int speed = 400;
void go_straight (int mm)
{
    // go straight
    set_create_distance(0);
    while (get_create_distance() <mm)
    {
        create_drive_direct (speed,speed);
    }
    create_stop();
}


int main()
{
    create_connect();
    enable_servos(); 
    
    
    // start of real stuff here
	 // turn 45 degrees
    set_create_total_angle(0);
    while (get_create_total_angle() >-45)
    {
		create_drive_direct (speed, -speed);
        printf("angle is %d\n", get_create_total_angle());
    }
    create_stop ();
   
    
    // go straight
	go_straight(800);    
    
    // turn 45 degrees
    set_create_total_angle(0);
    while (get_create_total_angle() >-45)
    {
		create_drive_direct (speed, -speed);
        printf("angle is %d\n", get_create_total_angle());
    }
    create_stop ();
    
    
	// end of real stuff here
create_stop ();
create_disconnect ();
return 0;
}
    
