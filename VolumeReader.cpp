/*********************************************************************
 * Copyright © 2014,
 * Marwan Abdellah: <abdellah.marwan@gmail.com>
 *
 * If you will use this software, kindly ask for permissions.
 ********************************************************************/

#include "Volume.h"
#include "MACROS.h"

#include <fstream>
#include <stdlib.h>

void Volume::ReadHeaderFile(char *prefix,
                            int &volumeWidth,
                            int &volumeHeight,
                            int &volumeDepth)
{
    char hdrFile[300];
    std::ifstream inputFileStream;

    // Adding the ".hdr" prefix to the dataset path
    sprintf(hdrFile, "%s.hdr", prefix);

    INFO("Dataset HDR hdrFile");

    // Open the eader hdrFile to read the dataset dimensions
    inputFileStream.open(hdrFile, std::ios::in);

    // Checking the openning of the file
    if (inputFileStream.fail())
    {
        INFO("Could not open the HDR file");
        INFO("Exiting");
        exit(0);
    }

    // Reading the dimensions
    inputFileStream >> volumeWidth;
    inputFileStream >> volumeHeight;
    inputFileStream >> volumeDepth;

    // Closing the ".hdr" file
    inputFileStream.close();

    INFO("HDR file has been read SUCCESSFULLY");
}

char* Volume::ReadRawFile(char *prefix, int& iWidth, int& iHeight, int& iDepth)
{
    char imgFile[100];
    std::ifstream inputFileStream;

    // Reading the header file
    Volume::ReadHeaderFile(prefix, iWidth, iHeight, iDepth);

    // Adding the ".img" prefix to the dataset path
    sprintf(imgFile, "%s.img", prefix);

    // Total number of voxels
    int numVoxels = iWidth * iHeight * iDepth;

    // Allocating the luminance image
    char* luminanceImage = new char [numVoxels];

    // Reading the volume image (luminance values)
    inputFileStream.open(imgFile, std::ios::in);
    if (inputFileStream.fail())
    {
        INFO("Input stream failed.");
        exit(0);
    }

    // Read the image byte by byte
    inputFileStream.read((char *)luminanceImage, numVoxels);

    // Closing the input volume stream
    inputFileStream.close();

    INFO("The volume has been read successfully into a luminance stream.");

    return luminanceImage;
}
