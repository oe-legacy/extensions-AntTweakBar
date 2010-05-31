
# Create the extension library
INCLUDE_DIRECTORIES("AntTweakBar/include")
# ADD_DEFINITIONS(-D_MACOSX )

SET( ANT_SOURCES
  AntTweakBar/include/AntTweakBar.h
  AntTweakBar/src/TwPrecomp.cpp
  AntTweakBar/src/TwMgr.cpp
  AntTweakBar/src/TwFonts.cpp
  AntTweakBar/src/TwBar.cpp
  AntTweakBar/src/TwColors.cpp
  AntTweakBar/src/TwOpenGL.cpp
  AntTweakBar/src/TwEventSDL.c
  AntTweakBar/src/LoadOGL.cpp
)

IF(APPLE)
SET(ANT_SOURCES ${ANT_SOURCES} AntTweakBar/src/AppleCursor.m)
ENDIF(APPLE)

#  Devices/AntSDLInput.cpp
# Display/AntTweakBarModule.cpp
ADD_LIBRARY(Extensions_AntTweakBar  
  Display/AntTweakBar.h
  Display/AntTweakBar.cpp
  ${ANT_SOURCES}

)



TARGET_LINK_LIBRARIES(Extensions_AntTweakBar )
