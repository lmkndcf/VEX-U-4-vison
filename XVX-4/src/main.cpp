/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       z                                                         */
/*    Created:      2023/10/19 23:51:41                                       */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
vex::vision::signature GREEN_CUBE;
vex::vision::signature  Green(1,-6371, -5205, -5788, -3855, -2855, -3354, 3.0, 0);  //绿色
vex::vision::signature  Green1(2,-6371, -5205, -5788, -3855, -2855, -3354, 6, 0);
vex::motor     left_motor1(18);
vex::motor     left_motor2(19);
vex::motor     right_motor1(16,true);
vex::motor     right_motor2(17,true);
vex::vision     vision1(7);

int x,y,h,w;//中心坐标；高度和宽度
int speed_add=10;
int main() 
{
    
    vision1.setSignature(Green1);
  vision1.setBrightness(100);

while(1)
{
int speed_stright=0;

      vision1.takeSnapshot(Green1);
      x=abs(vision1.largestObject.centerX);
      y=abs(vision1.largestObject.centerY);
      w=abs(vision1.largestObject.width);
      h=abs(vision1.largestObject.height);
      Brain.Screen.clearScreen();
   Brain.Screen.setCursor(1,1);
   Brain.Screen.print(x);
   Brain.Screen.setCursor(2,1);
   Brain.Screen.print(y);
   Brain.Screen.setCursor(3,1);
   Brain.Screen.print(w);
   Brain.Screen.setCursor(4,1);
   Brain.Screen.print(h);
   
 
   
    if(w>20&&w<150)
   {
      speed_stright=(150-w)*0.3;
     speed_stright=speed_stright>50?50:speed_stright;
         if(x>200)
   {
       right_motor1.spin(fwd,speed_add+speed_stright,pct);
       right_motor2.spin(fwd,speed_add+speed_stright,pct);
     left_motor1.spin(fwd,speed_stright,pct);
     left_motor2.spin(fwd,speed_stright,pct);
   }
   else if(x<140)
   {
    
   left_motor1.spin(fwd,speed_add+speed_stright,pct);
   left_motor2.spin(fwd,speed_add+speed_stright,pct);
     right_motor1.spin(fwd,speed_stright,pct);
     right_motor2.spin(fwd,speed_stright,pct);
   }
   else{
     right_motor1.spin(fwd,speed_stright,pct);
     right_motor2.spin(fwd,speed_stright,pct);
     left_motor1.spin(fwd,speed_stright,pct);
     left_motor2.spin(fwd,speed_stright,pct);
   }
   }
   else if(w>180)
   {
    right_motor1.spin(fwd,-10,pct);
     right_motor2.spin(fwd,-10,pct);
     left_motor1.spin(fwd,-10,pct);
     left_motor2.spin(fwd,-10,pct);
   }
   else{
    right_motor1.stop();
    right_motor2.stop();
    left_motor1.stop();
    left_motor2.stop();
   }
   this_thread::sleep_for(200);
}

}
