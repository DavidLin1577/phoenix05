#ifndef _TEST_MAIN_H_
#define _TEST_MAIN_H_

#include "test.h"
#include "lib_include.h"

#define TEST_CTL_EN      (0)
#define TEST_IOM_EN      (0)
#define TEST_WDT_EN      (0)
#define TEST_LPT_EN      (0)
#define TEST_TIM_EN      (1)
#define TEST_UART_EN     (0)
#define TEST_EFC_EN      (0)
#define TEST_SYSC_EN     (0)
#define TEST_PMU_EN      (0)

typedef enum test_mode
{
    MODEL = 0,
    FUNC  = 1,
    ITEM  = 2,
    PARA  = 3,
}test_mode_t;

// model define
typedef enum test_device
{
    MODEL_CTL = 0,                            //测试控制
    MODEL_IOM = 1,                            //测试IOM模块
    MODEL_WDT = 2,                            //测试看门狗模块
    MODEL_LPTIMER = 3,                        //测试低功耗定时器模块
    MODEL_TIMER = 4,                          //测试定时器模块
    MODEL_UART = 5,                           //测试UART模块
    MODEL_EFC = 6,                            //测试EFC模块
    MODEL_SYSC = 7,                           //测试SYSC模块
    MODEL_PMU = 8,                            //测试PMU模块                         
} test_device_t;

typedef enum ctrl_func
{
    CTRL_FUNC_CORE_RST = 0,                   //核复位
    CTRL_FUNC_CHIP_RST = 1,                   //芯片复位
    CTRL_FUNC_DIG_RST = 2,                    //数字复位
    CTRL_FUNC_CFG = 3,                        //寄存器操作
}ctrl_func_t;

typedef enum ctrl_item
{
    CTRL_CFG_REG_OPT_RD = 0,                  //寄存器读 #u32<0x00000000-0xffffffff>:寄存器地址#
    CTRL_CFG_REG_OPT_WR = 1,                  //寄存器写 #u32<0x00000000-0xffffffff>:寄存器地址#u32<0x00000000-0xffffffff>:寄存器数据#
}ctrl_item_t;

typedef enum iom_func
{
    IOM_FUNC_CFG = 0,                         //配置
    IOM_FUNC_GET_STS = 1,                     //读状态
    IOM_FUNC_GET_DATA = 2,                    //读数据
    IOM_FUNC_CTL_G_INT_EN = 3,                //模块全局中断使能
    IOM_FUNC_CTL_G_INT_DIS = 4,               //模块全局中断禁止
    IOM_FUNC_CTL_DEBOUNCE_EN = 5,             //去抖动使能滤波1系统时钟
    IOM_FUNC_CTL_DEBOUNCE_DIS = 6,            //去抖动禁止
    IOM_FUNC_CTL_IN_LS_SYNC_EN = 7,           //输入同步使能同步到pclk域
    IOM_FUNC_CTL_IN_LS_SYNC_DIS = 8,          //输入同步禁止
}iom_func_t;

typedef enum iom_item
{
    IOM_CFG_AF = 0,                           //复用功能 #u16<0x00000-0xfffff>:pin#u8<0x00-0x03>:0 gpio,1/2/3 fun1/2/3#
    IOM_CFG_AIN_EN = 1,                       //模拟输入使能 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_AIN_DIS = 2,                      //模拟输入禁止 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_OE_EN = 3,                        //输出使能 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_OE_DIS = 4,                       //输出禁止 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_PU_EN = 5,                        //上拉使能 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_PU_DIS = 6,                       //上拉禁止 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_PD_EN = 7,                        //下拉使能 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_PD_DIS = 8,                       //下拉禁止 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_OTYPE_EN = 9,                     //下拉使能 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_OTYPE_DIS = 10,                   //下拉禁止 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_DRS_STRONG = 11,                  //强驱动 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_DRS_WEAK = 12,                    //弱驱动 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_INT_TYPE_LVL = 13,                //电平中断 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_INT_TYPE_EDGE = 14,               //边缘中断 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_INT_POL_HIGH = 15,                //高电平中断 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_INT_POL_LOW = 16,                 //低电平中断 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_INT_EN = 17,                      //中断使能 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_INT_DIS = 18,                     //中断禁止 #u16<0x00000-0xfffff>:pin#

    IOM_CFG_OUT_DATA_HIGH = 19,               //输出数据高 #u16<0x00000-0xfffff>:pin#
    IOM_CFG_OUT_DATA_LOW = 20,                //输出数据低 #u16<0x00000-0xfffff>:pin#

}iom_item_t;


