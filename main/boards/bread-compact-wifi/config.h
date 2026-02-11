#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

// 1. 音频配置 (保持不变)
#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000
#define AUDIO_I2S_METHOD_SIMPLEX
#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_4
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_5
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_6
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_7
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_15
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_16

// 2. 基础引脚与按键 (移除冲突)
#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0
#define TOUCH_BUTTON_GPIO       GPIO_NUM_NC
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_39
#define LAMP_GPIO               GPIO_NUM_18

// 3. 屏幕驱动与物理引脚 (ST7789 核心)
#define LCD_TYPE_ST7789_SERIAL   1  // 强制开启 ST7789 驱动

#define DISPLAY_CLK_PIN        GPIO_NUM_21  // 对应你的 SCL
#define DISPLAY_MOSI_PIN       GPIO_NUM_47  // 对应你的 SDA
#define DISPLAY_RST_PIN        GPIO_NUM_45  // 对应你的 RES
#define DISPLAY_DC_PIN         GPIO_NUM_40  // 对应你的 DC
#define DISPLAY_CS_PIN         GPIO_NUM_41  // 对应你的 CS
#define DISPLAY_BACKLIGHT_PIN  GPIO_NUM_42  // 对应你的 BLK

// 4. 【关键补丁】映射旧变量名，防止编译器报错
#define DISPLAY_SDA_PIN        DISPLAY_MOSI_PIN
#define DISPLAY_SCL_PIN        DISPLAY_CLK_PIN

// 5. 显示参数
#define DISPLAY_WIDTH    240
#define DISPLAY_HEIGHT   240
#define DISPLAY_MIRROR_X false
#define DISPLAY_MIRROR_Y false
#define DISPLAY_SWAP_XY  false
#define DISPLAY_INVERT_COLOR true

#ifndef LCD_RGB_ELEMENT_ORDER_RGB
#define LCD_RGB_ELEMENT_ORDER_RGB 0
#endif
#define DISPLAY_RGB_ORDER       LCD_RGB_ELEMENT_ORDER_RGB

#define DISPLAY_OFFSET_X        0
#define DISPLAY_OFFSET_Y        0
#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false
#define DISPLAY_SPI_MODE        0

#endif // _BOARD_CONFIG_H_
