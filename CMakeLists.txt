cmake_minimum_required(VERSION 3.10)
PROJECT(umtp-responder C)

include(GNUInstallDirs)

find_package(Threads REQUIRED)

include_directories( ${CMAKE_CURRENT_BINARY_DIR})
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/inc)

########### UMTPRD ###########
file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c") 

add_executable(umtprd ${SRC})

target_link_libraries(umtprd ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS umtprd RUNTIME DESTINATION bin )

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/conf/umtprd.conf DESTINATION /etc/umtprd)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/conf/umtprd-ffs DESTINATION /usr/bin)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/conf/umtprd-gfs DESTINATION /usr/bin)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/umtp-responder.service DESTINATION /lib/systemd/system)


