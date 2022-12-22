################# CONFIG ##################

#init Cmake
cmake_minimum_required(VERSION 3.24)
project(TypeLink LANGUAGES CXX VERSION 1.0)

#set flags
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(UNIX)
    set(CMAKE_CXX_FLAGS "-std=c++20 -Ofast")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")
else()
    set(CMAKE_CXX_FLAGS "/std:c++20 /Ox /EHsc")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} /DEBUG:FULL /Wall")
endif()
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(CMAKE_THREADS_LIBS_INIT Threads::Threads)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
if (WIN32)
    set(BUILD_SHARED_LIBS OFF)
else()
    set(BUILD_SHARED_LIBS ON)
endif()

################## BUILD TYPELINK ##################

#set library name
set(LIBRARY TypeLink)

#set root path
set(LIBRARY_ROOT ${PROJECT_NAME}/Library)

#fetch include paths
set(LIBRARY_INC
    ${LIBRARY_ROOT}/Communication/
    ${LIBRARY_ROOT}/PacketManager/
    ${LIBRARY_ROOT}/Connection/
    ${LIBRARY_ROOT}/Console/
    ${LIBRARY_ROOT}/Exception/
    ${LIBRARY_ROOT}/Network/
    ${LIBRARY_ROOT}/Server/
    ${LIBRARY_ROOT}/Client/
    ${LIBRARY_ROOT}/
)

#fetch source files
set(LIBRARY_SRC
    ${LIBRARY_ROOT}/Communication/CommunicationTcp.cpp
    ${LIBRARY_ROOT}/Communication/CommunicationUdp.cpp
    ${LIBRARY_ROOT}/PacketManager/PacketManager.cpp
    ${LIBRARY_ROOT}/Connection/Connection.cpp
    ${LIBRARY_ROOT}/Console/Console.cpp
    ${LIBRARY_ROOT}/Exception/Exception.cpp
    ${LIBRARY_ROOT}/Network/Network.cpp
    ${LIBRARY_ROOT}/Server/Server.cpp
    ${LIBRARY_ROOT}/Server/ServerTcp.cpp
    ${LIBRARY_ROOT}/Server/ServerUdp.cpp
    ${LIBRARY_ROOT}/Client/Client.cpp
    ${LIBRARY_ROOT}/Client/ClientTcp.cpp
    ${LIBRARY_ROOT}/Client/ClientUdp.cpp
)

#set include paths
include_directories(
    ${LIBRARY_INC}
)

#set source files (create library)
add_library(${LIBRARY} ${LIBRARY_SRC})

#link library
target_include_directories(${LIBRARY} PUBLIC ${LIBRARY_INC})

#install target
install(TARGETS ${LIBRARY})

################## BUILD SERVER ##################

#set executable name
set(SERVER link_server)

#set root path
set(SERVER_ROOT ${PROJECT_NAME}/Server)

#fetch include paths
set(SERVER_INC
    ${SERVER_ROOT}/
)

#fetch source files
set(SERVER_SRC
    ${SERVER_ROOT}/main.cpp
)

#set include paths
include_directories(
    ${SERVER_INC}
)

#set source files (create executable)
add_executable(${SERVER} ${SERVER_SRC})

#link library with deps
target_link_libraries(${SERVER} PRIVATE ${LIBRARY})
set_target_properties(${SERVER} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set_target_properties(${SERVER} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

#install target
install(TARGETS ${SERVER})

################## BUILD CLIENT ##################

#set executable name
set(CLIENT link_client)

#set root path
set(CLIENT_ROOT ${PROJECT_NAME}/Client)

#fetch include paths
set(CLIENT_INC
    ${CLIENT_ROOT}/
)

#fetch source files
set(CLIENT_SRC
    ${CLIENT_ROOT}/main.cpp
)

#set include paths
include_directories(
    ${CLIENT_INC}
)

#set source files (create executable)
add_executable(${CLIENT} ${CLIENT_SRC})

#link library with deps
target_link_libraries(${CLIENT} PRIVATE ${LIBRARY})
set_target_properties(${CLIENT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set_target_properties(${CLIENT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

#install target
install(TARGETS ${CLIENT})
