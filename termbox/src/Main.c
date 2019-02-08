#include <stdio.h>
#include "termbox.h"

#ifndef CPPUTEST

int main(int argc, char *argv[])
{
    if(tb_init())
    {
        tb_select_input_mode(TB_INPUT_ESC);
        tb_select_output_mode(TB_OUTPUT_NORMAL);
        tb_clear();
    }

    tb_change_cell(0, 0, 'H', TB_BLACK, TB_WHITE);
    tb_change_cell(1, 0, 'E', TB_BLACK, TB_WHITE);
    tb_change_cell(2, 0, 'L', TB_BLACK, TB_WHITE);
    tb_change_cell(3, 0, 'L', TB_BLACK, TB_WHITE);
    tb_change_cell(4, 0, 'O', TB_BLACK, TB_WHITE);

    tb_present();

    
    while(1) 
    {
        struct tb_event ev;
        tb_poll_event(&ev);
        if (ev.key == TB_KEY_ESC) 
        {
            tb_shutdown();
            return 0;
        }
    }
}

#endif