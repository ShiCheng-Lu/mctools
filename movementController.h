#ifndef _MOVEMENT_CONTROLLER_H_
#define _MOVEMENT_CONTROLLER_H_

class MovementController {
    int horizontalAngleInPixels;
    int verticalAngleInPixels;
    int movementTime;  // time to travel one block, walking, in us

    // key will only be detected by minecraft consistently
    // if time_us >= 50
    void holdKey(char key, int time_us);

   public:
    void calibrate();

    // uses degrees
    void changeAngleHorizontal(int angle);
    void changeAngleVertical(int angle);

    void moveForward(float distance);  // measured in blocks
    void moveBack(float distance);
    void strafeLeft(float distance);
    void strafeRight(float distance);

    void jump(); // jump over 1 block after 100 us -> 400 us, peak at 250us
};

#endif
