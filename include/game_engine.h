/**
 * @file
 * @author  Jason White <whitewaterssoftwareinfo@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 *
 * @section DESCRIPTION
 *
 * This file contains the definition of the entire game engine class
 */


#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

/*
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}*/

using namespace std;

#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "game_engine_datatypes.h"
#include "controller.h"
#include "vector"

#define BLIT_ERROR (0x01)
#define BLIT_DYNAMIC (0x02)
#define BLIT_ABSOLUTE (0x04)
#define BLIT_FREE (0x08)

enum engine_state
{
    RUNNING=1,
    UNINITED=0,
    ERRORS=-1
};

enum textquality
{
    solid,
    shaded,
    blended
};



enum game_state { GAME_START, GAME_PLAYING, GAME_PAUSED, GAME_WIN0, GAME_WIN1 };

struct video_information
{
    SDL_Surface * screen;
    float view_x;
    float view_y;
    int width;
    int height;
    int target_width;
    int target_height;
    SDL_PixelFormat * format;
    bool full_screen;
    bool double_buffer;

    video_information()
    {
        screen=0;
        view_x=0;
        view_y=0;
        width=0;
        height=0;
        target_width=0;
        target_height=0;
        format=0;
        full_screen=0;
        double_buffer=0;
    }
};

struct sound_information
{
    unsigned char   sample_volume;
    unsigned char   stream_volume;
    unsigned int    sample_rate;
    char            channels;
    unsigned int    buffer_size;

    sound_information()
    {
        sample_volume=50;
        stream_volume=50;
        sample_rate=44100;
        channels=2;
        buffer_size=1024;
    }
};

struct gameplay_information
{
    int player0_score;
    int player1_score;
    int score_limit;
    bool pause;
    int counter;
    game_state state;

    gameplay_information()
    {
        player0_score=0;
        player1_score=0;
        counter=0;
        pause=0;
        state=GAME_START;
    }
};

struct map_information
{
    float scale;
    int scale_width;
    int scale_height;
    int abs_width;
    int abs_height;

    map_information()
    {
        scale=0;
        scale_width=0;
        scale_height=0;
        abs_width=0;
        abs_height=0;
    }
};

/** The game engine class, the interface logic inbetween SDL and the game code.**/

class game_engine
{
    /* Note: All function groupings should be split up into their respective files*/

    public:

        game_engine();

        bool load(int width,int height, bool cursor=0 );

        void quit();
        bool update();
        bool event();

        virtual ~game_engine();

        // ==== Game Play ====
        // Game Play Services eg. Reset

            void game_score(int player_number, int points);
            int  game_get_score_limit();
            void game_set_score_limit();
            game_state game_get_state();
            void game_init();
            void game_logic();

            int game_get_width();
            int game_get_height();
            int game_get_abswidth();
            int game_get_absheight();
            int game_get_scale();

            void game_set_map_information(map_information * info);


        // ==== Resources ====
        // Minipulation of game engine resources

            // ==== Object Management ====
            // Miniulate Objects

                controller * add_object(controller * cont);
                controller * get_object(std::string id);
                void clear_objects();
                bool remove_object(std::string id);
                bool remove_object(controller * cont);

            // ==== load resource ====
            // adds resources to the engine from `file`, returns NULL upon failure ie. missing file
                int load_font(std::string file, const char * id, int ptsize);
                int load_surface(std::string file, const char * id);
                int load_music(std::string file, const char * id);
                int load_sound(std::string file, const char * id);

            // ==== get resource ====
            // seaches for resorce and returns it, returns NULL if not found

                wwsige_surface * get_surface(std::string id);
                wwsige_music * get_music(std::string id);
                wwsige_sound * get_sound(std::string id);
                wwsige_font * get_font(std::string id);

            // ==== Map ====
            // Loading, Saving, etc of game maps

                bool load_map(std::string);

        // ==== Misc ====
        // Random Stuff

            double scale_value(double val);

        // ==== Joystick ====
        // Joystick Management

            void joystick_init();
            int joystick_number_present();
            SDL_Joystick *joystick_get(unsigned int number);

        // ==== Sound/Music ====
        // Sound Management

            void sound_stop();
            void music_stop();

            void sound_set_volume(int vol);
            void music_set_volume(int vol);

            void music_pause();
            void sound_pause();

            void music_unpause();
            void sound_unpause();

            bool music_play(std::string id,int loop=0);
            bool sound_play(std::string id, int loop=0);

            bool music_get_playing();
            bool sound_get_playing();

            bool music_get_paused();
            bool sound_get_paused();

        /* ==== Drawing ==== */
        // Rendering and other functions

            void blit( float x, float y, wwsige_surface* source, char flags=BLIT_DYNAMIC);
            wwsige_surface * render_text(std::string font, std::string texts, wwsige_color foreground ,wwsige_color background  , textquality quality=solid);

            //TODO:
            // A nice wrapper for the draw text function, with newline support
            //struct text_color
            //{
            //  red, green, blue, alpha
            //  bg_red ,bg_green ,bg_blue ,bg_alpha
            //}
            //draw_text(float x, float y,string font,text_color color , quality qual)

        /* ==== View ==== */
        // modify the view

            SDL_Rect view_get();
            void view_set(SDL_Rect view);
            void view_reset();
            void view_translate(float x, float y);

        // ==== Collisions ====
        // Collision Checking

            //TODO:
            //rename rect_collide->collide_rect
            //rename rect_collide_all->collide_rect_all
            //  make rect collide all return a vector of colliding objects
            //add collide_circle
            //add collide_triangle
            //add collide_polygon

            bool rect_collide(SDL_Rect a , SDL_Rect b);
            controller * rect_collide_all(SDL_Rect rect,controller * selfp,std::string type);
    protected:
    private:
        void update_objects();
        bool load__initalize();
        void load__config();

        void game_logic_start();
        void game_logic_playing();
        void game_logic_pause();
        void game_logic_win0();
        void game_logic_win1();

        engine_state state;
        video_information video;
        sound_information sound;
        gameplay_information gameplay;
        map_information map;

        SDL_Event * engine_event;

        std::vector<controller*> control_data;
        std::vector<wwsige_surface*> surface_data;
        std::vector<wwsige_music*> music_data;
        std::vector<wwsige_sound*> sound_data;
        std::vector<wwsige_font*> font_data;
        vector<SDL_Joystick*> joystick_vector;

        bool quit_;


        std::string map_name;
};

namespace game_eng
{
    extern game_engine * gm_engine;
}

#endif // GAME_ENGINE_H
