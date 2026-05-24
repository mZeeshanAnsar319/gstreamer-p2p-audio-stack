add_executable(example_alsa_capture
    alsa_capture_main.cpp
)

target_link_libraries(example_alsa_capture
    PRIVATE
        audio_stack::gstreamer_p2p_audio
)
