#pragma once

#include "IAudioDevice.hpp"

namespace audio {

class IAudioPlayback : public IAudioDevice {
public:
    virtual void setVolume(double volume) = 0;
};

}