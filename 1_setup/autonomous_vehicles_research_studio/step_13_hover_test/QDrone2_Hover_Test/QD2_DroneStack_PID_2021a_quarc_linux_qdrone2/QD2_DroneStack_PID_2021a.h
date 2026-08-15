/*
 * QD2_DroneStack_PID_2021a.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QD2_DroneStack_PID_2021a".
 *
 * Model version              : 11.6
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Fri Aug 14 15:35:51 2026
 *
 * Target selection: quarc_linux_qdrone2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef QD2_DroneStack_PID_2021a_h_
#define QD2_DroneStack_PID_2021a_h_
#ifndef QD2_DroneStack_PID_2021a_COMMON_INCLUDES_
#define QD2_DroneStack_PID_2021a_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "quanser_console.h"
#include "quanser_string.h"
#include "quanser_utf.h"
#include "quanser_types.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_start_time.h"
#include "quanser_extern.h"
#include "quanser_memory.h"
#include "stream_client_block.h"
#include "quanser_sigmoid.h"
#include "quanser_time.h"
#include "stream_server_block.h"
#include "quanser_ranging_sensor.h"
#endif                           /* QD2_DroneStack_PID_2021a_COMMON_INCLUDES_ */

#include "QD2_DroneStack_PID_2021a_types.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include <string.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTimerIndices
#define rtmGetMdlRefGlobalTimerIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalTimerIndices
#define rtmSetMdlRefGlobalTimerIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ()
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ()
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetProxyFunctions
#define rtmGetProxyFunctions(rtm)      ()
#endif

#ifndef rtmSetProxyFunctions
#define rtmSetProxyFunctions(rtm, val) ()
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ()
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStubFunctions
#define rtmGetStubFunctions(rtm)       ()
#endif

#ifndef rtmSetStubFunctions
#define rtmSetStubFunctions(rtm, val)  ()
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetclockTickHPtrsArray
#define rtmGetclockTickHPtrsArray(rtm) ()
#endif

#ifndef rtmSetclockTickHPtrsArray
#define rtmSetclockTickHPtrsArray(rtm, val) ()
#endif

#ifndef rtmGetclockTickPtrsArray
#define rtmGetclockTickPtrsArray(rtm)  ()
#endif

#ifndef rtmSetclockTickPtrsArray
#define rtmSetclockTickPtrsArray(rtm, val) ()
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetrateTransitionPtrsArray
#define rtmGetrateTransitionPtrsArray(rtm) ()
#endif

#ifndef rtmSetrateTransitionPtrsArray
#define rtmSetrateTransitionPtrsArray(rtm, val) ()
#endif

#ifndef rtmGettaskTimePtrsArray
#define rtmGettaskTimePtrsArray(rtm)   ()
#endif

#ifndef rtmSettaskTimePtrsArray
#define rtmSettaskTimePtrsArray(rtm, val) ()
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) <= 1)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
#define rtmSetFirstInitCond(rtm, val)  ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define QD2_DroneStack_PID_2021a_rtModel RT_MODEL_QD2_DroneStack_PID_2_T

/* Block signals for system '<S16>/Boolean Edge-Based Triggered Print' */
typedef struct {
  int32_T Print_o2;                    /* '<S26>/Print' */
} B_CoreSubsys_QD2_DroneStack_P_T;

/* Block states (default storage) for system '<S16>/Boolean Edge-Based Triggered Print' */
typedef struct {
  int8_T TriggeredSubsystem1_SubsysRanBC;/* '<S25>/Triggered Subsystem1' */
} DW_CoreSubsys_QD2_DroneStack__T;

/* Zero-crossing (trigger) state for system '<S16>/Boolean Edge-Based Triggered Print' */
typedef struct {
  ZCSigState TriggeredSubsystem1_Trig_ZCE;/* '<S25>/Triggered Subsystem1' */
} ZCE_CoreSubsys_QD2_DroneStack_T;

/* Block signals for system '<S18>/Boolean Value-Based Triggered Print' */
typedef struct {
  int32_T Print_o2;                    /* '<S30>/Print' */
} B_CoreSubsys_QD2_DroneStack_c_T;

/* Block states (default storage) for system '<S18>/Boolean Value-Based Triggered Print' */
typedef struct {
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S29>/Triggered Subsystem' */
} DW_CoreSubsys_QD2_DroneStac_f_T;

/* Zero-crossing (trigger) state for system '<S18>/Boolean Value-Based Triggered Print' */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S29>/Triggered Subsystem' */
} ZCE_CoreSubsys_QD2_DroneSta_f_T;

/* Block signals for system '<S13>/Use desired height when enabled' */
typedef struct {
  real_T h_dm1;                        /* '<S46>/h_d (m) [1]' */
} B_Usedesiredheightwhenenabled_T;

/* Block states (default storage) for system '<S13>/Use desired height when enabled' */
typedef struct {
  int8_T Usedesiredheightwhenenabled_Sub;
                                   /* '<S13>/Use desired height when enabled' */
  boolean_T Usedesiredheightwhenenabled_MOD;
                                   /* '<S13>/Use desired height when enabled' */
} DW_Usedesiredheightwhenenable_T;

/* Block signals for system '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
typedef struct {
  real_T Gain1[2];                     /* '<S82>/Gain1' */
  real_T Integrator1[3];               /* '<S84>/Integrator1' */
  real_T Product1[3];                  /* '<S84>/Product1' */
  real_T Product[3];                   /* '<S84>/Product' */
  real_T Product_i[3];                 /* '<S85>/Product' */
  real_T Product1_i[3];                /* '<S85>/Product1' */
  real_T Sum1[2];                      /* '<S82>/Sum1' */
} B_CoreSubsys_QD2_DroneStac_ca_T;

/* Block states (default storage) for system '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
typedef struct {
  int32_T sfEvent;
              /* '<S82>/Roll and Pitch Approximation from Accelerometer data' */
  boolean_T Integrator1_DWORK1;        /* '<S85>/Integrator1' */
  boolean_T Integrator1_DWORK1_n;      /* '<S84>/Integrator1' */
  boolean_T doneDoubleBufferReInit;
              /* '<S82>/Roll and Pitch Approximation from Accelerometer data' */
} DW_CoreSubsys_QD2_DroneSta_fw_T;

/* Continuous states for system '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
typedef struct {
  real_T Integrator1_CSTATE_b[3];      /* '<S85>/Integrator1' */
  real_T Integrator1_CSTATE_n[2];      /* '<S82>/Integrator1' */
  real_T Integrator2_CSTATE_od;        /* '<S82>/Integrator2' */
  real_T Integrator1_CSTATE_o[3];      /* '<S84>/Integrator1' */
  real_T Integrator2_CSTATE_i[3];      /* '<S84>/Integrator2' */
  real_T Integrator_CSTATE[2];         /* '<S82>/Integrator' */
  real_T Integrator2_CSTATE_k[3];      /* '<S85>/Integrator2' */
} X_CoreSubsys_QD2_DroneStac_ny_T;

/* State derivatives for system '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
typedef struct {
  real_T Integrator1_CSTATE_b[3];      /* '<S85>/Integrator1' */
  real_T Integrator1_CSTATE_n[2];      /* '<S82>/Integrator1' */
  real_T Integrator2_CSTATE_od;        /* '<S82>/Integrator2' */
  real_T Integrator1_CSTATE_o[3];      /* '<S84>/Integrator1' */
  real_T Integrator2_CSTATE_i[3];      /* '<S84>/Integrator2' */
  real_T Integrator_CSTATE[2];         /* '<S82>/Integrator' */
  real_T Integrator2_CSTATE_k[3];      /* '<S85>/Integrator2' */
} XDot_CoreSubsys_QD2_DroneS_n1_T;

/* State Disabled for system '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
typedef struct {
  boolean_T Integrator1_CSTATE_b[3];   /* '<S85>/Integrator1' */
  boolean_T Integrator1_CSTATE_n[2];   /* '<S82>/Integrator1' */
  boolean_T Integrator2_CSTATE_od;     /* '<S82>/Integrator2' */
  boolean_T Integrator1_CSTATE_o[3];   /* '<S84>/Integrator1' */
  boolean_T Integrator2_CSTATE_i[3];   /* '<S84>/Integrator2' */
  boolean_T Integrator_CSTATE[2];      /* '<S82>/Integrator' */
  boolean_T Integrator2_CSTATE_k[3];   /* '<S85>/Integrator2' */
} XDis_CoreSubsys_QD2_DroneS_ne_T;

