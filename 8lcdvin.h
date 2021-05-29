#ifndef _lcd_H
#define _lcd_H
void lcd_init();
void cmd_write(char);
void data_write(char);
void lcd_clear();
void lcd_Gotolineone();
void lcd_Gotolinetwo();
void lcd_displaystring(char *);
void lcd_displaynumberr(unsigned char);

#endif