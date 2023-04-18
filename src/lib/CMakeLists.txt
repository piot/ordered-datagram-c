cmake_minimum_required(VERSION 3.17)
project(ordered_datagram C)

set(CMAKE_C_STANDARD 11)

if (DEFINED PLATFORM)
    message("platform ${PLATFORM}")
    if (PLATFORM STREQUAL "OS64" )
        add_compile_definitions(TORNADO_OS_IOS)
        set(OS_IOS 1)
        set(OS_NAME "ios")
    endif()
elseif (APPLE)
    add_compile_definitions(TORNADO_OS_MACOS)
    set(OS_MACOS 1)
    set(OS_NAME "macos")
elseif (UNIX)
    add_compile_definitions(TORNADO_OS_LINUX)
    set(OS_LINUX 1)
    set(OS_NAME "linux")

elseif (WIN32)
    add_compile_definitions(TORNADO_OS_WINDOWS)
    set(OS_WINDOWS 1)
    set(OS_NAME "windows")
endif()


if (isDebug)
    message("Debug build detected")
    add_compile_definitions(CONFIGURATION_DEBUG TYRAN_CONFIGURATION_DEBUG)
    set(CONFIGURATION_DEBUG 1)
endif()


set(deps ../../deps/)

file(GLOB_RECURSE lib_src FOLLOW_SYMLINKS
        "*.c"
        )

add_library(ordered_datagram
    ${lib_src}
)


if (OS_WINDOWS)
    target_compile_options(ordered_datagram PRIVATE /F 5000000 /Wall /wd4668 /wd4820 /wd4100 /wd4710 /wd4711 /wd5945 /wd5105 /wd5045 /we4047 /we4255 /we4013 /we4020 /we4474 /we4477 /we4057 /we4101 /we4189 ) # /WX
else()
    target_compile_options(ordered_datagram PRIVATE -Wall -Wextra -Wshadow -Wstrict-aliasing -ansi -pedantic -Wno-declaration-after-statement -Wno-extra-semi-stmt -Wno-undef -Wno-unused-variable -Wno-unused-parameter -Wno-padded -Werror=implicit-function-declaration -Werror=incompatible-pointer-types -Werror=incompatible-function-pointer-types -Werror=missing-prototypes -Werror=int-conversion -Werror=return-type) # -Werror=incompatible-pointer-types-discards-qualifiers
    if (COMPILER_CLANG)
        target_compile_options(ordered_datagram PRIVATE -Wmost -Weverything -Werror=missing-variable-declarations)
    endif()
endif()

target_include_directories(ordered_datagram PUBLIC ${deps}piot/clog/src/include)
target_include_directories(ordered_datagram PUBLIC ${deps}piot/tiny-libc/src/include)
target_include_directories(ordered_datagram PUBLIC ${deps}piot/flood-c/src/include)
target_include_directories(ordered_datagram PUBLIC ${deps}piot/monotonic-time-c/src/include)
target_include_directories(ordered_datagram PUBLIC ../include)


