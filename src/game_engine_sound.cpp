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
 * This file contains all game_engine functions related to sound playback.
 */


#include "game_engine.h"
#include "message_log.h"

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_rotozoom.h"

/**
 * Stop all sound chunks (Mix_Chunk) that are currently being played. Note: this function does not stop music streams.
**/
void game_engine::sound_stop()
{
    Mix_HaltChannel(-1);
}

/**
 * Stop all music streams (Mix_Music) that are currently being played. Note: this function does not stop sound chunks.
**/
void game_engine::music_stop()
{
    Mix_HaltMusic();
}

/**
 * Set master playback volume for sound chunks (Mix_Chunk).
 * @param vol The desired volume in percent (1-100)
**/
void game_engine::sound_set_volume(int vol)
{
    if (vol < 0 or vol > 100)
    {
            vol=100;
            new message_log(MESSAGE_WARNING, "set_sound_volume: volume out of range");
    }

    if (vol==0)
    {
        Mix_Volume(-1, 0);
    }
    else
    {
        //unsigned char volume=(float)MIX_MAX_VOLUME*(vol/100);
        Mix_Volume(-1, vol*(MIX_MAX_VOLUME/100));
    }
}

/**
 * Set master playback volume for music streams (Mix_Music).
 * @param vol The desired volume in percent (1-100)
**/
void game_engine::music_set_volume(int vol)
{
    if (vol < 0 or vol > 100)
    {
        vol=100;
        new message_log(MESSAGE_WARNING, "set_music_volume: volume out of range");
    }

    if (vol==0)
    {
        sound.stream_volume=0;
        Mix_VolumeMusic(0);
    }
    else
    {
        printf("Value of volume is %d\n",vol*(MIX_MAX_VOLUME/100));
        Mix_VolumeMusic(vol*(MIX_MAX_VOLUME/100));
        sound.stream_volume=vol*(MIX_MAX_VOLUME/100);
    }
}

/**
 * Play a music stream (Mix_Music) with selectable looping.
 * @param id The string identifier of the desired music stream
 * @param loop The number of times to loop the music (-1 for infinite looping)
 * @return 0 on failure, 1 on success
**/
bool game_engine::music_play(std::string id,int loop)
{
    bool error_code=Mix_PlayMusic(get_music(id)->data,loop)+1; // return 0 on error, 1 otherwise

    if (error_code==0)
    {
        new message_log(MESSAGE_WARNING, "Play Music Error, id:`"+id+"`, `"+Mix_GetError()+"`");
        return 0;
    }

    Mix_VolumeMusic(sound.stream_volume);

    new message_log(MESSAGE_DEBUG2, "Play Music, id:`"+id+"`");

    return 1;
}


/**
 * Play a sound chunk (Mix_Chunk) with selectable looping.
 * @param id The string identifier of the desired sound chunk
 * @param loop The number of times to loop the sound (-1 for infinite looping)
 * @return 0 on failure, 1 on success
**/
bool game_engine::sound_play(std::string id,int loop)
{
    bool error_code= Mix_PlayChannel(-1,get_sound(id)->data,loop)+1;

    if (error_code==0)
    {
        new message_log(MESSAGE_WARNING, "Play Music: id:`"+id+"`, `"+Mix_GetError()+"`");
        return 0;
    }

    new message_log(MESSAGE_DEBUG2, "Play Sound: id:`"+id+"`");
    return 1;
}

void game_engine::music_pause()
{
    Mix_PauseMusic();
}

void game_engine::sound_pause()
{
    Mix_Pause(-1);
}

void game_engine::music_unpause()
{
    Mix_ResumeMusic();
}

void game_engine::sound_unpause()
{
    Mix_Resume(-1);
}


bool game_engine::music_get_playing()
{
    return Mix_PlayingMusic();
}

bool game_engine::sound_get_playing()
{
    return (Mix_Playing(-1) > 0); //return 1 if any number larger than 0 channels are playing
}


bool game_engine::music_get_paused()
{
    return Mix_PausedMusic();
}

bool game_engine::sound_get_paused()
{
    return (Mix_Paused(-1) > 0); //return 1 if any number larger than 0 channels are paused
}
