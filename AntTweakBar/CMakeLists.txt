IF(APPLE)
ADD_DEFINITIONS(-D_MACOSX -ObjC++)
ELSE(APPLE)
ADD_DEFINITIONS(-D_UNIX)
ENDIF(APPLE)


SET( ANT_SOURCES
  include/AntTweakBar.h
  src/TwPrecomp.cpp
  src/TwMgr.cpp
  src/TwFonts.cpp
  src/TwBar.cpp
  src/TwColors.cpp
  src/TwOpenGL.cpp
  src/TwEventSDL.c
  src/LoadOGL.cpp
)

ADD_LIBRARY(AntTweakBar
  ${ANT_SOURCES}
)
