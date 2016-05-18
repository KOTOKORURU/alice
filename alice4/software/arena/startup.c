#include <gl.h>
#include <device.h>
#include "arena.h"

#define INTRO 40

char *intro[INTRO] = {
"",
"				ARENA",
"",
"",
"",
"It is the year 2053.  The corporate wars are over, and the once great",
"corporate empires lie in ruin.  Man though, never tired of violence, has",
"changed the war machines of the past into todays sport.  MECHS, fourteen",
"foot tall humanoid fighting machines, and their pilots battle it out in",
"the arenas.",
"",
"Arena simulates this possible future sport.",
"",
"The robots or mechs are effectively fast maneuverable tanks.  They have",
"rollers on their feet and thus skate along the ground.  A computerized",
"balance system keeps them on their feet.  Systems include telescopic vision,",
"radar, jump jets, and a 40mm autocannon.  Instrumentation is displayed on",
"a heads-up display.",
"",
"The playing field is square and approximately one kilometer on a side.  There",
"is a maze in the center of the arena with entrances north and south",
"",
"Use -n option to play over the network.",
"",
"Commands",
"",
"z/Z - optics zoom in (telescopic) / zoom out (wide angle)",
"x/X - zoom in radar / zoom out radar",
"e   - fire cannon",
"s   - jump",
"c   - toggle visual tilt stabalizer",
"",
"mouse",
"",
"left mouse   - stop turn",
"middle mouse - brake",
"mouse x      - adjust turn",
"mouse y      - adjust throttle",
"",
"Hit any key to continue."};


startup()
{
    int i;

    color(BLUE);
    clear();

    color(WHITE);
    for (i=0; i<INTRO; i++)
    {
	cmov2i(30, (YMAXSCREEN-30) - i*18);
	charstr(intro[i]);
    }

    qdevice(KEYBD);

    if (network)
        init_comm();
    else
    {
	id = 0;
	player[0].id = 0;
	player[0].type = PLAYER;
    }

    shot = shots[id];

    while (qread(&i) != KEYBD)
	if (network)
	    send_death();

    unqdevice(KEYBD);
}
