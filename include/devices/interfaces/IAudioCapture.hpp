#pragma once

#include "IAudioDevice.hpp"

namespace audio {

class IAudioCapture : public IAudioDevice {
public:
    virtual void setLatency(int ms) = 0;
};

}