cmake_minimum_required(VERSION 3.16)
set(FORMS
        ../mainwindow.ui
        )
set(RESOURCES
        ../Risorse.qrc
        )
set(LIBRARIES
        Qt5::Widgets Qt5::Core podofo poppler poppler-qt5
        )
set(SOURCES
        main.cpp mainwindow.cpp mainwindow.h View.cpp View.h CommandPattern.cpp CommandPattern.h
        Command.cpp Command.h ManagementView.cpp ManagementView.h Pdf.cpp Pdf.h
        Page.cpp Page.h DeletePage.cpp DeletePage.h MovePage.cpp MovePage.h
        UnionPdf.cpp UnionPdf.h EditRotation.cpp EditRotation.h Text.txt SplitPage.h SplitPage.cpp
        )
set(PoDoFo_DIR ../lib/podofo/build)
find_package(PoDoFo REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_AUTOMOC ON)
qt5_wrap_ui(UIC_SOURCES ${FORMS})
qt5_add_resources(RCC_SOURCES ${RESOURCES})
add_executable(PdfManagement ${SOURCES} ${HEADERS} ${UIC_SOURCES} ${RCC_SOURCES} Observer.h Subject.h)
add_library(core ${SOURCES} ${LIBRARIES})
target_link_libraries(PdfManagement  ${LIBRARIES})
install(TARGETS PdfManagement RUNTIME DESTINATION bin)
install(FILES resource/PdfManagement.png DESTINATION share/icons/hicolor/48x48/apps)
install(FILES PdfManagement.desktop DESTINATION share/application)