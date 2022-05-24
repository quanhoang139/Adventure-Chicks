#ifndef TIMER_H_
#define TIMER_H_

#include <SDL.h>

class Timer {
    private:
        int start_tick_;
        int pause_tick_;

        bool is_paused_;
        bool is_started_;
    public:
        Timer();
        ~Timer();

        void start();
        void stop();
        void paused();
        void unpaused();

        int get_ticks();
        bool is_started();
        bool is_paused();
};

#endif // TIMER_H_
