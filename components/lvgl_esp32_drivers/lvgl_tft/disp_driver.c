/**
 * @file disp_driver.c
 */

#include "disp_driver.h"
#include "disp_spi.h"

void disp_driver_init(bool init_spi)
{
#if defined CONFIG_LVGL_TFT_DISPLAY_PROTOCOL_SPI
	if (init_spi) {
		disp_spi_init();
	}
#elif defined CONFIG_LVGL_TFT_DISPLAY_PROTOCOL_I2C
    i2c_master_init();
#endif


#if defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9341
    ili9341_init();
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9488
    ili9488_init();
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ST7789
    st7789_init();
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_HX8357
	 hx8357_init(HX8357D);
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9486 
    ili9486_init();
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_SH1107
    sh1107_init();
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_SSD1306
    ssd1306_init();
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_FT81X
	FT81x_init();
#endif
}

void disp_driver_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_map)
{
#if defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9341
    ili9341_flush(drv, area, color_map);
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9488
    ili9488_flush(drv, area, color_map);
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ST7789
    st7789_flush(drv, area, color_map);
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_HX8357
	hx8357_flush(drv, area, color_map);
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9486
    ili9486_flush(drv, area, color_map);
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_SH1107
	sh1107_flush(drv, area, color_map);
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_SSD1306
    ssd1306_flush(drv, area, color_map);
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_FT81X
	FT81x_flush(drv, area, color_map);
#endif
}
void disp_driver_rounder(lv_disp_drv_t * disp_drv, lv_area_t * area)
{
#if defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_SSD1306
    ssd1306_rounder(disp_drv, area);
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_SH1107
    sh1107_rounder(disp_drv, area);
#endif
}

void disp_driver_set_px(struct _disp_drv_t * disp_drv, uint8_t * buf, lv_coord_t buf_w, lv_coord_t x, lv_coord_t y,
    lv_color_t color, lv_opa_t opa) 
{
#if defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_SSD1306
    ssd1306_set_px_cb(disp_drv, buf, buf_w, x, y, color, opa);
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_SH1107
    sh1107_set_px_cb(disp_drv, buf, buf_w, x, y, color, opa);
#endif
}
