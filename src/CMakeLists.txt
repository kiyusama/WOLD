set(SOURCES
  main.cpp
  PacketSender.cpp
)

add_executable(wold ${SOURCES})
target_link_libraries(wold dpp)
