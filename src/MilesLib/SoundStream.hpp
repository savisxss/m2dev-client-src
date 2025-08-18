#pragma once

#include <mss.h>

class SoundStream
{
public:
    SoundStream(HSTREAM stream);
    ~SoundStream();

    SoundStream(const SoundStream&) = delete;
    void operator=(const SoundStream&) = delete;

    void Play(int loopCount = 1) const;
    void Pause() const;
    void Resume() const;
    void Stop();
    float GetVolume() const;
    void SetVolume(float volume) const;
    bool IsDone() const;

private:
    HSTREAM m_stream;
};

