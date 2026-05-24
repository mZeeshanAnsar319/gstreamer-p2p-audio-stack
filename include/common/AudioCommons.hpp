#pragma once

#include <string>

namespace audio {

enum class AudioBackend {
    ALSA,
    PULSE,
    PIPEWIRE
};

struct AudioCaptureConfig {
    int sampleRate = 48000;
    int channels = 2;
    std::string deviceName;
};

}