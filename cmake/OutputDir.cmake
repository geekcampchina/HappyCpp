IF(BUILD_MODE STREQUAL "STATIC")
  SET(OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin_static)
ELSE()
  SET(OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin_shared)
ENDIF()

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR}/debug)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIR}/release)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL ${OUTPUT_DIR}/minsizerel)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO
    ${OUTPUT_DIR}/relwithdebinfo)

SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR}/debug)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIR}/release)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL ${OUTPUT_DIR}/minsizerel)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO
    ${OUTPUT_DIR}/relwithdebinfo)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR}/debug)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIR}/release)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${OUTPUT_DIR}/minsizerel)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO
    ${OUTPUT_DIR}/relwithdebinfo)