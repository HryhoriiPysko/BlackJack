cmake_minimum_required(VERSION 3.5)

project(MyBlackJack VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
set(HEADERS
        mainwindow.h
        scene/scene.h
        view/view.h
)
set(SOURCES
        main.cpp
        mainwindow.cpp
        scene/scene.cpp
        view/view.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MyBlackJack
        MANUAL_FINALIZATION
        ${HEADERS}
        ${SOURCES}
    )
else()
    add_executable(MyBlackJack
        ${HEADERS}
        ${SOURCES}
    )
endif()

target_link_libraries(MyBlackJack PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(MyBlackJack PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MyBlackJack)
endif()
