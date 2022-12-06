
#ifndef _DMP_DATA_H_
#define _DMP_DATA_H_

#define DEFAULT_MPU_HZ	200


unsigned char mpu_dmp_init(void);
unsigned char mpu_dmp_get_data(float *pitch,float *roll,float *yaw);
int DMP_Init(void);




#endif

