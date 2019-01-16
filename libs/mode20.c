#include "libs.h"
#include "main.h"
#include "mode20.h"


static char time_data_arr[9]={03,04,05,06,07,08,09,10,\0};
static int i = 0;
static int j = 1;

void do_mode20(UI_DATA* ud){

lcd_clear();
lcd_putstr(0,0,"->");
lcd_putstr(2,0,time_data_arr[i]);
lcd_putstr(4,0,"ﾌﾝﾀｲﾏｰ");
lcd_putstr(2,1,time_data_arr[j]);
lcd_putstr(4,1,"ﾌﾝﾀｲﾏｰ");


switch(ud->sw){

case KEY_SHORT_U:
     i=i+1;
     j=j+1;
     if(i>8){
	i=0;
     }
     if(j>8){
	j=0;
     }
     break;

case KEY_SHORT_D:
     i=i-1;
     j=j-1;
     if(i<0){
	i=8;
     }
     if(j<0){
	j=8;
     }
     break;

case KEY_LONG_R:
     ud->mode=MODE_20+i;/*次は，モード変更*/
     break;

case KEY_LONG_C: /* 中央キーの長押し */
    lcd_cursor(FALSE);
    lcd_blink(FALSE);
    ud->mode=MODE_0; /* メニューに移動 */
    break;


default:
 break;


}
}
	
