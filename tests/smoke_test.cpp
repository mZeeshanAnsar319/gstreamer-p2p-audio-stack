#include <gst/gst.h>

#include "include/gstreamer/GstUtils.hpp"

int main()
{
    gst_init(nullptr, nullptr);

    GstElement* element = audio::GstUtils::makeElement("fakesrc", "smoke_test_src");
    gst_object_unref(element);

    return 0;
}
