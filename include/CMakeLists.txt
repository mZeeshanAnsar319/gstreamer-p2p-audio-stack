# Public headers are discovered automatically as the tree grows.
file(GLOB_RECURSE AUDIO_STACK_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

add_library(gstreamer_p2p_audio ${AUDIO_STACK_LIB_TYPE})

target_include_directories(gstreamer_p2p_audio
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/devices/interfaces>
        $<INSTALL_INTERFACE:include>
)

# Track headers for IDEs and future install rules; no separate compile step.
target_sources(gstreamer_p2p_audio
    PRIVATE
        ${AUDIO_STACK_HEADERS}
)

if(AUDIO_STACK_BUILD_SHARED)
    set_target_properties(gstreamer_p2p_audio PROPERTIES
        POSITION_INDEPENDENT_CODE ON
    )
endif()

add_library(audio_stack::gstreamer_p2p_audio ALIAS gstreamer_p2p_audio)
