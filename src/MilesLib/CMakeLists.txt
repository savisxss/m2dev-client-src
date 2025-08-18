file(GLOB_RECURSE FILE_SOURCES "*.h" "*.c" "*.cpp")

add_library(MilesLib STATIC ${FILE_SOURCES})

target_link_libraries(MilesLib 
	lzo2
)

GroupSourcesByFolder(MilesLib)
