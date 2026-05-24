#pragma once

#include "devices/interfaces/IAudioPlayback.hpp"
#include "include/common/AudioCommons.hpp"

namespace audio {

class AlsaPlaybackDevice : public IAudioPlayback {
public:
    explicit AlsaPlaybackDevice(const AudioDevConfig& config);

    GstElement* createElement() override;

    void setVolume(double volume) override;

private:
    AudioDevConfig m_config;
    double m_volume = 1.0;
};

}