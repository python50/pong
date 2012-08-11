#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=g++
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/game_engine.o \
	${OBJECTDIR}/lua/lfs.o \
	${OBJECTDIR}/lua/lstate.o \
	${OBJECTDIR}/lua/lcode.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/lua/print.o \
	${OBJECTDIR}/src/game_engine_joystick.o \
	${OBJECTDIR}/src/game_engine_collision.o \
	${OBJECTDIR}/src/game_engine_view.o \
	${OBJECTDIR}/lua/lmathlib.o \
	${OBJECTDIR}/lua/lfunc.o \
	${OBJECTDIR}/src/player_paddle.o \
	${OBJECTDIR}/lua/ldblib.o \
	${OBJECTDIR}/lua/lstrlib.o \
	${OBJECTDIR}/lua/loadlib.o \
	${OBJECTDIR}/src/tile.o \
	${OBJECTDIR}/sdl_gfx/SDL_gfxBlitFunc.o \
	${OBJECTDIR}/src/ui/main_menu_ui.o \
	${OBJECTDIR}/lua/ldebug.o \
	${OBJECTDIR}/src/game_math.o \
	${OBJECTDIR}/lua/ltm.o \
	${OBJECTDIR}/lua/linit.o \
	${OBJECTDIR}/src/pong_ball.o \
	${OBJECTDIR}/src/game_engine_resource.o \
	${OBJECTDIR}/sdl_gfx/SDL_rotozoom.o \
	${OBJECTDIR}/lua/ltablib.o \
	${OBJECTDIR}/src/lua_object.o \
	${OBJECTDIR}/sdl_gfx/SDL_framerate.o \
	${OBJECTDIR}/src/game_engine_misc.o \
	${OBJECTDIR}/lua/loslib.o \
	${OBJECTDIR}/src/ui/startup_ui.o \
	${OBJECTDIR}/lua/lzio.o \
	${OBJECTDIR}/lua/lgc.o \
	${OBJECTDIR}/lua/lopcodes.o \
	${OBJECTDIR}/lua/liolib.o \
	${OBJECTDIR}/lua/lundump.o \
	${OBJECTDIR}/lua/ldo.o \
	${OBJECTDIR}/src/misc.o \
	${OBJECTDIR}/lua/lobject.o \
	${OBJECTDIR}/lua/lbaselib.o \
	${OBJECTDIR}/sdl_gfx/SDL_imageFilter.o \
	${OBJECTDIR}/lua/lmem.o \
	${OBJECTDIR}/src/map_parser.o \
	${OBJECTDIR}/src/config_manager.o \
	${OBJECTDIR}/lua/ldump.o \
	${OBJECTDIR}/src/ui/startup_splash_ui.o \
	${OBJECTDIR}/lua/lstring.o \
	${OBJECTDIR}/sqlite/sqlite3.o \
	${OBJECTDIR}/src/game_engine_draw.o \
	${OBJECTDIR}/lua/lvm.o \
	${OBJECTDIR}/src/config_file.o \
	${OBJECTDIR}/src/game_object.o \
	${OBJECTDIR}/lua/llex.o \
	${OBJECTDIR}/src/message_log.o \
	${OBJECTDIR}/sdl_gfx/SDL_gfxPrimitives.o \
	${OBJECTDIR}/lua/lauxlib.o \
	${OBJECTDIR}/lua/lparser.o \
	${OBJECTDIR}/src/game_engine_sound.o \
	${OBJECTDIR}/lua/lapi.o \
	${OBJECTDIR}/lua/ltable.o \
	${OBJECTDIR}/src/game_engine_gameplay.o \
	${OBJECTDIR}/src/controller.o \
	${OBJECTDIR}/src/text.o \
	${OBJECTDIR}/src/text_menu.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lSDL_image -lSDL_ttf -lSDL_mixer -lpthread -ldl `sdl-config --libs`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pong

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pong: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pong ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/game_engine.o: src/game_engine.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/game_engine.o src/game_engine.cpp

${OBJECTDIR}/lua/lfs.o: lua/lfs.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lfs.o lua/lfs.c

${OBJECTDIR}/lua/lstate.o: lua/lstate.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lstate.o lua/lstate.c

