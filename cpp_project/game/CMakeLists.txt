cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)

#컴파일 옵션 추가
add_compile_options(-std=c++17 -ggdb3 -O3 -Wall -Werror)

#define 추가
add_definitions(
	-D_DEBUG
	-DJSON_IS_AMALGAMATION
	-DBOOST_BIND_GLOBAL_PLACEHOLDERS
	-D_MOVE_SYNC
	-D_MOVE_SYNC2
	-D_MOVE_CONFIRM
	-D_CHANNEL
	-D_SERVER_MOVE_SPEED_CHECK
	-D_USE_FILE_LOG
	-D_USER_COUNT
	-D_USE_DEV_GM_OPER
	-D_USE_GLOBAL_SERVICE
	-D_USE_NEW_NOT_ALLOW_PACKET
	-D_USE_NOT_ALLOW_DUPLICATION_LOGIN
	-D_USE_PLAYER_EMERGENCY_CLOSE
	-D_USE_SERVER_CALC_POWER
	-D_USE_PACKET_SERIALIZE_CHECK
	-D_USE_GLOBAL_CONTENTS_TICKET
	-D_USE_GATE
	-D_USE_WORLD_GAME
	-D_USE_GATE_COMMUNITY
	-D_USE_GLOBAL_EXCHANGE_MERGE__
	-D_USE_PACKET_WORKER_EX__
)
 
#header include 경로
include_directories(
    ../extraLibrary
    ../extraLibrary/boost/include
	../extraLibrary/network
    ../extraLibrary/pathEngine
	../extraLibrary/json
    ../extraLibrary/openssl/include
)
 
 #라이브러리 링크 디렉토리 경로
link_directories()
 
#전체 적용될 라이브러리 링크
link_libraries(
    pthread
)

# https://www.cv-learn.com/20220120-unused-parameter/
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-function")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-reorder")

#cmake 변수 처리
# file(GLOB all_srcs "./*.cpp")
# file(GLOB SRC_PROTOCOL_FILES "../extraLibrary/protocol/*.h")
# file(GLOB SRC_ASTAR_FILES "../extraLibrary/pathEngine/astar/*.cpp" "../extraLibrary/pathEngine/astar/*.h")
file(GLOB_RECURSE SRC_GAME_FILES "*.cpp" "*.h")




#set(OUTPUT_STATIC_LIB "hello")
#add_library(${OUTPUT_STATIC_LIB} STATIC ${all_srcs})

#라이브러리 생성
add_executable(main ${SRC_GAME_FILES})