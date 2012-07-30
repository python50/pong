--
--tile object implimented in lua
--

require "math";
dofile("keymap.lua");

--- Must have these varibles
x=0;
y=0;
z=0;
image_name="ship1";
delete_this=0;
persistant=0;
no_collide=1;
id_type="lua_tile";

--- Other varibles
speed=2;

function init ()--, z, image_name, blank)
    printl("hi from lua\n");
end

-- 2 | 1
-- -- --
-- 3 | 0

function move( dir, speed )

	if     dir==0 then
		x=x+1;
		printl("Right\n");
	elseif dir==1 then
		y=y-1;
		printl("Down\n");
	elseif dir==2 then
		x=x-1;
		printl("Left\n");
	elseif dir==3 then
		y=y+1;
		printl("Up\n");
	end
end

function keyboard()

	if (get_keyboard(keytable["K_a"])==1) then
		move(1,speed);
		--return;
	end

	if (get_keyboard(keytable["K_UP"])==1) then
		move(1,speed);
		--return;
	end

	if (get_keyboard(keytable["K_RIGHT"])==1) then
		move(0,speed);
		--return;
	end

	if (get_keyboard(keytable["K_DOWN"])==1) then
		move(3,speed);
		--return;
	end

	if (get_keyboard(keytable["K_LEFT"])==1) then
		move(2,speed);
		--return;
	end
end

function update()
	keyboard();
	blit(x,y,"ship1",0);
end
