#####################################################################
# Copyright © 2011-2012,
# Marwan Abdellah: <abdellah.marwan@gmail.com>
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation.

# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.

# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.
#####################################################################

#########################################################
#! Project name
#########################################################
PROJECT(raw2pbrt)

#########################################################
#! Minimum required CMake version
#########################################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#########################################################
#! Source list
#########################################################
SET(SRC_LIST raw2pbrt.cpp
             VolumeReader.cpp
             VolumeWriter.cpp
             pbrtWriter.cpp
)

#########################################################
#! Headers
#########################################################
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

#########################################################
#! Executable generation
#########################################################
ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_LIST})

#########################################################
#! Installation
#########################################################
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
