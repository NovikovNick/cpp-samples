add_library (sample_dll SHARED)
add_library (sample::dll ALIAS sample_dll)
target_compile_features(sample_dll PUBLIC cxx_std_20)
target_sources(sample_dll 
	INTERFACE 
		"sample_dll.h"
	PRIVATE
		"sample_dll.cc")
target_include_directories(sample_dll 
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
	PRIVATE 
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/.>)
set_property(TARGET sample_dll PROPERTY
		MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")