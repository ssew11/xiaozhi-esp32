#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

// ================= 音频配置 (保持不变) =================
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

// ================= 按键与LED (保持不变) =================
#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0
#define TOUCH_BUTTON_GPIO       GPIO_NUM_NC
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_NC

// ================= 屏幕核心配置 (强制修改) =================
// 1. 激活 ST7789 SPI 驱动
#define LCD_TYPE_ST7789_SERIAL

// 2. 强制指定为你测出的正确引脚
#define DISPLAY_CLK_PIN        GPIO_NUM_21  // SCL
#define DISPLAY_MOSI_PIN       GPIO_NUM_47  // SDA
#define DISPLAY_RST_PIN        GPIO_NUM_45  // RES
#define DISPLAY_DC_PIN         GPIO_NUM_40  // DC
#define DISPLAY_CS_PIN         GPIO_NUM_41  // CS
#define DISPLAY_BACKLIGHT_PIN  GPIO_NUM_42  // BLK

// 3. 分辨率设置：240x280 (如果下方还有黑边，把 280 改为 320)
#define DISPLAY_WIDTH    240
#define DISPLAY_HEIGHT   280

// 4. 镜像与颜色设置
#define DISPLAY_MIRROR_X false
#define DISPLAY_MIRROR_Y false
#define DISPLAY_SWAP_XY  false
#define DISPLAY_INVERT_COLOR    true
#define DISPLAY_RGB_ORDER       LCD_RGB_ELEMENT_ORDER_RGB

// 5. 偏移量设置
// 长方形屏幕经常需要偏移。如果图像没对齐，尝试修改 Y 为 20
#define DISPLAY_OFFSET_X  0
#define DISPLAY_OFFSET_Y  20 

#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false
#define DISPLAY_SPI_MODE 0

// ================= 其他 =================
#define LAMP_GPIO GPIO_NUM_18

#endif // _BOARD_CONFIG_H_
