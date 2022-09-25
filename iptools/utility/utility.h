#ifndef UTILITY_H
#define UTILITY_H

#include "../image/image.h"
#include <sstream>
#include <math.h>

class utility {
public:
    utility();

    virtual ~utility();

    static std::string intToString(int number);

    static int checkValue(int value);

    static bool isInBounds(int x, int y, image &src);

    static void histostretch(image &src, image &tgt, int numROI, int *pixelX, int *pixelY, int *sX, int *sY, int *c, int *d);

    static void althistostretch(image &src, image &tgt, int numROI, int *pixelX, int *pixelY, int *sX, int *sY,
                         int *threshold);

    static void histothres(image &src, image &tgt, int numROI, int *pixelX, int *pixelY, int *sX, int *sY, int *t, int *c, int *d);

    static void percchastretch(image &src, image &tgt, int numROI, int pixelX[3], int pixelY[3], int sX[3],
                            int sY[3], int ws[3], int threshold[3]);

    static void rgbstretch(image &src, image &tgt, int numROI, int pixelX[3], int pixelY[3], int sX[3], int sY[3],
                           float redScale[3], float greenScale[3], float blueScale[3]);

    static void istretch(image &src, image &tgt, int numROI, int *pixelX, int *pixelY, int *sX, int *sY, int *value);

    static void hstretch(image &src, image &tgt, int numROI, int *pixelX, int *pixelY, int *sX, int *sY, int *value);

    static void sstretch(image &src, image &tgt, int numROI, int *pixelX, int *pixelY, int *sX, int *sY, int *value);

    static void fullhsistretch(image &src, image &tgt, int numROI, int *pixelX, int *pixelY, int *sX, int *sY, int *value);
};

#endif