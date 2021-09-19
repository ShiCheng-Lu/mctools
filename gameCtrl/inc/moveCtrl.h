#ifndef _MOVE_CTRL_H_
#define _MOVE_CTRL_H_

namespace MoveCtrl {

// move a number of blocks
void moveForward(int blocks);
void moveBackward(int blocks);

// strafe a number of blocks
void strafeLeft(int blocks);
void strafeRight(int blocks);

void beginSprint();

void endSprint();

void jump();

}  // namespace MoveCtrl

#endif