/* Block signals (default storage) */
typedef struct {
  real_T HILRead_o1[3];                /* '<S5>/HIL Read' */
  real_T HILRead_o2[23];               /* '<S5>/HIL Read' */
  real_T StreamClient_o4[16];          /* '<S2>/Stream Client' */
  real_T DataTypeConversion1;          /* '<S1>/Data Type Conversion1' */
  real_T DataTypeConversion;           /* '<S5>/Data Type Conversion' */
  real_T Product;                      /* '<S1>/Product' */
  real_T ContinuousSigmoid_o1;         /* '<S13>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_o2;         /* '<S13>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_o3;         /* '<S13>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_o4;         /* '<S13>/Continuous Sigmoid' */
  real_T Memory;                       /* '<S1>/Memory' */
  real_T Switch2;                      /* '<S44>/Switch2' */
  real_T Integrator1;                  /* '<S3>/Integrator1' */
  real_T IFtoHRrotationmatrix[9];      /* '<S3>/Transpose' */
  real_T ContinuousSigmoid_o1_a;       /* '<S51>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_o2_l;       /* '<S51>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_o3_b;       /* '<S51>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_o4_m;       /* '<S51>/Continuous Sigmoid' */
  real_T ContinuousSigmoid1_o1;        /* '<S51>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_o2;        /* '<S51>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_o3;        /* '<S51>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_o4;        /* '<S51>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid2_o1;        /* '<S51>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_o2;        /* '<S51>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_o3;        /* '<S51>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_o4;        /* '<S51>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid3_o1;        /* '<S51>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_o2;        /* '<S51>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_o3;        /* '<S51>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_o4;        /* '<S51>/Continuous Sigmoid3' */
  real_T Switch2_m[4];                 /* '<S57>/Switch2' */
  real_T Gain[4];                      /* '<S1>/Gain' */
  real_T SelectDataforIMU1[9];         /* '<S63>/Select Data for IMU1' */
  real_T SelectDataforIMU0[9];         /* '<S63>/Select Data for IMU0' */
  real_T Product3[9];                  /* '<S5>/Product3' */
  real_T Product4[6];                  /* '<S5>/Product4' */
  real_T Product1[3];                  /* '<S3>/Product1' */
  real_T UnsaturatedControllerCommandsNr[4];/* '<S1>/Sum2' */
  real_T Integrator1_o[2];             /* '<S39>/Integrator1' */
  real_T GeneralizedCommandNradradrads4[4];/* '<S1>/ ' */
  real_T RateLimiterNs;                /* '<S13>/Rate Limiter (N//s)' */
  real_T NetThrottle;                  /* '<S13>/(N)' */
  real_T SpecifyAngleModeforStabilizerDO;
                  /* '<S1>/Specify Angle Mode for Stabilizer (DO NOT CHANGE)' */
  real_T AttitudeTorqueCommands[3];    /* '<S7>/Switch' */
  real_T DataTypeConversion_k;         /* '<S13>/Data Type Conversion' */
  real_T AttitudeAngleCommands[3];   /* '<S7>/Saturate Stabilization Command' */
  real_T Sum6[3];                      /* '<S7>/Sum6' */
  real_T SaturationCommandAuthorityNm1[3];
                                /* '<S7>/Saturation Command  Authority (Nm)1' */
  real_T Delay;                        /* '<S7>/Delay' */
  real_T MaximumCommandAuthority[4];   /* '<S5>/Maximum  Command Authority ' */
  real_T Selector[4];                  /* '<S64>/Selector' */
  real_T RateTransition7[2];           /* '<S5>/Rate Transition7' */
  real_T RateTransition2;              /* '<S5>/Rate Transition2' */
  real_T RateTransition1;              /* '<S5>/Rate Transition1' */
  real_T ExtractESCChannels[4];        /* '<S5>/Extract ESC Channels' */
  real_T ComputationTime;              /* '<S81>/Computation Time' */
  real_T SampleTime;                   /* '<S81>/Sample Time' */
  real_T RateTransition;               /* '<S81>/Rate Transition' */
  real_T RateTransition1_n;            /* '<S81>/Rate Transition1' */
  real_T RateTransition2_m;            /* '<S81>/Rate Transition2' */
  real_T RateTransition3;              /* '<S81>/Rate Transition3' */
  real_T RateTransition6[60];          /* '<S5>/Rate Transition6' */
  real_T Bias1[4];                     /* '<S64>/Bias1' */
  real_T Delay3;                       /* '<S70>/Delay3' */
  real_T Delay2;                       /* '<S70>/Delay2' */
  real_T Delay1;                       /* '<S70>/Delay1' */
  real_T Delay_n;                      /* '<S70>/Delay' */
  real_T DataTypeConversion_n;         /* '<S96>/Data Type Conversion' */
  real_T DataTypeConversion_o;         /* '<S98>/Data Type Conversion' */
  real_T DataTypeConversion_a;         /* '<S99>/Data Type Conversion' */
  real_T DataTypeConversion_ai;        /* '<S100>/Data Type Conversion' */
  real_T DataTypeConversion_d;         /* '<S101>/Data Type Conversion' */
  real_T DataTypeConversion_a2;        /* '<S102>/Data Type Conversion' */
  real_T DataTypeConversion_p;         /* '<S103>/Data Type Conversion' */
  real_T DataTypeConversion_b;         /* '<S104>/Data Type Conversion' */
  real_T DataTypeConversion_nn;        /* '<S105>/Data Type Conversion' */
  real_T DataTypeConversion_h;         /* '<S106>/Data Type Conversion' */
  real_T DataTypeConversion_l;         /* '<S107>/Data Type Conversion' */
  real_T DataTypeConversion_df;        /* '<S108>/Data Type Conversion' */
  real_T DataTypeConversion_hb;        /* '<S109>/Data Type Conversion' */
  real_T DataTypeConversion_e;         /* '<S80>/Data Type Conversion' */
  real_T UnitDelay;                    /* '<Root>/Unit Delay' */
  real_T Clock1;                       /* '<S47>/Clock1' */
  real_T DataTypeConversion4;          /* '<S47>/Data Type Conversion4' */
  real_T Abs;                          /* '<S22>/Abs' */
  real_T Abs1;                         /* '<S22>/Abs1' */
  real_T DataTypeConversion3;          /* '<S1>/Data Type Conversion3' */
  real_T DataTypeConversion12;         /* '<S10>/Data Type Conversion12' */
  real_T DataTypeConversion11;         /* '<S10>/Data Type Conversion11' */
  real_T DataTypeConversion10;         /* '<S10>/Data Type Conversion10' */
  real_T DataTypeConversion2;          /* '<S10>/Data Type Conversion2' */
  real_T DataTypeConversion6[17];      /* '<S1>/Data Type Conversion6' */
  real_T DataTypeConversion4_a;        /* '<S1>/Data Type Conversion4' */
  real_T DataTypeConversion2_l;        /* '<S1>/Data Type Conversion2' */
  real_T TmpSignalConversionAtToHostFile[36];
  real_T Gain1[4];                     /* '<S1>/Gain1' */
  real_T DataTypeConversion9[4];       /* '<S10>/Data Type Conversion9' */
  real_T SensorIssue;                  /* '<S10>/Data Type Conversion5' */
  real_T DataTypeConversion_e3;        /* '<S21>/Data Type Conversion' */
  real_T Product_i[2];                 /* '<S39>/Product' */
  real_T Product1_m[2];                /* '<S39>/Product1' */
  real_T DataTypeConversion_i;         /* '<S14>/Data Type Conversion' */
  real_T DataTypeConversion_ni;        /* '<S49>/Data Type Conversion' */
  real_T DataTypeConversion_l2;        /* '<S50>/Data Type Conversion' */
  real_T Ki1;                          /* '<S3>/Ki1' */
  real_T Product1_j[3];                /* '<S52>/Product1' */
  real_T Ki3[3];                       /* '<S3>/Ki3' */
  real_T Product_b[3];                 /* '<S52>/Product' */
  real_T Sum2;                         /* '<S3>/Sum2' */
  real_T IFAccelerometerdatamss3[3];   /* '<S3>/gravity correction' */
  real_T Sum9[3];                      /* '<S3>/Sum9' */
  real_T Gain_f[6];                    /* '<S111>/Gain' */
  real_T Gain_k[6];                    /* '<S112>/Gain' */
  real_T SampleTime_d;                 /* '<S110>/Sample Time' */
  real_T ComputationTime_l;            /* '<S110>/Computation Time' */
  real_T DataTypeConversion4_f;        /* '<S110>/Data Type Conversion4' */
  real_T DataTypeConversion1_i;        /* '<S110>/Data Type Conversion1' */
  real_T DataTypeConversion5;          /* '<S110>/Data Type Conversion5' */
  real_T TmpSignalConversionAtToHostFi_a[20];
  real_T DataTypeConversion_m;         /* '<S113>/Data Type Conversion' */
  real_T DataTypeConversion_ah;        /* '<S114>/Data Type Conversion' */
  real_T StreamServer_o4;              /* '<S5>/Stream Server' */
  real_T RateTransition_p[7];          /* '<S5>/Rate Transition' */
  real_T x0;                           /* '<S72>/x0' */
  real_T Product_j[2];                 /* '<S72>/Product' */
  real_T Product1_d[2];                /* '<S72>/Product1' */
  real_T ToFFilterInitialConditionm;
                                   /* '<S5>/ToF Filter Initial Condition (m)' */
  real_T RangingSensor_o1;             /* '<S5>/Ranging Sensor' */
  real_T RangingSensor_o2;             /* '<S5>/Ranging Sensor' */
  real_T RangingSensor_o3;             /* '<S5>/Ranging Sensor' */
  real_T RangingSensor_o4;             /* '<S5>/Ranging Sensor' */
  real_T Product_g;                    /* '<S71>/Product' */
  real_T Product1_g;                   /* '<S71>/Product1' */
  real_T OutportBufferForOut1;         /* '<S97>/Constant' */
  real_T cmd[4];                       /* '<S5>/MATLAB Function' */
  real_T cmd_enable;                   /* '<S5>/MATLAB Function' */
  real_T tele_enable;                  /* '<S5>/MATLAB Function' */
  real_T esc_ready;                    /* '<S5>/MATLAB Function' */
  real_T esc_timeout;                  /* '<S5>/MATLAB Function' */
  real_T state;                        /* '<S5>/MATLAB Function' */
  real_T n[4];                         /* '<S70>/MATLAB Function' */
  real_T ImpAsg_InsertedFor_ESCDataOut4_[4];/* '<S89>/Switch' */
  real_T ImpAsg_InsertedFor_ESCDataOut_k[4];/* '<S88>/Switch' */
  real_T ImpAsg_InsertedFor_ESCDataOu_kc[4];/* '<S87>/Switch' */
  real_T enable;                       /* '<S51>/MATLAB Function4' */
  real_T yaw_ref;                      /* '<S51>/MATLAB Function4' */
  real_T max_yaw_vel;                  /* '<S51>/MATLAB Function4' */
  real_T max_yaw_accel;                /* '<S51>/MATLAB Function4' */
  real_T enable_c;                     /* '<S51>/MATLAB Function2' */
  real_T height_ref;                   /* '<S51>/MATLAB Function2' */
  real_T max_height_vel;               /* '<S51>/MATLAB Function2' */
  real_T max_height_accel;             /* '<S51>/MATLAB Function2' */
  real_T enable_n;                     /* '<S51>/MATLAB Function1' */
  real_T y_ref;                        /* '<S51>/MATLAB Function1' */
  real_T max_y_vel;                    /* '<S51>/MATLAB Function1' */
  real_T max_y_accel;                  /* '<S51>/MATLAB Function1' */
  real_T enable_k;                     /* '<S51>/MATLAB Function' */
  real_T x_ref;                        /* '<S51>/MATLAB Function' */
  real_T max_x_vel;                    /* '<S51>/MATLAB Function' */
  real_T max_x_accel;                  /* '<S51>/MATLAB Function' */
  real_T enable_d;               /* '<S13>/Hover Throttle Sigmoid Parameters' */
  real_T throttle_ref;           /* '<S13>/Hover Throttle Sigmoid Parameters' */
  real_T max_throttle_vel;       /* '<S13>/Hover Throttle Sigmoid Parameters' */
  real_T max_throttle_accel;     /* '<S13>/Hover Throttle Sigmoid Parameters' */
  real_T Next_state;                   /* '<S1>/STATE MACHINE TRANSITION' */
  int32_T StreamClient_o2;             /* '<S2>/Stream Client' */
  int32_T RateTransition14;            /* '<S5>/Rate Transition14' */
  int32_T Print_o2;                    /* '<S28>/Print' */
  uint8_T ModelArgument[80];           /* '<S2>/Model Argument' */
  uint8_T StreamClient_o1;             /* '<S2>/Stream Client' */
  uint8_T MatrixConcatenate[240];      /* '<S16>/Matrix Concatenate' */
  uint8_T RateTransition16;            /* '<S5>/Rate Transition16' */
  boolean_T DataTypeConversion_pb[4];  /* '<S10>/Data Type Conversion' */
  boolean_T DataTypeConversion22;      /* '<S10>/Data Type Conversion22' */
  boolean_T DataTypeConversion24;      /* '<S10>/Data Type Conversion24' */
  boolean_T Compare;                   /* '<S8>/Compare' */
  boolean_T AND[4];                    /* '<S70>/AND' */
  boolean_T LogicalOperator;           /* '<S96>/Logical Operator' */
  boolean_T LogicalOperator_b;         /* '<S98>/Logical Operator' */
  boolean_T LogicalOperator_a;         /* '<S99>/Logical Operator' */
  boolean_T LogicalOperator_bu;        /* '<S102>/Logical Operator' */
  boolean_T LogicalOperator_m;         /* '<S103>/Logical Operator' */
  boolean_T LogicalOperator_l;         /* '<S104>/Logical Operator' */
  boolean_T LogicalOperator_l3;        /* '<S105>/Logical Operator' */
  boolean_T LogicalOperator_o;         /* '<S106>/Logical Operator' */
  boolean_T LogicalOperator_ms;        /* '<S107>/Logical Operator' */
  boolean_T LogicalOperator_og;        /* '<S108>/Logical Operator' */
  boolean_T LogicalOperator_on;        /* '<S109>/Logical Operator' */
  boolean_T LogicalOperator_lm;        /* '<S100>/Logical Operator' */
  boolean_T LogicalOperator_i;         /* '<S101>/Logical Operator' */
  boolean_T OR;                        /* '<S5>/OR' */
  boolean_T LogicalOperator_p;         /* '<S80>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S80>/Relational Operator' */
  boolean_T LogicalOperator3;          /* '<S10>/Logical Operator3' */
  boolean_T LogicalOperator_ab;        /* '<S21>/Logical Operator' */
  boolean_T RelationalOperator_g;      /* '<S21>/Relational Operator' */
  boolean_T LogicalOperator_f;         /* '<S49>/Logical Operator' */
  boolean_T RelationalOperator_i;      /* '<S49>/Relational Operator' */
  boolean_T LogicalOperator_ft;        /* '<S50>/Logical Operator' */
  boolean_T RelationalOperator_h;      /* '<S50>/Relational Operator' */
  boolean_T DataTypeConversion4_fx;    /* '<S10>/Data Type Conversion4' */
  boolean_T DataTypeConversion23;      /* '<S10>/Data Type Conversion23' */
  boolean_T Compare_c;                 /* '<S22>/Compare' */
  boolean_T Compare1;                  /* '<S22>/Compare1' */
  boolean_T Compare2;                  /* '<S22>/Compare2' */
  boolean_T LogicalOperator_mx;        /* '<S19>/Logical Operator' */
  boolean_T LogicalOperator2;          /* '<S19>/Logical Operator2' */
  boolean_T checkifmeasuredheightexceedsmax;
  /* '<S19>/check if measured height exceeds maximum height safety threshold' */
  boolean_T LogicalOperator3_e;        /* '<S19>/Logical Operator3' */
  boolean_T LogicalOperator_bd;        /* '<S14>/Logical Operator' */
  boolean_T TmpSignalConversionAtBooleanEdg[3];
  boolean_T DataTypeConversion2_o;     /* '<S24>/Data Type Conversion2' */
  boolean_T DataTypeConversion5_c;     /* '<S24>/Data Type Conversion5' */
  boolean_T DataTypeConversion_f;      /* '<S24>/Data Type Conversion' */
  boolean_T DataTypeConversion8;       /* '<S24>/Data Type Conversion8' */
  boolean_T DataTypeConversion14;      /* '<S24>/Data Type Conversion14' */
  boolean_T DataTypeConversion9_m;     /* '<S24>/Data Type Conversion9' */
  boolean_T DataTypeConversion10_a;    /* '<S24>/Data Type Conversion10' */
  boolean_T DataTypeConversion11_h;    /* '<S24>/Data Type Conversion11' */
  boolean_T DataTypeConversion12_i;    /* '<S24>/Data Type Conversion12' */
  boolean_T LogicalOperator_bx;        /* '<S114>/Logical Operator' */
  boolean_T RelationalOperator_e;      /* '<S114>/Relational Operator' */
  boolean_T LogicalOperator_c;         /* '<S113>/Logical Operator' */
  boolean_T RelationalOperator_gi;     /* '<S113>/Relational Operator' */
  boolean_T HILWatchdog;               /* '<S110>/HIL Watchdog' */
  boolean_T AND_f;                     /* '<S5>/AND' */
  boolean_T Input;                     /* '<S20>/Input' */
  B_CoreSubsys_QD2_DroneStac_ca_T CoreSubsys_pn[2];
                   /* '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
  B_Usedesiredheightwhenenabled_T UsedesiredYwhenenabled;/* '<S51>/Use desired Y  when enabled' */
  B_Usedesiredheightwhenenabled_T UsedesiredXwhenenabled;/* '<S51>/Use desired X  when enabled' */
  B_Usedesiredheightwhenenabled_T Usedesyawwhenenabled;/* '<S51>/Use des yaw  when enabled' */
  B_Usedesiredheightwhenenabled_T Usedesheightwhenenabled;
                                      /* '<S51>/Use des height  when enabled' */
  B_Usedesiredheightwhenenabled_T Usedesiredheightwhenenabled_c;
                                   /* '<S13>/Use desired height when enabled' */
  B_CoreSubsys_QD2_DroneStack_c_T CoreSubsys_p[9];
                               /* '<S18>/Boolean Value-Based Triggered Print' */
  B_CoreSubsys_QD2_DroneStack_P_T CoreSubsys[3];
                                /* '<S16>/Boolean Edge-Based Triggered Print' */
} B_QD2_DroneStack_PID_2021a_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  t_ranging_measurement RangingSensor_Measurements;/* '<S5>/Ranging Sensor' */
  t_timeout Time_Timeout;              /* '<S5>/Time' */
  t_timeout ComputationTime_BeginTime; /* '<S81>/Computation Time' */
  t_timeout ComputationTime_ComputationTime;/* '<S81>/Computation Time' */
  t_timeout SampleTime_PreviousTime;   /* '<S81>/Sample Time' */
  t_timeout Time_Timeout_d;            /* '<S10>/Time' */
  t_timeout SampleTime_PreviousTime_d; /* '<S110>/Sample Time' */
  t_timeout ComputationTime_BeginTime_g;/* '<S110>/Computation Time' */
  t_timeout ComputationTime_ComputationTi_o;/* '<S110>/Computation Time' */
  t_timeout ComputationTime1_BeginTime;/* '<S81>/Computation Time1' */
  t_timeout ComputationTime1_ComputationTim;/* '<S81>/Computation Time1' */
  t_timeout SampleTime1_PreviousTime;  /* '<S81>/Sample Time1' */
  t_timeout ComputationTime2_BeginTime;/* '<S81>/Computation Time2' */
  t_timeout ComputationTime2_ComputationTim;/* '<S81>/Computation Time2' */
  t_timeout SampleTime2_PreviousTime;  /* '<S81>/Sample Time2' */
  real_T Delay_DSTATE[100];            /* '<S7>/Delay' */
  real_T Delay3_DSTATE[2];             /* '<S70>/Delay3' */
  real_T Delay2_DSTATE[2];             /* '<S70>/Delay2' */
  real_T Delay1_DSTATE[2];             /* '<S70>/Delay1' */
  real_T Delay_DSTATE_e[2];            /* '<S70>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S96>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S98>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S99>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S102>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S103>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S104>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S105>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S106>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S107>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_h;/* '<S108>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_n1;/* '<S109>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S100>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S101>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_bm;/* '<S80>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTAT_jy;/* '<S21>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S49>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S50>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_ja;/* '<S14>/Discrete-Time Integrator' */
  real_T DelayInput1_DSTATE;           /* '<S27>/Delay Input1' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S114>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_fv;/* '<S113>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_a1[2];/* '<S72>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S72>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTAT_ax;/* '<S71>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTAT_l;/* '<S71>/Discrete-Time Integrator1' */
  real_T HILInitialize_AIMinimums[4];  /* '<S5>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[4];  /* '<S5>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[2];/* '<S5>/HIL Initialize' */
  real_T HILInitialize_POSortedFreqs[6];/* '<S5>/HIL Initialize' */
  real_T HILInitialize_POValues[6];    /* '<S5>/HIL Initialize' */
  real_T Memory_PreviousInput;         /* '<S2>/Memory' */
  real_T Memory_PreviousInput_f;       /* '<S5>/Memory' */
  real_T ContinuousSigmoid_Sigmoid[11];/* '<S13>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_Time;       /* '<S13>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_Target;     /* '<S13>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_PPos;       /* '<S13>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_PVel;       /* '<S13>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_MVel;       /* '<S13>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_MAcc;       /* '<S13>/Continuous Sigmoid' */
  real_T Memory_PreviousInput_e;       /* '<S1>/Memory' */
  real_T ContinuousSigmoid_Sigmoid_l[11];/* '<S51>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_Time_c;     /* '<S51>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_Target_d;   /* '<S51>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_PPos_a;     /* '<S51>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_PVel_p;     /* '<S51>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_MVel_l;     /* '<S51>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_MAcc_p;     /* '<S51>/Continuous Sigmoid' */
  real_T ContinuousSigmoid1_Sigmoid[11];/* '<S51>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_Time;      /* '<S51>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_Target;    /* '<S51>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_PPos;      /* '<S51>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_PVel;      /* '<S51>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_MVel;      /* '<S51>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_MAcc;      /* '<S51>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid2_Sigmoid[11];/* '<S51>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_Time;      /* '<S51>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_Target;    /* '<S51>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_PPos;      /* '<S51>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_PVel;      /* '<S51>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_MVel;      /* '<S51>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_MAcc;      /* '<S51>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid3_Sigmoid[11];/* '<S51>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_Time;      /* '<S51>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_Target;    /* '<S51>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_PPos;      /* '<S51>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_PVel;      /* '<S51>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_MVel;      /* '<S51>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_MAcc;      /* '<S51>/Continuous Sigmoid3' */
  real_T PrevY;                        /* '<S13>/Rate Limiter (N//s)' */
  real_T LastMajorTime;                /* '<S13>/Rate Limiter (N//s)' */
  real_T RateTransition7_Buffer0[2];   /* '<S5>/Rate Transition7' */
  real_T RateTransition2_Buffer0;      /* '<S5>/Rate Transition2' */
  real_T RateTransition1_Buffer0;      /* '<S5>/Rate Transition1' */
  real_T Memory_PreviousInput_a[4];    /* '<S67>/Memory' */
  real_T Memory_PreviousInput_as[4];   /* '<S69>/Memory' */
  real_T RateTransition_Buffer0;       /* '<S81>/Rate Transition' */
  real_T RateTransition1_Buffer0_m;    /* '<S81>/Rate Transition1' */
  real_T RateTransition2_Buffer0_m;    /* '<S81>/Rate Transition2' */
  real_T RateTransition3_Buffer0;      /* '<S81>/Rate Transition3' */
  real_T Memory_PreviousInput_n[4];    /* '<S68>/Memory' */
  real_T RateTransition_Buffer[7];     /* '<S5>/Rate Transition' */
  real_T RateTransition10_Buffer[4];   /* '<S5>/Rate Transition10' */
  real_T RateTransition11_Buffer;      /* '<S5>/Rate Transition11' */
  real_T RateTransition12_Buffer;      /* '<S5>/Rate Transition12' */
  real_T RateTransition15_Buffer[9];   /* '<S5>/Rate Transition15' */
  real_T RateTransition17_Buffer[9];   /* '<S5>/Rate Transition17' */
  real_T RateTransition19_Buffer[9];   /* '<S5>/Rate Transition19' */
  real_T RateTransition20_Buffer;      /* '<S5>/Rate Transition20' */
  real_T RateTransition3_Buffer[9];    /* '<S5>/Rate Transition3' */
  real_T RateTransition8_Buffer[12];   /* '<S5>/Rate Transition8' */
  real_T Memory2_PreviousInput;        /* '<S5>/Memory2' */
  real_T next_state_after_pause;       /* '<S5>/MATLAB Function' */
  real_T state_counter;                /* '<S5>/MATLAB Function' */
  real_T state_counter_after_pause;    /* '<S5>/MATLAB Function' */
  real_T esc_timeout_state;            /* '<S5>/MATLAB Function' */
  real_T idx;                          /* '<S70>/MATLAB Function' */
  real_T state;                        /* '<S64>/MATLAB Function' */
  real_T ms_time_prev;                 /* '<S47>/MATLAB Function' */
  t_uint64 ToHostFile_PointsWritten;   /* '<S5>/To Host File' */
  t_uint64 ToHostFile_PointsWritten_l; /* '<S1>/To Host File' */
  t_uint64 ToHostFile_PointsWritten_p; /* '<S7>/To Host File' */
  t_pstream StreamClient_Stream;       /* '<S2>/Stream Client' */
  t_pstream StreamServer_Stream;       /* '<S5>/Stream Server' */
  t_ranging_sensor RangingSensor_Sensor;/* '<S5>/Ranging Sensor' */
  t_card HILInitialize_Card;           /* '<S5>/HIL Initialize' */
  void *HILRead_PWORK;                 /* '<S5>/HIL Read' */
  struct {
    void *LoggedData;
  } ESCSelectRaw_PWORK;                /* '<S5>/ESC Select Raw' */

  void *HILWriteDigital_PWORK;         /* '<S5>/HIL Write Digital' */
  void *ToHostFile_PWORK[2];           /* '<S5>/To Host File' */
  struct {
    void *LoggedData;
  } Telemetry_PWORK;                   /* '<S64>/Telemetry' */

  struct {
    void *LoggedData[4];
  } ESCChannelMismatrch_PWORK;         /* '<S70>/ESC Channel Mismatrch' */

  struct {
    void *LoggedData[4];
  } ESCChannelMismatrchCount_PWORK;    /* '<S70>/ESC Channel Mismatrch Count' */

  struct {
    void *LoggedData[4];
  } ESCChannelSelectionIndex_PWORK;    /* '<S70>/ESC Channel Selection Index' */

  struct {
    void *LoggedData[3];
  } TimingCheck_PWORK;                 /* '<S81>/Timing Check' */

  struct {
    void *LoggedData;
  } Generalizedcommands_PWORK;         /* '<S1>/Generalized  commands ' */

  void *ToHostFile_PWORK_p[2];         /* '<S1>/To Host File' */
  struct {
    void *LoggedData[12];
  } FSM_PWORK;                         /* '<S10>/FSM' */

  struct {
    void *LoggedData[4];
  } HeightCheck_PWORK;                 /* '<S10>/Height Check ' */

  struct {
    void *LoggedData[4];
  } JoystickInfo_PWORK;                /* '<S10>/Joystick Info' */

  struct {
    void *LoggedData[3];
  } ThrottleCheck_PWORK;               /* '<S10>/Throttle Check' */

  struct {
    void *LoggedData[2];
  } CommunicationLoss_PWORK;           /* '<S47>/Communication Loss' */

  struct {
    void *LoggedData[4];
  } IFPoseTrackingPerformanceTracki;
                           /* '<S3>/IF Pose Tracking  (Performance Tracking)' */

  struct {
    void *LoggedData[2];
  } RollandPitchAngleControldeg_PWO;
                                 /* '<S7>/Roll and Pitch Angle Control (deg)' */

  struct {
    void *LoggedData[3];
  } RollPitchandYawRateControldegs_;
                          /* '<S7>/Roll, Pitch and Yaw Rate Control (deg//s)' */

  void *HILWatchdog_PWORK;             /* '<S110>/HIL Watchdog' */
  void *ToHostFile_PWORK_k[2];         /* '<S7>/To Host File' */
  struct {
    void *LoggedData;
  } ComputationTimes_PWORK;            /* '<S110>/Computation Time (s)' */

  struct {
    void *LoggedData;
  } SampleTimes_PWORK;                 /* '<S110>/Sample Time (s)' */

  void *HILWritePWM_PWORK;             /* '<S73>/HIL Write PWM' */
  emxArray_real_T_QD2_DroneStac_T* buffer;/* '<S70>/MATLAB Function' */
  int32_T HILInitialize_DOStates[6];   /* '<S5>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[2];/* '<S5>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[2];/* '<S5>/HIL Initialize' */
  int32_T HILInitialize_POModeValues[6];/* '<S5>/HIL Initialize' */
  int32_T HILInitialize_POAlignValues[6];/* '<S5>/HIL Initialize' */
  int32_T HILInitialize_POPolarityVals[6];/* '<S5>/HIL Initialize' */
  int32_T sfEvent;                     /* '<S5>/MATLAB Function' */
  int32_T sfEvent_n;                   /* '<S5>/Force to percentage Mapping' */
  int32_T sfEvent_c;                   /* '<S70>/MATLAB Function' */
  int32_T sfEvent_nd;                  /* '<S64>/MATLAB Function' */
  int32_T sfEvent_b;                   /* '<S51>/Signmoid Type' */
  int32_T sfEvent_i;                   /* '<S51>/MATLAB Function4' */
  int32_T sfEvent_id;                  /* '<S51>/MATLAB Function2' */
  int32_T sfEvent_iv;                  /* '<S51>/MATLAB Function1' */
  int32_T sfEvent_o;                   /* '<S51>/MATLAB Function' */
  int32_T sfEvent_l;                   /* '<S47>/MATLAB Function' */
  int32_T sfEvent_np;                  /* '<S13>/Throttle Switchbox' */
  int32_T sfEvent_m;             /* '<S13>/Hover Throttle Sigmoid Parameters' */
  int32_T sfEvent_e;                   /* '<S1>/STATE MACHINE TRANSITION' */
  int32_T sfEvent_cx;                  /* '<S1>/STATE MACHINE LOGIC' */
  uint32_T HILInitialize_POSortedChans[6];/* '<S5>/HIL Initialize' */
  uint32_T ToHostFile_SamplesCount;    /* '<S5>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength; /* '<S5>/To Host File' */
  uint32_T ToHostFile_SamplesCount_h;  /* '<S1>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength_e;/* '<S1>/To Host File' */
  uint32_T ToHostFile_SamplesCount_n;  /* '<S7>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength_f;/* '<S7>/To Host File' */
  int_T StringDisplay_IWORK[2];        /* '<S2>/String Display' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S96>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S98>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S99>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S102>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_oi;/* '<S103>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S104>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_n;/* '<S105>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_p5;/* '<S106>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S107>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_nn;/* '<S108>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_eu;/* '<S109>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_gx;/* '<S100>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S101>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_oj;/* '<S80>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_dp;/* '<S21>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_l;/* '<S49>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_gh;/* '<S50>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_a;/* '<S14>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_df;/* '<S114>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_az;/* '<S113>/Discrete-Time Integrator' */
  int8_T TriggeredSubsystemLatchingFlag_;
                               /* '<S77>/Triggered Subsystem - Latching Flag' */
  int8_T EnabledSubsystemWriteESCCommand;
                            /* '<S5>/Enabled Subsystem -  Write ESC Commands' */
  int8_T LatchEStop_SubsysRanBC;       /* '<S10>/Latch E-Stop' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S17>/Triggered Subsystem' */
  uint8_T ContinuousSigmoid_Flag;      /* '<S13>/Continuous Sigmoid' */
  uint8_T ContinuousSigmoid_Flag_h;    /* '<S51>/Continuous Sigmoid' */
  uint8_T ContinuousSigmoid1_Flag;     /* '<S51>/Continuous Sigmoid1' */
  uint8_T ContinuousSigmoid2_Flag;     /* '<S51>/Continuous Sigmoid2' */
  uint8_T ContinuousSigmoid3_Flag;     /* '<S51>/Continuous Sigmoid3' */
  boolean_T HILInitialize_DOBits[6];   /* '<S5>/HIL Initialize' */
  boolean_T Time_Owner;                /* '<S5>/Time' */
  boolean_T StreamClient_Connected;    /* '<S2>/Stream Client' */
  boolean_T Memory1_PreviousInput;     /* '<S5>/Memory1' */
  boolean_T Integrator1_DWORK1;        /* '<S39>/Integrator1' */
  boolean_T PrevLimited;               /* '<S13>/Rate Limiter (N//s)' */
  boolean_T Time_Owner_h;              /* '<S10>/Time' */
  boolean_T Integrator1_DWORK1_p;      /* '<S52>/Integrator1' */
  boolean_T HILWatchdog_IsStarted;     /* '<S110>/HIL Watchdog' */
  boolean_T Memory3_PreviousInput;     /* '<S5>/Memory3' */
  boolean_T doneDoubleBufferReInit;    /* '<S5>/MATLAB Function' */
  boolean_T next_state_after_pause_not_empt;/* '<S5>/MATLAB Function' */
  boolean_T state_counter_not_empty;   /* '<S5>/MATLAB Function' */
  boolean_T state_counter_after_pause_not_e;/* '<S5>/MATLAB Function' */
  boolean_T esc_timeout_state_not_empty;/* '<S5>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_g;  /* '<S5>/Force to percentage Mapping' */
  boolean_T doneDoubleBufferReInit_a;  /* '<S70>/MATLAB Function' */
  boolean_T idx_not_empty;             /* '<S70>/MATLAB Function' */
  boolean_T buffer_not_empty;          /* '<S70>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_b;  /* '<S64>/MATLAB Function' */
  boolean_T state_not_empty;           /* '<S64>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_ai; /* '<S51>/Signmoid Type' */
  boolean_T doneDoubleBufferReInit_h;  /* '<S51>/MATLAB Function4' */
  boolean_T doneDoubleBufferReInit_i;  /* '<S51>/MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_l;  /* '<S51>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_hj; /* '<S51>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_af; /* '<S47>/MATLAB Function' */
  boolean_T ms_time_prev_not_empty;    /* '<S47>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S13>/Throttle Switchbox' */
  boolean_T doneDoubleBufferReInit_k;
                                 /* '<S13>/Hover Throttle Sigmoid Parameters' */
  boolean_T doneDoubleBufferReInit_b3; /* '<S1>/STATE MACHINE TRANSITION' */
  boolean_T doneDoubleBufferReInit_o;  /* '<S1>/STATE MACHINE LOGIC' */
  t_boolean HILWriteDigital_Buffer[6]; /* '<S5>/HIL Write Digital' */
  DW_CoreSubsys_QD2_DroneSta_fw_T CoreSubsys_pn[2];
                   /* '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
  DW_Usedesiredheightwhenenable_T UsedesiredYwhenenabled;/* '<S51>/Use desired Y  when enabled' */
  DW_Usedesiredheightwhenenable_T UsedesiredXwhenenabled;/* '<S51>/Use desired X  when enabled' */
  DW_Usedesiredheightwhenenable_T Usedesyawwhenenabled;/* '<S51>/Use des yaw  when enabled' */
  DW_Usedesiredheightwhenenable_T Usedesheightwhenenabled;
                                      /* '<S51>/Use des height  when enabled' */
  DW_Usedesiredheightwhenenable_T Usedesiredheightwhenenabled_c;
                                   /* '<S13>/Use desired height when enabled' */
  DW_CoreSubsys_QD2_DroneStac_f_T CoreSubsys_p[9];
                               /* '<S18>/Boolean Value-Based Triggered Print' */
  DW_CoreSubsys_QD2_DroneStack__T CoreSubsys[3];
                                /* '<S16>/Boolean Edge-Based Triggered Print' */
} DW_QD2_DroneStack_PID_2021a_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S3>/Integrator1' */
  real_T Integrator1_CSTATE_f[4];      /* '<S1>/Integrator1' */
  real_T Integrator6_CSTATE[3];        /* '<S3>/Integrator6' */
  real_T Integrator1_CSTATE_h[2];      /* '<S39>/Integrator1' */
  real_T Integrator2_CSTATE[2];        /* '<S39>/Integrator2' */
  real_T Integrator2_CSTATE_o;         /* '<S3>/Integrator2' */
  real_T Integrator7_CSTATE[3];        /* '<S3>/Integrator7' */
  real_T Integrator2_CSTATE_c[3];      /* '<S52>/Integrator2' */
  real_T Integrator1_CSTATE_j[3];      /* '<S52>/Integrator1' */
  X_CoreSubsys_QD2_DroneStac_ny_T CoreSubsys_pn[2];/* '<S82>/CoreSubsys' */
} X_QD2_DroneStack_PID_2021a_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S3>/Integrator1' */
  real_T Integrator1_CSTATE_f[4];      /* '<S1>/Integrator1' */
  real_T Integrator6_CSTATE[3];        /* '<S3>/Integrator6' */
  real_T Integrator1_CSTATE_h[2];      /* '<S39>/Integrator1' */
  real_T Integrator2_CSTATE[2];        /* '<S39>/Integrator2' */
  real_T Integrator2_CSTATE_o;         /* '<S3>/Integrator2' */
  real_T Integrator7_CSTATE[3];        /* '<S3>/Integrator7' */
  real_T Integrator2_CSTATE_c[3];      /* '<S52>/Integrator2' */
  real_T Integrator1_CSTATE_j[3];      /* '<S52>/Integrator1' */
  XDot_CoreSubsys_QD2_DroneS_n1_T CoreSubsys_pn[2];/* '<S82>/CoreSubsys' */
} XDot_QD2_DroneStack_PID_2021a_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S3>/Integrator1' */
  boolean_T Integrator1_CSTATE_f[4];   /* '<S1>/Integrator1' */
  boolean_T Integrator6_CSTATE[3];     /* '<S3>/Integrator6' */
  boolean_T Integrator1_CSTATE_h[2];   /* '<S39>/Integrator1' */
  boolean_T Integrator2_CSTATE[2];     /* '<S39>/Integrator2' */
  boolean_T Integrator2_CSTATE_o;      /* '<S3>/Integrator2' */
  boolean_T Integrator7_CSTATE[3];     /* '<S3>/Integrator7' */
  boolean_T Integrator2_CSTATE_c[3];   /* '<S52>/Integrator2' */
  boolean_T Integrator1_CSTATE_j[3];   /* '<S52>/Integrator1' */
  XDis_CoreSubsys_QD2_DroneS_ne_T CoreSubsys_pn[2];/* '<S82>/CoreSubsys' */
} XDis_QD2_DroneStack_PID_2021a_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator1_Reset_ZCE;    /* '<S1>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE;    /* '<S3>/Integrator2' */
  ZCSigState Integrator7_Reset_ZCE;    /* '<S3>/Integrator7' */
  ZCSigState TriggeredSubsystemLatchingFlag_;
                               /* '<S77>/Triggered Subsystem - Latching Flag' */
  ZCSigState LatchEStop_Trig_ZCE;      /* '<S10>/Latch E-Stop' */
  ZCE_CoreSubsys_QD2_DroneSta_f_T CoreSubsys_p[9];
                               /* '<S18>/Boolean Value-Based Triggered Print' */
  ZCSigState TriggeredSubsystem_Trig_ZCE_g;/* '<S17>/Triggered Subsystem' */
  ZCE_CoreSubsys_QD2_DroneStack_T CoreSubsys[3];
                                /* '<S16>/Boolean Edge-Based Triggered Print' */
} PrevZCX_QD2_DroneStack_PID_20_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            QD2_DroneStack_PID_2021a_B
#define BlockIO                        B_QD2_DroneStack_PID_2021a_T
#define rtX                            QD2_DroneStack_PID_2021a_X
#define ContinuousStates               X_QD2_DroneStack_PID_2021a_T
#define rtXdot                         QD2_DroneStack_PID_2021a_XDot
#define StateDerivatives               XDot_QD2_DroneStack_PID_2021a_T
#define tXdis                          QD2_DroneStack_PID_2021a_XDis
#define StateDisabled                  XDis_QD2_DroneStack_PID_2021a_T
#define rtP                            QD2_DroneStack_PID_2021a_P
#define Parameters                     P_QD2_DroneStack_PID_2021a_T
#define rtDWork                        QD2_DroneStack_PID_2021a_DW
#define D_Work                         DW_QD2_DroneStack_PID_2021a_T
#define rtPrevZCSigState               QD2_DroneStack_PID_2021_PrevZCX
#define PrevZCSigStates                PrevZCX_QD2_DroneStack_PID_20_T

