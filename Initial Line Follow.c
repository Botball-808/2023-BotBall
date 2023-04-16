#include <stdio.h>
#include <stdbool.h>
#include <kipr/create.h>
#include <kipr/wombat.h>
#include <stdlib.h>

const float circ = 175.9;
const float distance_traveled_in_tick = 0.17584;

void follow_till_distance(int mm, bool leftsideofline){
    int ticks = mm/distance_traveled_in_tick;    
    int leftmotor = 0;
    int rightmotor= 1;
    
    if (leftsideofline == false)
    {
        leftmotor = 1;
        rightmotor = 0;
    }
    cmpc(0);
    int speed = 50;
    while (gmpc(0) < ticks){
        int actual = get_create_rfcliff_amt();
        int di = 0.5;
        int error = (actual - 1600)*di;
        if (actual > 1600)
        { 
            ao();
            motor(leftmotor, speed+error);
            motor(rightmotor, speed-error);
        }
                  else{
                      ao();
                      motor(rightmotor, speed+error);
                      motor(leftmotor, speed-error);
                 }
        ao();
}
}
void go_forward(int mm){
    int ticks = mm/distance_traveled_in_tick;
    cmpc(0);
    while (gmpc(0) < ticks){
        motor(0,100);
        motor(1,100);
    }
}
int main ()
{
        create_connect();
        int black = 600;
        int white =2500;
        double target =(black+white)/2;
        int speed = 200;
        
        while(get_create_rbump() == 0)
        {
            int actual = get_create_rfcliff_amt();
            printf("sensor value=%d\n", actual);
            double deviation = (abs(actual-target))/target * 0.5;
            printf("deviation=%f\n", deviation);
            int increase_to_speed = speed * (1+deviation);            
            //int error = ((actual/target))*(speed);
        
            if ( actual < target) // black
                create_drive_direct(speed,increase_to_speed);
                //create_drive_direct(reduce_to_speed,increase_to_speed);
            else //white
                create_drive_direct(increase_to_speed, speed);
                //create_drive_direct(increase_to_speed, reduce_to_speed);
        /*
        if ( actual < target ) // black
            create_drive_direct(speed,error*2.5);
        else //white
            create_drive_direct(error, speed);
        */
    }
     create_stop();
     create_disconnect();
  //int travel = 300/distance_traveled_in_tick;  
    return 0;
}