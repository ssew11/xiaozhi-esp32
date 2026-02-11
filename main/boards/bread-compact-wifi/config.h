#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

// ================= 1. 音频部分 (保持该板子默认) =================
#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000
#define AUDIO_I2S_METHOD_SIMPLEX

#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_4
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_5
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_6
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_7
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_15
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_16

// ================= 2. 基础引脚 =================
#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0
#define TOUCH_BUTTON_GPIO       GPIO_NUM_NC
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_39
#define LAMP_GPIO               GPIO_NUM_18

// ================= 3. ST7789 屏幕配置 (你的物理引脚) =================

// 强制指定驱动类型为 ST7789
#define LCD_TYPE_ST7789_SERIAL

#define DISPLAY_CLK_PIN        GPIO_NUM_21  // SCL
#define DISPLAY_MOSI_PIN       GPIO_NUM_47  // SDA
#define DISPLAY_RST_PIN        GPIO_NUM_45  // RES
#define DISPLAY_DC_PIN         GPIO_NUM_40  // DC
#define DISPLAY_CS_PIN         GPIO_NUM_41  // CS
#define DISPLAY_BACKLIGHT_PIN  GPIO_NUM_42  // BLK

// ================= 4. 显示参数 (强制写死) =================
#define DISPLAY_WIDTH    240
#define DISPLAY_HEIGHT   240

#define DISPLAY_MIRROR_X false
#define DISPLAY_MIRROR_Y false
#define DISPLAY_SWAP_XY  false
#define DISPLAY_INVERT_COLOR true

// 兼容性宏：防止底层代码找不到旧变量名
#define DISPLAY_SDA_PIN  DISPLAY_MOSI_PIN
#define DISPLAY_SCL_PIN  DISPLAY_CLK_PIN

#ifndef LCD_RGB_ELEMENT_ORDER_RGB
#define LCD_RGB_ELEMENT_ORDER_RGB 0
#endif
#define DISPLAY_RGB_ORDER       LCD_RGB_ELEMENT_ORDER_RGB

#define DISPLAY_OFFSET_X  0
#define DISPLAY_OFFSET_Y  0
#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false
#define DISPLAY_SPI_MODE  0

#endif // _BOARD_CONFIG_H_
