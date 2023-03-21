add_library(c_lib)
add_library(sample::c_lib ALIAS c_lib)
target_compile_features(c_lib PUBLIC c_std_17)
target_sources(c_lib 
	INTERFACE 
		"sample.h"
	PRIVATE 
		"sample.c")
target_include_directories(c_lib 
	PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/.>)