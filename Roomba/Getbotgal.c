#include <kipr/wombat.h>
#include <kipr/botball.h>
#include <kipr/create.h>
void flush(){
  int threshold = 1900; int speed = 250;
while ( (get_create_lfcliff_amt() < threshold) ||
(get_create_rfcliff_amt() < threshold) )
{
if ( (get_create_lfcliff_amt() < threshold) &&
(get_create_rfcliff_amt() >= threshold) )
{
create_drive_direct(0.75*speed, -0.1*speed);
}
else if ( (get_create_lfcliff_amt() >= threshold) &&
(get_create_rfcliff_amt() < threshold) )
{
create_drive_direct(-0.1*speed, 0.75*speed);
}
else
{
create_drive_direct(speed,speed);
}
}
create_stop();  
    
}
void find_black(){
 while (get_create_lfcliff_amt()>600){
  create_drive_direct (100,100);   
 }
    create_stop();
}
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

create_drive_direct(100, 100);
msleep(1000);
create_drive_direct(-100, -100);
msleep(1000);
create_stop();

wait_for_light(0);
   // create_connect();
   // enable_servos(); 
    
    
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
    find_black();
    flush();
    
    
	// end of real stuff here
create_stop ();
create_disconnect ();
return 0;
}
