    这是ST提供的3个启动文件，分别适用于不同容量的STM32芯片。
    这三个文件为： 
        startup_stm32f10x_ld.s
        startup_stm32f10x_md.s
        startup_stm32f10x_hd.s
    其中，ld.s适用于小容量 产品；md.s适用于中等容量产品；hd适用于大容量产品；
    这里的容量是指FLASH的大小.判断方法如下：
       小容量：FLASH≤32K
       中容量：64K≤FLASH≤128K
       大容量：256K≤FLASH
    所以，请大家根据自己所用的STM32芯片选择不同的.s文件。
                                                        


		广州市星翼电子科技有限公司
                电话：020-38271790
                传真：020-36773971
	       	购买：http://shop62103354.taobao.com
                      http://shop62057469.taobao.com
               	技术支持论坛：www.openedv.com
                公司网址：www.alientek.com