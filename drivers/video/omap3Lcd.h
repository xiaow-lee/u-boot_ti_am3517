#ifndef _OMAP3LCD_H_
#define _OMAP3LCD_H_


#define DISPC_BASE			0x48050400
#define DSS_BASE			0x48050000
#define DSS_CLK_BASE			0x48004e00
#define SGX_CLK_BASE			0x48004b00
#define DSI_BASE			0x4804FC00
#define PAD_CONFIG_BASE			0x48002030

#define GPIO5_OE	0x49056034 
#define GPIO5_DATAOUT	0x4905603C 
#define GPIO6_OE	0x49058034
#define GPIO6_DATAOUT	0x4905803C


#define CLOCK_CTRL_BASE			0x48004D00
#define CLOCK_CTRL_REG(idx)		((const u16) {idx})
#define CM_CLKEN_PLL			CLOCK_CTRL_REG(0x00)
#define CM_CLKSEL2_PLL			CLOCK_CTRL_REG(0x44)


#define DSS_REG(idx)			((const u16) { idx })
#define DISPC_REG(idx)			((const u16) { idx })
#define DSS_CLK_REG(idx)		((const u16) { idx })
#define SGX_CLK_REG(idx)		((const u16) { idx })
#define DSI_REG(idx)			((const u16) { idx })
#define PAD_CONFIG_REG(idx)		((const u16) { idx })

#define GPT11_MUX_OFFSET		PAD_CONFIG_REG(0x1AC)
#define GPT9_MUX_OFFSET			PAD_CONFIG_REG(0x144)
#define	PKOFF_MUX_OFFSET		PAD_CONFIG_REG(0x13C)

#define CONTROL_PADCONF_DSS_PCLK	PAD_CONFIG_REG(0xA4)
#define CONTROL_PADCONF_DSS_VSYNC	PAD_CONFIG_REG(0xA8)
#define CONTROL_PADCONF_DSS_DATA0	PAD_CONFIG_REG(0xAC)
#define CONTROL_PADCONF_DSS_DATA2	PAD_CONFIG_REG(0xB0)
#define CONTROL_PADCONF_DSS_DATA4	PAD_CONFIG_REG(0xB4)
#define CONTROL_PADCONF_DSS_DATA6	PAD_CONFIG_REG(0xB8)
#define CONTROL_PADCONF_DSS_DATA8	PAD_CONFIG_REG(0xBC)
#define CONTROL_PADCONF_DSS_DATA10	PAD_CONFIG_REG(0xC0)
#define CONTROL_PADCONF_DSS_DATA12	PAD_CONFIG_REG(0xC4)
#define CONTROL_PADCONF_DSS_DATA14	PAD_CONFIG_REG(0xC8)
#define CONTROL_PADCONF_DSS_DATA16	PAD_CONFIG_REG(0xCC)
#define CONTROL_PADCONF_DSS_DATA18	PAD_CONFIG_REG(0xD0)
#define CONTROL_PADCONF_DSS_DATA20	PAD_CONFIG_REG(0xD4)
#define CONTROL_PADCONF_DSS_DATA22	PAD_CONFIG_REG(0xD8)


#define CM_FCLKEN_DSS		DSS_CLK_REG(0x00)
#define CM_ICLKEN_DSS		DSS_CLK_REG(0x10)
#define CM_AUTOIDLE_DSS		DSS_CLK_REG(0x30)
#define CM_CLKSEL_DSS		DSS_CLK_REG(0x40)
#define CM_CLKSTCTRL_DSS	DSS_CLK_REG(0x48)
#define CM_CLKSTST_DSS		DSS_CLK_REG(0x4c)
#define CM_SLEEPDEP_DSS		DSS_CLK_REG(0x44)


#define DSS_REVISION			DSS_REG(0x0000)
#define DSS_SYSCONFIG			DSS_REG(0x0010)
#define DSS_SYSSTATUS			DSS_REG(0x0014)
#define DSS_IRQSTATUS			DSS_REG(0x0018)
#define DSS_CONTROL			DSS_REG(0x0040)
#define DSS_SDI_CONTROL		DSS_REG(0x0044)
#define DSS_PLL_CONTROL		DSS_REG(0x0048)
#define DSS_SDI_STATUS			DSS_REG(0x005C)



