# Implementation files are discovered automatically as the tree grows.
file(GLOB_RECURSE AUDIO_STACK_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

target_sources(gstreamer_p2p_audio
    PRIVATE
        ${AUDIO_STACK_SOURCES}
)

target_link_libraries(gstreamer_p2p_audio
    PUBLIC
        PkgConfig::GSTREAMER
)

target_compile_options(gstreamer_p2p_audio
    PRIVATE
        $<$<CONFIG:Debug>:-g -O0>
        $<$<CONFIG:Release>:-O3 -DNDEBUG>
        $<$<CONFIG:RelWithDebInfo>:-O2 -g -DNDEBUG>
)
