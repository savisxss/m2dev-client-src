#pragma once
#include "SampleFile.hpp"
#include <mss.h>

class SoundSample
{
public:
    SoundSample(HSAMPLE sample);
    SoundSample(SoundSample &&other);
    SoundSample(const SoundSample &other) = delete;
    ~SoundSample();

    SoundSample &operator=(SoundSample &&other);
    SoundSample &operator=(const SoundSample &other) = delete;

    bool SetFile(SampleFilePtr sample);

    void Play(int loopCount = 1) const;
    void Pause() const;
    void Resume() const;
    void Stop() const;
    float GetVolume() const;
    void SetVolume(float volume) const;
    bool IsDone() const;

    void SetPosition(float x, float y, float z) const;
    void SetVelocity(float fx, float fy, float fz, float fMagnitude) const;

    void UpdatePosition(float fElapsedTime);

private:
    HSAMPLE m_sample;
    SampleFilePtr m_sampleFile;
};

