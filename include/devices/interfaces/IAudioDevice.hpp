#pragma once

#include <gst/gst.h>

namespace audio {

class IAudioDevice {
public:
    virtual ~IAudioDevice() = default;

    virtual GstElement* createElement() = 0;
};

}