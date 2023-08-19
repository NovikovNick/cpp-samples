add_library (template_lib)
add_library (template::lib ALIAS template_lib)
target_compile_features(template_lib PUBLIC cxx_std_20)
target_sources(template_lib 
	INTERFACE 
		"templates.h"
	PRIVATE
		"templates.cc")
target_include_directories(template_lib 
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
	PRIVATE 
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/.>)