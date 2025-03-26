function (listDir directory)

    file(GLOB CHILDREN RELATIVE ${directory} ${directory}/*)
    foreach(child in ${CHILDREN})
        message(STATUS [INFO] " " ${child})
    endforeach(child in ${CHILDREN})

endfunction()


function (extract_basename_from_m_file TEMPLATE_M_FILE_NAME)
    #regex: parse function header from template m file
    file(STRINGS ${TEMPLATE_M_FILE_NAME} HEADER_LINES REGEX "^[ \\t]*function[ \\t]*\\[([a-zA-Z][a-zA-Z0-9_]*),.*$")
    foreach(LINE ${HEADER_LINES})
        #regex: grab basename from function line (string after '=')
        string(REGEX REPLACE "^.*=[ \\t]*(.*)$" "\\1" BASE_NAME ${LINE})
        #we only expect one result from the file parsing - so break after the first one
        break()
    endforeach()
    if(NOT DEFINED BASE_NAME)
        message(FATAL_ERROR "Extracting base name from template m file ${TEMPLATE_M_FILE_NAME} failed")
    endif()
    set(BASE_NAME ${BASE_NAME} PARENT_SCOPE)
    message(STATUS [INFO] " " ${BASE_NAME})
endfunction()