#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#define DATA_PATH "data/"

#include <SDL_mixer.h>

#include <string>
#include <map>



class MusicManager
{
    public:
        MusicManager();
        ~MusicManager();

        void loadMusic(const std::string &path);
        void loadSoundEffect(const std::string &path);

        bool playMusic(const std::string music, int loop);
        bool playSoundEffect(const std::string sound, int loop);
        void pauseMusic();

        void resumeMusic();
        bool isPlaying();
        bool isPaused();
        int getVolume();
        void setMusicVolume(int zeroTo128);
        void setSfxVolume(int zeroTo128);


        void mute();
        void lowerVolume();
        void increaseVolume();

        Mix_Music* operator[](const std::string);

    protected:

    private:
        std::map<std::string, Mix_Music*> m_musicMap;
        std::map<std::string, Mix_Chunk*> m_soundMap;
        bool onMute;
        int m_volume;
};

#endif // MUSICMANAGER_H
