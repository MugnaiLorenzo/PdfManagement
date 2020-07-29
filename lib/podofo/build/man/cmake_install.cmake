# Install script for directory: /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE FILES
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofobox.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofocolor.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofocountpages.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofocrop.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofogc.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofoencrypt.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofoimg2pdf.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofoimgextract.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofoimpose.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofoincrementalupdates.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofomerge.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofopages.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofopdfinfo.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofotxt2pdf.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofotxtextract.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofouncompress.1"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/man/podofoxmp.1"
    )
endif()

