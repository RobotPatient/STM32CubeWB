/**
  ******************************************************************************
  * @file    dataset_ftd.c
  * @author  MCD Application Team
  * @brief   This file contains the Operational Dataset (FTD only) interface
  *          shared between M0 and M4.
  ******************************************************************************
  * @attention
 *
 * Copyright (c) 2018-2021 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */


/* Includes ------------------------------------------------------------------*/
#include "stm32wbxx_hal.h"

#include "stm32wbxx_core_interface_def.h"
#include "tl_thread_hci.h"

/* Include definition of compilation flags requested for OpenThread configuration */
#include OPENTHREAD_CONFIG_FILE

#if OPENTHREAD_FTD

#include "dataset_ftd.h"

otError otDatasetCreateNewNetwork(otInstance *aInstance, otOperationalDataset *aDataset)
{
	otError rspData;
	
    Pre_OtCmdProcessing();
    /* prepare buffer */
    Thread_OT_Cmd_Request_t* p_ot_req = THREAD_Get_OTCmdPayloadBuffer();

    p_ot_req->ID = MSG_M4TOM0_OT_DATASET_CREATE_NEW_NETWORK;

    p_ot_req->Size=1;
    p_ot_req->Data[0] = (uint32_t) aDataset;

    Ot_Cmd_Transfer();

    p_ot_req = THREAD_Get_OTCmdRspPayloadBuffer();
    rspData = (otError)p_ot_req->Data[0];
  
  Post_OtCmdProcessing();
  
  return rspData;
}

uint32_t otDatasetGetDelayTimerMinimal(otInstance *aInstance)
{
	uint32_t rspData;
	
    Pre_OtCmdProcessing();
    /* prepare buffer */
    Thread_OT_Cmd_Request_t* p_ot_req = THREAD_Get_OTCmdPayloadBuffer();

    p_ot_req->ID = MSG_M4TOM0_OT_DATASET_GET_DELAY_TIMER_MINIMAL;

    p_ot_req->Size=0;

    Ot_Cmd_Transfer();

    p_ot_req = THREAD_Get_OTCmdRspPayloadBuffer();
    rspData = (uint32_t)p_ot_req->Data[0];
  
  Post_OtCmdProcessing();
  
  return rspData;
}

otError otDatasetSetDelayTimerMinimal(otInstance *aInstance, uint32_t aDelayTimerMinimal)
{
	otError rspData;
	
    Pre_OtCmdProcessing();
    /* prepare buffer */
    Thread_OT_Cmd_Request_t* p_ot_req = THREAD_Get_OTCmdPayloadBuffer();

    p_ot_req->ID = MSG_M4TOM0_OT_DATASET_SET_DELAY_TIMER_MINIMAL;

    p_ot_req->Size=1;
    p_ot_req->Data[0] = (uint32_t) aDelayTimerMinimal;

    Ot_Cmd_Transfer();

    p_ot_req = THREAD_Get_OTCmdRspPayloadBuffer();
    rspData = (otError)p_ot_req->Data[0];
  
    Post_OtCmdProcessing();
  
    return rspData;
}

#endif //OPENTHREAD_FTD
