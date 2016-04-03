//
// Created by SJ Holland on 4/3/16.
//

#ifndef SDTTEST_LEVEL_H
#define SDTTEST_LEVEL_H


class Level {

public:

    Level(int w, int h): width(w), height(h) {};

    int getHeight();
    int getWidth();

private:
    int height;
    int width;
};


#endif //SDTTEST_LEVEL_H
