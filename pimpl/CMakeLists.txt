add_library(pimpl)
add_library(sample::pimpl ALIAS pimpl)
target_compile_features(pimpl PUBLIC cxx_std_20)
target_sources(pimpl 
	INTERFACE 
		"public/facade.h"
	PRIVATE 
		"public/controller.h"
		"public/service.h"
		"public/repository.h"
		"private/facade.cc"
		"private/controller.cc"
		"private/service.cc"
		"private/repository.cc"
)
target_include_directories(pimpl 
	PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/public>)