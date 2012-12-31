#include <common.h>
#include <asm/io.h>
#include <asm/arch/mem.h>
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-types.h>
#include <video_fb.h>

#include "omap3Lcd.h"

GraphicDevice glcd_dev;

static u16 lcd_static_mem[1024*1024]; 


void backlight(void)
{
	pad_write_reg(GPT11_MUX_OFFSET,0x14);
	gpio_write_reg(GPIO6_OE,(gpio_read_reg(GPIO6_OE))&(0xffffffff&(0<<21)));
	gpio_write_reg(GPIO6_DATAOUT,(gpio_read_reg(GPIO6_DATAOUT))|(1<<21));
}

int lcd_ctrl_init(void )
{
	u32 l = clkctrl_read_reg(CM_CLKSEL2_PLL);
	printf("CLKSEL2_PLL is %d\n",l);

	u32 m = clkctrl_read_reg(CM_CLKEN_PLL);
	printf("CM_CLLEN_PLL is %d\n",m);	
	m &= 0xffffff;	
	m |= (0x7 << 16);//|(0x0f<<20);
	clkctrl_write_reg(CM_CLKEN_PLL,m);
//	printf("CM_CLLEN_PLL is %d\n",m);

	dss_clk_write_reg(CM_CLKSEL_DSS,0x10009);


	dss_clk_write_reg(CM_FCLKEN_DSS, 5);
	dss_clk_write_reg(CM_ICLKEN_DSS, 1);
	dss_clk_write_reg(CM_AUTOIDLE_DSS, 0);
	dss_clk_write_reg(CM_SLEEPDEP_DSS,0);
	dss_clk_write_reg(CM_CLKSTCTRL_DSS,0);


	dss_write_reg(DSS_SYSCONFIG,0x0002);
	while(! dss_read_reg(DSS_SYSSTATUS));
	
	dispc_write_reg(DISPC_CONTROL, 0x00018308 );//change 18309 to 18109 for 24bit per pix
	dispc_write_reg(DISPC_SIZE_LCD, 0x01df027f);	//size:640*480
	dispc_write_reg(DISPC_CONFIG,0x4);
	dispc_write_reg(DISPC_TIMING_H, 0x0720101e);	//LCD Timing params
	dispc_write_reg(DISPC_TIMING_V, 0x02100a03);
	dispc_write_reg(DISPC_POL_FREQ, 0x7<<12);
	dispc_write_reg(DISPC_DIVISOR, 0x00010004);     //maybe need change


	dispc_write_reg(DISPC_GFX_SIZE, 0x01df027f);	
	dispc_write_reg(DISPC_GFX_FIFO_THRESHOLD, 0x03ff0300);
	dispc_write_reg(DISPC_GFX_ROW_INC, 0x01);
	dispc_write_reg(DISPC_GFX_PIXEL_INC, 0x01);


	memset(lcd_static_mem, 0x00, sizeof(lcd_static_mem));
	dispc_write_reg(DISPC_GFX_BA0, (unsigned int )lcd_static_mem);


//	dispc_write_reg(DISPC_GFX_BA0, LCD_STATIC_MEM);


	dispc_write_reg(DISPC_GFX_POSITION, 0);
	dispc_write_reg(DISPC_GFX_ATTRIBUTES, 0x02d);	//change for GFX configuration
	
	dispc_write_reg(DISPC_CONTROL, 0x00018329);
	
//	printf("color test\n");

	backlight();


	return 0;
}

void *video_hw_init (void)
{
    lcd_ctrl_init ();

    /* fill in Graphic Device */

   glcd_dev.frameAdrs = (u32)lcd_static_mem;
//	glcd_dev.frameAdrs = LCD_STATIC_MEM;	

    glcd_dev.winSizeX = 640;
    glcd_dev.winSizeY = 480;
    glcd_dev.gdfBytesPP = 2;
    glcd_dev.gdfIndex = GDF_16BIT_565RGB;
    return (void *) &glcd_dev;
}

void video_set_lut(unsigned int index,
            unsigned char r, unsigned char g, unsigned char b)
{
}


