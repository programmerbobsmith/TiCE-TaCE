#include <stdint.h>
#include <graphx.h>
#include <fileioc.h>
#include <stdbool.h>
#include <time.h>
#include <ti/getcsc.h>

//function prototypes
void x_draw(unsigned int x, unsigned int y);
void y_draw(unsigned int x, unsigned int y);
void board_draw(void);

int main()
{
	gfx_Begin();
	gfx_ZeroScreen();
	gfx_SetTextFGColor(254);
	gfx_SetColor(0);
	struct stuff
	{
		bool turn;
		unsigned int wins;
		unsigned int losses;
		unsigned int draws;
	}record;
	uint8_t appvar = ti_Open("TicTac","r+");
	if (appvar == 0)
	{
		appvar = ti_Open("TicTac","w");
		record.wins = record.losses = record.draws = 0;
		record.turn = false;
		ti_Write(&record,sizeof(struct stuff),1,appvar);
		ti_Rewind(appvar);
	}
	ti_Read(&record,sizeof(struct stuff),1,appvar);
	gfx_PrintStringXY("TIC     TAC     TOE",120,40);
	gfx_PrintStringXY("Your Record:   ",100,55);
	gfx_PrintInt(record.wins,1);
	gfx_PrintChar('-');
	gfx_PrintInt(record.losses,1);
	gfx_PrintChar('-');
	gfx_PrintInt(record.draws,1);
	gfx_PrintStringXY("Credits:",50,210);
	gfx_PrintStringXY("- Jonathan Khayat 'Bob Smith'",60,220);
	gfx_PrintStringXY("Copyright October 2022. All Rights Reserved.",10,230);
	unsigned int key;
	while(key = os_GetCSC(), key != sk_Enter)
    {
        if((clock() % CLOCKS_PER_SEC < CLOCKS_PER_SEC * 8 / 10))
		{
			gfx_SetColor(0);
        	gfx_FillRectangle(125,100,110,10);
        }else
		{
			gfx_SetColor(254);
        	gfx_PrintStringXY("[Enter] to Start",125,100);
        }
		if (key == sk_Clear)
		{
			gfx_End();
			return 0;
		}
    }
	gfx_ZeroScreen();
	board_draw();
	while(!os_GetCSC());
	gfx_End();
	return 0;
}

void board_draw(void)
{
	gfx_ZeroScreen();
	gfx_SetColor(254);
	gfx_VertLine(140,30,120);
	gfx_VertLine(180,30,120);
	gfx_HorizLine(100,70,120);
	gfx_HorizLine(100,110,120);
	gfx_PrintStringXY("[clear] - exit and lose the game.",35,230);
}
