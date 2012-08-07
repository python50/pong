--config.lua
--Note: use `1` or `0` not `true` or `false`

--Standard resolutions:
--  640x480
--
--Note: there may be some scaling problems with higher resolutions.
--with non 4:3 ratio resolutions
--
--Do not choose a size smaller then 640x480, things break badly !

screen_width=640;
screen_height=480;

fullscreen=1;	--1= Fullscreen, hardware acceleration (Fast !)
		--0= Windowed, software only (Slow !)

double_buffer=0; --Prevents graphical tearing, Slows down program drawing.
		 --If you lack a proper graphics card then choose 0, else 1
		 --If its too slow after that, theres nothing you can do ...

--Volume: Between 0% and 100%,recommended 50%
sound_volume=75;
music_volume=75;

--input_mode
--  0 keyboard
--  1 joystick
--  2 both
input_mode=2