${OBJECTDIR}/lua/lcode.o: lua/lcode.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lcode.o lua/lcode.c

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/lua/print.o: lua/print.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/print.o lua/print.c

${OBJECTDIR}/src/game_engine_joystick.o: src/game_engine_joystick.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/game_engine_joystick.o src/game_engine_joystick.cpp

${OBJECTDIR}/src/game_engine_collision.o: src/game_engine_collision.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/game_engine_collision.o src/game_engine_collision.cpp

${OBJECTDIR}/src/game_engine_view.o: src/game_engine_view.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/game_engine_view.o src/game_engine_view.cpp

${OBJECTDIR}/lua/lmathlib.o: lua/lmathlib.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lmathlib.o lua/lmathlib.c

${OBJECTDIR}/lua/lfunc.o: lua/lfunc.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lfunc.o lua/lfunc.c

${OBJECTDIR}/src/player_paddle.o: src/player_paddle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/player_paddle.o src/player_paddle.cpp

${OBJECTDIR}/lua/ldblib.o: lua/ldblib.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/ldblib.o lua/ldblib.c

${OBJECTDIR}/lua/lstrlib.o: lua/lstrlib.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lstrlib.o lua/lstrlib.c

${OBJECTDIR}/lua/loadlib.o: lua/loadlib.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/loadlib.o lua/loadlib.c

${OBJECTDIR}/src/tile.o: src/tile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/tile.o src/tile.cpp

${OBJECTDIR}/sdl_gfx/SDL_gfxBlitFunc.o: sdl_gfx/SDL_gfxBlitFunc.c 
	${MKDIR} -p ${OBJECTDIR}/sdl_gfx
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/sdl_gfx/SDL_gfxBlitFunc.o sdl_gfx/SDL_gfxBlitFunc.c

${OBJECTDIR}/src/ui/main_menu_ui.o: src/ui/main_menu_ui.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ui
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ui/main_menu_ui.o src/ui/main_menu_ui.cpp

${OBJECTDIR}/lua/ldebug.o: lua/ldebug.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/ldebug.o lua/ldebug.c

${OBJECTDIR}/src/game_math.o: src/game_math.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/game_math.o src/game_math.cpp

${OBJECTDIR}/lua/ltm.o: lua/ltm.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/ltm.o lua/ltm.c

${OBJECTDIR}/lua/linit.o: lua/linit.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/linit.o lua/linit.c

${OBJECTDIR}/src/pong_ball.o: src/pong_ball.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/pong_ball.o src/pong_ball.cpp

${OBJECTDIR}/src/game_engine_resource.o: src/game_engine_resource.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/game_engine_resource.o src/game_engine_resource.cpp

${OBJECTDIR}/sdl_gfx/SDL_rotozoom.o: sdl_gfx/SDL_rotozoom.c 
	${MKDIR} -p ${OBJECTDIR}/sdl_gfx
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/sdl_gfx/SDL_rotozoom.o sdl_gfx/SDL_rotozoom.c

${OBJECTDIR}/lua/ltablib.o: lua/ltablib.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/ltablib.o lua/ltablib.c

${OBJECTDIR}/src/lua_object.o: src/lua_object.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/lua_object.o src/lua_object.cpp

${OBJECTDIR}/sdl_gfx/SDL_framerate.o: sdl_gfx/SDL_framerate.c 
	${MKDIR} -p ${OBJECTDIR}/sdl_gfx
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/sdl_gfx/SDL_framerate.o sdl_gfx/SDL_framerate.c

${OBJECTDIR}/src/game_engine_misc.o: src/game_engine_misc.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/game_engine_misc.o src/game_engine_misc.cpp

${OBJECTDIR}/lua/loslib.o: lua/loslib.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/loslib.o lua/loslib.c

${OBJECTDIR}/src/ui/startup_ui.o: src/ui/startup_ui.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ui
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ui/startup_ui.o src/ui/startup_ui.cpp

${OBJECTDIR}/lua/lzio.o: lua/lzio.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lzio.o lua/lzio.c

${OBJECTDIR}/lua/lgc.o: lua/lgc.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lgc.o lua/lgc.c

${OBJECTDIR}/lua/lopcodes.o: lua/lopcodes.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lopcodes.o lua/lopcodes.c

