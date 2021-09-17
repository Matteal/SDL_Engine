#include "MusicManager.h"
#include <iostream>

MusicManager::MusicManager()
{
    loadMusic("main_theme.wav");
    onMute = false;
    m_volume = 128;
}

MusicManager::~MusicManager()
{
    //dtor
}

void MusicManager::loadMusic(const std::string &path)
{
    std::string name = path.substr(path.find_last_of('/')+1);
    name = name.substr(0,name.find('.'));

    m_musicMap[name] = Mix_LoadMUS((DATA_PATH + path).c_str());
}

/*void MusicManager::loadSoundEffect(const std::string &path)
{
    std::string name = path.substr(path.find_last_of('/')+1);
    name = name.substr(0,name.find('.'));

    m_soundMap[name] =
}*/

bool MusicManager::playMusic(const std::string music)
{
    if (!isPlaying())
    {
        Mix_PlayMusic(m_musicMap[music],-1);
        return true;
    }
    std::cout << "An error occured to play " << music << std::endl;
    return false;
}

void MusicManager::pauseMusic()
{
    if (!isPaused())
    {
        Mix_PausedMusic();
    }
}

void MusicManager::resumeMusic()
{
    if (isPaused())
    {
        Mix_ResumeMusic();
    }
}

bool MusicManager::isPlaying()
{
    if(Mix_PlayingMusic() == 0)
    {
        return false; // No music is played
    }
    return true;
}

bool MusicManager::isPaused()
{
    if(Mix_PausedMusic() == 1)
    {
        return true; // A music is paused
    }
    return false;
}

//Volume

void MusicManager::mute()
{
    if (onMute)
    {
        Mix_VolumeMusic(m_volume);
        std::cout << Mix_VolumeMusic(-1) << std::endl;
        onMute = false;
    }
    else
    {
        m_volume = Mix_VolumeMusic(-1);
        Mix_VolumeMusic(0);
        onMute = true;
    }
}

void MusicManager::lowerVolume()
{
    if(Mix_VolumeMusic(-1) != 0)
    {
        m_volume-=2;
        Mix_VolumeMusic(m_volume);
        std::cout << Mix_VolumeMusic(-1) << std::endl;
    }
}

void MusicManager::increaseVolume()
{
    if(Mix_VolumeMusic(-1) != 128)
    {
        m_volume+=2;
        Mix_VolumeMusic(m_volume);
        std::cout << Mix_VolumeMusic(-1) << std::endl;
    }
}


