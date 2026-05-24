add_executable(audio_stack_smoke_test
    smoke_test.cpp
)

target_link_libraries(audio_stack_smoke_test
    PRIVATE
        audio_stack::gstreamer_p2p_audio
)

add_test(
    NAME audio_stack_smoke_test
    COMMAND audio_stack_smoke_test
)
