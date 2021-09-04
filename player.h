#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <set>
#include <string>
#include <utility>
#include <vector>

struct Coord {
    int x, y, z;
};

struct Item {
    std::string name;
    int amout;
    std::pair<int, int> slot;
};

class Player {
    Coord location;
    std::vector<std::vector<Item>> inventory;

    int heightMovement;
    

    void Calibrate();

   public:
    Player(Coord coord);
    ~Player();

    void lookUp();

    void lookDown();

    void moveTo(Coord coord);

    void lookAngle(float angle);

    void jump();
};

#endif