typedef enum wdt_func
{
    WDT_FUNC_CFG = 0,                         //配置参数
    WDT_FUNC_CTL_RUN = 1,                     //正常序列启动
    WDT_FUNC_CTL_NO_RUN = 2,                  //非正常序列启动
    WDT_FUNC_GET_STS = 3,                     //读运行状态或中断标志信息
    WDT_FUNC_FEED = 4,                        //1ms喂狗一次
	WDT_FUNC_INT = 5,                         //看门狗中断功能测试
	WDT_FUNC_OVT = 6,                         //看门狗溢出功能测试
	WDT_FUNC_DEINIT = 7,                      //看门狗关闭功能测试
} wdt_func_t;


typedef enum wdt_item
{
    WDT_CFG_PARM = 0,                         //配置 #u32<0x00000000-0xffffffff>:延时ms#u8<0-1>:clksrc lrc-xtl#u8<0-1>:mode int-rst中断测P18口波形#
}wdt_item_t;


typedef enum lptimer_func
{
    LPT_FUNC_CFG = 0,                        //配置参数
    LPT_FUNC_CTL_EN = 1,                     //LPT运行使能
    LPT_FUNC_CTL_DIS = 2,                    //LPT运行停止
    LPT_FUNC_GET_CNT = 3,                    //LPT获得计数值
    LPT_FUNC_GET_STS = 4,                    //LPT获得状态信息
}lptimer_func_t;

typedef enum lptimer_item
{
    LPT_CFG_PARM = 0,                        //LPT配置  #u8<0-1>:clksrc lrc-xtl#u32<0x00000000-0xffffffff>:延时ms#u8<0-1>:mode sig-pit#
	LPT_CFG_IE_CTL = 1,                      //LPT中断控制测P18口波形 #u8<0-1>:dis-enable#
}lptimer_item_t;

typedef enum timer_func
{
    TIMER_FUNC_CFG = 0,                      //配置
    TIMER_FUNC_RUN_TIM0 = 1,                 //运行TIM0
    TIMER_FUNC_STOP_TIM0 = 2,                //停止TIM0
    TIMER_FUNC_RUN_TIM1 = 3,                 //运行TIM1
    TIMER_FUNC_STOP_TIM1 = 4,                //停止TIM1
    TIMER_FUNC_RUN_TIM2 = 5,                 //运行TIM2
    TIMER_FUNC_STOP_TIM2 = 6,                //停止TIM2
    TIMER_FUNC_RUN_TIM3 = 7,                 //运行TIM3
    TIMER_FUNC_STOP_TIM3 = 8,                //停止TIM3
    TIMER_FUNC_RUN_TIM4 = 9,                 //运行TIM4
    TIMER_FUNC_STOP_TIM4 = 10,               //停止TIM4
    TIMER_FUNC_PAUSE_TIM0 = 11,              //暂停TIM0
    TIMER_FUNC_RESTORE_TIM0 = 12,            //恢复TIM0
    TIMER_FUNC_PAUSE_TIM1 = 13,              //暂停TIM1
    TIMER_FUNC_RESTORE_TIM1 = 14,            //恢复TIM1
    TIMER_FUNC_PAUSE_TIM2 = 15,              //暂停TIM2
    TIMER_FUNC_RESTORE_TIM2 = 16,            //恢复TIM2
    TIMER_FUNC_PAUSE_TIM3 = 17,              //暂停TIM3
    TIMER_FUNC_RESTORE_TIM3 = 18,            //恢复TIM3
    TIMER_FUNC_PAUSE_TIM4 = 19,              //暂停TIM4
    TIMER_FUNC_RESTORE_TIM4 = 20,            //恢复TIM4
	TIMER_FUNC_TIMING = 21,
	TIMER_FUNC_COUNT = 22,
	TIMER_FUNC_PWM = 23,                     //测试完整流程的PWM,0x17
}timer_func_t;


typedef enum timer_item
{
    TIMER_CFG_TIMER = 0,                     //配置定时模式 #u8<1-2>:timer1/2#u32<0x00000000-0xffffffff>:延时时间#
    TIMER_CFG_CNT = 1,                       //配置计数模式 #u8<1-2>:timer1/2#u8<0-1>:计数电平控制tim1(pin06),tim2(pin12)#
    TIMER_CFG_PWM = 2,                       //配置PWM模式
                                             //#u8<1-2>:timer1/2#u8<0-3>:pwm极性#u32<0-1000000>:频率#u8<0-100>:占空比#u8<0-1>:端口tim1tog12-14,tim2tog13-15;tim1ntog16,tim2ntog17#u16<0x0000-0xffff>:死区时间#
    TIMER_CFG_IE_CTL = 3,                    //#u8<1-2>:timer1/2#u8<0-1>:dis-enable#
}timer_item_t;


