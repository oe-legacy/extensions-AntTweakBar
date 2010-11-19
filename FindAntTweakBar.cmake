# - Try to find AntTweakBar
# Once done this will define
#
#  AntTweakBar_FOUND - system has AntTweakBar
#  AntTweakBar_INCLUDE_DIR - the AntTweakBar include directory
#  AntTweakBar_LIBRARIES - Link these to use AntTweakBar
#

FIND_PATH(AntTweakBar_INCLUDE_DIR NAMES AntTweakBar.h
  PATHS
  ${PROJECT_BINARY_DIR}/include
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/libraries/AntTweakBar/include
  NO_DEFAULT_PATH
)

FIND_LIBRARY(AntTweakBar_LIBRARY NAMES
  AntTweakBar
  PATHS
  ${PROJECT_BINARY_DIR}/lib
  ${PROJECT_SOURCE_DIR}/lib
  ${PROJECT_SOURCE_DIR}/libraries/AntTweakBar/lib
  NO_DEFAULT_PATH
)

IF(AntTweakBar_INCLUDE_DIR AND AntTweakBar_LIBRARY)
   SET(AntTweakBar_FOUND TRUE)
ENDIF(AntTweakBar_INCLUDE_DIR AND AntTweakBar_LIBRARY)

# show the GLEW_INCLUDE_DIR and GLEW_LIBRARIES variables only in the advanced view
IF(AntTweakBar_FOUND)
  MARK_AS_ADVANCED(AntTweakBar_INCLUDE_DIR AntTweakBar_LIBRARIES)
  INCLUDE_DIRECTORIES(${AntTweakBar_INCLUDE_DIR})
ELSE (AntTweakBar_FOUND)
	MESSAGE ("WARNING: Could not find AntTweakBar - depending targets will be disabled.")
  SET(OE_MISSING_LIBS "${OE_MISSING_LIBS}, pThread")
ENDIF(AntTweakBar_FOUND)
