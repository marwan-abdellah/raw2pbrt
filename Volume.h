/*********************************************************************
 * Copyright © 2014,
 * Marwan Abdellah: <abdellah.marwan@gmail.com>
 *
 * If you will use this software, kindly ask for permissions.
 ********************************************************************/

#ifndef VOLUME_H
#define VOLUME_H

namespace Volume
{
void ReadHeaderFile(char *prefix,
                    int &volumeWidth,
                    int &volumeHeight,
                    int &volumeDepth);

char* ReadRawFile(char *prefix, int& iWidth, int& iHeight, int& iDepth);


void WriteRawFile (const char* volData,
                   const int volWidth,
                   const int volHeight,
                   const int volDepth,
                   char* fileName);

void WriteAsciiFile (const char* volData,
                     const int volWidth,
                     const int volHeight,
                     const int volDepth,
                     char* fileName);

void Write_pbrtVolume(const char* volData,
                      const int volWidth,
                      const int volHeight,
                      const int volDepth,
                      char* fileName);


}

#endif // VOLUME_H
