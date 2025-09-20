file(GLOB_RECURSE FILE_SOURCES "*.h" "*.c" "*.cpp")

add_executable(PackMaker ${FILE_SOURCES})
target_link_libraries(PackMaker 
	libzstd_static
	cryptopp-static
)
