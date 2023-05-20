#include <kipr/wombat.h>
#include <kipr/botball.h>
#include <kipr/create.h>
void find_bump(){
    while (get_create_lbump()!=1){
        create_drive_direct (100,100);   
    }
    create_stop();
}
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
    while (get_create_lfcliff_amt()>700){
        printf("value is %d\n", get_create_lfcliff_amt());
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
    create_stop();
   
    
    set_servo_position(1,1900);
    msleep(1000);
    set_servo_position(0,1800);
    msleep(1000);
    set_servo_position(0,100);
    msleep(1000);
    wait_for_light(0);
    // create_connect();
    // enable_servos(); 
    shut_down_in(119);

	//Turning right is negative
	//Turning left is positive
    // start of real stuff here
	
	set_servo_position(1,450);
	msleep(1000);
	
	set_servo_position(0,100);

    // turn 45 degrees 
    set_create_total_angle(0);
    while (get_create_total_angle() >-44)
    {
        create_drive_direct (75, -75);
        printf("1 angle is %d\n", get_create_total_angle());
    }
    create_stop ();


    // go straight
    go_straight(775);    

    // turn 45 degrees
    set_create_total_angle(0);
    while (get_create_total_angle() >-44)
    {
        create_drive_direct (50, -50);
        printf("2 angle is %d\n", get_create_total_angle());
    }
    create_stop ();
    find_black();
    flush();
    go_straight(220);

    set_create_total_angle(0);
    while (get_create_total_angle() >-88)
    {
        create_drive_direct (50, -50);
        printf("3 angle is %d\n", get_create_total_angle());
    }
    create_stop ();
	
	set_servo_position(0,1800);
	msleep(1000);
	
    create_drive_direct(-100, -100);
    msleep(2200);
    create_stop ();
    
	set_servo_position(0,10);
    msleep(2000);
    
    set_servo_position(1,850);
    msleep(2000);
    go_straight(700);

    set_create_total_angle(0);
    while (get_create_total_angle() <90)
    {
        create_drive_direct (-50, 50);
        printf("4 angle is %d\n", get_create_total_angle());
    }
    create_stop();
    
    set_servo_position(1,100);
    msleep(2000);
	set_servo_position(0,1800);
	msleep(2000);
	
	 set_create_total_angle(0);
    while (get_create_total_angle() >-90)
    {
        create_drive_direct (50, -50);
        printf("5 angle is %d\n", get_create_total_angle());
    }
    create_stop();
    
    set_servo_position(1,450);
    msleep(1000);
	
	create_drive_direct(-100,-100);
	msleep(6500);
	
	go_straight(100);
	
	
	set_create_total_angle(0);
    while (get_create_total_angle() >-90)
    {
        create_drive_direct (50, -50);
        printf("6 angle is %d\n", get_create_total_angle());
    }
    create_stop();
	
	create_drive_direct(-100,-100);
	msleep(2500);
	
	set_create_total_angle(0);
    while (get_create_total_angle() <90)
    {
        create_drive_direct (-50, 50);
        printf("7 angle is %d\n", get_create_total_angle());
    }
    create_stop();
	
   
	set_servo_position(0,1800);
	msleep(1000);

	create_drive_direct(-100,-100);
	msleep(1600);
	
	set_servo_position(0,250);
	msleep(2000);
    
    set_servo_position(1,800);
	
	go_straight(100);
	
	set_create_total_angle(0);
    while (get_create_total_angle() >-90)
    {
        create_drive_direct (50, -50);
        printf("8 angle is %d\n", get_create_total_angle());
    }
    create_stop();
	
	go_straight(700);
	
	set_create_total_angle(0);
    while (get_create_total_angle() <90)
    {
        create_drive_direct (-50, 50);
        printf("9 angle is %d\n", get_create_total_angle());
    }
    create_stop();
	
	create_drive_direct(-100,-100);
	msleep(1500);
	
	go_straight(500);
	
	set_create_total_angle(0);
    while (get_create_total_angle() >-180)
    {
        create_drive_direct (50, -50);
        printf("10 angle is %d\n", get_create_total_angle());
    }
    create_stop();
    
    set_servo_position(1,100);
    msleep(2000);
	
	set_servo_position(0,1800);
	msleep(1000);
	
	set_create_total_angle(0);
    while (get_create_total_angle() >-180)
    {
        create_drive_direct (50, -50);
        printf("11 angle is %d\n", get_create_total_angle());
    }
    create_stop();
	
    set_servo_position(1,450);
    msleep(1000);
    
	create_drive_direct(-100,-100);
	msleep(8000);
    
	set_servo_position(0,100);
	msleep(1000);
    
    set_servo_position(1,800);
    msleep(1000);
	
	go_straight(500);
	
	set_create_total_angle(0);
    while (get_create_total_angle() >-180)
    {
        create_drive_direct (50, -50);
        printf("10 angle is %d\n", get_create_total_angle());
    }
    create_stop();
    
    set_servo_position(1,100);
    msleep(2000);
	
	set_servo_position(0,1800);
	msleep(1000);
	
	set_servo_position(1,200);
	msleep(1000);
	
	set_create_total_angle(0);
    while (get_create_total_angle() >-180)
    {
        create_drive_direct (50, -50);
        printf("11 angle is %d\n", get_create_total_angle());
    }
    create_stop();
	
	create_drive_direct(-100,-100);
	msleep(8000);
	
	go_straight(100);
	
	set_create_total_angle(0);
    while (get_create_total_angle() >-90)
    {
        create_drive_direct (50, -50);
        printf("12 angle is %d\n", get_create_total_angle());
    }
    create_stop();
	
	create_drive_direct(100,100);
	msleep(2500);
	
	set_create_total_angle(0);
    while (get_create_total_angle() <90)
    {
        create_drive_direct (-50, 50);
        printf("13 angle is %d\n", get_create_total_angle());
    }
    create_stop();
	
	create_drive_direct(-100,-100);
	msleep(1600);
	
	set_servo_position(0,300);
	msleep(1000);
	
	

    // end of real stuff here
    create_stop ();
    create_disconnect ();
    return 0;
}
