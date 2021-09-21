#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>

class Timer
{
    public:
        Timer();
        ~Timer();
        void start();
        void pause();
        void stop();
        void unpause();

        Uint32 getTicks();

        bool isStarted();
        bool isPaused();

    protected:

    private:

        Uint32 m_startTicks;
        Uint32 m_pausedTicks;

        bool m_paused;
        bool m_started;


};

#endif // TIMER_H
