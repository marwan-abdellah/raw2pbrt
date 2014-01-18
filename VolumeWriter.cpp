/*********************************************************************
 * Copyright © 2014,
 * Marwan Abdellah: <abdellah.marwan@gmail.com>
 *
 * If you will use this software, kindly ask for permissions.
 ********************************************************************/

#include "Volume.h"
#include "MACROS.h"

#include <fstream>
#include <sstream>

void Volume::WriteRawFile (const char* volData,
                           const int volWidth,
                           const int volHeight,
                           const int volDepth,
                           char* fileName)
{
    std::ofstream fileStream(fileName, std::ios::out | std::ios::app | std::ios::binary);

    int index = 0;
    for (int i = 0; i < volWidth; i++)
        for (int j = 0; j < volHeight; j++)
            for (int k = 0; k < volDepth; k++)
            {
                fileStream << volData[index];
                index++;
            }

    INFO("The volume has been successfully written into a Raw file.");
}

void Volume::WriteAsciiFile (const char* volData,
                             const int volWidth,
                             const int volHeight,
                             const int volDepth,
                             char* fileName)
{
    std::ofstream fileStream(fileName, std::ios::out);

    int index = 0;
    for (int i = 0; i < volWidth; i++)
        for (int j = 0; j < volHeight; j++)
            for (int k = 0; k < volDepth; k++)
            {
                fileStream << static_cast<int> ((unsigned char)(volData[index])) << " ";
                index++;
            }

    INFO("The volume has been successfully written to an Ascii file.");
}

void Volume::Write_pbrtVolume(const char* volData,
                              const int volWidth,
                              const int volHeight,
                              const int volDepth,
                              char* fileName)
{
    INFO("Writing the volume to a pbrt file.");

    char pbrtVolumeFile[200] = "";
    strcat(pbrtVolumeFile, fileName);
    strcat(pbrtVolumeFile, "-volume.pbrt");

    std::ofstream fileStream(pbrtVolumeFile, std::ios::out);

    // String stream
    std::stringstream pbrtVolumeStream;

    // Grid
    pbrtVolumeStream << "Volume \"volumegrid\" " << std::endl;

    // Dimensions
    pbrtVolumeStream << "\t \"integer nx\" " << volWidth << std::endl;
    pbrtVolumeStream << "\t \"integer ny\" " << volHeight << std::endl;
    pbrtVolumeStream << "\t \"integer nz\" " << volDepth << std::endl;

    // Grid size
    pbrtVolumeStream << "\t \"point p0\" [-1.0 -1.0 -1.0 ] \n";
    pbrtVolumeStream << "\t \"point p1\" [1.0 1.0 1.0 ] \n";

    // Volume ASCII data
    pbrtVolumeStream << "\t \"float density\" [";

    int index = 0;
    for (int i = 0; i < volWidth; i++)
        for (int j = 0; j < volHeight; j++)
            for (int k = 0; k < volDepth; k++)
            {
                pbrtVolumeStream << static_cast<int> ((unsigned char)(volData[index])) << " ";
                index++;
            }

    pbrtVolumeStream << "] \n";

    // Dump the string stream to an output file stream
    fileStream << pbrtVolumeStream.rdbuf();

    INFO("The volume has been successfully written to an pbrt file.");
}
