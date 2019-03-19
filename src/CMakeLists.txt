add_executable(${PROJECT_NAME} main.cpp version.h)

#find_package(Dummy MODULE COMPONENTS Comp1 Comp2 REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE Dummy::Comp1 Dummy::Comp2)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

find_package(Git)

if(GIT_FOUND)
    execute_process(COMMAND "${GIT_EXECUTABLE}" "describe"
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                    RESULT_VARIABLE _GIT_REV_GET_RESULT
                    OUTPUT_VARIABLE _GIT_REV)
    if(_GIT_REV_GET_RESULT EQUAL 0)
        string(STRIP ${_GIT_REV} AUTO_DEFINED_VERSION)
        configure_file("detail/auto_defined_version.h.in"
                        "auto_defined_version.h" @ONLY)
        set_property(SOURCE "version.h" APPEND
                    PROPERTY INTERFACE_COMPILE_DEFINITIONS "VERSION_IS_AUTO_DEFINED=1")
    else()
        set(WARNING "Getting version info from git hasn't been successful.")  
    endif()
else()
        set(WARNING "Git not found. Version info cannot be gathered.")  
endif()
