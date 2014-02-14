/*********************************************************************
 * Copyright © 2014,
 * Marwan Abdellah: <abdellah.marwan@gmail.com>
 *
 * If you will use this software, kindly ask for permissions.
 ********************************************************************/

#include "pbrtWriter.h"
#include "MACROS.h"

#include <fstream>
#include <sstream>

void pbrtWriter::WriteSceneFile(char* fileName)
{
    INFO("Writing the pbrt scene file.");

    char pbrtFile[200] = "";
    char pbrtVolumeFile[200] = "";

    strcat(pbrtFile, fileName);
    strcat(pbrtFile, ".pbrt");

    pbrtVolumeFile[200];
    strcat(pbrtVolumeFile, fileName);
    strcat(pbrtVolumeFile, "-volume.pbrt");

    std::ofstream fileStream(pbrtFile, std::ios::out);

    fileStream << "###########################################################" << std::endl;
    fileStream << "# This file has been automatically generated with raw2pbrt. " << std::endl;
    fileStream << "# Basic pbrt scene file with volume grid. " << std::endl;
    fileStream << "###########################################################" << std::endl;

    fileStream << "# For further detais, look at gluLookAt() " << std::endl;
    fileStream << "# eyeX eyeY eyeZ pX pY pZ  normX normY normZ " << std::endl;
    fileStream << "LookAt 5.0 0.0 0.0  0.0 0.0 0.0  0.0 1.0 0.0 " << std::endl;

    fileStream << "# Camera " << std::endl;
    fileStream << "Camera \"perspective\" " << std::endl;
    fileStream << "\t \"float fov\" [28] " << std::endl;

    fileStream << "# Film " << std::endl;
    fileStream << "Film \"image\" " << std::endl;
    fileStream << "\t \"integer xresolution\" [1920] " << std::endl;
    fileStream << "\t \"integer yresolution\" [1080] " << std::endl;
    fileStream << "\t \"string filename\" \"file.exr\" " << std::endl;

    fileStream << "# Sampler "<< std::endl;
    fileStream << "Sampler \"bestcandidate\" " << std::endl;
    fileStream << "\t \"integer pixelsamples\" [15] " << std::endl;
    fileStream << "\t PixelFilter \"triangle\" " << std::endl;

    fileStream << "# Volume integrator " << std::endl;
    fileStream << "VolumeIntegrator \"single\" " << std::endl;
    fileStream << "\t float stepsize\" [.0025] " << std::endl;

    fileStream << "# Scene " << std::endl;
    fileStream << "WorldBegin " << std::endl;

    fileStream << "# Light "<< std::endl;
    fileStream << "LightSource \"point\" " << std::endl;
    fileStream << "\t point from\" [0 10 2] " << std::endl;
    fileStream << "\t \"color I\" [100 100 100] " << std::endl;

    fileStream << "# Volume ASCII file " << std::endl;
    fileStream << "Include \"" << pbrtVolumeFile << "\"" << std::endl;
    fileStream << "\t \"color sigma_a\" [0 0 0] " << std::endl;
    fileStream << "\t \"color sigma_s\" [0 0 0] " << std::endl;
    fileStream << "\t \"color Le\" [4.5 250 4.5] " << std::endl;

    fileStream << "WorldEnd"<< std::endl;

    INFO("The pbrt scene file has been successfully created.");
}

