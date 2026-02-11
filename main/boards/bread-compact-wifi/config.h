#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

// ================= 1. 音频与基础配置 (保持原样) =================
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

// ================= 2. 移除按键冲突 (给屏幕让路) =================
#define TOUCH_BUTTON_GPIO       GPIO_NUM_NC
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_NC

// ================= 3. 屏幕核心配置 (强制写入你的引脚) =================

// 激活驱动
#define LCD_TYPE_ST7789_SERIAL

// 你的物理接线定义
#define DISPLAY_CLK_PIN        GPIO_NUM_21  // SCL
#define DISPLAY_MOSI_PIN       GPIO_NUM_47  // SDA
#define DISPLAY_RST_PIN        GPIO_NUM_45  // RES
#define DISPLAY_DC_PIN         GPIO_NUM_40  // DC
#define DISPLAY_CS_PIN         GPIO_NUM_41  // CS
#define DISPLAY_BACKLIGHT_PIN  GPIO_NUM_42  // BLK

// --- 【重要：修复编译器的报错补丁】 ---
// 如果底层代码还在找旧的 SDA/SCL 名字，我们给它指路到新的引脚
#define DISPLAY_SDA_PIN        DISPLAY_MOSI_PIN
#define DISPLAY_SCL_PIN        DISPLAY_CLK_PIN
// ------------------------------------

// ================= 4. 显示物理参数 =================
#define DISPLAY_WIDTH          240
#define DISPLAY_HEIGHT         240

#define DISPLAY_MIRROR_X       false
#define DISPLAY_MIRROR_Y       false
#define DISPLAY_SWAP_XY        false
#define DISPLAY_INVERT_COLOR   true

// 强制定义颜色顺序常量，防止缺少头文件
#ifndef LCD_RGB_ELEMENT_ORDER_RGB
#define LCD_RGB_ELEMENT_ORDER_RGB 0
#endif
#define DISPLAY_RGB_ORDER      LCD_RGB_ELEMENT_ORDER_RGB

#define DISPLAY_OFFSET_X       0
#define DISPLAY_OFFSET_Y       0
#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false
#define DISPLAY_SPI_MODE       0

#define LAMP_GPIO              GPIO_NUM_18

#endif // _BOARD_CONFIG_H_
