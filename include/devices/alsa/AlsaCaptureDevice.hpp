#pragma once

#include "include/devices/interfaces/IAudioCapture.hpp"
#include "include/common/AudioCommons.hpp"

namespace audio {

class AlsaCaptureDevice : public IAudioCapture {
public:
    explicit AlsaCaptureDevice(const AudioCaptureConfig& config);

    GstElement* createElement() override;

    void setLatency(int ms) override;

private:
    AudioCaptureConfig m_config;
    int m_latencyMs = 20;
};

}