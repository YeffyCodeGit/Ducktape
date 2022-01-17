cmake_minimum_required (VERSION 3.12)

enable_language(C)
set(CMAKE_CXX_FLAGS "-fPIC")

set_target_properties(${PROJECT} PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)

target_include_directories(${PROJECT} PUBLIC "${DTROOT}/include")

target_link_directories(${PROJECT} PUBLIC "${DTROOT}/build")

target_include_directories(${PROJECT} PUBLIC "${DTROOT}/include/Ducktape/external/box2d/include/;${DTROOT}/include/Ducktape/external/box2d/src;")

target_link_directories(${PROJECT} PUBLIC "${DTROOT}/include/Ducktape/external/box2d/bin;")

if (UNIX)
    target_include_directories(${PROJECT} PUBLIC "${DTROOT}/include/Ducktape/external/SFML-windows-gcc/SFML-2.5.1/include")

    target_link_directories(${PROJECT} PUBLIC "${DTROOT}/include/Ducktape/external/SFML-windows-gcc/SFML-2.5.1/lib;")
endif (UNIX)

if (WIN32)
    target_include_directories(${PROJECT} PUBLIC "${DTROOT}/include/Ducktape/external/SFML-windows-gcc/SFML-2.5.1/include")

    target_link_directories(${PROJECT} PUBLIC "${DTROOT}/include/Ducktape/external/SFML-windows-gcc/SFML-2.5.1/lib;")
endif (WIN32)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${DTROOT}/include/Ducktape/external/)

set(SFML_STATIC_LIBRARIES TRUE)

if (UNIX)
    find_package(SFML PATHS ${DTROOT}/include/Ducktape/external/SFML-linux-gcc/lib/cmake/SFML COMPONENTS graphics audio window network system CONFIG REQUIRED)
endif (UNIX)

if (WIN32)
    find_package(SFML PATHS ${DTROOT}/include/Ducktape/external/SFML-windows-gcc/SFML-2.5.1/lib/cmake/SFML COMPONENTS graphics audio window network system CONFIG REQUIRED)
endif (WIN32)

target_link_libraries(${PROJECT} PRIVATE 
    ducktape
    sfml-window
    sfml-system
    opengl32
    winmm
    gdi32
    sfml-graphics
    sfml-system
    sfml-window
    opengl32
    freetype
    sfml-audio
    sfml-system
    openal32
    flac
    vorbisenc
    vorbisfile
    vorbis
    ogg
    sfml-network
    sfml-system
    ws2_32
    sfml-system
    winmm
    box2d
)