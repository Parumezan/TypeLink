# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Louis/Desktop/TypeLink

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TypeLink.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TypeLink.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TypeLink.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TypeLink.dir/flags.make

CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Communication/CommunicationTcp.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Communication/CommunicationTcp.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Communication/CommunicationTcp.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Communication/CommunicationTcp.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.s

CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Communication/CommunicationUdp.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Communication/CommunicationUdp.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Communication/CommunicationUdp.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Communication/CommunicationUdp.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.s

CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/PacketManager/PacketManager.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/PacketManager/PacketManager.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/PacketManager/PacketManager.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/PacketManager/PacketManager.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.s

CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Connection/Connection.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Connection/Connection.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Connection/Connection.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Connection/Connection.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.s

CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Console/Console.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Console/Console.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Console/Console.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Console/Console.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.s

CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Exception/Exception.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Exception/Exception.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Exception/Exception.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Exception/Exception.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.s

CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Network/Network.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Network/Network.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Network/Network.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Network/Network.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.s

CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Server/Server.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Server/Server.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Server/Server.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Server/Server.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.s

CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Server/ServerTcp.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Server/ServerTcp.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Server/ServerTcp.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Server/ServerTcp.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.s

CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Server/ServerUdp.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Server/ServerUdp.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Server/ServerUdp.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Server/ServerUdp.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.s

CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Client/Client.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Client/Client.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Client/Client.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Client/Client.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.s

CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Client/ClientTcp.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Client/ClientTcp.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Client/ClientTcp.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Client/ClientTcp.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.s

CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.o: CMakeFiles/TypeLink.dir/flags.make
CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.o: /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Client/ClientUdp.cpp
CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.o: CMakeFiles/TypeLink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.o -MF CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.o.d -o CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.o -c /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Client/ClientUdp.cpp

CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Client/ClientUdp.cpp > CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.i

CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Louis/Desktop/TypeLink/TypeLink/Library/Client/ClientUdp.cpp -o CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.s

# Object files for target TypeLink
TypeLink_OBJECTS = \
"CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.o" \
"CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.o" \
"CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.o" \
"CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.o" \
"CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.o" \
"CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.o" \
"CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.o" \
"CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.o" \
"CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.o" \
"CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.o" \
"CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.o" \
"CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.o" \
"CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.o"

# External object files for target TypeLink
TypeLink_EXTERNAL_OBJECTS =

libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationTcp.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/Communication/CommunicationUdp.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/PacketManager/PacketManager.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/Connection/Connection.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/Console/Console.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/Exception/Exception.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/Network/Network.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/Server/Server.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerTcp.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/Server/ServerUdp.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/Client/Client.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientTcp.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/TypeLink/Library/Client/ClientUdp.cpp.o
libTypeLink.so: CMakeFiles/TypeLink.dir/build.make
libTypeLink.so: CMakeFiles/TypeLink.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX shared library libTypeLink.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TypeLink.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TypeLink.dir/build: libTypeLink.so
.PHONY : CMakeFiles/TypeLink.dir/build

CMakeFiles/TypeLink.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TypeLink.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TypeLink.dir/clean

CMakeFiles/TypeLink.dir/depend:
	cd /mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Louis/Desktop/TypeLink /mnt/c/Users/Louis/Desktop/TypeLink /mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug /mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug /mnt/c/Users/Louis/Desktop/TypeLink/cmake-build-debug/CMakeFiles/TypeLink.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TypeLink.dir/depend

