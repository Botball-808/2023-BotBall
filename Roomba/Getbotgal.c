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
   /* motor(0,-20);
    msleep(3000);
    motor(0,20);
    msleep(3000);
    motor(0,0);
    set_servo_position(0,1800);
    msleep(1000);
    set_servo_position(0,100);
    msleep(1000);*/
    wait_for_light(0);
    // create_connect();
    // enable_servos(); 
    shut_down_in(119);

    // start of real stuff here




    // turn 45 degrees 
    set_create_total_angle(0);
    while (get_create_total_angle() >-44)
    {
        create_drive_direct (75, -75);
        printf("1 angle is %d\n", get_create_total_angle());
    }
    create_stop ();


    // go straight
    go_straight(700);    

    // turn 45 degrees
    set_create_total_angle(0);
    while (get_create_total_angle() >-46)
    {
        create_drive_direct (90, -90);
        printf("2 angle is %d\n", get_create_total_angle());
    }
    create_stop ();
    find_black();
    flush();
    go_straight(220);

    set_create_total_angle(0);
    while (get_create_total_angle() >-90)
    {
        create_drive_direct (100, -100);
        printf("3 angle is %d\n", get_create_total_angle());
    }
    create_stop ();
    create_drive_direct(-100, -100);
    msleep(1700);
    /*motor(0,-20);
    msleep(4750);
    motor(0,0);
    set_servo_position(0,1800);
    msleep(1000);
    create_drive_direct(-100, -100);
    msleep(1200);
	set_servo_position(0,100);
    msleep(1000);*/
    go_straight(700);

    set_create_total_angle(0);
    while (get_create_total_angle() <90)
    {
        create_drive_direct (-50, 50);
        printf("4 angle is %d\n", get_create_total_angle());
    }
    create_stop();
    msleep(2000);

    set_create_total_angle(0);
    while (get_create_total_angle() <90)
    {
        create_drive_direct (-50, 50);
        printf("5 angle is %d\n", get_create_total_angle());
    }
    create_stop();
    msleep(2000);

    set_create_total_angle(0);
    while (get_create_total_angle() >-90)
    {
        create_drive_direct (50, -50);
        printf("6 angle is %d\n", get_create_total_angle());
    }
    msleep(2000);



    // end of real stuff here
    create_stop ();
    create_disconnect ();
    return 0;
}
