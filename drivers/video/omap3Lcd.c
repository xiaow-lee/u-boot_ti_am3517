#include <common.h>
#include <asm/io.h>
#include <asm/arch/mem.h>
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-types.h>
#include <video_fb.h>

#include "omap3Lcd.h"

GraphicDevice glcd_dev;
 
u16 lcd_static_mem[640*640];

#define	Screen_Width	640
#define	Width		640
#define Height		480
#define	Pixel_Size	2

void backlight(void)
{
	//set PK_OFF high
	pad_write_reg(PKOFF_MUX_OFFSET,0x14);
	gpio_write_reg(GPIO5_OE,(gpio_read_reg(GPIO5_OE))&(0xffffffff&(0<<12)));
	gpio_write_reg(GPIO5_DATAOUT,(gpio_read_reg(GPIO5_DATAOUT))|(1<<12));

	//set PWM_OUT high
	pad_write_reg(GPT11_MUX_OFFSET,0x10c0014);
	gpio_write_reg(GPIO6_OE,(gpio_read_reg(GPIO6_OE))&(0xffffffff&(0<<21)));
	gpio_write_reg(GPIO6_DATAOUT,(gpio_read_reg(GPIO6_DATAOUT))|(1<<21));

/*following code are for song's test*/
/*
	*(volatile unsigned short *)(0x480021E8) = 0x0004;	//gpio96 output
	*(volatile unsigned short *)(0x480021E4) = 0x0004;
	*(volatile unsigned int*)(0x49054034) &= ~1;
	*(volatile unsigned int*)(0x4905403c) |= 1;		//gpio96 output 0
	*(volatile unsigned int*)(0x49052034) &= ~(1<<30);
	*(volatile unsigned int*)(0x4905203c) &= ~(1<<30);		//gpio94 output 1
	printf("stop for test");
	while(1);
*/
}

int lcd_ctrl_init(void )
{
	u8 rotation = 90;
	u16 fbw,fbh;

	u32 l = clkctrl_read_reg(CM_CLKSEL2_PLL);

	u32 m = clkctrl_read_reg(CM_CLKEN_PLL);	
	m &= 0xffffff;	
	m |= (0x7 << 16);//|(0x0f<<20);
	clkctrl_write_reg(CM_CLKEN_PLL,m);


	dss_clk_write_reg(CM_CLKSEL_DSS,0x10009);

	dss_clk_write_reg(CM_FCLKEN_DSS, 5);
	dss_clk_write_reg(CM_ICLKEN_DSS, 1);
	dss_clk_write_reg(CM_AUTOIDLE_DSS, 0);
	dss_clk_write_reg(CM_SLEEPDEP_DSS,0);
	dss_clk_write_reg(CM_CLKSTCTRL_DSS,0);

	dss_write_reg(DSS_SYSCONFIG,0x0002);
	while(! dss_read_reg(DSS_SYSSTATUS));
	
	dispc_write_reg(DISPC_CONTROL, 0x00018308);
	dispc_write_reg(DISPC_SIZE_LCD, 0x01df027f);	//size:640*480
	dispc_write_reg(DISPC_CONFIG,0x4);
	dispc_write_reg(DISPC_TIMING_H, 0x0720101e);	//LCD Timing params
	dispc_write_reg(DISPC_TIMING_V, 0x02100a03);
	dispc_write_reg(DISPC_POL_FREQ, 0x07000);
	dispc_write_reg(DISPC_DIVISOR, 0x00010005);     //maybe need change

	dispc_write_reg(DISPC_GFX_SIZE, 0x01df027f);	
	dispc_write_reg(DISPC_GFX_FIFO_THRESHOLD,0x03ff03bf);
	dispc_write_reg(DISPC_GFX_POSITION,0x0);
	dispc_write_reg(DISPC_GFX_ATTRIBUTES, 0x0ad);	//change for GFX configuration

	memset(lcd_static_mem, 0x0000, sizeof(lcd_static_mem));

	switch(rotation)
	{	
		case 90:
			fbw = Height;
			fbh = Width;
			dispc_write_reg(DISPC_GFX_BA0, (u32)lcd_static_mem + Screen_Width*(fbh-1)*Pixel_Size);
			dispc_write_reg(DISPC_GFX_PIXEL_INC,1 - (1+Screen_Width)*Pixel_Size);
			dispc_write_reg(DISPC_GFX_ROW_INC,1 + Screen_Width*(fbh-1)*Pixel_Size);
			break;
//		case 180:
//			dispc_write_reg(DISPC_GFX_BA0, (u32)lcd_static_mem + (Image_Width*Image_Height-1)*2);
//			dispc_write_reg(DISPC_GFX_PIXEL_INC,-4);
//			dispc_write_reg(DISPC_GFX_ROW_INC,-4);
//			break;
//		case 270:
		default:
			dispc_write_reg(DISPC_GFX_BA0, (u32)lcd_static_mem);
			dispc_write_reg(DISPC_GFX_PIXEL_INC,1);
			dispc_write_reg(DISPC_GFX_ROW_INC,1);
	}
	printf("Buffer base address is %lx\n",dispc_read_reg(DISPC_GFX_BA0));
	dispc_write_reg(DISPC_CONTROL, 0x00018329);

	backlight();

	return 0;
}

void *video_hw_init (void)
{
    lcd_ctrl_init ();

    /* fill in Graphic Device */

   glcd_dev.frameAdrs = (u32)lcd_static_mem;
 //   glcd_dev.frameAdrs = LCD_BUFFER_BASE;	

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


