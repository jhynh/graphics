#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SDL2_image::SDL2_image" for configuration "Debug"
set_property(TARGET SDL2_image::SDL2_image APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SDL2_image::SDL2_image PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "SDL2::SDL2"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libSDL2_image-2.0d.so.0.600.2"
  IMPORTED_SONAME_DEBUG "libSDL2_image-2.0d.so.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS SDL2_image::SDL2_image )
list(APPEND _IMPORT_CHECK_FILES_FOR_SDL2_image::SDL2_image "${_IMPORT_PREFIX}/lib/libSDL2_image-2.0d.so.0.600.2" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
