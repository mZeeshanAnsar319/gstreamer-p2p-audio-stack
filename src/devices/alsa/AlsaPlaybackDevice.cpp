#include "devices/alsa/AlsaPlaybackDevice.hpp"
#include "gstreamer/GstUtils.hpp"

namespace audio {

AlsaPlaybackDevice::AlsaPlaybackDevice(
    const AudioDevConfig& config)
    : m_config(config)
{
}

GstElement* AlsaPlaybackDevice::createElement()
{
    auto* sink = GstUtils::makeElement(
        "alsasink",
        "alsa_playback");

    g_object_set(
        G_OBJECT(sink),
        "device",
        m_config.deviceName.c_str(),
        nullptr);

    return sink;
}

void AlsaPlaybackDevice::setVolume(double volume)
{
    m_volume = volume;
}

}