typedef enum uart_func
{
    UART_FUNC_CFG = 0,                       //配置
    UART_FUNC_RD1_DAT = 1,                   //读串口1数据
    UART_FUNC_RD1_STS = 2,                   //读串口1状态
    UART_FUNC_CLR1_STS = 3,                  //清串口1状态
}uart_func_t;

typedef enum uart_item
{
    UART_CFG_PARM = 0,                       //初始化配置 #u8<1-2>:uart 1-2#u8<0-1>:port 14/15-18/19#u8<0-2>:mode
                                             //8/10/11bit#u16<1200-115200>:波特率#
    UART_CFG_RCV_VRF = 1,                    //接收校验位配置 #U8<0-1>:0 odd-even#
    UART_CFG_CTL = 2,                        //一次配置多机模式/接收使能/起始位检测 #u8<0-7>:bit0-2:sm2-ren-sfd 3bit为1使能0禁止#
    UART_CFG_IE_CTL = 3,                     //中断控制 #u8<0-1>:dis-en#u8<0-2>:int_type rxst-tx-rx#
    UART_CFG_SEND_DAT = 4,                   //配置发送数据带bit8不用可设为0 #u16<0x0000-0x01ff>:send data#
    UART_CFG_ADDR_MSK = 5,                   //配置地址与屏蔽 #u8<0x00-0xff>:addr#u8<0x00-0xff>:mask#

}uart_item_t;

typedef enum efc_func
{
    EFC_FUNC_INIT = 0,                       //初始化
    EFC_FUNC_CFG = 1,                        //配置控制
    EFC_FUNC_CHP_ERS = 2,                    //芯片擦除
    EFC_FUNC_RD_STS = 3,                     //读状态
}efc_func_t;

typedef enum efc_item
{
    EFC_CFG_SIG_PRG = 0,                     //单地址编程 #u32<0x10100000-0x10107fff>:addr#u8<0-2>:type
                                             // byte-hw-word#u32<0x00000000-0xffffffff>:data#
    EFC_CFG_RD = 1,                          //读地址数据 #u32<0x10100000-0x10107fff>:addr#
    EFC_CFG_PG_ERS = 2,                      //页擦除 #u32<0x10100000-0x10107fff>:addr#
}efc_item_t;

typedef enum sysc_func
{
    SYSC_FUNC_CFG = 0,                       //配置
    SYSC_FUNC_TIMDIV = 1,                    //测试TIM分频测p18频率从256k-1k
    SYSC_FUNC_HCLK_DIV = 2,                  //HCLK分频测p16输出波形从128k-1k
    SYSC_FUNC_PCLK_DIV = 3,                  //测试TIM分频测p18频率从128k-1k
}sysc_func_t;

typedef enum sysc_item
{
    SYSC_CFG_CLK_SRC = 0,                    //配置系统时钟源测p16输出波形 #u8<0-3>:hrc-lrc-xth-xtl#
    SYSC_CFG_TST_OUT = 1,                    //配置测试输出时钟P16 #u8<0-127>:div 2-256#
}sysc_item_t;

typedef enum pmu_func
{
    PMU_FUNC_CFG = 0,                        //配置
    PMU_FUNC_SLP = 1,                        //sleep
    PMU_FUNC_DPSLP = 2,                      //deep sleep
    PMU_FUNC_POWDWN = 3,                     //power down
    PMU_FUNC_SFT_RST_COR = 4,                //软件复位核
    PMU_FUNC_SFT_RST_DIG = 5,                //软件复位数字
    PMU_FUNC_SFT_RST_CHP = 6,                //软件复位芯片
    PMU_FUNC_GET_BAK_VAL = 7,                //获得备份值
}pmu_func_t;

typedef enum pmu_item
{
    PMU_CFG_GPWK = 0,                        //gpio唤醒控制 #u8<0-1>:sycn-asycn#u8<0-1>:level low-high#u8<0x01-0x0f>:wkpin 16/17/18/19(4bitset 1 valid)#
    PMU_CFG_BAK_VAL = 1,                     //配置备份值 #u32<0x00000000-0xffffffff>:bak value#
}pmu_item_t;

#endif /*_TEST_MAIN_H_*/
