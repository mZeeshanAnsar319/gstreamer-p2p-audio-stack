#include <gst/gst.h>

#include "include/devices/alsa/AlsaCaptureDevice.hpp"

int main(int argc, char* argv[])
{
    gst_init(&argc, &argv);

    audio::AudioDevConfig config;
    config.sampleRate = 48000;
    config.channels = 2;
    config.deviceName = (argc > 1) ? argv[1] : "default";

    audio::AlsaCaptureDevice capture(config);
    capture.setLatency(20);

    GstElement* element = capture.createElement();
    if (element) {
        g_print("Created ALSA capture element for device: %s\n",
                config.deviceName.c_str());
        gst_object_unref(element);
    }

    return 0;
}
