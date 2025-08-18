#pragma once

#include <string_view>
#include "SoundStream.hpp"
#include <mss.h>

enum MusicState
{
    MUSIC_STATE_OFF,
    MUSIC_STATE_PLAY,
    MUSIC_STATE_FADE_IN,
    MUSIC_STATE_FADE_OUT,
    MUSIC_STATE_FADE_LIMIT_OUT,
};

// TODO(tim): make members private?
struct MusicInstance
{
    MusicInstance(HSTREAM stream, std::string_view filename,
                  float fVolume, float fVolumeSpeed);

    bool Update(float musicVolume);

    MusicState MusicState;
    float fVolume;
    float fLimitVolume;
    float fVolumeSpeed;
    std::string filename;
    SoundStream stream;
};
