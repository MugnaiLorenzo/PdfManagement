# Install script for directory: /home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo" TYPE FILE FILES
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/podofo-base.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/podofo.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/base" TYPE FILE FILES
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/podofo_config.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/Pdf3rdPtyForwardDecl.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfArray.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfCanvas.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfColor.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfCompilerCompat.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfCompilerCompatPrivate.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfContentsTokenizer.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfData.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfDataType.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfDate.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfDefines.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfDefinesPrivate.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfDictionary.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfEncoding.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfEncodingFactory.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfEncrypt.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfExtension.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfError.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfFileStream.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfFilter.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfFiltersPrivate.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfImmediateWriter.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfInputDevice.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfInputStream.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfLocale.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfMemStream.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfMemoryManagement.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfName.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfObject.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfObjectStreamParserObject.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfOutputDevice.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfOutputStream.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfParser.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfParserObject.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfRect.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfRefCountedBuffer.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfRefCountedInputDevice.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfReference.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfStream.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfString.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfTokenizer.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfVariant.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfVecObjects.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfVersion.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfWriter.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfXRef.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfXRefStream.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/PdfXRefStreamParserObject.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/podofoapi.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/base/util" TYPE FILE FILES
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/util/PdfMutex.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/util/PdfMutexImpl_noop.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/util/PdfMutexImpl_win32.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/util/PdfMutexImpl_pthread.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/base/util/PdfMutexWrapper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/podofo/doc" TYPE FILE FILES
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfAcroForm.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfAction.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfAnnotation.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfCMapEncoding.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfContents.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfDestination.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfDifferenceEncoding.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfDocument.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfElement.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfEncodingObjectFactory.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfExtGState.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfField.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFileSpec.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFont.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontCID.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontCache.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontConfigWrapper.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontFactory.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontFactoryBase14Data.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontMetrics.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontMetricsBase14.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontMetricsFreetype.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontMetricsObject.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontSimple.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontTTFSubset.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontTrueType.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontType1.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontType3.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFontType1Base14.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfFunction.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfHintStream.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfIdentityEncoding.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfImage.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfInfo.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfMemDocument.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfNamesTree.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfOutlines.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfPage.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfPagesTree.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfPagesTreeCache.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfPainter.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfPainterMM.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfShadingPattern.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfSignOutputDevice.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfSignatureField.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfStreamedDocument.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfTable.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfTilingPattern.h"
    "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/src/doc/PdfXObject.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so.0.9.6" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so.0.9.6")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so.0.9.6"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/src/libpodofo.so.0.9.6")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so.0.9.6" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so.0.9.6")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so.0.9.6"
         OLD_RPATH "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/src:/usr/local/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so.0.9.6")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/src/libpodofo.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so"
         OLD_RPATH "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/src:/usr/local/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpodofo.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/lorenzo/CLionProjects/PdfManagement/lib/podofo/build/libpodofo-0.pc")
endif()

