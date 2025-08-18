add_library(MilesSoundSystem STATIC IMPORTED GLOBAL)

set_target_properties(MilesSoundSystem PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/extern/include"
    IMPORTED_LOCATION  "${CMAKE_CURRENT_LIST_DIR}/mss64.lib"
)
