#include "include/gstreamer/GstUtils.hpp"

#include <stdexcept>

namespace audio {

GstElement* GstUtils::makeElement(
    const std::string& factory,
    const std::string& name)
{
    auto* element = gst_element_factory_make(
        factory.c_str(),
        name.c_str());

    if (!element) {
        throw std::runtime_error(
            "Failed to create GStreamer element: " + factory);
    }

    return element;
}

}