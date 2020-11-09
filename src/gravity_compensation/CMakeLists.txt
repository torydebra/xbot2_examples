find_package(xbot2 REQUIRED)

add_xbot2_plugin(gravity_compensation
    gravity_compensation.cpp)

install(
    TARGETS gravity_compensation
    DESTINATION lib
    )


add_executable(try try.cpp )

target_link_libraries(try
    xbot2::xbot2   
)
