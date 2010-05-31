
# Create the extension library
INCLUDE_DIRECTORIES("AntTweakBar/include")

SUBDIRS("AntTweakBar")

# IF(APPLE)
# SET(ANT_SOURCES ${ANT_SOURCES} AntTweakBar/src/AppleCursor.m)
# ENDIF(APPLE)

#  Devices/AntSDLInput.cpp
# Display/AntTweakBarModule.cpp
ADD_LIBRARY(Extensions_AntTweakBar  
  Display/AntTweakBar.h
  Display/AntTweakBar.cpp
//  ${ANT_SOURCES}

)



TARGET_LINK_LIBRARIES(Extensions_AntTweakBar AntTweakBar )
