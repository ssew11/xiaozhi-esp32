#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

// 1. 基础配置（保持不动）
#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000
#define AUDIO_I2S_METHOD_SIMPLEX
#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_4
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_5
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_6
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_7
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_15
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_16
#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0

// 2. 映射引脚（关键：不删除旧名字，只改数值）
// 即使代码在找 SDA，我们给它 47 号引脚；找 SCL，给它 21 号引脚。
#define DISPLAY_SDA_PIN        GPIO_NUM_47  // 对应你的 SDA/MOSI
#define DISPLAY_SCL_PIN        GPIO_NUM_21  // 对应你的 SCL/CLK
#define DISPLAY_RST_PIN        GPIO_NUM_45  // 对应你的 RES
#define DISPLAY_DC_PIN         GPIO_NUM_40  // 对应你的 DC
#define DISPLAY_CS_PIN         GPIO_NUM_41  // 对应你的 CS
#define DISPLAY_BACKLIGHT_PIN  GPIO_NUM_42  // 对应你的 BLK

// 3. 这里的命名是为了骗过编译器，让它以为是在配置 SPI
#define DISPLAY_MOSI_PIN       DISPLAY_SDA_PIN
#define DISPLAY_CLK_PIN        DISPLAY_SCL_PIN

// 4. 定义屏幕规格
#define DISPLAY_WIDTH          240
#define DISPLAY_HEIGHT         240
#define DISPLAY_INVERT_COLOR   true
#define LCD_TYPE_ST7789_SERIAL 1 

// 5. 屏蔽冲突按键
#define TOUCH_BUTTON_GPIO       GPIO_NUM_NC
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_39
#define LAMP_GPIO               GPIO_NUM_18

#endif
