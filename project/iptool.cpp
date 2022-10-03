/************************************************************
 *															*
 * This sample project include three functions:				*
 * 1. Add intensity for gray-level image.					*
 *    Input: source image, output image name, value			*
 *															*
 * 2. Image thresholding: pixels will become black if the	*
 *    intensity is below the threshold, and white if above	*
 *    or equal the threshold.								*
 *    Input: source image, output image name, threshold		*
 *															*
 * 3. Image scaling: reduction/expansion of 2 for 			*
 *    the width and length. This project uses averaging 	*
 *    technique for reduction and pixel replication			*
 *    technique for expansion.								*
 *    Input: source image, output image name, scale factor	*
 *															*
 ************************************************************/

#include "../iptools/core.h"
#include <strings.h>
#include <string.h>

using namespace std;

#define MAXLEN 256

int main(int argc, char **argv) {
    image src, tgt, histogram;
    FILE *fp;
    char str[MAXLEN];
    char infile[MAXLEN], outfile[MAXLEN];
    char *pch;
    int numROI, ROIcount;
    int pixelX[3], pixelY[3], sX[3], sY[3], p1[3], p2[3], p3[3];
    bool called[9] = {false};
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open file: %s\n", argv[1]);
        exit(1);
    }

    while (fgets(str, MAXLEN, fp) != NULL) {
        pch = strtok(str, " ");
        src.read(pch);
        strcpy(infile, pch);
        cout << "Input file: " << infile << endl;
        cout << "Resolution: " << src.getNumberOfRows() << "x" << src.getNumberOfColumns() << endl;
        pch = strtok(NULL, " ");
        strcpy(outfile, pch);
        cout << "Output file: " << outfile << endl;
        numROI = atoi(strtok(NULL, " "));
        cout << "Processing " << numROI << " ROI(s) total." << endl;
        int ROIremaining = numROI;
        ROIcount = 0;
        while (ROIremaining > 0) {
            pixelX[ROIcount] = atoi(strtok(NULL, " "));
            pixelY[ROIcount] = atoi(strtok(NULL, " "));
            sX[ROIcount] = atoi(strtok(NULL, " "));
            sY[ROIcount] = atoi(strtok(NULL, " "));
            pch = strtok(NULL, " ");
            if (strncasecmp(pch, "histostretch", MAXLEN) == 0) {
                p1[ROIcount] = atoi(strtok(NULL, " "));
                p2[ROIcount] = atoi(strtok(NULL, " "));
                if (!called[0]) called[0] = true;
            } else if (strncasecmp(pch, "althistostretch", MAXLEN) == 0) {
                p1[ROIcount] = atoi(strtok(NULL, " "));
                p2[ROIcount] = atoi(strtok(NULL, " "));
                if (!called[1]) called[1] = true;
            } else if (strncasecmp(pch, "histothres", MAXLEN) == 0) {
                p1[ROIcount] = atoi(strtok(NULL, " "));
                p2[ROIcount] = atoi(strtok(NULL, " "));
                p3[ROIcount] = atoi(strtok(NULL, " "));
                if (!called[2]) called[2] = true;
            } else if (strncasecmp(pch, "percchastrech", MAXLEN) == 0) {
                p1[ROIcount] = atoi(strtok(NULL, " "));
                p2[ROIcount] = atoi(strtok(NULL, " "));
                p3[ROIcount] = atoi(strtok(NULL, " "));
                if (!called[3]) called[3] = true;
            } else if (strncasecmp(pch, "rgbstretch", MAXLEN) == 0) {
                p1[ROIcount] = atof(strtok(NULL, " "));
                p2[ROIcount] = atof(strtok(NULL, " "));
                if (!called[4]) called[4] = true;
            } else if (strncasecmp(pch, "istretch", MAXLEN) == 0) {
                p1[ROIcount] = atof(strtok(NULL, " "));
                p2[ROIcount] = atof(strtok(NULL, " "));
                if (!called[5]) called[5] = true;
            } else if (strncasecmp(pch, "hstretch", MAXLEN) == 0) {
                p1[ROIcount] = atof(strtok(NULL, " "));
                p2[ROIcount] = atof(strtok(NULL, " "));
                if (!called[6]) called[6] = true;
            } else if (strncasecmp(pch, "sstretch", MAXLEN) == 0) {
                p1[ROIcount] = atof(strtok(NULL, " "));
                p2[ROIcount] = atof(strtok(NULL, " "));
                if (!called[7]) called[7] = true;
            } else if (strncasecmp(pch, "fullhsistretch", MAXLEN) == 0) {
                p1[ROIcount] = atof(strtok(NULL, " "));
                p2[ROIcount] = atof(strtok(NULL, " "));
                if (!called[8]) called[8] = true;
            } else {
                printf("No function: %s\n", pch);
                continue;
            }
            --ROIremaining;
            ++ROIcount;
        }

        if (called[0]) {
            utility::histostretch(src, tgt, numROI, pixelX, pixelY, sX, sY, p1, p2);
            called[0] = 0;
        }
        if (called[1]) {
            utility::althistostretch(src, tgt, numROI, pixelX, pixelY, sX, sY, p1, p2);
            called[1] = 0;
        }
        if (called[2]) {
            utility::histothres(src, tgt, numROI, pixelX, pixelY, sX, sY, p1, p2, p3);
            called[2] = 0;
        }
        if (called[3]) {
            utility::percchastrech(src, tgt, numROI, pixelX, pixelY, sX, sY, p1, p2, p3);
            called[3] = 0;
        }
        if (called[4]) {
            utility::rgbstretch(src, tgt, numROI, pixelX, pixelY, sX, sY, p1, p2);
            called[4] = 0;
        }
        if (called[5]) {
            utility::istretch(src, tgt, numROI, pixelX, pixelY, sX, sY, p1, p2);
            called[5] = 0;
        }
        if (called[6]) {
            utility::hstretch(src, tgt, numROI, pixelX, pixelY, sX, sY, p1, p2);
            called[6] = 0;
        }
        if (called[7]) {
            utility::sstretch(src, tgt, numROI, pixelX, pixelY, sX, sY, p1, p2);
            called[7] = 0;
        }
        if (called[8]) {
            utility::fullhsistretch(src, tgt, numROI, pixelX, pixelY, sX, sY, p1, p2);
            called[8] = 0;
        }
        tgt.save(outfile);
    }
    fclose(fp);
    return 0;
}