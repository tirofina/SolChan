cmake_minimum_required (VERSION 3.1) 

project(P3_SAMPLE)


set (CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})
include_directories ( inc )

set ( manager_src
    src/common.cpp
    src/manager.cpp
    src/m_impl.cpp
    src/store.cpp
)

set ( customer_src
    src/common.cpp
    src/customer.cpp
    src/c_impl.cpp
)

add_executable ( manager ${manager_src} )
add_executable ( customer ${customer_src} )

install ( TARGETS manager customer 
    RUNTIME DESTINATION bin
)