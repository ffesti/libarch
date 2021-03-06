if(NOT WITH_PYTHON3)
    return()
endif()


message("Building bindings for python3")


find_package(Python3 REQUIRED)
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})


function(add_python3_module LIBRARY_NAME MODULE_NAME)
    set(TARGET_NAME "python3_${MODULE_NAME}")
    swig_add_library(${TARGET_NAME} LANGUAGE python SOURCES ../../${LIBRARY_NAME}/${MODULE_NAME}.i)
    set_property(TARGET ${TARGET_NAME} PROPERTY OUTPUT_NAME ${MODULE_NAME})
    target_compile_options(${TARGET_NAME} PUBLIC ${SWIG_COMPILE_OPTIONS})
    set_target_properties("${TARGET_NAME}" PROPERTIES LINKER_LANGUAGE C)

    string(REPLACE "_" "-" C_LIBRARY_NAME ${LIBRARY_NAME})
    swig_link_libraries(${TARGET_NAME} ${C_LIBRARY_NAME})
    swig_link_libraries(${TARGET_NAME} ${PYTHON_LIBRARIES})

    install(TARGETS ${TARGET_NAME} LIBRARY DESTINATION ${Python3_SITEARCH}/${LIBRARY_NAME})
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME}.py DESTINATION ${Python3_SITEARCH}/${LIBRARY_NAME})
endfunction()


add_subdirectory(libparch)