/* Parameters for system: '<S16>/Boolean Edge-Based Triggered Print' */
struct P_CoreSubsys_QD2_DroneStack_P_T_ {
  uint32_T Print_MaxUnits;             /* Computed Parameter: Print_MaxUnits
                                        * Referenced by: '<S26>/Print'
                                        */
  boolean_T Print_Active;              /* Computed Parameter: Print_Active
                                        * Referenced by: '<S26>/Print'
                                        */
};

/* Parameters for system: '<S18>/Boolean Value-Based Triggered Print' */
struct P_CoreSubsys_QD2_DroneStack_g_T_ {
  uint32_T Print_MaxUnits;             /* Computed Parameter: Print_MaxUnits
                                        * Referenced by: '<S30>/Print'
                                        */
  boolean_T Print_Active;              /* Computed Parameter: Print_Active
                                        * Referenced by: '<S30>/Print'
                                        */
};

/* Parameters for system: '<S13>/Use desired height when enabled' */
struct P_Usedesiredheightwhenenabled_T_ {
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S46>/Out1'
                                        */
};

/* Parameters for system: '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
struct P_CoreSubsys_QD2_DroneStac_gm_T_ {
  real_T AccelerometerFilterCutoffFreque;/* Expression: 120
                                          * Referenced by: '<S82>/Accelerometer Filter Cutoff Frequency (rad//s)'
                                          */
  real_T AccelerometerFilterDampingRatio;/* Expression: 1
                                          * Referenced by: '<S82>/Accelerometer Filter Damping Ratio'
                                          */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S82>/Integrator1'
                                        */
  real_T Gain_Gain[2];                 /* Expression: [0.25 0.25]
                                        * Referenced by: '<S82>/Gain'
                                        */
  real_T Gain1_Gain[2];                /* Expression: [0.1 0.1]
                                        * Referenced by: '<S82>/Gain1'
                                        */
  real_T GyroFilterCutoffFrequencyrads_V;/* Expression: 100
                                          * Referenced by: '<S82>/Gyro Filter Cutoff Frequency (rad//s)'
                                          */
  real_T GyroFilterDampingRatio_Value; /* Expression: 0.7
                                        * Referenced by: '<S82>/Gyro Filter Damping Ratio'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S82>/Integrator2'
                                        */
  real_T Integrator2_IC_n;             /* Expression: 0
                                        * Referenced by: '<S84>/Integrator2'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S82>/Integrator'
                                        */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S84>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 2
                                        * Referenced by: '<S85>/Constant'
                                        */
  real_T Integrator2_IC_o;             /* Expression: 0
                                        * Referenced by: '<S85>/Integrator2'
                                        */
};

