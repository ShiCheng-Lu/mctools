#include "moveCtrl.h"

void MoveCtrl::moveForward(int blocks);
void MoveCtrl::moveBackward(int blocks);

// strafe a number of blocks
void MoveCtrl::strafeLeft(int blocks);
void MoveCtrl::strafeRight(int blocks);

void beginSprint();

void endSprint();

void jump();