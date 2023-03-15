add_library(sml INTERFACE)
add_library (boost_ext::sml ALIAS sml)
target_include_directories(sml INTERFACE boost)
install(FILES
  boost/sml.hpp
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/boost)