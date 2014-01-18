/*********************************************************************
 * Copyright © 2014,
 * Marwan Abdellah: <abdellah.marwan@gmail.com>
 *
 * If you will use this software, kindly ask for permissions.
 ********************************************************************/

#include <iostream>
#include "MACROS.h"
#include "Volume.h"
#include "pbrtWriter.h"

using namespace std;

int raw2pbrt(int argc, char** argv)
{
    if (strcmp(argv[1],"--help") || strcmp(argv[1],"-h"))
    {

        std::cout << "raw2pbrt converter, by Marwan Abdellah <abdellah.marwan@gmail.com>." << std::endl;
        std::cout << "Use this command to generate a pbrt scene with an ASCII volume file " << std::endl;
        std::cout << "\t raw2pbrt <RAW_VOLUME_DIR> <OUTPUT_FILE_NAME>" << std::endl;
        return 0;
    }

    if (argc < 3)
    {
        std::cout << "******************************************************************************" << std::endl;
        std::cout << "Please provide a path to the directory that has "
                     "the header and the raw files." << std::endl;
        std::cout << "The directory name should be the same as the header "
                     "and the raw files" << std::endl;
        std::cout << "For example ./raw2pbrt ~/Volume OutputFileName" << std::endl;
        std::cout << "******************************************************************************" << std::endl;

        INFO("Exitting");

        return 0;
    }

    // Volume prefix
    char* volumePrefix = argv[1];
    std::cout << volumePrefix;

    // Array containing the volume data
    char* volumeData;

    // Volume dimensions
    int NX, NY, NZ;

    // Output file name
    char* outputFile = argv[2];

    // Read th volume raw file
    volumeData = Volume::ReadRawFile(volumePrefix, NX, NY, NZ);

    // Generate the pbrt scene descriptor file
    pbrtWriter::WriteSceneFile(outputFile);

    // Write the pbrt volume file
    Volume::Write_pbrtVolume(volumeData, NX, NY, NZ, outputFile);

    return 0;
}

int main (int argc, char** argv) { return raw2pbrt (argc, argv); }
