#include "include/devices/alsa/AlsaCaptureDevice.hpp"
#include "include/gstreamer/GstUtils.hpp"

namespace audio {

AlsaCaptureDevice::AlsaCaptureDevice(
    const AudioCaptureConfig& config)
    : m_config(config)
{
}

GstElement* AlsaCaptureDevice::createElement()
{
    auto* src = GstUtils::makeElement(
        "alsasrc",
        "alsa_capture");

    g_object_set(
        G_OBJECT(src),
        "device",
        m_config.deviceName.c_str(),
        nullptr);

    g_object_set(
        G_OBJECT(src),
        "latency-time",
        m_latencyMs * 1000,
        nullptr);

    return src;
}

void AlsaCaptureDevice::setLatency(int ms)
{
    m_latencyMs = ms;
}

}