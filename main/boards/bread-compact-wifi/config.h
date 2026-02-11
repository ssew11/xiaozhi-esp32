#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

// ================= 音频部分 (保持原样) =================
#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000
#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX
#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_4
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_5
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_6
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_7
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_15
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_16
#else
#define AUDIO_I2S_GPIO_WS GPIO_NUM_4
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_5
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_6
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_7
#endif

// ================= 按键与LED (解决冲突) =================
#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0

// 将原本占用 GPIO47 和 40 的按键设为无效(NC)，给屏幕让路
#define TOUCH_BUTTON_GPIO       GPIO_NUM_NC
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_39

// ================= 屏幕核心配置 (关键修改) =================

// 1. 激活 ST7789 驱动逻辑
#define LCD_TYPE_ST7789_SERIAL 1

// 2. 定义 ST7789 的真实物理引脚 (你测出来的)
#define DISPLAY_CLK_PIN        GPIO_NUM_21  // SCL
#define DISPLAY_MOSI_PIN       GPIO_NUM_47  // SDA
#define DISPLAY_RST_PIN        GPIO_NUM_45  // RES
#define DISPLAY_DC_PIN         GPIO_NUM_40  // DC
#define DISPLAY_CS_PIN         GPIO_NUM_41  // CS
#define DISPLAY_BACKLIGHT_PIN  GPIO_NUM_42  // BLK

// 3. 【防报错补丁】保留旧变量名，指向新引脚
// 这样如果代码还在找 SDA/SCL，编译器就不会报错，而是直接用新的 MOSI/CLK
#define DISPLAY_SDA_PIN        DISPLAY_MOSI_PIN
#define DISPLAY_SCL_PIN        DISPLAY_CLK_PIN

// 4. 屏幕参数 (强制写死，不依赖 menuconfig)
#define DISPLAY_WIDTH    240
#define DISPLAY_HEIGHT   240

// 5. 显示方向与颜色
#define DISPLAY_MIRROR_X false
#define DISPLAY_MIRROR_Y false
#define DISPLAY_SWAP_XY  false
#define DISPLAY_INVERT_COLOR    true

// 6. 手动定义颜色格式，防止缺少头文件报错
#ifndef LCD_RGB_ELEMENT_ORDER_RGB
#define LCD_RGB_ELEMENT_ORDER_RGB 0
#endif
#define DISPLAY_RGB_ORDER       LCD_RGB_ELEMENT_ORDER_RGB

#define DISPLAY_OFFSET_X        0
#define DISPLAY_OFFSET_Y        0
#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false
#define DISPLAY_SPI_MODE        0

// 其他
#define LAMP_GPIO GPIO_NUM_18

#endif // _BOARD_CONFIG_H_
