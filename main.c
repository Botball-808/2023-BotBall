#include <kipr/wombat.h>

int main() 
{ 
    enable_servos();
    set_servo_position(0,0);
    msleep(2000);
    ao();
    set_servo_position(0,2000);
    msleep(2000);
    ao();
    set_servo_position(0,300);
    msleep(2000);
    ao();
    disable_servos();
    return 0;
}