--startup.lua
--Startup script for the game engine, allows for some flexibility with resource management

--require'lfs' --TODO LFS directory search loading

--- Surface ---

load_surface("data/image/paddle.png" ,"paddle");
load_surface("data/image/ball.png" ,"ball");
load_surface("data/image/line.png","line");

load_surface("data/image/cursor-48.png","cursor-48");

load_surface("data/image/background/splash.png","background-splash");
load_surface("data/image/background/circuit.png","background-circuit");

--- Sound ---

load_sound("data/sound/beep0.ogg","beep0");
load_sound("data/sound/beep1.ogg","beep1");
load_sound("data/sound/beep1_short.ogg","beep1_short");
load_sound("data/sound/thud_0.ogg","thud_0");
load_sound("data/sound/menu_ding.ogg","menu_ding");

--- Music ---
--load_music("data/music/sweetdream.ogg","startup");
  load_music("data/music/lime.ogg","startup");
load_music("data/music/ramon.ogg","game_play_1");
load_music("data/music/djc_e2p.ogg","game_play");
load_music("data/music/canon_pour_deux.ogg","game_play_2");
load_music("data/music/lime.ogg","game_play_3");
load_music("data/music/buss.ogg","game_over");
--- Font ---

--Jura
load_font("data/font/jura/JuraMedium.ttf","jura_medium-8",8);
load_font("data/font/jura/JuraMedium.ttf","jura_medium-12",12);
load_font("data/font/jura/JuraMedium.ttf","jura_medium-18",18);
load_font("data/font/jura/JuraMedium.ttf","jura_medium-24",24);
load_font("data/font/jura/JuraMedium.ttf","jura_medium-28",28);
load_font("data/font/jura/JuraDemiBold.ttf","jura_bold-34",34);
load_font("data/font/jura/JuraDemiBold.ttf","jura_bold-48",48);
---
