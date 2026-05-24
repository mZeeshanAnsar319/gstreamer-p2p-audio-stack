#pragma once

#include <gst/gst.h>
#include <string>

namespace audio {

class GstUtils {
public:
    static GstElement* makeElement(
        const std::string& factory,
        const std::string& name);
};

}