/* DISPC common */
#define DISPC_REVISION			DISPC_REG(0x0000)
#define DISPC_SYSCONFIG			DISPC_REG(0x0010)
#define DISPC_SYSSTATUS			DISPC_REG(0x0014)
#define DISPC_IRQSTATUS			DISPC_REG(0x0018)
#define DISPC_IRQENABLE			DISPC_REG(0x001C)
#define DISPC_CONTROL			DISPC_REG(0x0040)
#define DISPC_CONFIG			DISPC_REG(0x0044)
#define DISPC_CAPABLE			DISPC_REG(0x0048)
#define DISPC_DEFAULT_COLOR0		DISPC_REG(0x004C)
#define DISPC_DEFAULT_COLOR1		DISPC_REG(0x0050)
#define DISPC_TRANS_COLOR0		DISPC_REG(0x0054)
#define DISPC_TRANS_COLOR1		DISPC_REG(0x0058)
#define DISPC_LINE_STATUS		DISPC_REG(0x005C)
#define DISPC_LINE_NUMBER		DISPC_REG(0x0060)
#define DISPC_TIMING_H			DISPC_REG(0x0064)
#define DISPC_TIMING_V			DISPC_REG(0x0068)
#define DISPC_POL_FREQ			DISPC_REG(0x006C)
#define DISPC_DIVISOR			DISPC_REG(0x0070)
#define DISPC_GLOBAL_ALPHA		DISPC_REG(0x0074)
#define DISPC_SIZE_DIG			DISPC_REG(0x0078)
#define DISPC_SIZE_LCD			DISPC_REG(0x007C)

/* DISPC GFX plane */
#define DISPC_GFX_BA0			DISPC_REG(0x0080)
#define DISPC_GFX_BA1			DISPC_REG(0x0084)
#define DISPC_GFX_POSITION		DISPC_REG(0x0088)
#define DISPC_GFX_SIZE			DISPC_REG(0x008C)
#define DISPC_GFX_ATTRIBUTES		DISPC_REG(0x00A0)
#define DISPC_GFX_FIFO_THRESHOLD	DISPC_REG(0x00A4)
#define DISPC_GFX_FIFO_SIZE_STATUS	DISPC_REG(0x00A8)
#define DISPC_GFX_ROW_INC		DISPC_REG(0x00AC)
#define DISPC_GFX_PIXEL_INC		DISPC_REG(0x00B0)
#define DISPC_GFX_WINDOW_SKIP		DISPC_REG(0x00B4)
#define DISPC_GFX_TABLE_BA		DISPC_REG(0x00B8)

#define DISPC_DATA_CYCLE1		DISPC_REG(0x01D4)
#define DISPC_DATA_CYCLE2		DISPC_REG(0x01D8)
#define DISPC_DATA_CYCLE3		DISPC_REG(0x01DC)

#define DISPC_CPR_COEF_R		DISPC_REG(0x0220)
#define DISPC_CPR_COEF_G		DISPC_REG(0x0224)
#define DISPC_CPR_COEF_B		DISPC_REG(0x0228)

#define DISPC_GFX_PRELOAD		DISPC_REG(0x022C)



/* DSI_PLL_CTRL_SCP */

#define DSI_PLL_CONTROL			DSI_REG(0x300 + 0x0000)
#define DSI_PLL_STATUS			DSI_REG(0x300 + 0x0004)
#define DSI_PLL_GO			DSI_REG(0x300 + 0x0008)
#define DSI_PLL_CONFIGURATION1		DSI_REG(0x300 + 0x000C)
#define DSI_PLL_CONFIGURATION2		DSI_REG(0x300 + 0x0010)


enum dss_clock {
	DSS_CLK_ICK	= 1 << 0,
	DSS_CLK_FCK1	= 1 << 1,
	DSS_CLK_FCK2	= 1 << 2,
	DSS_CLK_54M	= 1 << 3,
	DSS_CLK_96M	= 1 << 4,
};

static inline void gpio_write_reg(const u32 idx,u32 val)
{
	__raw_writel(val,idx);
}

static inline void clkctrl_write_reg(const u16 idx,u32 val)
{
	__raw_writel(val,CLOCK_CTRL_BASE + idx);
}
static inline u32 gpio_read_reg(const u32 idx)
{
	return __raw_readl(idx);
}

static inline u32 clkctrl_read_reg(const u16 idx)
{
	return __raw_readl(CLOCK_CTRL_BASE + idx);
}

static inline void pad_write_reg(const u16 idx, u32 val)
{
	__raw_writel(val,PAD_CONFIG_BASE + idx);
}
static inline u32 pad_read_reg(const u16 idx)
{
	return __raw_readl(PAD_CONFIG_BASE + idx);
}


static inline void dss_clk_write_reg(const u16 idx, u32 val)
{
	__raw_writel(val, DSS_CLK_BASE + idx);
}

static inline u32 dss_clk_read_reg(const u16 idx)
{
	return __raw_readl(DSS_CLK_BASE + idx);
}

static inline void dss_write_reg(const u16 idx, u32 val)
{
	__raw_writel(val, DSS_BASE + idx);
}

static inline u32 dss_read_reg(const u16 idx)
{
	return __raw_readl(DSS_BASE + idx);
}

static inline void dispc_write_reg(const u16 idx, s32 val)
{
	__raw_writel(val, DISPC_BASE + idx);
}

static inline u32 dispc_read_reg(const u16 idx)
{
	return __raw_readl(DISPC_BASE + idx);
}


#endif
