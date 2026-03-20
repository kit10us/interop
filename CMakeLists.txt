cmake_minimum_required (VERSION 3.29.0)

option(TESTS "Include unit tests" FALSE)
set(CMAKE_SUPPRESS_REGENERATION ON)

if(${CMAKE_CXX_COMPILER})
	message("CMAKE_CXX_COMPILER:" ${CMAKE_CXX_COMPILER})
else()
	message("CMAKE_CXX_COMPILER not set. Can impact project settings.")
endif()
message("")

include(cmakeutil/Functions.txt)

project(interop CXX)

function(GenerateMain)

	set(TARGET_NAME ${PROJECT_NAME})
	set(NAMESPACE "io")
	
	AddStandardCompileOptions(${TARGET_NAME})

	if(MSVC)
		#set(CMAKE_CONFIGURATION_TYPES 
		#	"DebugWindows;ReleaseWindows"
		#	CACHE STRING "" FORCE
		#)

		add_compile_definitions(
			_UNICODE
			UNICODE
			_LIB
		)
	endif()

	file (GLOB MAIN_SOURCES "${NAMESPACE}/*.h" "${NAMESPACE}/*.cpp" "${NAMESPACE}/*.inl")

	#add_compile_definitions(_DEBUG)
	
	add_library(${PROJECT_NAME} INTERFACE ${MAIN_SOURCES})
	

	if(MSVC)
		include_external_msproject(ResourceManager ${CMAKE_CURRENT_SOURCE_DIR}/../resourcemanager/ResourceManager.vcxproj)
		add_dependencies(${TARGET_NAME} ResourceManager)
		
		set_target_properties(${PROJECT_NAME} PROPERTIES 
			PREFIX ""
			SUFFIX ".lib"
		)
	endif()

	source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${MAIN_SOURCES})

	include_directories(.)
endfunction()

function(GenerateUnitTests)
endfunction()

GenerateMain()

#set_target_properties(ALL_BUILD ZERO_CHECK PROPERTIES
#	EXCLUDE_FROM_ALL 1
#)


if(${TESTS})
	message("Including unit tests...")
	GenerateUnitTests()
endif()