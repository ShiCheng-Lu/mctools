#ifndef _MENU_CTRL_H_
#define _MENU_CTRL_H_

namespace MenuCtrl {

void selectInv(int x, int y);

void initialize(int ui_scale);

void changeOffset(float offset_x, float offset_y);

// drop the selected item
void dropItem(bool all = true);
// take the selected item
void takeItem(bool quick = true);

bool invOpen();

}  // namespace MenuCtrl

#endif
