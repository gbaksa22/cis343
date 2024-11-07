// AudioManager.hpp

#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <SDL2/SDL.h>
#include <string>

class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    bool initialize();
    bool loadWAV(const std::string& filename);
    void play();
    void stop();
    void cleanup();

private:
    SDL_AudioSpec wavSpec;
    Uint8* wavBuffer;
    Uint32 wavLength;
};

#endif // AUDIOMANAGER_HPP
