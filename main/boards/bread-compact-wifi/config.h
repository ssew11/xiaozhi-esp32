#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

// =========================================================
// 第一步：防止编译错误的“补丁”
// =========================================================

// 1. 手动定义颜色顺序常量 (防止缺少头文件报错)
#ifndef LCD_RGB_ELEMENT_ORDER_RGB
#define LCD_RGB_ELEMENT_ORDER_RGB 0
#endif
#ifndef LCD_RGB_ELEMENT_ORDER_BGR
#define LCD_RGB_ELEMENT_ORDER_BGR 1
#endif

// 2. 清除所有可能的引脚定义冲突 (防止 Redefined 报错)
#undef TOUCH_BUTTON_GPIO
#undef VOLUME_UP_BUTTON_GPIO
#undef DISPLAY_SDA_PIN
#undef DISPLAY_SCL_PIN
#undef DISPLAY_CLK_PIN
#undef DISPLAY_MOSI_PIN
#undef DISPLAY_CS_PIN
#undef DISPLAY_DC_PIN
#undef DISPLAY_RST_PIN
#undef DISPLAY_BACKLIGHT_PIN

// =========================================================
// 第二步：音频配置 (保持原样)
// =========================================================
#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000
#define AUDIO_I2S_METHOD_SIMPLEX
#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_4
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_5
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_6
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_7
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_15
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_16

// =========================================================
// 第三步：按键配置 (解决冲突)
// =========================================================
#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0

// ！！！关键：将原本占用屏幕引脚的按键设为 NC (无效)
#define TOUCH_BUTTON_GPIO       GPIO_NUM_NC  // 避让 GPIO 47
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC  // 避让 GPIO 40
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_39

// =========================================================
// 第四步：屏幕引脚 (ST7789 SPI)
// =========================================================

// 1. 强制激活 ST7789 驱动
#define LCD_TYPE_ST7789_SERIAL 1

// 2. 你的 ST7789 真实引脚
#define DISPLAY_CLK_PIN        GPIO_NUM_21  // SCL
#define DISPLAY_MOSI_PIN       GPIO_NUM_47  // SDA
#define DISPLAY_RST_PIN        GPIO_NUM_45  // RES
#define DISPLAY_DC_PIN         GPIO_NUM_40  // DC
#define DISPLAY_CS_PIN         GPIO_NUM_41  // CS
#define DISPLAY_BACKLIGHT_PIN  GPIO_NUM_42  // BLK

// 3. 【防报错兼容定义】
// 如果固件代码还在找 OLED 的引脚名，我们将它们指向 NC 或对应引脚
// 这样即使它是 OLED 版固件，也不会因为找不到变量而编译失败
#define DISPLAY_SDA_PIN        GPIO_NUM_47
#define DISPLAY_SCL_PIN        GPIO_NUM_21

// =========================================================
// 第五步：显示参数
// =========================================================
#define DISPLAY_WIDTH    240
#define DISPLAY_HEIGHT   240  // 如果屏幕下方有黑边，请改为 280 或 320
#define DISPLAY_MIRROR_X false
#define DISPLAY_MIRROR_Y false
#define DISPLAY_SWAP_XY  false
#define DISPLAY_INVERT_COLOR    true

#define DISPLAY_RGB_ORDER       LCD_RGB_ELEMENT_ORDER_RGB
#define DISPLAY_OFFSET_X        0
#define DISPLAY_OFFSET_Y        0
#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false
#define DISPLAY_SPI_MODE        0

#define LAMP_GPIO GPIO_NUM_18

#endif // _BOARD_CONFIG_H_
