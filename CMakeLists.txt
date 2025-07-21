cmake_minimum_required(VERSION 3.5)
project(_rps LANGUAGES CXX)


find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Network)

include(FetchContent)



qt_standard_project_setup()

include_directories(${CMAKE_SOURCE_DIR}/include)

qt_add_resources(RESOURCES resources.qrc)

qt_add_executable(_rps
    WIN32 MACOSX_BUNDLE
    src/GameManager.cpp
    include/GameManager.h
    include/mainwindow.h
    mainwindow.cpp
    mainwindow.ui
    main.cpp
    ${RESOURCES} 
    
)

target_link_libraries(_rps
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Network
)

include(GNUInstallDirs)

install(TARGETS _rps
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET _rps
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

