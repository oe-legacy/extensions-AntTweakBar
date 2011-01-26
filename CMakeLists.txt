IF(NOT MINGW)
	# Create the extension library
	INCLUDE_DIRECTORIES("AntTweakBar/include")

	SUBDIRS("AntTweakBar")

	# IF(APPLE)
	# SET(ANT_SOURCES ${ANT_SOURCES} AntTweakBar/src/AppleCursor.m)
	# ENDIF(APPLE)

	#  Devices/AntSDLInput.cpp
	# Display/AntTweakBarModule.cpp
ENDIF(NOT MINGW)
ADD_LIBRARY(Extensions_AntTweakBar  
	Display/AntTweakBar.h
	Display/AntTweakBar.cpp
  	Display/ITweakBar.h
  	Display/ITweakBar.cpp
  	Utils/TweakItem.h
  	Utils/TweakItem.cpp
  	Utils/TweakBar.h
  	Utils/TweakBar.cpp
  	Utils/TweakGroup.h
  	Utils/TweakGroup.cpp
  	Utils/TweakVar.h
  	Utils/TweakVar.cpp
)

IF(NOT MINGW)
	TARGET_LINK_LIBRARIES(Extensions_AntTweakBar AntTweakBar )
ELSE(NOT MINGW)
	TARGET_LINK_LIBRARIES(Extensions_AntTweakBar AntTweakBar
		${AntTweakBar_LIBRARY}
	)
ENDIF(NOT MINGW)
