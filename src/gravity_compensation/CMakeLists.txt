find_package(xbot2 REQUIRED)

add_xbot2_plugin(gravity_compensation
    gravity_compensation.cpp)

install(
    TARGETS gravity_compensation
    DESTINATION lib
    )