/* Parameters for system: '<S70>/For Each Subsystem' */
struct P_CoreSubsys_QD2_DroneSt_gmy0_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S93>/Constant'
                                       */
};

/* Parameters (default storage) */
struct P_QD2_DroneStack_PID_2021a_T_ {
  real_T KT[3];                        /* Variable: KT
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Motor_Matrix[16];             /* Variable: Motor_Matrix
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Resetwhenstartingtotakeoff_cons;
                              /* Mask Parameter: Resetwhenstartingtotakeoff_cons
                               * Referenced by: '<S8>/Constant'
                               */
  real_T IgnoreYawControllerunlessinFlig;
                              /* Mask Parameter: IgnoreYawControllerunlessinFlig
                               * Referenced by: '<S42>/Constant'
                               */
  real_T IgnoreYawControllerunlessinFl_h;
                              /* Mask Parameter: IgnoreYawControllerunlessinFl_h
                               * Referenced by: '<S43>/Constant'
                               */
  real_T IgnoreControllerunlessinTakeoff;
                              /* Mask Parameter: IgnoreControllerunlessinTakeoff
                               * Referenced by: '<S41>/Constant'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S90>/Constant'
                                       */
  real_T Greaterthanminimumexpectedvolta;
                              /* Mask Parameter: Greaterthanminimumexpectedvolta
                               * Referenced by: '<S94>/Constant'
                               */
  real_T Lessthanminimumthresholdvoltage;
                              /* Mask Parameter: Lessthanminimumthresholdvoltage
                               * Referenced by: '<S95>/Constant'
                               */
  real_T Waitatleast2secondstoallowforin;
                              /* Mask Parameter: Waitatleast2secondstoallowforin
                               * Referenced by: '<S23>/Constant'
                               */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S15>/Constant'
                                      */
  real_T Thresholdtodetectifthedroneiscl;
                              /* Mask Parameter: Thresholdtodetectifthedroneiscl
                               * Referenced by: '<S38>/Constant'
                               */
  real_T Thresholdtodetectifthecommanded;
                              /* Mask Parameter: Thresholdtodetectifthecommanded
                               * Referenced by: '<S37>/Constant'
                               */
  real_T Ifthemeasuredheightismorethan02;
                              /* Mask Parameter: Ifthemeasuredheightismorethan02
                               * Referenced by: '<S35>/Constant'
                               */
  real_T themeasuredheightislessthan015m;
                              /* Mask Parameter: themeasuredheightislessthan015m
                               * Referenced by: '<S31>/Constant'
                               */
  real_T FlightState_const;            /* Mask Parameter: FlightState_const
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T TakeoffThrottleHeightState_cons;
                              /* Mask Parameter: TakeoffThrottleHeightState_cons
                               * Referenced by: '<S36>/Constant'
                               */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S32>/Constant'
                                      */
  real_T Ifthedroneisatorbelowthisheight;
                              /* Mask Parameter: Ifthedroneisatorbelowthisheight
                               * Referenced by: '<S34>/Constant'
                               */
  real_T StreamClient_default_value[16];
                                   /* Mask Parameter: StreamClient_default_value
                                    * Referenced by: '<S2>/Stream Client'
                                    */
  real_T StreamServer_default_value;
                                   /* Mask Parameter: StreamServer_default_value
                                    * Referenced by: '<S5>/Stream Server'
                                    */
  real_T Threshold_duration;           /* Mask Parameter: Threshold_duration
                                        * Referenced by: '<S80>/duration'
                                        */
  real_T Threshold_duration_l;         /* Mask Parameter: Threshold_duration_l
                                        * Referenced by: '<S21>/duration'
                                        */
  real_T Threshold1_duration;          /* Mask Parameter: Threshold1_duration
                                        * Referenced by: '<S49>/duration'
                                        */
  real_T Threshold2_duration;          /* Mask Parameter: Threshold2_duration
                                        * Referenced by: '<S50>/duration'
                                        */
  real_T Threshold_duration_o;         /* Mask Parameter: Threshold_duration_o
                                        * Referenced by: '<S14>/duration'
                                        */
  real_T Stopmodel_duration;           /* Mask Parameter: Stopmodel_duration
                                        * Referenced by: '<S114>/duration'
                                        */
  real_T Communication_duration;       /* Mask Parameter: Communication_duration
                                        * Referenced by: '<S113>/duration'
                                        */
  real_T DiscreteSecondOrderLowPassFilte;
                              /* Mask Parameter: DiscreteSecondOrderLowPassFilte
                               * Referenced by: '<S72>/bandwidth'
                               */
  real_T DiscreteSecondOrderLowPassFil_p;
                              /* Mask Parameter: DiscreteSecondOrderLowPassFil_p
                               * Referenced by: '<S72>/zeta'
                               */
  real_T Threshold_threshold;          /* Mask Parameter: Threshold_threshold
                                        * Referenced by: '<S80>/threshold'
                                        */
  real_T Threshold_threshold_p;        /* Mask Parameter: Threshold_threshold_p
                                        * Referenced by: '<S21>/threshold'
                                        */
  real_T Threshold1_threshold;         /* Mask Parameter: Threshold1_threshold
                                        * Referenced by: '<S49>/threshold'
                                        */
  real_T Threshold2_threshold;         /* Mask Parameter: Threshold2_threshold
                                        * Referenced by: '<S50>/threshold'
                                        */
  real_T Threshold_threshold_pd;       /* Mask Parameter: Threshold_threshold_pd
                                        * Referenced by: '<S14>/threshold'
                                        */
  real_T Stopmodel_threshold;          /* Mask Parameter: Stopmodel_threshold
                                        * Referenced by: '<S114>/threshold'
                                        */
  real_T Communication_threshold;     /* Mask Parameter: Communication_threshold
                                       * Referenced by: '<S113>/threshold'
                                       */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S27>/Delay Input1'
                                        */
  int32_T CompareToConstant1_const_m;
                                   /* Mask Parameter: CompareToConstant1_const_m
                                    * Referenced by: '<S66>/Constant'
                                    */
  uint32_T HILRead_analog_channels[3];/* Mask Parameter: HILRead_analog_channels
                                       * Referenced by: '<S5>/HIL Read'
                                       */
  uint32_T HILWritePWM_channels[4];    /* Mask Parameter: HILWritePWM_channels
                                        * Referenced by: '<S73>/HIL Write PWM'
                                        */
  uint32_T HILWriteDigital_channels[6];
                                     /* Mask Parameter: HILWriteDigital_channels
                                      * Referenced by: '<S5>/HIL Write Digital'
                                      */
  uint32_T HILRead_other_channels[23]; /* Mask Parameter: HILRead_other_channels
                                        * Referenced by: '<S5>/HIL Read'
                                        */
  int8_T StopwithMessage_message_icon;
                                 /* Mask Parameter: StopwithMessage_message_icon
                                  * Referenced by: '<S115>/Show Message on Host'
                                  */
  int8_T StopwithMessage1_message_icon;
                                /* Mask Parameter: StopwithMessage1_message_icon
                                 * Referenced by: '<S116>/Show Message on Host'
                                 */
  int8_T StopwithMessage3_message_icon;
                                /* Mask Parameter: StopwithMessage3_message_icon
                                 * Referenced by: '<S117>/Show Message on Host'
                                 */
  uint8_T StringDisplay_alignment;    /* Mask Parameter: StringDisplay_alignment
                                       * Referenced by: '<S2>/String Display'
                                       */
  uint8_T CompareToConstant_const_n;/* Mask Parameter: CompareToConstant_const_n
                                     * Referenced by: '<S65>/Constant'
                                     */
  uint8_T StringDisplay_display_mode;
                                   /* Mask Parameter: StringDisplay_display_mode
                                    * Referenced by: '<S2>/String Display'
                                    */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant5'
                                        */
  real_T RedRed_Value[6];              /* Expression: [ 1 0 0 1 0 0]
                                        * Referenced by: '<S75>/Red Red'
                                        */
  real_T LEDOFF_Value[6];              /* Expression: [ 0 0 0 0 0 0]
                                        * Referenced by: '<S75>/LED OFF'
                                        */
  real_T YellowYellow_Value[6];        /* Expression: [ 1 1 0 1 1 0  ]
                                        * Referenced by: '<S75>/Yellow Yellow'
                                        */
  real_T YellowGreen_Value[6];         /* Expression: [ 1 1 0 0 1 0  ]
                                        * Referenced by: '<S75>/Yellow Green'
                                        */
  real_T BlueBlue_Value[6];            /* Expression: [0 0 1 0 0 1]
                                        * Referenced by: '<S75>/Blue Blue'
                                        */
  real_T YellowRed_Value[6];           /* Expression: [ 1 1 0 1 0 0  ]
                                        * Referenced by: '<S75>/Yellow Red'
                                        */
  real_T RedYellow_Value[6];           /* Expression: [ 1 0 0 1 1 0  ]
                                        * Referenced by: '<S75>/Red Yellow'
                                        */
  real_T GreenGreen_Value[6];          /* Expression: [0 1 0 0 1 0]
                                        * Referenced by: '<S75>/Green Green'
                                        */
  real_T YellowBlue_Value[6];          /* Expression: [ 1 1 0 0 0 1  ]
                                        * Referenced by: '<S75>/Yellow Blue'
                                        */
  real_T RedBlue_Value[6];             /* Expression: [ 1 0 0 0 0 1   ]
                                        * Referenced by: '<S75>/Red Blue'
                                        */
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S97>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S97>/Constant'
                                        */
  real_T Motor0_Value[4];              /* Expression: [1 0 0 0]
                                        * Referenced by: '<S5>/Motor 0'
                                        */
  real_T Motor1_Value[4];              /* Expression: [0 1 0 0]
                                        * Referenced by: '<S5>/Motor 1'
                                        */
  real_T Motor2_Value[4];              /* Expression: [0 0 1 0]
                                        * Referenced by: '<S5>/Motor 2'
                                        */
  real_T Motor3_Value[4];              /* Expression: [0 0 0 1]
                                        * Referenced by: '<S5>/Motor 3'
                                        */
  real_T Noselection_Value[4];         /* Expression: [0 0 0 0]
                                        * Referenced by: '<S5>/No selection'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S13>/Switch'
                                        */
  real_T zeroreferencetorquecommands_Val[3];/* Expression: [0 0 0]
                                             * Referenced by: '<Root>/zero reference torque commands'
                                             */
  real_T HILInitialize_OOTerminate;/* Expression: set_other_outputs_at_terminate
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  real_T HILInitialize_OOExit;    /* Expression: set_other_outputs_at_switch_out
                                   * Referenced by: '<S5>/HIL Initialize'
                                   */
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;    /* Expression: set_other_outputs_at_switch_in
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh;         /* Expression: analog_input_maximums
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow;          /* Expression: analog_input_minimums
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_EIFrequency;    /* Expression: encoder_filter_frequency
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_POFrequency;    /* Expression: pwm_frequency
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_POInitial;      /* Expression: initial_pwm_outputs
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T HILInitialize_POWatchdog;     /* Expression: watchdog_pwm_outputs
                                        * Referenced by: '<S5>/HIL Initialize'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Memory_InitialCondition_c;    /* Expression: 0
                                        * Referenced by: '<S5>/Memory'
                                        */
  real_T gravityms2_Value;             /* Expression: 9.81
                                        * Referenced by: '<S1>/gravity (m//s^2)'
                                        */
  real_T DroneWeightkg_Value;          /* Expression: 1.504
                                        * Referenced by: '<Root>/Drone  Weight (kg)'
                                        */
  real_T SaturationUpperLimitGain_Gain;/* Expression: 1.05
                                        * Referenced by: '<S13>/Saturation Upper Limit Gain'
                                        */
  real_T ContinuousSigmoid_XI;         /* Expression: initial_position
                                        * Referenced by: '<S13>/Continuous Sigmoid'
                                        */
  real_T ContinuousSigmoid_VI;         /* Expression: initial_velocity
                                        * Referenced by: '<S13>/Continuous Sigmoid'
                                        */
  real_T ContinuousSigmoid_Hold;       /* Expression: hold_off
                                        * Referenced by: '<S13>/Continuous Sigmoid'
                                        */
  real_T Memory_InitialCondition_b;    /* Expression: 1
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Constant2_Value[2];           /* Expression: [2.33 46600]
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Constant3_Value[2];           /* Expression: [1.7475 17.475]
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S13>/Switch1'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant2_Value_a[16];
                            /* Expression: [0 0 1 0; 0 -1 0 0; 1 0 0 0; 0 0 0 1]
                             * Referenced by: '<S1>/Constant2'
                             */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T PositionSafetyThresholdm3_Value[3];/* Expression: [2 2 2.5]
                                             * Referenced by: '<S3>/Position Safety Threshold (m) [3]'
                                             */
  real_T Constant1_Value_j;            /* Expression: Inf
                                        * Referenced by: '<S51>/Constant1'
                                        */
  real_T ContinuousSigmoid_XI_a;       /* Expression: initial_position
                                        * Referenced by: '<S51>/Continuous Sigmoid'
                                        */
  real_T ContinuousSigmoid_VI_n;       /* Expression: initial_velocity
                                        * Referenced by: '<S51>/Continuous Sigmoid'
                                        */
  real_T ContinuousSigmoid_Hold_d;     /* Expression: hold_off
                                        * Referenced by: '<S51>/Continuous Sigmoid'
                                        */
  real_T ContinuousSigmoid1_XI;        /* Expression: initial_position
                                        * Referenced by: '<S51>/Continuous Sigmoid1'
                                        */
  real_T ContinuousSigmoid1_VI;        /* Expression: initial_velocity
                                        * Referenced by: '<S51>/Continuous Sigmoid1'
                                        */
  real_T ContinuousSigmoid1_Hold;      /* Expression: hold_off
                                        * Referenced by: '<S51>/Continuous Sigmoid1'
                                        */
  real_T ContinuousSigmoid2_XI;        /* Expression: initial_position
                                        * Referenced by: '<S51>/Continuous Sigmoid2'
                                        */
  real_T ContinuousSigmoid2_VI;        /* Expression: initial_velocity
                                        * Referenced by: '<S51>/Continuous Sigmoid2'
                                        */
  real_T ContinuousSigmoid2_Hold;      /* Expression: hold_off
                                        * Referenced by: '<S51>/Continuous Sigmoid2'
                                        */
  real_T ContinuousSigmoid3_XI;        /* Expression: initial_position
                                        * Referenced by: '<S51>/Continuous Sigmoid3'
                                        */
  real_T ContinuousSigmoid3_VI;        /* Expression: initial_velocity
                                        * Referenced by: '<S51>/Continuous Sigmoid3'
                                        */
  real_T ContinuousSigmoid3_Hold;      /* Expression: hold_off
                                        * Referenced by: '<S51>/Continuous Sigmoid3'
                                        */
  real_T Gain_Gain[4];                 /* Expression: [-1 -1 0 -1]
                                        * Referenced by: '<S51>/Gain'
                                        */
  real_T KpradmradmNmradsrad_Gain[4];  /* Expression: [pi/6 pi/6 35.0 15]
                                        * Referenced by: '<S1>/Kp (rad // m, rad // m, N // m, rad//s // rad)'
                                        */
  real_T Gain_Gain_l[4];               /* Expression: [0.9 0.9 0.9 0.5]
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Integrator1_IC_i;             /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Integrator1_UpperSat[4];      /* Expression: [0.26 0.33 15 0.05].*0.75
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Integrator1_LowerSat[4];   /* Expression: [-0.26 -0.33 -15 -0.05].*0.75
                                     * Referenced by: '<S1>/Integrator1'
                                     */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator6'
                                        */
  real_T Constant1_Value_k;            /* Expression: 2
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T KdradmsradmsNmsradsrads_Gain[4];/* Expression: [pi/2 pi/2 28 4]
                                          * Referenced by: '<S1>/Kd (rad // m//s, rad // m//s, N // m//s, rad//s // rad//s)'
                                          */
  real_T Gain2_Gain[4];                /* Expression: [0.4 0.4 1 0.1]
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T SaturateStabilizationCommand_Up[4];/* Expression: [pi/4 pi/4 35 100*pi/180]
                                             * Referenced by: '<S1>/Saturate Stabilization Command'
                                             */
  real_T SaturateStabilizationCommand_Lo[4];
                                    /* Expression: [-pi/4 -pi/4 -35 -100*pi/180]
                                     * Referenced by: '<S1>/Saturate Stabilization Command'
                                     */
  real_T RateLimiterNs_RisingLim;      /* Expression: 100
                                        * Referenced by: '<S13>/Rate Limiter (N//s)'
                                        */
  real_T RateLimiterNs_FallingLim;     /* Expression: -100
                                        * Referenced by: '<S13>/Rate Limiter (N//s)'
                                        */
  real_T N_UpperSat;                   /* Expression: 58
                                        * Referenced by: '<S13>/(N)'
                                        */
  real_T N_LowerSat;                   /* Expression: 0
                                        * Referenced by: '<S13>/(N)'
                                        */
  real_T SpecifyAngleModeforStabilizerDO;/* Expression: 0
                                          * Referenced by: '<S1>/Specify Angle Mode for Stabilizer (DO NOT CHANGE)'
                                          */
  real_T ZeroTorqueCommand_Value[3];   /* Expression: [0 0 0]
                                        * Referenced by: '<S7>/Zero Torque//Command'
                                        */
  real_T Switch_Threshold_l;           /* Expression: 0.5
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T NullAttitudeCommandradradrads_V[3];/* Expression: [0 0 0]
                                             * Referenced by: '<S13>/Null Attitude Command (rad, rad, rad//s)'
                                             */
  real_T Switch1_Threshold_b;          /* Expression: 0.5
                                        * Referenced by: '<S7>/Switch1'
                                        */
  real_T SaturateStabilizationCommand__o[3];/* Expression: [pi/4 pi/4 10*pi/18]
                                             * Referenced by: '<S7>/Saturate Stabilization Command'
                                             */
  real_T SaturateStabilizationCommand__g[3];/* Expression: [-pi/4 -pi/4 -10*pi/18]
                                             * Referenced by: '<S7>/Saturate Stabilization Command'
                                             */
  real_T Gain1_Gain[3];                /* Expression: [1 1 0]
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T K_p_angleradsrad_Gain[3];     /* Expression: [12 12 1]
                                        * Referenced by: '<S7>/K_p_angle (rad//s // rad)'
                                        */
  real_T Scale_Gain[3];                /* Expression: [1 1 2]
                                        * Referenced by: '<S7>/Scale'
                                        */
  real_T K_d_angleradsrads_Gain[3];    /* Expression: [0.1 0.1 0]
                                        * Referenced by: '<S7>/K_d_angle (rad//s // rad//s)'
                                        */
  real_T Scale1_Gain[3];               /* Expression: [1 1 2]
                                        * Referenced by: '<S7>/Scale1'
                                        */
  real_T SaturationMaxRaterads_UpperSat[3];/* Expression: 10*pi/3*[1 1 1]
                                            * Referenced by: '<S7>/Saturation Max Rate  (rad//s)'
                                            */
  real_T SaturationMaxRaterads_LowerSat[3];/* Expression: -10*pi/3*[1 1 1]
                                            * Referenced by: '<S7>/Saturation Max Rate  (rad//s)'
                                            */
  real_T K_p_speedNmrads_Gain[3];   /* Expression: [ 0.1876    0.1544    0.0395]
                                     * Referenced by: '<S7>/K_p_speed (Nm // rad//s)'
                                     */
  real_T Scale5_Gain[3];               /* Expression: [1 1 2]
                                        * Referenced by: '<S7>/Scale5'
                                        */
  real_T K_d_speedNmradss1_Gain[3];  /* Expression: [0.0032    0.0026     0.005]
                                      * Referenced by: '<S7>/K_d_speed (Nm // rad//s//s)1'
                                      */
  real_T Scale4_Gain[3];               /* Expression: [1 1 2]
                                        * Referenced by: '<S7>/Scale4'
                                        */
  real_T SaturationCommandAuthorityNm1_U[3];/* Expression: [1.0915 0.8984 0.0984]
                                             * Referenced by: '<S7>/Saturation Command  Authority (Nm)1'
                                             */
  real_T SaturationCommandAuthorityNm1_L[3];/* Expression: -[1.0915 0.8984 0.0984]
                                             * Referenced by: '<S7>/Saturation Command  Authority (Nm)1'
                                             */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S7>/Delay'
                                        */
  real_T ZeroReferenceMotorCommands_Valu[4];/* Expression: [0 0 0 0]
                                             * Referenced by: '<Root>/Zero Reference Motor Commands'
                                             */
  real_T MaximumCommandAuthority_UpperSa[4];/* Expression: [1 1 1 1]
                                             * Referenced by: '<S5>/Maximum  Command Authority '
                                             */
  real_T MaximumCommandAuthority_LowerSa[4];/* Expression: [1 1 1 1]*0.025
                                             * Referenced by: '<S5>/Maximum  Command Authority '
                                             */
  real_T Constant1_Value_c[32];
  /* Expression: [0 0 0 0; 1 0 0 0; 0 0 0 0; 0 1 0 0; 0 0 0 0; 0 0 1 0; 0 0 0 0;  0 0 0 1]
   * Referenced by: '<S64>/Constant1'
   */
  real_T Constant2_Value_e;            /* Expression: 8
                                        * Referenced by: '<S64>/Constant2'
                                        */
  real_T RateTransition7_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S5>/Rate Transition7'
                                          */
  real_T RateTransition2_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S5>/Rate Transition2'
                                          */
  real_T RateTransition1_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S5>/Rate Transition1'
                                          */
  real_T Dividebyhalfofthenumberofpolesi;/* Expression: 2/14
                                          * Referenced by: '<S5>/Divide by half of the number of poles in motor'
                                          */
  real_T Multiplebyresolutionsupposedtob;/* Expression: 1
                                          * Referenced by: '<S5>/Multiple by resolution (supposed to be 100 RPM)'
                                          */
  real_T Memory_InitialCondition_l[4]; /* Expression: zeros(1,4)
                                        * Referenced by: '<S67>/Memory'
                                        */
  real_T Converttoequivalentvoltagebased;/* Expression: 1/1300
                                          * Referenced by: '<S5>/Convert to equivalent voltage (based on motor Kv rating)'
                                          */
  real_T Saturation_UpperSat;          /* Expression: 17
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 10
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Memory_InitialCondition_lk[4];/* Expression: zeros(1,4)
                                        * Referenced by: '<S69>/Memory'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S81>/Rate Transition'
                                          */
  real_T RateTransition1_InitialCondit_o;/* Expression: 0
                                          * Referenced by: '<S81>/Rate Transition1'
                                          */
  real_T RateTransition2_InitialCondit_l;/* Expression: 0
                                          * Referenced by: '<S81>/Rate Transition2'
                                          */
  real_T RateTransition3_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S81>/Rate Transition3'
                                          */
  real_T Gain_Gain_d;                  /* Expression: .7
                                        * Referenced by: '<S64>/Gain'
                                        */
  real_T Bias1_Bias[4];                /* Expression: 0:3
                                        * Referenced by: '<S64>/Bias1'
                                        */
  real_T Memory_InitialCondition_cr[4];/* Expression: zeros(1,4)
                                        * Referenced by: '<S68>/Memory'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S70>/Delay3'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S70>/Delay2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S70>/Delay1'
                                        */
  real_T Delay_InitialCondition_g;     /* Expression: 0.0
                                        * Referenced by: '<S70>/Delay'
                                        */
  real_T Constant_Value_k;             /* Expression: 200
                                        * Referenced by: '<S70>/Constant'
                                        */
  real_T ZeroYaw_Value;                /* Expression: 0
                                        * Referenced by: '<S5>/Zero Yaw'
                                        */
  real_T BatteryLowTimeThresholds_Value;/* Expression: 0.3
                                         * Referenced by: '<S77>/Battery Low Time Threshold (s)'
                                         */
  real_T Constant_Value_i;             /* Expression: 0.5
                                        * Referenced by: '<S77>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S96>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S96>/Discrete-Time Integrator'
                                        */
  real_T Constant1_Value_p;            /* Expression: 1
                                        * Referenced by: '<S79>/Constant1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<S79>/Constant2'
                                        */
  real_T DiscreteTimeIntegrator_gainva_f;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                           * Referenced by: '<S98>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_b;  /* Expression: 0
                                        * Referenced by: '<S98>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_p;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                           * Referenced by: '<S99>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_g;  /* Expression: 0
                                        * Referenced by: '<S99>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_g;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_g
                           * Referenced by: '<S102>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_e;  /* Expression: 0
                                        * Referenced by: '<S102>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_e;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                           * Referenced by: '<S103>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_n;  /* Expression: 0
                                        * Referenced by: '<S103>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_o;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                           * Referenced by: '<S104>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: 0
                                        * Referenced by: '<S104>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_d;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_d
                           * Referenced by: '<S105>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_f;  /* Expression: 0
                                        * Referenced by: '<S105>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainv_el;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_el
                           * Referenced by: '<S106>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_h;  /* Expression: 0
                                        * Referenced by: '<S106>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainv_f5;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_f5
                           * Referenced by: '<S107>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S107>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_m;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                           * Referenced by: '<S108>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_mg; /* Expression: 0
                                        * Referenced by: '<S108>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                           * Referenced by: '<S109>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_hh; /* Expression: 0
                                        * Referenced by: '<S109>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainv_my;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_my
                           * Referenced by: '<S100>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_n2; /* Expression: 0
                                        * Referenced by: '<S100>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_a;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                           * Referenced by: '<S101>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_m0; /* Expression: 0
                                        * Referenced by: '<S101>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainv_fp;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_fp
                           * Referenced by: '<S80>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_k;  /* Expression: 0
                                        * Referenced by: '<S80>/Discrete-Time Integrator'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainv_e0;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_e0
                           * Referenced by: '<S21>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_nh; /* Expression: 0
                                        * Referenced by: '<S21>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_i;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                           * Referenced by: '<S49>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_fy; /* Expression: 0
                                        * Referenced by: '<S49>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainv_g3;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_g3
                           * Referenced by: '<S50>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_gy; /* Expression: 0
                                        * Referenced by: '<S50>/Discrete-Time Integrator'
                                        */
  real_T MAXthrottlepercentageForTrim_Va;/* Expression: 0.034
                                          * Referenced by: '<S22>/MAX throttle   percentage (%)  For Trim  '
                                          */
  real_T MaxThrottleHQ7inch_Value;     /* Expression: 10.79*4
                                        * Referenced by: '<Root>/Max Throttle HQ 7 inch'
                                        */
  real_T MAXthrottlepercentageForCMD_Val;/* Expression: 0.171
                                          * Referenced by: '<S22>/MAX throttle percentage (%) For CMD '
                                          */
  real_T MAXthrottlepercentageForCtrl_Va;/* Expression: 0.068
                                          * Referenced by: '<S22>/MAX throttle percentage (%) For Ctrl '
                                          */
  real_T u5ofCommandedHeight_Gain;     /* Expression: 0.75
                                        * Referenced by: '<S19>/75% of  Commanded Height'
                                        */
  real_T DiscreteTimeIntegrator_gainv_e1;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_e1
                           * Referenced by: '<S14>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_l;  /* Expression: 0
                                        * Referenced by: '<S14>/Discrete-Time Integrator'
                                        */
  real_T KiradsmradsmNsmradsrads_Gain[4];/* Expression: [1 1 6 0]
                                          * Referenced by: '<S1>/Ki (rad s // m, rad s // m, N s//m, rad//s // rad//s)'
                                          */
  real_T Gain1_Gain_h[4];              /* Expression: [ 0.01 0.01 1 0]
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Constant4_Value_m;            /* Expression: 1
                                        * Referenced by: '<S12>/Constant4'
                                        */
  real_T Constant5_Value_h;            /* Expression: 100
                                        * Referenced by: '<S12>/Constant5'
                                        */
  real_T Constant_Value_f;             /* Expression: 2
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S39>/Integrator2'
                                        */
  real_T Integrator2_IC_g;             /* Expression: 0
                                        * Referenced by: '<S3>/Integrator2'
                                        */
  real_T Integrator7_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator7'
                                        */
  real_T Ki1_Gain;                     /* Expression: 0.1
                                        * Referenced by: '<S3>/Ki1'
                                        */
  real_T wn_Value;                     /* Expression: 50
                                        * Referenced by: '<S3>/wn'
                                        */
  real_T Integrator2_IC_gq;            /* Expression: 0
                                        * Referenced by: '<S52>/Integrator2'
                                        */
  real_T Ki3_Gain;                     /* Expression: 0.1
                                        * Referenced by: '<S3>/Ki3'
                                        */
  real_T Kp1_Gain;                     /* Expression: 1
                                        * Referenced by: '<S3>/Kp1'
                                        */
  real_T Kp3_Gain;                     /* Expression: 4
                                        * Referenced by: '<S3>/Kp3'
                                        */
  real_T Constant2_Value_f[2];         /* Expression: [2 0.2]
                                        * Referenced by: '<S51>/Constant2'
                                        */
  real_T Constant3_Value_c[2];         /* Expression: [3 10]
                                        * Referenced by: '<S51>/Constant3'
                                        */
  real_T Constant4_Value_c[2];         /* Expression: [3 4.5]
                                        * Referenced by: '<S51>/Constant4'
                                        */
  real_T Constant5_Value_j[2];         /* Expression: [2 10]
                                        * Referenced by: '<S51>/Constant5'
                                        */
  real_T Constant6_Value[2];           /* Expression: [2 0.5]
                                        * Referenced by: '<S51>/Constant6'
                                        */
  real_T Constant7_Value[2];           /* Expression: [2 2]
                                        * Referenced by: '<S51>/Constant7'
                                        */
  real_T Constant8_Value[2];           /* Expression: [2 10]
                                        * Referenced by: '<S51>/Constant8'
                                        */
  real_T Constant9_Value[2];           /* Expression: [2 0.2]
                                        * Referenced by: '<S51>/Constant9'
                                        */
  real_T Constant_Value_o;             /* Expression: 2
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T zt_Value;                     /* Expression: 1
                                        * Referenced by: '<S3>/zt'
                                        */
  real_T gravitycorrection_Bias[3];    /* Expression: [0 0 -9.81]
                                        * Referenced by: '<S3>/gravity correction'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 180/pi
                                        * Referenced by: '<S111>/Gain'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 180/pi
                                        * Referenced by: '<S112>/Gain'
                                        */
  real_T DiscreteTimeIntegrator_gainva_n;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                           * Referenced by: '<S114>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_n2p;/* Expression: 0
                                        * Referenced by: '<S114>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainv_m3;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_m3
                           * Referenced by: '<S113>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_j;  /* Expression: 0
                                        * Referenced by: '<S113>/Discrete-Time Integrator'
                                        */
  real_T HILWatchdog_Timeout;          /* Expression: timeout
                                        * Referenced by: '<S110>/HIL Watchdog'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S5>/Memory2'
                                        */
  real_T Constant_Value_b;             /* Expression: 2
                                        * Referenced by: '<S72>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_c;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_c
                           * Referenced by: '<S72>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_e4; /* Expression: 0
                                        * Referenced by: '<S72>/Discrete-Time Integrator'
                                        */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S72>/x0'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S72>/Discrete-Time Integrator1'
                           */
  real_T Constant_Value_j;             /* Expression: 2
                                        * Referenced by: '<S71>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                           * Referenced by: '<S71>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_gl; /* Expression: 0
                                        * Referenced by: '<S71>/Discrete-Time Integrator'
                                        */
  real_T ToFFilterInitialConditionm_Valu;/* Expression: 0
                                          * Referenced by: '<S5>/ToF Filter Initial Condition (m)'
                                          */
  real_T DiscreteTimeIntegrator1_gainv_c;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainv_c
                           * Referenced by: '<S71>/Discrete-Time Integrator1'
                           */
  real_T ToFFilterCutoffFrequencyrad_Val;/* Expression: 40
                                          * Referenced by: '<S5>/ToF Filter Cutoff Frequency (rad)'
                                          */
  real_T RangingSensor_Budget;         /* Expression: timing_budget
                                        * Referenced by: '<S5>/Ranging Sensor'
                                        */
  real_T RangingSensor_Period;         /* Expression: measurement_period
                                        * Referenced by: '<S5>/Ranging Sensor'
                                        */
  real_T RangingSensor_MaxInterpolationD;/* Expression: max_interpolated_distance
                                          * Referenced by: '<S5>/Ranging Sensor'
                                          */
  real_T RangingSensor_MaxInterpolationA;/* Expression: max_interpolated_angle
                                          * Referenced by: '<S5>/Ranging Sensor'
                                          */
  real_T ToFFilterDampingRatio_Value;  /* Expression: 1
                                        * Referenced by: '<S5>/ToF Filter Damping Ratio'
                                        */
  real_T ToFSensorXYOffsetsm_Value[2]; /* Expression: [0 0]
                                        * Referenced by: '<S5>/ToF Sensor XY Offsets (m)'
                                        */
  int32_T HILInitialize_DOWatchdog[6];
                                 /* Computed Parameter: HILInitialize_DOWatchdog
                                  * Referenced by: '<S5>/HIL Initialize'
                                  */
  int32_T HILInitialize_EIInitial;/* Computed Parameter: HILInitialize_EIInitial
                                   * Referenced by: '<S5>/HIL Initialize'
                                   */
  int32_T HILInitialize_POModes[5]; /* Computed Parameter: HILInitialize_POModes
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  int32_T HILInitialize_POConfiguration;
                            /* Computed Parameter: HILInitialize_POConfiguration
                             * Referenced by: '<S5>/HIL Initialize'
                             */
  int32_T HILInitialize_POAlignment;
                                /* Computed Parameter: HILInitialize_POAlignment
                                 * Referenced by: '<S5>/HIL Initialize'
                                 */
  int32_T HILInitialize_POPolarity;
                                 /* Computed Parameter: HILInitialize_POPolarity
                                  * Referenced by: '<S5>/HIL Initialize'
                                  */
  int32_T StreamClient_SndPriority;
                                 /* Computed Parameter: StreamClient_SndPriority
                                  * Referenced by: '<S2>/Stream Client'
                                  */
  int32_T StreamClient_RcvPriority;
                                 /* Computed Parameter: StreamClient_RcvPriority
                                  * Referenced by: '<S2>/Stream Client'
                                  */
  int32_T ToHostFile_Encoding;        /* Computed Parameter: ToHostFile_Encoding
                                       * Referenced by: '<S5>/To Host File'
                                       */
  int32_T ToHostFile_Encoding_f;    /* Computed Parameter: ToHostFile_Encoding_f
                                     * Referenced by: '<S1>/To Host File'
                                     */
  int32_T ToHostFile_Encoding_n;    /* Computed Parameter: ToHostFile_Encoding_n
                                     * Referenced by: '<S7>/To Host File'
                                     */
  int32_T StreamServer_SndPriority;
                                 /* Computed Parameter: StreamServer_SndPriority
                                  * Referenced by: '<S5>/Stream Server'
                                  */
  int32_T StreamServer_RcvPriority;
                                 /* Computed Parameter: StreamServer_RcvPriority
                                  * Referenced by: '<S5>/Stream Server'
                                  */
  uint32_T Print_MaxUnits;             /* Computed Parameter: Print_MaxUnits
                                        * Referenced by: '<S28>/Print'
                                        */
  uint32_T HILInitialize_AIChannels[4];
                                 /* Computed Parameter: HILInitialize_AIChannels
                                  * Referenced by: '<S5>/HIL Initialize'
                                  */
  uint32_T HILInitialize_DIChannels[6];
                                 /* Computed Parameter: HILInitialize_DIChannels
                                  * Referenced by: '<S5>/HIL Initialize'
                                  */
  uint32_T HILInitialize_DOChannels[6];
                                 /* Computed Parameter: HILInitialize_DOChannels
                                  * Referenced by: '<S5>/HIL Initialize'
                                  */
  uint32_T HILInitialize_EIChannels[2];
                                 /* Computed Parameter: HILInitialize_EIChannels
                                  * Referenced by: '<S5>/HIL Initialize'
                                  */
  uint32_T HILInitialize_EIQuadrature;
                               /* Computed Parameter: HILInitialize_EIQuadrature
                                * Referenced by: '<S5>/HIL Initialize'
                                */
  uint32_T HILInitialize_POChannels[6];
                                 /* Computed Parameter: HILInitialize_POChannels
                                  * Referenced by: '<S5>/HIL Initialize'
                                  */
  uint32_T StreamClient_SndSize;     /* Computed Parameter: StreamClient_SndSize
                                      * Referenced by: '<S2>/Stream Client'
                                      */
  uint32_T StreamClient_RcvSize;     /* Computed Parameter: StreamClient_RcvSize
                                      * Referenced by: '<S2>/Stream Client'
                                      */
  uint32_T StreamClient_SndFIFO;     /* Computed Parameter: StreamClient_SndFIFO
                                      * Referenced by: '<S2>/Stream Client'
                                      */
  uint32_T StreamClient_RcvFIFO;     /* Computed Parameter: StreamClient_RcvFIFO
                                      * Referenced by: '<S2>/Stream Client'
                                      */
  uint32_T ToHostFile_Decimation;   /* Computed Parameter: ToHostFile_Decimation
                                     * Referenced by: '<S5>/To Host File'
                                     */
  uint32_T ToHostFile_BitRate;         /* Computed Parameter: ToHostFile_BitRate
                                        * Referenced by: '<S5>/To Host File'
                                        */
  uint32_T ToHostFile_Decimation_j;
                                  /* Computed Parameter: ToHostFile_Decimation_j
                                   * Referenced by: '<S1>/To Host File'
                                   */
  uint32_T ToHostFile_BitRate_p;     /* Computed Parameter: ToHostFile_BitRate_p
                                      * Referenced by: '<S1>/To Host File'
                                      */
  uint32_T ToHostFile_Decimation_m;
                                  /* Computed Parameter: ToHostFile_Decimation_m
                                   * Referenced by: '<S7>/To Host File'
                                   */
  uint32_T ToHostFile_BitRate_h;     /* Computed Parameter: ToHostFile_BitRate_h
                                      * Referenced by: '<S7>/To Host File'
                                      */
  uint32_T StreamServer_SndSize;     /* Computed Parameter: StreamServer_SndSize
                                      * Referenced by: '<S5>/Stream Server'
                                      */
  uint32_T StreamServer_RcvSize;     /* Computed Parameter: StreamServer_RcvSize
                                      * Referenced by: '<S5>/Stream Server'
                                      */
  uint32_T StreamServer_SndFIFO;     /* Computed Parameter: StreamServer_SndFIFO
                                      * Referenced by: '<S5>/Stream Server'
                                      */
  uint32_T StreamServer_RcvFIFO;     /* Computed Parameter: StreamServer_RcvFIFO
                                      * Referenced by: '<S5>/Stream Server'
                                      */
  uint32_T RangingSensor_Range;       /* Computed Parameter: RangingSensor_Range
                                       * Referenced by: '<S5>/Ranging Sensor'
                                       */
  boolean_T Print_Active;              /* Computed Parameter: Print_Active
                                        * Referenced by: '<S28>/Print'
                                        */
  boolean_T LatchedOutput_Y0;          /* Computed Parameter: LatchedOutput_Y0
                                        * Referenced by: '<S20>/Latched Output'
                                        */
  boolean_T HILWritePWM_Active;        /* Computed Parameter: HILWritePWM_Active
                                        * Referenced by: '<S73>/HIL Write PWM'
                                        */
  boolean_T Constant_Value_dj;         /* Computed Parameter: Constant_Value_dj
                                        * Referenced by: '<S118>/Constant'
                                        */
  boolean_T Constant_Value_g;          /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S119>/Constant'
                                        */
  boolean_T Constant_Value_p;          /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S120>/Constant'
                                        */
  boolean_T HILInitialize_Active;    /* Computed Parameter: HILInitialize_Active
                                      * Referenced by: '<S5>/HIL Initialize'
                                      */
  boolean_T HILInitialize_AOTerminate;
                                /* Computed Parameter: HILInitialize_AOTerminate
                                 * Referenced by: '<S5>/HIL Initialize'
                                 */
  boolean_T HILInitialize_AOExit;    /* Computed Parameter: HILInitialize_AOExit
                                      * Referenced by: '<S5>/HIL Initialize'
                                      */
  boolean_T HILInitialize_DOTerminate;
                                /* Computed Parameter: HILInitialize_DOTerminate
                                 * Referenced by: '<S5>/HIL Initialize'
                                 */
  boolean_T HILInitialize_DOExit;    /* Computed Parameter: HILInitialize_DOExit
                                      * Referenced by: '<S5>/HIL Initialize'
                                      */
  boolean_T HILInitialize_POTerminate;
                                /* Computed Parameter: HILInitialize_POTerminate
                                 * Referenced by: '<S5>/HIL Initialize'
                                 */
  boolean_T HILInitialize_POExit;    /* Computed Parameter: HILInitialize_POExit
                                      * Referenced by: '<S5>/HIL Initialize'
                                      */
  boolean_T HILInitialize_CKPStart;/* Computed Parameter: HILInitialize_CKPStart
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKPEnter;/* Computed Parameter: HILInitialize_CKPEnter
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKStart;  /* Computed Parameter: HILInitialize_CKStart
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_CKEnter;  /* Computed Parameter: HILInitialize_CKEnter
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AIPStart;/* Computed Parameter: HILInitialize_AIPStart
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AIPEnter;/* Computed Parameter: HILInitialize_AIPEnter
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOPStart;/* Computed Parameter: HILInitialize_AOPStart
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOPEnter;/* Computed Parameter: HILInitialize_AOPEnter
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOStart;  /* Computed Parameter: HILInitialize_AOStart
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AOEnter;  /* Computed Parameter: HILInitialize_AOEnter
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AOReset;  /* Computed Parameter: HILInitialize_AOReset
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOPStart;/* Computed Parameter: HILInitialize_DOPStart
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOPEnter;/* Computed Parameter: HILInitialize_DOPEnter
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOStart;  /* Computed Parameter: HILInitialize_DOStart
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOEnter;  /* Computed Parameter: HILInitialize_DOEnter
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOReset;  /* Computed Parameter: HILInitialize_DOReset
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_EIPStart;/* Computed Parameter: HILInitialize_EIPStart
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  boolean_T HILInitialize_EIPEnter;/* Computed Parameter: HILInitialize_EIPEnter
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  boolean_T HILInitialize_EIStart;  /* Computed Parameter: HILInitialize_EIStart
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_EIEnter;  /* Computed Parameter: HILInitialize_EIEnter
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POPStart;/* Computed Parameter: HILInitialize_POPStart
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POPEnter;/* Computed Parameter: HILInitialize_POPEnter
                                    * Referenced by: '<S5>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POStart;  /* Computed Parameter: HILInitialize_POStart
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POEnter;  /* Computed Parameter: HILInitialize_POEnter
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POReset;  /* Computed Parameter: HILInitialize_POReset
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_OOReset;  /* Computed Parameter: HILInitialize_OOReset
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOFinal;  /* Computed Parameter: HILInitialize_DOFinal
                                     * Referenced by: '<S5>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOInitial;
                                  /* Computed Parameter: HILInitialize_DOInitial
                                   * Referenced by: '<S5>/HIL Initialize'
                                   */
  boolean_T HILRead_Active;            /* Computed Parameter: HILRead_Active
                                        * Referenced by: '<S5>/HIL Read'
                                        */
  boolean_T StreamClient_Active;      /* Computed Parameter: StreamClient_Active
                                       * Referenced by: '<S2>/Stream Client'
                                       */
  boolean_T Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<S5>/Memory1'
                                  */
  boolean_T HILWriteDigital_Active;/* Computed Parameter: HILWriteDigital_Active
                                    * Referenced by: '<S5>/HIL Write Digital'
                                    */
  boolean_T HILWatchdog_Active;        /* Computed Parameter: HILWatchdog_Active
                                        * Referenced by: '<S110>/HIL Watchdog'
                                        */
  boolean_T Memory3_InitialCondition;
                                 /* Computed Parameter: Memory3_InitialCondition
                                  * Referenced by: '<S5>/Memory3'
                                  */
  boolean_T StreamServer_Active;      /* Computed Parameter: StreamServer_Active
                                       * Referenced by: '<S5>/Stream Server'
                                       */
  boolean_T RangingSensor_Active;    /* Computed Parameter: RangingSensor_Active
                                      * Referenced by: '<S5>/Ranging Sensor'
                                      */
  int8_T StreamClient_Optimize;     /* Computed Parameter: StreamClient_Optimize
                                     * Referenced by: '<S2>/Stream Client'
                                     */
  int8_T StreamClient_Implementation;
                              /* Computed Parameter: StreamClient_Implementation
                               * Referenced by: '<S2>/Stream Client'
                               */
  int8_T ShowMessageonHost_MsgIcon;
                                /* Computed Parameter: ShowMessageonHost_MsgIcon
                                 * Referenced by: '<S24>/Show Message on Host'
                                 */
  int8_T ShowMessageonHost1_MsgIcon;
                               /* Computed Parameter: ShowMessageonHost1_MsgIcon
                                * Referenced by: '<S24>/Show Message on Host1'
                                */
  int8_T ShowMessageonHost2_MsgIcon;
                               /* Computed Parameter: ShowMessageonHost2_MsgIcon
                                * Referenced by: '<S24>/Show Message on Host2'
                                */
  int8_T ShowMessageonHost3_MsgIcon;
                               /* Computed Parameter: ShowMessageonHost3_MsgIcon
                                * Referenced by: '<S24>/Show Message on Host3'
                                */
  int8_T ShowMessageonHost4_MsgIcon;
                               /* Computed Parameter: ShowMessageonHost4_MsgIcon
                                * Referenced by: '<S24>/Show Message on Host4'
                                */
  int8_T ShowMessageonHost5_MsgIcon;
                               /* Computed Parameter: ShowMessageonHost5_MsgIcon
                                * Referenced by: '<S24>/Show Message on Host5'
                                */
  int8_T ShowMessageonHost6_MsgIcon;
                               /* Computed Parameter: ShowMessageonHost6_MsgIcon
                                * Referenced by: '<S24>/Show Message on Host6'
                                */
  int8_T ShowMessageonHost7_MsgIcon;
                               /* Computed Parameter: ShowMessageonHost7_MsgIcon
                                * Referenced by: '<S24>/Show Message on Host7'
                                */
  int8_T ShowMessageonHost8_MsgIcon;
                               /* Computed Parameter: ShowMessageonHost8_MsgIcon
                                * Referenced by: '<S24>/Show Message on Host8'
                                */
  int8_T StreamServer_Optimize;     /* Computed Parameter: StreamServer_Optimize
                                     * Referenced by: '<S5>/Stream Server'
                                     */
  int8_T StreamServer_Implementation;
                              /* Computed Parameter: StreamServer_Implementation
                               * Referenced by: '<S5>/Stream Server'
                               */
  uint8_T StringConstant8_Value[80];   /* Expression: value
                                        * Referenced by: '<S17>/String Constant8'
                                        */
  uint8_T StringConstant5_Value[80];   /* Expression: value
                                        * Referenced by: '<S17>/String Constant5'
                                        */
  uint8_T StringConstant1_Value[80];   /* Expression: value
                                        * Referenced by: '<S17>/String Constant1'
                                        */
  uint8_T StringConstant2_Value[80];   /* Expression: value
                                        * Referenced by: '<S17>/String Constant2'
                                        */
  uint8_T StringConstant3_Value[80];   /* Expression: value
                                        * Referenced by: '<S17>/String Constant3'
                                        */
  uint8_T StringConstant6_Value[80];   /* Expression: value
                                        * Referenced by: '<S17>/String Constant6'
                                        */
  uint8_T StringConstant9_Value[80];   /* Expression: value
                                        * Referenced by: '<S17>/String Constant9'
                                        */
  uint8_T StringConstant4_Value[80];   /* Expression: value
                                        * Referenced by: '<S17>/String Constant4'
                                        */
  uint8_T StringConstant7_Value[80];   /* Expression: value
                                        * Referenced by: '<S17>/String Constant7'
                                        */
  uint8_T StreamClient_URI;            /* Expression: uri_argument
                                        * Referenced by: '<S2>/Stream Client'
                                        */
  uint8_T StreamClient_Endian;        /* Computed Parameter: StreamClient_Endian
                                       * Referenced by: '<S2>/Stream Client'
                                       */
  uint8_T ManualSwitchSelectCommandInput_;
                          /* Computed Parameter: ManualSwitchSelectCommandInput_
                           * Referenced by: '<S5>/Manual Switch -   Select Command Input'
                           */
  uint8_T ToHostFile_VarName[9];       /* Expression: variable_name_argument
                                        * Referenced by: '<S5>/To Host File'
                                        */
  uint8_T ToHostFile_FileFormat;    /* Computed Parameter: ToHostFile_FileFormat
                                     * Referenced by: '<S5>/To Host File'
                                     */
  uint8_T ToHostFile_file_name[68];    /* Expression: file_name_argument
                                        * Referenced by: '<S5>/To Host File'
                                        */
  uint8_T ToHostFile_VarName_l[15];    /* Expression: variable_name_argument
                                        * Referenced by: '<S1>/To Host File'
                                        */
  uint8_T ToHostFile_FileFormat_n;/* Computed Parameter: ToHostFile_FileFormat_n
                                   * Referenced by: '<S1>/To Host File'
                                   */
  uint8_T ToHostFile_file_name_h[74];  /* Expression: file_name_argument
                                        * Referenced by: '<S1>/To Host File'
                                        */
  uint8_T StringConstant16_Value[80];  /* Expression: value
                                        * Referenced by: '<S16>/String Constant16'
                                        */
  uint8_T StringConstant12_Value[80];  /* Expression: value
                                        * Referenced by: '<S16>/String Constant12'
                                        */
  uint8_T StringConstant13_Value[80];  /* Expression: value
                                        * Referenced by: '<S16>/String Constant13'
                                        */
  uint8_T StringConstant_Value[80];    /* Expression: value
                                        * Referenced by: '<S18>/String Constant'
                                        */
  uint8_T StringConstant1_Value_g[80]; /* Expression: value
                                        * Referenced by: '<S18>/String Constant1'
                                        */
  uint8_T StringConstant2_Value_k[80]; /* Expression: value
                                        * Referenced by: '<S18>/String Constant2'
                                        */
  uint8_T StringConstant3_Value_i[80]; /* Expression: value
                                        * Referenced by: '<S18>/String Constant3'
                                        */
  uint8_T StringConstant8_Value_b[80]; /* Expression: value
                                        * Referenced by: '<S18>/String Constant8'
                                        */
  uint8_T StringConstant4_Value_i[80]; /* Expression: value
                                        * Referenced by: '<S18>/String Constant4'
                                        */
  uint8_T StringConstant5_Value_n[80]; /* Expression: value
                                        * Referenced by: '<S18>/String Constant5'
                                        */
  uint8_T StringConstant6_Value_k[80]; /* Expression: value
                                        * Referenced by: '<S18>/String Constant6'
                                        */
  uint8_T StringConstant7_Value_d[80]; /* Expression: value
                                        * Referenced by: '<S18>/String Constant7'
                                        */
  uint8_T ToHostFile_VarName_g[16];    /* Expression: variable_name_argument
                                        * Referenced by: '<S7>/To Host File'
                                        */
  uint8_T ToHostFile_FileFormat_a;/* Computed Parameter: ToHostFile_FileFormat_a
                                   * Referenced by: '<S7>/To Host File'
                                   */
  uint8_T ToHostFile_file_name_j[75];  /* Expression: file_name_argument
                                        * Referenced by: '<S7>/To Host File'
                                        */
  uint8_T StreamServer_URI[36];        /* Expression: uri_argument
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  uint8_T StreamServer_Endian;        /* Computed Parameter: StreamServer_Endian
                                       * Referenced by: '<S5>/Stream Server'
                                       */
  P_CoreSubsys_QD2_DroneSt_gmy0_T CoreSubsys_pna;/* '<S70>/For Each Subsystem' */
  P_CoreSubsys_QD2_DroneStac_gm_T CoreSubsys_pn;
                   /* '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
  P_Usedesiredheightwhenenabled_T UsedesiredYwhenenabled;/* '<S51>/Use desired Y  when enabled' */
  P_Usedesiredheightwhenenabled_T UsedesiredXwhenenabled;/* '<S51>/Use desired X  when enabled' */
  P_Usedesiredheightwhenenabled_T Usedesyawwhenenabled;/* '<S51>/Use des yaw  when enabled' */
  P_Usedesiredheightwhenenabled_T Usedesheightwhenenabled;
                                      /* '<S51>/Use des height  when enabled' */
  P_Usedesiredheightwhenenabled_T Usedesiredheightwhenenabled_c;
                                   /* '<S13>/Use desired height when enabled' */
  P_CoreSubsys_QD2_DroneStack_g_T CoreSubsys_p;
                               /* '<S18>/Boolean Value-Based Triggered Print' */
  P_CoreSubsys_QD2_DroneStack_P_T CoreSubsys;
                                /* '<S16>/Boolean Edge-Based Triggered Print' */
};