${OBJECTDIR}/lua/liolib.o: lua/liolib.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/liolib.o lua/liolib.c

${OBJECTDIR}/lua/lundump.o: lua/lundump.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lundump.o lua/lundump.c

${OBJECTDIR}/lua/ldo.o: lua/ldo.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/ldo.o lua/ldo.c

${OBJECTDIR}/src/misc.o: src/misc.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/misc.o src/misc.cpp

${OBJECTDIR}/lua/lobject.o: lua/lobject.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lobject.o lua/lobject.c

${OBJECTDIR}/lua/lbaselib.o: lua/lbaselib.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lbaselib.o lua/lbaselib.c

${OBJECTDIR}/sdl_gfx/SDL_imageFilter.o: sdl_gfx/SDL_imageFilter.c 
	${MKDIR} -p ${OBJECTDIR}/sdl_gfx
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/sdl_gfx/SDL_imageFilter.o sdl_gfx/SDL_imageFilter.c

${OBJECTDIR}/lua/lmem.o: lua/lmem.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lmem.o lua/lmem.c

${OBJECTDIR}/src/map_parser.o: src/map_parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/map_parser.o src/map_parser.cpp

${OBJECTDIR}/src/config_manager.o: src/config_manager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/config_manager.o src/config_manager.cpp

${OBJECTDIR}/lua/ldump.o: lua/ldump.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/ldump.o lua/ldump.c

${OBJECTDIR}/src/ui/startup_splash_ui.o: src/ui/startup_splash_ui.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ui
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ui/startup_splash_ui.o src/ui/startup_splash_ui.cpp

${OBJECTDIR}/lua/lstring.o: lua/lstring.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lstring.o lua/lstring.c

${OBJECTDIR}/sqlite/sqlite3.o: sqlite/sqlite3.c 
	${MKDIR} -p ${OBJECTDIR}/sqlite
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/sqlite/sqlite3.o sqlite/sqlite3.c

${OBJECTDIR}/src/game_engine_draw.o: src/game_engine_draw.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/game_engine_draw.o src/game_engine_draw.cpp

${OBJECTDIR}/lua/lvm.o: lua/lvm.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lvm.o lua/lvm.c

${OBJECTDIR}/src/config_file.o: src/config_file.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/config_file.o src/config_file.cpp

${OBJECTDIR}/src/game_object.o: src/game_object.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/game_object.o src/game_object.cpp

${OBJECTDIR}/lua/llex.o: lua/llex.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/llex.o lua/llex.c

${OBJECTDIR}/src/message_log.o: src/message_log.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/message_log.o src/message_log.cpp

${OBJECTDIR}/sdl_gfx/SDL_gfxPrimitives.o: sdl_gfx/SDL_gfxPrimitives.c 
	${MKDIR} -p ${OBJECTDIR}/sdl_gfx
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/sdl_gfx/SDL_gfxPrimitives.o sdl_gfx/SDL_gfxPrimitives.c

${OBJECTDIR}/lua/lauxlib.o: lua/lauxlib.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lauxlib.o lua/lauxlib.c

${OBJECTDIR}/lua/lparser.o: lua/lparser.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lparser.o lua/lparser.c

${OBJECTDIR}/src/game_engine_sound.o: src/game_engine_sound.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/game_engine_sound.o src/game_engine_sound.cpp

${OBJECTDIR}/lua/lapi.o: lua/lapi.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/lapi.o lua/lapi.c

${OBJECTDIR}/lua/ltable.o: lua/ltable.c 
	${MKDIR} -p ${OBJECTDIR}/lua
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua/ltable.o lua/ltable.c

${OBJECTDIR}/src/game_engine_gameplay.o: src/game_engine_gameplay.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/game_engine_gameplay.o src/game_engine_gameplay.cpp

${OBJECTDIR}/src/controller.o: src/controller.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controller.o src/controller.cpp

${OBJECTDIR}/src/text.o: src/text.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/text.o src/text.cpp

${OBJECTDIR}/src/text_menu.o: src/text_menu.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Iinclude/ui -Isrc -Isrc/ui -Ilua -Isdl_gfx -Isqlite -I/usr/include/SDL -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/text_menu.o src/text_menu.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pong

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