/* Real-time Model Data Structure */
struct tag_RTM_QD2_DroneStack_PID_20_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][56];
  ODE1_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    uint32_T clockTick3;
    uint32_T clockTickH3;
    time_T stepSize3;
    uint32_T clockTick4;
    uint32_T clockTickH4;
    time_T stepSize4;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[5];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
      boolean_T TID1_3;
      boolean_T TID1_4;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[5];
    time_T offsetTimesArray[5];
    int_T sampleTimeTaskIDArray[5];
    int_T sampleHitArray[5];
    int_T perTaskSampleHitsArray[25];
    time_T tArray[5];
  } Timing;
};

/* Block parameters (default storage) */
extern P_QD2_DroneStack_PID_2021a_T QD2_DroneStack_PID_2021a_P;

/* Block signals (default storage) */
extern B_QD2_DroneStack_PID_2021a_T QD2_DroneStack_PID_2021a_B;

/* Continuous states (default storage) */
extern X_QD2_DroneStack_PID_2021a_T QD2_DroneStack_PID_2021a_X;

/* Disabled states (default storage) */
extern XDis_QD2_DroneStack_PID_2021a_T QD2_DroneStack_PID_2021a_XDis;

/* Block states (default storage) */
extern DW_QD2_DroneStack_PID_2021a_T QD2_DroneStack_PID_2021a_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_QD2_DroneStack_PID_20_T QD2_DroneStack_PID_2021_PrevZCX;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Model entry point functions */
extern void QD2_DroneStack_PID_2021a_initialize(void);
extern void QD2_DroneStack_PID_2021a_output0(void);
extern void QD2_DroneStack_PID_2021a_update0(void);
extern void QD2_DroneStack_PID_2021a_output2(void);
extern void QD2_DroneStack_PID_2021a_update2(void);
extern void QD2_DroneStack_PID_2021a_output3(void);
extern void QD2_DroneStack_PID_2021a_update3(void);
extern void QD2_DroneStack_PID_2021a_output4(void);
extern void QD2_DroneStack_PID_2021a_update4(void);
extern void QD2_DroneStack_PID_2021a_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern QD2_DroneStack_PID_2021a_rtModel *QD2_DroneStack_PID_2021a(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_QD2_DroneStack_PID_2_T *const QD2_DroneStack_PID_2021a_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'QD2_DroneStack_PID_2021a'
 * '<S1>'   : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)'
 * '<S2>'   : 'QD2_DroneStack_PID_2021a/Communication'
 * '<S3>'   : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION'
 * '<S4>'   : 'QD2_DroneStack_PID_2021a/Powered by QUARC'
 * '<S5>'   : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ'
 * '<S6>'   : 'QD2_DroneStack_PID_2021a/Quanser'
 * '<S7>'   : 'QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2'
 * '<S8>'   : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/Reset when starting to takeoff'
 * '<S9>'   : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE LOGIC'
 * '<S10>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS'
 * '<S11>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE TRANSITION'
 * '<S12>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/Signal  Smoothing'
 * '<S13>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/THROTTLE SWITCHBOX '
 * '<S14>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/Threshold'
 * '<S15>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Compare To Constant2'
 * '<S16>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Extra Messages for Console'
 * '<S17>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate State Messages for Console'
 * '<S18>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console'
 * '<S19>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Height Checks'
 * '<S20>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Latch E-Stop'
 * '<S21>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Threshold'
 * '<S22>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Throttle Checks'
 * '<S23>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Wait at least 2 seconds to allow for initialization (e.g., bias removal)'
 * '<S24>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Warning Messages'
 * '<S25>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Extra Messages for Console/Boolean Edge-Based Triggered Print'
 * '<S26>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Extra Messages for Console/Boolean Edge-Based Triggered Print/Triggered Subsystem1'
 * '<S27>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate State Messages for Console/Detect Change'
 * '<S28>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate State Messages for Console/Triggered Subsystem'
 * '<S29>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console/Boolean Value-Based Triggered Print'
 * '<S30>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console/Boolean Value-Based Triggered Print/Triggered Subsystem'
 * '<S31>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Height Checks/...the measured height is less than 0.15m...'
 * '<S32>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Height Checks/Compare To Constant1'
 * '<S33>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Height Checks/Flight State'
 * '<S34>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Height Checks/If the drone is at or below this height (m),  then the drone has landed NOTE - minimum height to be considered flying is 0.15m   '
 * '<S35>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Height Checks/If the measured height is more than 0.2 m below the commanded height and...'
 * '<S36>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Height Checks/Takeoff Throttle Height State'
 * '<S37>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Height Checks/Threshold to detect if the commanded height is close to the desired height (m)'
 * '<S38>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Height Checks/Threshold to detect if the drone is close to the commanded height (m)'
 * '<S39>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/Signal  Smoothing/Second-Order Low-Pass Filter'
 * '<S40>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/THROTTLE SWITCHBOX /Hover Throttle Sigmoid Parameters'
 * '<S41>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/THROTTLE SWITCHBOX /Ignore Controller unless in Takeoff, Flight or Landing'
 * '<S42>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/THROTTLE SWITCHBOX /Ignore Yaw Controller unless in Flight1'
 * '<S43>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/THROTTLE SWITCHBOX /Ignore Yaw Controller unless in Flight2'
 * '<S44>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/THROTTLE SWITCHBOX /Saturation Dynamic'
 * '<S45>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/THROTTLE SWITCHBOX /Throttle Switchbox'
 * '<S46>'  : 'QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/THROTTLE SWITCHBOX /Use desired height when enabled'
 * '<S47>'  : 'QD2_DroneStack_PID_2021a/Communication/Detect Communication Loss'
 * '<S48>'  : 'QD2_DroneStack_PID_2021a/Communication/Detect Communication Loss/MATLAB Function'
 * '<S49>'  : 'QD2_DroneStack_PID_2021a/Communication/Detect Communication Loss/Threshold1'
 * '<S50>'  : 'QD2_DroneStack_PID_2021a/Communication/Detect Communication Loss/Threshold2'
 * '<S51>'  : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox'
 * '<S52>'  : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Second-Order Low-Pass Filter'
 * '<S53>'  : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/MATLAB Function'
 * '<S54>'  : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/MATLAB Function1'
 * '<S55>'  : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/MATLAB Function2'
 * '<S56>'  : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/MATLAB Function4'
 * '<S57>'  : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Saturation Dynamic'
 * '<S58>'  : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Signmoid Type'
 * '<S59>'  : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Use des height  when enabled'
 * '<S60>'  : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Use des yaw  when enabled'
 * '<S61>'  : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Use desired X  when enabled'
 * '<S62>'  : 'QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Use desired Y  when enabled'
 * '<S63>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Attitude Estimate from IMU Data'
 * '<S64>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Choose Motor Telemetry'
 * '<S65>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Compare To Constant'
 * '<S66>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Compare To Constant1'
 * '<S67>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Construct ESC Speed'
 * '<S68>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Construct ESC Temperature'
 * '<S69>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Construct ESC Voltage'
 * '<S70>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Detect ESC Problems'
 * '<S71>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Discrete Second-Order Low-Pass Filter'
 * '<S72>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Discrete Second-Order Low-Pass Filter1'
 * '<S73>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Enabled Subsystem -  Write ESC Commands'
 * '<S74>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Force to percentage Mapping'
 * '<S75>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Generate LED Pattern'
 * '<S76>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/MATLAB Function'
 * '<S77>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Monitor Battery Level'
 * '<S78>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Radians to Degrees'
 * '<S79>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring'
 * '<S80>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Threshold'
 * '<S81>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Timing Monitors'
 * '<S82>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Attitude Estimate from IMU Data/For Each Subsystem - Iterate over IMU0 and IMU1'
 * '<S83>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Attitude Estimate from IMU Data/For Each Subsystem - Iterate over IMU0 and IMU1/Roll and Pitch Approximation from Accelerometer data'
 * '<S84>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Attitude Estimate from IMU Data/For Each Subsystem - Iterate over IMU0 and IMU1/Second-Order Low-Pass Filter'
 * '<S85>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Attitude Estimate from IMU Data/For Each Subsystem - Iterate over IMU0 and IMU1/Second-Order Low-Pass Filter1'
 * '<S86>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Choose Motor Telemetry/MATLAB Function'
 * '<S87>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Construct ESC Speed/For Each Subsystem -  Construct ESC Signal'
 * '<S88>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Construct ESC Temperature/For Each Subsystem -  Construct ESC Signal'
 * '<S89>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Construct ESC Voltage/For Each Subsystem -  Construct ESC Signal'
 * '<S90>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Detect ESC Problems/Compare To Constant'
 * '<S91>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Detect ESC Problems/For Each Subsystem'
 * '<S92>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Detect ESC Problems/MATLAB Function'
 * '<S93>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Detect ESC Problems/For Each Subsystem/Compare To Constant'
 * '<S94>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Monitor Battery Level/Greater than minimum expected voltage (Valid Battery Reading)'
 * '<S95>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Monitor Battery Level/Less than minimum threshold voltage (Battery level too low)'
 * '<S96>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Monitor Battery Level/Threshold'
 * '<S97>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Monitor Battery Level/Triggered Subsystem - Latching Flag'
 * '<S98>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold'
 * '<S99>'  : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold1'
 * '<S100>' : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold10'
 * '<S101>' : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold11'
 * '<S102>' : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold2'
 * '<S103>' : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold3'
 * '<S104>' : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold4'
 * '<S105>' : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold5'
 * '<S106>' : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold6'
 * '<S107>' : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold7'
 * '<S108>' : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold8'
 * '<S109>' : 'QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold9'
 * '<S110>' : 'QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY'
 * '<S111>' : 'QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/Radians to Degrees'
 * '<S112>' : 'QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/Radians to Degrees1'
 * '<S113>' : 'QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Communication'
 * '<S114>' : 'QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop model'
 * '<S115>' : 'QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop with Message'
 * '<S116>' : 'QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop with Message1'
 * '<S117>' : 'QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop with Message3'
 * '<S118>' : 'QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop with Message/Compare'
 * '<S119>' : 'QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop with Message1/Compare'
 * '<S120>' : 'QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop with Message3/Compare'
 */
#endif                                 /* QD2_DroneStack_PID_2021a_h_ */
