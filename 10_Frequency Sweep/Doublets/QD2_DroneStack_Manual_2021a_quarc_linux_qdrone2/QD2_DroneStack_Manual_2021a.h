/*
 * QD2_DroneStack_Manual_2021a.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QD2_DroneStack_Manual_2021a".
 *
 * Model version              : 3.0
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Fri Aug 14 17:12:33 2026
 *
 * Target selection: quarc_linux_qdrone2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef QD2_DroneStack_Manual_2021a_h_
#define QD2_DroneStack_Manual_2021a_h_
#ifndef QD2_DroneStack_Manual_2021a_COMMON_INCLUDES_
#define QD2_DroneStack_Manual_2021a_COMMON_INCLUDES_
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
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_start_time.h"
#include "quanser_extern.h"
#include "quanser_string.h"
#include "quanser_memory.h"
#include "stream_client_block.h"
#include "quanser_types.h"
#include "quanser_time.h"
#include "stream_server_block.h"
#include "quanser_ranging_sensor.h"
#endif                        /* QD2_DroneStack_Manual_2021a_COMMON_INCLUDES_ */

#include "QD2_DroneStack_Manual_2021a_types.h"
#include "rt_nonfinite.h"
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
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
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
#define QD2_DroneStack_Manual_2021a_rtModel RT_MODEL_QD2_DroneStack_Manua_T

/* Block signals for system '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
typedef struct {
  real_T Gain1[2];                     /* '<S28>/Gain1' */
  real_T Integrator1[3];               /* '<S30>/Integrator1' */
  real_T Product1[3];                  /* '<S30>/Product1' */
  real_T Product[3];                   /* '<S30>/Product' */
  real_T Product_j[3];                 /* '<S31>/Product' */
  real_T Product1_e[3];                /* '<S31>/Product1' */
  real_T Sum1[2];                      /* '<S28>/Sum1' */
} B_CoreSubsys_QD2_DroneStack_M_T;

/* Block states (default storage) for system '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
typedef struct {
  int32_T sfEvent;
              /* '<S28>/Roll and Pitch Approximation from Accelerometer data' */
  boolean_T Integrator1_DWORK1;        /* '<S31>/Integrator1' */
  boolean_T Integrator1_DWORK1_b;      /* '<S30>/Integrator1' */
  boolean_T doneDoubleBufferReInit;
              /* '<S28>/Roll and Pitch Approximation from Accelerometer data' */
} DW_CoreSubsys_QD2_DroneStack__T;

/* Continuous states for system '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S31>/Integrator1' */
  real_T Integrator1_CSTATE_h[2];      /* '<S28>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S28>/Integrator2' */
  real_T Integrator1_CSTATE_h5[3];     /* '<S30>/Integrator1' */
  real_T Integrator2_CSTATE_k[3];      /* '<S30>/Integrator2' */
  real_T Integrator_CSTATE[2];         /* '<S28>/Integrator' */
  real_T Integrator2_CSTATE_e[3];      /* '<S31>/Integrator2' */
} X_CoreSubsys_QD2_DroneStack_M_T;

/* State derivatives for system '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S31>/Integrator1' */
  real_T Integrator1_CSTATE_h[2];      /* '<S28>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S28>/Integrator2' */
  real_T Integrator1_CSTATE_h5[3];     /* '<S30>/Integrator1' */
  real_T Integrator2_CSTATE_k[3];      /* '<S30>/Integrator2' */
  real_T Integrator_CSTATE[2];         /* '<S28>/Integrator' */
  real_T Integrator2_CSTATE_e[3];      /* '<S31>/Integrator2' */
} XDot_CoreSubsys_QD2_DroneStac_T;

/* State Disabled for system '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
typedef struct {
  boolean_T Integrator1_CSTATE[3];     /* '<S31>/Integrator1' */
  boolean_T Integrator1_CSTATE_h[2];   /* '<S28>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S28>/Integrator2' */
  boolean_T Integrator1_CSTATE_h5[3];  /* '<S30>/Integrator1' */
  boolean_T Integrator2_CSTATE_k[3];   /* '<S30>/Integrator2' */
  boolean_T Integrator_CSTATE[2];      /* '<S28>/Integrator' */
  boolean_T Integrator2_CSTATE_e[3];   /* '<S31>/Integrator2' */
} XDis_CoreSubsys_QD2_DroneStac_T;

/* Block signals (default storage) */
typedef struct {
  real_T HILRead_o1[3];                /* '<S2>/HIL Read' */
  real_T HILRead_o2[23];               /* '<S2>/HIL Read' */
  real_T StreamClient_o4[11];          /* '<S1>/Stream Client' */
  real_T AttitudeTorqueCommands[3];    /* '<S4>/Switch' */
  real_T AttitudeAngleCommands[3];   /* '<S4>/Saturate Stabilization Command' */
  real_T SelectDataforIMU1[9];         /* '<S9>/Select Data for IMU1' */
  real_T SelectDataforIMU0[9];         /* '<S9>/Select Data for IMU0' */
  real_T Product3[9];                  /* '<S2>/Product3' */
  real_T Sum6[3];                      /* '<S4>/Sum6' */
  real_T SaturationCommandAuthorityNm1[3];
                                /* '<S4>/Saturation Command  Authority (Nm)1' */
  real_T Delay;                        /* '<S4>/Delay' */
  real_T MaximumCommandAuthority[4];   /* '<S2>/Maximum  Command Authority ' */
  real_T Selector[4];                  /* '<S10>/Selector' */
  real_T RateTransition7[2];           /* '<S2>/Rate Transition7' */
  real_T RateTransition2;              /* '<S2>/Rate Transition2' */
  real_T RateTransition1;              /* '<S2>/Rate Transition1' */
  real_T ExtractESCChannels[4];        /* '<S2>/Extract ESC Channels' */
  real_T ComputationTime;              /* '<S27>/Computation Time' */
  real_T SampleTime;                   /* '<S27>/Sample Time' */
  real_T RateTransition;               /* '<S27>/Rate Transition' */
  real_T RateTransition1_d;            /* '<S27>/Rate Transition1' */
  real_T RateTransition2_f;            /* '<S27>/Rate Transition2' */
  real_T RateTransition3;              /* '<S27>/Rate Transition3' */
  real_T RateTransition6[60];          /* '<S2>/Rate Transition6' */
  real_T Bias1[4];                     /* '<S10>/Bias1' */
  real_T Delay3;                       /* '<S16>/Delay3' */
  real_T Delay2;                       /* '<S16>/Delay2' */
  real_T Delay1;                       /* '<S16>/Delay1' */
  real_T Delay_i;                      /* '<S16>/Delay' */
  real_T DataTypeConversion;           /* '<S42>/Data Type Conversion' */
  real_T DataTypeConversion_h;         /* '<S26>/Data Type Conversion' */
  real_T Clock;                        /* '<S5>/Clock' */
  real_T DataTypeConversion_c;         /* '<S5>/Data Type Conversion' */
  real_T DataTypeConversion_k;         /* '<S7>/Data Type Conversion' */
  real_T DataTypeConversion_cz;        /* '<S8>/Data Type Conversion' */
  real_T Gain[6];                      /* '<S57>/Gain' */
  real_T Gain_l[6];                    /* '<S58>/Gain' */
  real_T SampleTime_h;                 /* '<S56>/Sample Time' */
  real_T ComputationTime_a;            /* '<S56>/Computation Time' */
  real_T DataTypeConversion4;          /* '<S56>/Data Type Conversion4' */
  real_T DataTypeConversion1;          /* '<S56>/Data Type Conversion1' */
  real_T DataTypeConversion5;          /* '<S56>/Data Type Conversion5' */
  real_T TmpSignalConversionAtToHostFile[20];
  real_T DataTypeConversion_p;         /* '<S59>/Data Type Conversion' */
  real_T DataTypeConversion_a;         /* '<S60>/Data Type Conversion' */
  real_T StreamServer_o4;              /* '<S2>/Stream Server' */
  real_T RateTransition_g[7];          /* '<S2>/Rate Transition' */
  real_T x0;                           /* '<S18>/x0' */
  real_T Product[2];                   /* '<S18>/Product' */
  real_T Product1[2];                  /* '<S18>/Product1' */
  real_T ToFFilterInitialConditionm;
                                   /* '<S2>/ToF Filter Initial Condition (m)' */
  real_T RangingSensor_o1;             /* '<S2>/Ranging Sensor' */
  real_T RangingSensor_o2;             /* '<S2>/Ranging Sensor' */
  real_T RangingSensor_o3;             /* '<S2>/Ranging Sensor' */
  real_T RangingSensor_o4;             /* '<S2>/Ranging Sensor' */
  real_T Product_k;                    /* '<S17>/Product' */
  real_T Product1_p;                   /* '<S17>/Product1' */
  real_T OutportBufferForOut1;         /* '<S43>/Constant' */
  real_T cmd[4];                       /* '<S2>/MATLAB Function' */
  real_T cmd_enable;                   /* '<S2>/MATLAB Function' */
  real_T tele_enable;                  /* '<S2>/MATLAB Function' */
  real_T esc_ready;                    /* '<S2>/MATLAB Function' */
  real_T esc_timeout;                  /* '<S2>/MATLAB Function' */
  real_T state;                        /* '<S2>/MATLAB Function' */
  real_T n[4];                         /* '<S16>/MATLAB Function' */
  real_T ImpAsg_InsertedFor_ESCDataOut4_[4];/* '<S35>/Switch' */
  real_T ImpAsg_InsertedFor_ESCDataOut_k[4];/* '<S34>/Switch' */
  real_T ImpAsg_InsertedFor_ESCDataOu_kc[4];/* '<S33>/Switch' */
  uint32_T DataTypeConversion_ko;      /* '<S2>/Data Type Conversion' */
  int32_T RateTransition14;            /* '<S2>/Rate Transition14' */
  uint8_T IPAddressofSupervisoryModelMiss[80];
     /* '<S1>/IP Address of  Supervisory Model (Mission Operator//Commander)' */
  uint8_T StreamClient_o1;             /* '<S1>/Stream Client' */
  uint8_T RateTransition16;            /* '<S2>/Rate Transition16' */
  boolean_T AND[4];                    /* '<S16>/AND' */
  boolean_T LogicalOperator;           /* '<S42>/Logical Operator' */
  boolean_T LogicalOperator_f;         /* '<S26>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S26>/Relational Operator' */
  boolean_T LogicalOperator_p;         /* '<S7>/Logical Operator' */
  boolean_T LogicalOperator_m;         /* '<S8>/Logical Operator' */
  boolean_T LogicalOperator_a;         /* '<S60>/Logical Operator' */
  boolean_T RelationalOperator_g;      /* '<S60>/Relational Operator' */
  boolean_T LogicalOperator_k;         /* '<S59>/Logical Operator' */
  boolean_T RelationalOperator_p;      /* '<S59>/Relational Operator' */
  boolean_T HILWatchdog;               /* '<S56>/HIL Watchdog' */
  boolean_T AND_g;                     /* '<S2>/AND' */
  B_CoreSubsys_QD2_DroneStack_M_T CoreSubsys[2];
                    /* '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
} B_QD2_DroneStack_Manual_2021a_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  t_ranging_measurement RangingSensor_Measurements;/* '<S2>/Ranging Sensor' */
  t_timeout Time_Timeout;              /* '<S2>/Time' */
  t_timeout ComputationTime_BeginTime; /* '<S27>/Computation Time' */
  t_timeout ComputationTime_ComputationTime;/* '<S27>/Computation Time' */
  t_timeout SampleTime_PreviousTime;   /* '<S27>/Sample Time' */
  t_timeout SampleTime_PreviousTime_j; /* '<S56>/Sample Time' */
  t_timeout ComputationTime_BeginTime_b;/* '<S56>/Computation Time' */
  t_timeout ComputationTime_ComputationTi_j;/* '<S56>/Computation Time' */
  t_timeout ComputationTime1_BeginTime;/* '<S27>/Computation Time1' */
  t_timeout ComputationTime1_ComputationTim;/* '<S27>/Computation Time1' */
  t_timeout SampleTime1_PreviousTime;  /* '<S27>/Sample Time1' */
  t_timeout ComputationTime2_BeginTime;/* '<S27>/Computation Time2' */
  t_timeout ComputationTime2_ComputationTim;/* '<S27>/Computation Time2' */
  t_timeout SampleTime2_PreviousTime;  /* '<S27>/Sample Time2' */
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  real_T Delay_DSTATE_l[50];           /* '<S4>/Delay' */
  real_T Delay3_DSTATE[2];             /* '<S16>/Delay3' */
  real_T Delay2_DSTATE[2];             /* '<S16>/Delay2' */
  real_T Delay1_DSTATE[2];             /* '<S16>/Delay1' */
  real_T Delay_DSTATE_ln[2];           /* '<S16>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S42>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S26>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S7>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S8>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S60>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_lx;/* '<S59>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_o[2];/* '<S18>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S18>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S17>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTAT_d;/* '<S17>/Discrete-Time Integrator1' */
  real_T HILInitialize_AIMinimums[4];  /* '<S2>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[4];  /* '<S2>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[2];/* '<S2>/HIL Initialize' */
  real_T HILInitialize_POSortedFreqs[6];/* '<S2>/HIL Initialize' */
  real_T HILInitialize_POValues[6];    /* '<S2>/HIL Initialize' */
  real_T Memory_PreviousInput;         /* '<S2>/Memory' */
  real_T RateTransition7_Buffer0[2];   /* '<S2>/Rate Transition7' */
  real_T RateTransition2_Buffer0;      /* '<S2>/Rate Transition2' */
  real_T RateTransition1_Buffer0;      /* '<S2>/Rate Transition1' */
  real_T Memory_PreviousInput_h[4];    /* '<S13>/Memory' */
  real_T Memory_PreviousInput_k[4];    /* '<S15>/Memory' */
  real_T RateTransition_Buffer0;       /* '<S27>/Rate Transition' */
  real_T RateTransition1_Buffer0_l;    /* '<S27>/Rate Transition1' */
  real_T RateTransition2_Buffer0_l;    /* '<S27>/Rate Transition2' */
  real_T RateTransition3_Buffer0;      /* '<S27>/Rate Transition3' */
  real_T Memory_PreviousInput_a[4];    /* '<S14>/Memory' */
  real_T RateTransition_Buffer[7];     /* '<S2>/Rate Transition' */
  real_T RateTransition10_Buffer[4];   /* '<S2>/Rate Transition10' */
  real_T RateTransition11_Buffer;      /* '<S2>/Rate Transition11' */
  real_T RateTransition12_Buffer;      /* '<S2>/Rate Transition12' */
  real_T RateTransition15_Buffer[9];   /* '<S2>/Rate Transition15' */
  real_T RateTransition17_Buffer[9];   /* '<S2>/Rate Transition17' */
  real_T RateTransition19_Buffer[9];   /* '<S2>/Rate Transition19' */
  real_T RateTransition20_Buffer;      /* '<S2>/Rate Transition20' */
  real_T RateTransition3_Buffer[9];    /* '<S2>/Rate Transition3' */
  real_T RateTransition8_Buffer[12];   /* '<S2>/Rate Transition8' */
  real_T Memory2_PreviousInput;        /* '<S2>/Memory2' */
  real_T next_state_after_pause;       /* '<S2>/MATLAB Function' */
  real_T state_counter;                /* '<S2>/MATLAB Function' */
  real_T state_counter_after_pause;    /* '<S2>/MATLAB Function' */
  real_T esc_timeout_state;            /* '<S2>/MATLAB Function' */
  real_T idx;                          /* '<S16>/MATLAB Function' */
  real_T state;                        /* '<S10>/MATLAB Function' */
  real_T ms_time_prev;                 /* '<S5>/MATLAB Function' */
  t_pstream StreamClient_Stream;       /* '<S1>/Stream Client' */
  t_pstream StreamServer_Stream;       /* '<S2>/Stream Server' */
  t_ranging_sensor RangingSensor_Sensor;/* '<S2>/Ranging Sensor' */
  t_uint64 ToHostFile_PointsWritten;   /* '<S2>/To Host File' */
  t_uint64 ToHostFile_PointsWritten_m; /* '<S4>/To Host File' */
  t_card HILInitialize_Card;           /* '<S2>/HIL Initialize' */
  void *HILRead_PWORK;                 /* '<S2>/HIL Read' */
  struct {
    void *LoggedData;
  } ESCSelectRaw_PWORK;                /* '<S2>/ESC Select Raw' */

  void *HILWriteDigital_PWORK;         /* '<S2>/HIL Write Digital' */
  void *ToHostFile_PWORK[2];           /* '<S2>/To Host File' */
  struct {
    void *LoggedData;
  } Telemetry_PWORK;                   /* '<S10>/Telemetry' */

  struct {
    void *LoggedData[4];
  } ESCChannelMismatrch_PWORK;         /* '<S16>/ESC Channel Mismatrch' */

  struct {
    void *LoggedData[4];
  } ESCChannelMismatrchCount_PWORK;    /* '<S16>/ESC Channel Mismatrch Count' */

  struct {
    void *LoggedData[4];
  } ESCChannelSelectionIndex_PWORK;    /* '<S16>/ESC Channel Selection Index' */

  struct {
    void *LoggedData[3];
  } TimingCheck_PWORK;                 /* '<S27>/Timing Check' */

  struct {
    void *LoggedData[2];
  } RollandPitchAngleControldeg_PWO;
                                 /* '<S4>/Roll and Pitch Angle Control (deg)' */

  struct {
    void *LoggedData[3];
  } RollPitchandYawRateControldegs_;
                          /* '<S4>/Roll, Pitch and Yaw Rate Control (deg//s)' */

  void *HILWatchdog_PWORK;             /* '<S56>/HIL Watchdog' */
  void *ToHostFile_PWORK_f[2];         /* '<S4>/To Host File' */
  struct {
    void *LoggedData;
  } ComputationTimes_PWORK;            /* '<S56>/Computation Time (s)' */

  struct {
    void *LoggedData;
  } SampleTimes_PWORK;                 /* '<S56>/Sample Time (s)' */

  void *HILWritePWM_PWORK;             /* '<S19>/HIL Write PWM' */
  emxArray_real_T_QD2_DroneStac_T* buffer;/* '<S16>/MATLAB Function' */
  int32_T HILInitialize_DOStates[6];   /* '<S2>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[2];/* '<S2>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[2];/* '<S2>/HIL Initialize' */
  int32_T HILInitialize_POModeValues[6];/* '<S2>/HIL Initialize' */
  int32_T HILInitialize_POAlignValues[6];/* '<S2>/HIL Initialize' */
  int32_T HILInitialize_POPolarityVals[6];/* '<S2>/HIL Initialize' */
  int32_T sfEvent;                     /* '<S2>/MATLAB Function' */
  int32_T sfEvent_e;                   /* '<S2>/Force to percentage Mapping' */
  int32_T sfEvent_d;                   /* '<S16>/MATLAB Function' */
  int32_T sfEvent_b;                   /* '<S10>/MATLAB Function' */
  int32_T sfEvent_a;                   /* '<S5>/MATLAB Function' */
  uint32_T HILInitialize_POSortedChans[6];/* '<S2>/HIL Initialize' */
  uint32_T ToHostFile_SamplesCount;    /* '<S2>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength; /* '<S2>/To Host File' */
  uint32_T ToHostFile_SamplesCount_k;  /* '<S4>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength_l;/* '<S4>/To Host File' */
  int_T StringDisplay_IWORK[2];        /* '<S1>/String Display' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S42>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_h;/* '<S26>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_hs;/* '<S7>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_b;/* '<S8>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_j;/* '<S60>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_k;/* '<S59>/Discrete-Time Integrator' */
  int8_T TriggeredSubsystemLatchingFlag_;
                               /* '<S23>/Triggered Subsystem - Latching Flag' */
  int8_T EnabledSubsystemWriteESCCommand;
                            /* '<S2>/Enabled Subsystem -  Write ESC Commands' */
  boolean_T HILInitialize_DOBits[6];   /* '<S2>/HIL Initialize' */
  boolean_T Time_Owner;                /* '<S2>/Time' */
  boolean_T StreamClient_Connected;    /* '<S1>/Stream Client' */
  boolean_T Memory1_PreviousInput;     /* '<S2>/Memory1' */
  boolean_T HILWatchdog_IsStarted;     /* '<S56>/HIL Watchdog' */
  boolean_T Memory3_PreviousInput;     /* '<S2>/Memory3' */
  boolean_T doneDoubleBufferReInit;    /* '<S2>/MATLAB Function' */
  boolean_T next_state_after_pause_not_empt;/* '<S2>/MATLAB Function' */
  boolean_T state_counter_not_empty;   /* '<S2>/MATLAB Function' */
  boolean_T state_counter_after_pause_not_e;/* '<S2>/MATLAB Function' */
  boolean_T esc_timeout_state_not_empty;/* '<S2>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S2>/Force to percentage Mapping' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S16>/MATLAB Function' */
  boolean_T idx_not_empty;             /* '<S16>/MATLAB Function' */
  boolean_T buffer_not_empty;          /* '<S16>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_o;  /* '<S10>/MATLAB Function' */
  boolean_T state_not_empty;           /* '<S10>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_b;  /* '<S5>/MATLAB Function' */
  boolean_T ms_time_prev_not_empty;    /* '<S5>/MATLAB Function' */
  t_boolean HILWriteDigital_Buffer[6]; /* '<S2>/HIL Write Digital' */
  DW_CoreSubsys_QD2_DroneStack__T CoreSubsys[2];
                    /* '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
} DW_QD2_DroneStack_Manual_2021_T;

/* Continuous states (default storage) */
typedef struct {
  X_CoreSubsys_QD2_DroneStack_M_T CoreSubsys[2];/* '<S28>/CoreSubsys' */
} X_QD2_DroneStack_Manual_2021a_T;

/* State derivatives (default storage) */
typedef struct {
  XDot_CoreSubsys_QD2_DroneStac_T CoreSubsys[2];/* '<S28>/CoreSubsys' */
} XDot_QD2_DroneStack_Manual_20_T;

/* State disabled  */
typedef struct {
  XDis_CoreSubsys_QD2_DroneStac_T CoreSubsys[2];/* '<S28>/CoreSubsys' */
} XDis_QD2_DroneStack_Manual_20_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystemLatchingFlag_;
                               /* '<S23>/Triggered Subsystem - Latching Flag' */
} PrevZCX_QD2_DroneStack_Manual_T;

#ifndef ODE2_INTG
#define ODE2_INTG

/* ODE2 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[2];                        /* derivatives */
} ODE2_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            QD2_DroneStack_Manual_2021a_B
#define BlockIO                        B_QD2_DroneStack_Manual_2021a_T
#define rtX                            QD2_DroneStack_Manual_2021a_X
#define ContinuousStates               X_QD2_DroneStack_Manual_2021a_T
#define rtXdot                         QD2_DroneStack_Manual_2021_XDot
#define StateDerivatives               XDot_QD2_DroneStack_Manual_20_T
#define tXdis                          QD2_DroneStack_Manual_2021_XDis
#define StateDisabled                  XDis_QD2_DroneStack_Manual_20_T
#define rtP                            QD2_DroneStack_Manual_2021a_P
#define Parameters                     P_QD2_DroneStack_Manual_2021a_T
#define rtDWork                        QD2_DroneStack_Manual_2021a_DW
#define D_Work                         DW_QD2_DroneStack_Manual_2021_T
#define rtPrevZCSigState               QD2_DroneStack_Manual_2_PrevZCX
#define PrevZCSigStates                PrevZCX_QD2_DroneStack_Manual_T

/* Parameters for system: '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
struct P_CoreSubsys_QD2_DroneStack_M_T_ {
  real_T AccelerometerFilterCutoffFreque;/* Expression: 120
                                          * Referenced by: '<S28>/Accelerometer Filter Cutoff Frequency (rad//s)'
                                          */
  real_T AccelerometerFilterDampingRatio;/* Expression: 1
                                          * Referenced by: '<S28>/Accelerometer Filter Damping Ratio'
                                          */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S28>/Integrator1'
                                        */
  real_T Gain_Gain[2];                 /* Expression: [0.25 0.25]
                                        * Referenced by: '<S28>/Gain'
                                        */
  real_T Gain1_Gain[2];                /* Expression: [0.1 0.1]
                                        * Referenced by: '<S28>/Gain1'
                                        */
  real_T GyroFilterCutoffFrequencyrads_V;/* Expression: 100
                                          * Referenced by: '<S28>/Gyro Filter Cutoff Frequency (rad//s)'
                                          */
  real_T GyroFilterDampingRatio_Value; /* Expression: 0.7
                                        * Referenced by: '<S28>/Gyro Filter Damping Ratio'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S28>/Integrator2'
                                        */
  real_T Integrator2_IC_j;             /* Expression: 0
                                        * Referenced by: '<S30>/Integrator2'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S28>/Integrator'
                                        */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: 2
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Integrator2_IC_g;             /* Expression: 0
                                        * Referenced by: '<S31>/Integrator2'
                                        */
};

/* Parameters for system: '<S16>/For Each Subsystem' */
struct P_CoreSubsys_QD2_DroneStac_gm_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S39>/Constant'
                                       */
};

/* Parameters (default storage) */
struct P_QD2_DroneStack_Manual_2021a_T_ {
  real_T KT[3];                        /* Variable: KT
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Motor_Matrix[16];             /* Variable: Motor_Matrix
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S36>/Constant'
                                       */
  real_T Greaterthanminimumexpectedvolta;
                              /* Mask Parameter: Greaterthanminimumexpectedvolta
                               * Referenced by: '<S40>/Constant'
                               */
  real_T Lessthanminimumthresholdvoltage;
                              /* Mask Parameter: Lessthanminimumthresholdvoltage
                               * Referenced by: '<S41>/Constant'
                               */
  real_T StreamClient_default_value[11];
                                   /* Mask Parameter: StreamClient_default_value
                                    * Referenced by: '<S1>/Stream Client'
                                    */
  real_T StreamServer_default_value;
                                   /* Mask Parameter: StreamServer_default_value
                                    * Referenced by: '<S2>/Stream Server'
                                    */
  real_T Threshold_duration;           /* Mask Parameter: Threshold_duration
                                        * Referenced by: '<S26>/duration'
                                        */
  real_T Threshold_duration_d;         /* Mask Parameter: Threshold_duration_d
                                        * Referenced by: '<S7>/duration'
                                        */
  real_T Threshold1_duration;          /* Mask Parameter: Threshold1_duration
                                        * Referenced by: '<S8>/duration'
                                        */
  real_T Stopmodel_duration;           /* Mask Parameter: Stopmodel_duration
                                        * Referenced by: '<S60>/duration'
                                        */
  real_T Communication_duration;       /* Mask Parameter: Communication_duration
                                        * Referenced by: '<S59>/duration'
                                        */
  real_T DiscreteSecondOrderLowPassFilte;
                              /* Mask Parameter: DiscreteSecondOrderLowPassFilte
                               * Referenced by: '<S18>/bandwidth'
                               */
  real_T DiscreteSecondOrderLowPassFil_p;
                              /* Mask Parameter: DiscreteSecondOrderLowPassFil_p
                               * Referenced by: '<S18>/zeta'
                               */
  real_T Threshold_threshold;          /* Mask Parameter: Threshold_threshold
                                        * Referenced by: '<S26>/threshold'
                                        */
  real_T Threshold_threshold_h;        /* Mask Parameter: Threshold_threshold_h
                                        * Referenced by: '<S7>/threshold'
                                        */
  real_T Threshold1_threshold;         /* Mask Parameter: Threshold1_threshold
                                        * Referenced by: '<S8>/threshold'
                                        */
  real_T Stopmodel_threshold;          /* Mask Parameter: Stopmodel_threshold
                                        * Referenced by: '<S60>/threshold'
                                        */
  real_T Communication_threshold;     /* Mask Parameter: Communication_threshold
                                       * Referenced by: '<S59>/threshold'
                                       */
  int32_T CompareToConstant1_const;  /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S12>/Constant'
                                      */
  uint32_T HILRead_analog_channels[3];/* Mask Parameter: HILRead_analog_channels
                                       * Referenced by: '<S2>/HIL Read'
                                       */
  uint32_T HILWritePWM_channels[4];    /* Mask Parameter: HILWritePWM_channels
                                        * Referenced by: '<S19>/HIL Write PWM'
                                        */
  uint32_T HILWriteDigital_channels[6];
                                     /* Mask Parameter: HILWriteDigital_channels
                                      * Referenced by: '<S2>/HIL Write Digital'
                                      */
  uint32_T HILRead_other_channels[23]; /* Mask Parameter: HILRead_other_channels
                                        * Referenced by: '<S2>/HIL Read'
                                        */
  int8_T StopwithMessage_message_icon;
                                 /* Mask Parameter: StopwithMessage_message_icon
                                  * Referenced by: '<S61>/Show Message on Host'
                                  */
  int8_T StopwithMessage1_message_icon;
                                /* Mask Parameter: StopwithMessage1_message_icon
                                 * Referenced by: '<S62>/Show Message on Host'
                                 */
  int8_T StopwithMessage3_message_icon;
                                /* Mask Parameter: StopwithMessage3_message_icon
                                 * Referenced by: '<S63>/Show Message on Host'
                                 */
  uint8_T StringDisplay_alignment;    /* Mask Parameter: StringDisplay_alignment
                                       * Referenced by: '<S1>/String Display'
                                       */
  uint8_T CompareToConstant_const_e;/* Mask Parameter: CompareToConstant_const_e
                                     * Referenced by: '<S11>/Constant'
                                     */
  uint8_T StringDisplay_display_mode;
                                   /* Mask Parameter: StringDisplay_display_mode
                                    * Referenced by: '<S1>/String Display'
                                    */
  real_T RedRed_Value[6];              /* Expression: [ 1 0 0 1 0 0]
                                        * Referenced by: '<S21>/Red Red'
                                        */
  real_T LEDOFF_Value[6];              /* Expression: [ 0 0 0 0 0 0]
                                        * Referenced by: '<S21>/LED OFF'
                                        */
  real_T YellowYellow_Value[6];        /* Expression: [ 1 1 0 1 1 0  ]
                                        * Referenced by: '<S21>/Yellow Yellow'
                                        */
  real_T YellowGreen_Value[6];         /* Expression: [ 1 1 0 0 1 0  ]
                                        * Referenced by: '<S21>/Yellow Green'
                                        */
  real_T BlueBlue_Value[6];            /* Expression: [0 0 1 0 0 1]
                                        * Referenced by: '<S21>/Blue Blue'
                                        */
  real_T YellowRed_Value[6];           /* Expression: [ 1 1 0 1 0 0  ]
                                        * Referenced by: '<S21>/Yellow Red'
                                        */
  real_T RedYellow_Value[6];           /* Expression: [ 1 0 0 1 1 0  ]
                                        * Referenced by: '<S21>/Red Yellow'
                                        */
  real_T GreenGreen_Value[6];          /* Expression: [0 1 0 0 1 0]
                                        * Referenced by: '<S21>/Green Green'
                                        */
  real_T YellowBlue_Value[6];          /* Expression: [ 1 1 0 0 0 1  ]
                                        * Referenced by: '<S21>/Yellow Blue'
                                        */
  real_T RedBlue_Value[6];             /* Expression: [ 1 0 0 0 0 1   ]
                                        * Referenced by: '<S21>/Red Blue'
                                        */
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S43>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T Motor0_Value[4];              /* Expression: [1 0 0 0]
                                        * Referenced by: '<S2>/Motor 0'
                                        */
  real_T Motor1_Value[4];              /* Expression: [0 1 0 0]
                                        * Referenced by: '<S2>/Motor 1'
                                        */
  real_T Motor2_Value[4];              /* Expression: [0 0 1 0]
                                        * Referenced by: '<S2>/Motor 2'
                                        */
  real_T Motor3_Value[4];              /* Expression: [0 0 0 1]
                                        * Referenced by: '<S2>/Motor 3'
                                        */
  real_T Noselection_Value[4];         /* Expression: [0 0 0 0]
                                        * Referenced by: '<S2>/No selection'
                                        */
  real_T HILInitialize_OOTerminate;/* Expression: set_other_outputs_at_terminate
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  real_T HILInitialize_OOExit;    /* Expression: set_other_outputs_at_switch_out
                                   * Referenced by: '<S2>/HIL Initialize'
                                   */
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;    /* Expression: set_other_outputs_at_switch_in
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh;         /* Expression: analog_input_maximums
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow;          /* Expression: analog_input_minimums
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_EIFrequency;    /* Expression: encoder_filter_frequency
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_POFrequency;    /* Expression: pwm_frequency
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_POInitial;      /* Expression: initial_pwm_outputs
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T HILInitialize_POWatchdog;     /* Expression: watchdog_pwm_outputs
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T ZeroTorqueCommand_Value[3];   /* Expression: [0 0 0]
                                        * Referenced by: '<S4>/Zero Torque//Command'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S4>/Switch1'
                                        */
  real_T SaturateStabilizationCommand_Up[3];/* Expression: [pi/4 pi/4 10*pi/18]
                                             * Referenced by: '<S4>/Saturate Stabilization Command'
                                             */
  real_T SaturateStabilizationCommand_Lo[3];/* Expression: [-pi/4 -pi/4 -10*pi/18]
                                             * Referenced by: '<S4>/Saturate Stabilization Command'
                                             */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Gain1_Gain[3];                /* Expression: [1 1 0]
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T K_p_angleradsrad_Gain[3];     /* Expression: [12 12 1]
                                        * Referenced by: '<S4>/K_p_angle (rad//s // rad)'
                                        */
  real_T Scale_Gain[3];                /* Expression: [1 1 2]
                                        * Referenced by: '<S4>/Scale'
                                        */
  real_T K_d_angleradsrads_Gain[3];    /* Expression: [0.1 0.1 0]
                                        * Referenced by: '<S4>/K_d_angle (rad//s // rad//s)'
                                        */
  real_T Scale1_Gain[3];               /* Expression: [1 1 2]
                                        * Referenced by: '<S4>/Scale1'
                                        */
  real_T SaturationMaxRaterads_UpperSat[3];/* Expression: 10*pi/3*[1 1 1]
                                            * Referenced by: '<S4>/Saturation Max Rate  (rad//s)'
                                            */
  real_T SaturationMaxRaterads_LowerSat[3];/* Expression: -10*pi/3*[1 1 1]
                                            * Referenced by: '<S4>/Saturation Max Rate  (rad//s)'
                                            */
  real_T K_p_speedNmrads_Gain[3];   /* Expression: [ 0.1876    0.1544    0.0395]
                                     * Referenced by: '<S4>/K_p_speed (Nm // rad//s)'
                                     */
  real_T Scale5_Gain[3];               /* Expression: [1 1 2]
                                        * Referenced by: '<S4>/Scale5'
                                        */
  real_T K_d_speedNmradss1_Gain[3];  /* Expression: [0.0032    0.0026     0.005]
                                      * Referenced by: '<S4>/K_d_speed (Nm // rad//s//s)1'
                                      */
  real_T Scale4_Gain[3];               /* Expression: [1 1 2]
                                        * Referenced by: '<S4>/Scale4'
                                        */
  real_T SaturationCommandAuthorityNm1_U[3];/* Expression: [1.0915 0.8984 0.0984]
                                             * Referenced by: '<S4>/Saturation Command  Authority (Nm)1'
                                             */
  real_T SaturationCommandAuthorityNm1_L[3];/* Expression: -[1.0915 0.8984 0.0984]
                                             * Referenced by: '<S4>/Saturation Command  Authority (Nm)1'
                                             */
  real_T Delay_InitialCondition_i;     /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay'
                                        */
  real_T ZeroReferenceMotorCommands_Valu[4];/* Expression: [0 0 0 0]
                                             * Referenced by: '<Root>/Zero Reference Motor Commands'
                                             */
  real_T MaximumCommandAuthority_UpperSa[4];/* Expression: [1 1 1 1]
                                             * Referenced by: '<S2>/Maximum  Command Authority '
                                             */
  real_T MaximumCommandAuthority_LowerSa[4];/* Expression: [1 1 1 1]*0.025
                                             * Referenced by: '<S2>/Maximum  Command Authority '
                                             */
  real_T Constant1_Value_f[32];
  /* Expression: [0 0 0 0; 1 0 0 0; 0 0 0 0; 0 1 0 0; 0 0 0 0; 0 0 1 0; 0 0 0 0;  0 0 0 1]
   * Referenced by: '<S10>/Constant1'
   */
  real_T Constant2_Value;              /* Expression: 8
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T RateTransition7_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S2>/Rate Transition7'
                                          */
  real_T RateTransition2_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S2>/Rate Transition2'
                                          */
  real_T RateTransition1_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S2>/Rate Transition1'
                                          */
  real_T Dividebyhalfofthenumberofpolesi;/* Expression: 2/14
                                          * Referenced by: '<S2>/Divide by half of the number of poles in motor'
                                          */
  real_T Multiplebyresolutionsupposedtob;/* Expression: 1
                                          * Referenced by: '<S2>/Multiple by resolution (supposed to be 100 RPM)'
                                          */
  real_T Memory_InitialCondition_k[4]; /* Expression: zeros(1,4)
                                        * Referenced by: '<S13>/Memory'
                                        */
  real_T Converttoequivalentvoltagebased;/* Expression: 1/1300
                                          * Referenced by: '<S2>/Convert to equivalent voltage (based on motor Kv rating)'
                                          */
  real_T Saturation_UpperSat;          /* Expression: 17
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 10
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Memory_InitialCondition_b[4]; /* Expression: zeros(1,4)
                                        * Referenced by: '<S15>/Memory'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S27>/Rate Transition'
                                          */
  real_T RateTransition1_InitialCondit_m;/* Expression: 0
                                          * Referenced by: '<S27>/Rate Transition1'
                                          */
  real_T RateTransition2_InitialCondit_o;/* Expression: 0
                                          * Referenced by: '<S27>/Rate Transition2'
                                          */
  real_T RateTransition3_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S27>/Rate Transition3'
                                          */
  real_T Gain_Gain;                    /* Expression: .7
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Bias1_Bias[4];                /* Expression: 0:3
                                        * Referenced by: '<S10>/Bias1'
                                        */
  real_T Memory_InitialCondition_bp[4];/* Expression: zeros(1,4)
                                        * Referenced by: '<S14>/Memory'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S16>/Delay3'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S16>/Delay2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S16>/Delay1'
                                        */
  real_T Delay_InitialCondition_m;     /* Expression: 0.0
                                        * Referenced by: '<S16>/Delay'
                                        */
  real_T Constant_Value_o;             /* Expression: 200
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T ZeroYaw_Value;                /* Expression: 0
                                        * Referenced by: '<S2>/Zero Yaw'
                                        */
  real_T BatteryLowTimeThresholds_Value;/* Expression: 0.3
                                         * Referenced by: '<S23>/Battery Low Time Threshold (s)'
                                         */
  real_T Constant_Value_j;             /* Expression: 0.5
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S42>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S42>/Discrete-Time Integrator'
                                        */
  real_T Constant1_Value_o;            /* Expression: 1
                                        * Referenced by: '<S25>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                           * Referenced by: '<S26>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_j;  /* Expression: 0
                                        * Referenced by: '<S26>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_o;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                           * Referenced by: '<S7>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                           * Referenced by: '<S8>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: 0
                                        * Referenced by: '<S8>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 180/pi
                                        * Referenced by: '<S57>/Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180/pi
                                        * Referenced by: '<S58>/Gain'
                                        */
  real_T DiscreteTimeIntegrator_gainv_bm;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_bm
                           * Referenced by: '<S60>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_a;  /* Expression: 0
                                        * Referenced by: '<S60>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainv_b1;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_b1
                           * Referenced by: '<S59>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_my; /* Expression: 0
                                        * Referenced by: '<S59>/Discrete-Time Integrator'
                                        */
  real_T HILWatchdog_Timeout;          /* Expression: timeout
                                        * Referenced by: '<S56>/HIL Watchdog'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S2>/Memory2'
                                        */
  real_T Constant_Value_l;             /* Expression: 2
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_f;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                           * Referenced by: '<S18>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_n;  /* Expression: 0
                                        * Referenced by: '<S18>/Discrete-Time Integrator'
                                        */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S18>/x0'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S18>/Discrete-Time Integrator1'
                           */
  real_T Constant_Value_n;             /* Expression: 2
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainv_o5;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_o5
                           * Referenced by: '<S17>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_ac; /* Expression: 0
                                        * Referenced by: '<S17>/Discrete-Time Integrator'
                                        */
  real_T ToFFilterInitialConditionm_Valu;/* Expression: 0
                                          * Referenced by: '<S2>/ToF Filter Initial Condition (m)'
                                          */
  real_T DiscreteTimeIntegrator1_gainv_i;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainv_i
                           * Referenced by: '<S17>/Discrete-Time Integrator1'
                           */
  real_T ToFFilterCutoffFrequencyrad_Val;/* Expression: 40
                                          * Referenced by: '<S2>/ToF Filter Cutoff Frequency (rad)'
                                          */
  real_T RangingSensor_Budget;         /* Expression: timing_budget
                                        * Referenced by: '<S2>/Ranging Sensor'
                                        */
  real_T RangingSensor_Period;         /* Expression: measurement_period
                                        * Referenced by: '<S2>/Ranging Sensor'
                                        */
  real_T RangingSensor_MaxInterpolationD;/* Expression: max_interpolated_distance
                                          * Referenced by: '<S2>/Ranging Sensor'
                                          */
  real_T RangingSensor_MaxInterpolationA;/* Expression: max_interpolated_angle
                                          * Referenced by: '<S2>/Ranging Sensor'
                                          */
  real_T ToFFilterDampingRatio_Value;  /* Expression: 1
                                        * Referenced by: '<S2>/ToF Filter Damping Ratio'
                                        */
  real_T ToFSensorXYOffsetsm_Value[2]; /* Expression: [0 0]
                                        * Referenced by: '<S2>/ToF Sensor XY Offsets (m)'
                                        */
  int32_T HILInitialize_DOWatchdog[6];
                                 /* Computed Parameter: HILInitialize_DOWatchdog
                                  * Referenced by: '<S2>/HIL Initialize'
                                  */
  int32_T HILInitialize_EIInitial;/* Computed Parameter: HILInitialize_EIInitial
                                   * Referenced by: '<S2>/HIL Initialize'
                                   */
  int32_T HILInitialize_POModes[5]; /* Computed Parameter: HILInitialize_POModes
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  int32_T HILInitialize_POConfiguration;
                            /* Computed Parameter: HILInitialize_POConfiguration
                             * Referenced by: '<S2>/HIL Initialize'
                             */
  int32_T HILInitialize_POAlignment;
                                /* Computed Parameter: HILInitialize_POAlignment
                                 * Referenced by: '<S2>/HIL Initialize'
                                 */
  int32_T HILInitialize_POPolarity;
                                 /* Computed Parameter: HILInitialize_POPolarity
                                  * Referenced by: '<S2>/HIL Initialize'
                                  */
  int32_T StreamClient_SndPriority;
                                 /* Computed Parameter: StreamClient_SndPriority
                                  * Referenced by: '<S1>/Stream Client'
                                  */
  int32_T StreamClient_RcvPriority;
                                 /* Computed Parameter: StreamClient_RcvPriority
                                  * Referenced by: '<S1>/Stream Client'
                                  */
  int32_T ToHostFile_Encoding;        /* Computed Parameter: ToHostFile_Encoding
                                       * Referenced by: '<S2>/To Host File'
                                       */
  int32_T ToHostFile_Encoding_b;    /* Computed Parameter: ToHostFile_Encoding_b
                                     * Referenced by: '<S4>/To Host File'
                                     */
  int32_T StreamServer_SndPriority;
                                 /* Computed Parameter: StreamServer_SndPriority
                                  * Referenced by: '<S2>/Stream Server'
                                  */
  int32_T StreamServer_RcvPriority;
                                 /* Computed Parameter: StreamServer_RcvPriority
                                  * Referenced by: '<S2>/Stream Server'
                                  */
  uint32_T HILInitialize_AIChannels[4];
                                 /* Computed Parameter: HILInitialize_AIChannels
                                  * Referenced by: '<S2>/HIL Initialize'
                                  */
  uint32_T HILInitialize_DIChannels[6];
                                 /* Computed Parameter: HILInitialize_DIChannels
                                  * Referenced by: '<S2>/HIL Initialize'
                                  */
  uint32_T HILInitialize_DOChannels[6];
                                 /* Computed Parameter: HILInitialize_DOChannels
                                  * Referenced by: '<S2>/HIL Initialize'
                                  */
  uint32_T HILInitialize_EIChannels[2];
                                 /* Computed Parameter: HILInitialize_EIChannels
                                  * Referenced by: '<S2>/HIL Initialize'
                                  */
  uint32_T HILInitialize_EIQuadrature;
                               /* Computed Parameter: HILInitialize_EIQuadrature
                                * Referenced by: '<S2>/HIL Initialize'
                                */
  uint32_T HILInitialize_POChannels[6];
                                 /* Computed Parameter: HILInitialize_POChannels
                                  * Referenced by: '<S2>/HIL Initialize'
                                  */
  uint32_T StreamClient_SndSize;     /* Computed Parameter: StreamClient_SndSize
                                      * Referenced by: '<S1>/Stream Client'
                                      */
  uint32_T StreamClient_RcvSize;     /* Computed Parameter: StreamClient_RcvSize
                                      * Referenced by: '<S1>/Stream Client'
                                      */
  uint32_T StreamClient_SndFIFO;     /* Computed Parameter: StreamClient_SndFIFO
                                      * Referenced by: '<S1>/Stream Client'
                                      */
  uint32_T StreamClient_RcvFIFO;     /* Computed Parameter: StreamClient_RcvFIFO
                                      * Referenced by: '<S1>/Stream Client'
                                      */
  uint32_T ToHostFile_Decimation;   /* Computed Parameter: ToHostFile_Decimation
                                     * Referenced by: '<S2>/To Host File'
                                     */
  uint32_T ToHostFile_BitRate;         /* Computed Parameter: ToHostFile_BitRate
                                        * Referenced by: '<S2>/To Host File'
                                        */
  uint32_T ToHostFile_Decimation_m;
                                  /* Computed Parameter: ToHostFile_Decimation_m
                                   * Referenced by: '<S4>/To Host File'
                                   */
  uint32_T ToHostFile_BitRate_b;     /* Computed Parameter: ToHostFile_BitRate_b
                                      * Referenced by: '<S4>/To Host File'
                                      */
  uint32_T StreamServer_SndSize;     /* Computed Parameter: StreamServer_SndSize
                                      * Referenced by: '<S2>/Stream Server'
                                      */
  uint32_T StreamServer_RcvSize;     /* Computed Parameter: StreamServer_RcvSize
                                      * Referenced by: '<S2>/Stream Server'
                                      */
  uint32_T StreamServer_SndFIFO;     /* Computed Parameter: StreamServer_SndFIFO
                                      * Referenced by: '<S2>/Stream Server'
                                      */
  uint32_T StreamServer_RcvFIFO;     /* Computed Parameter: StreamServer_RcvFIFO
                                      * Referenced by: '<S2>/Stream Server'
                                      */
  uint32_T RangingSensor_Range;       /* Computed Parameter: RangingSensor_Range
                                       * Referenced by: '<S2>/Ranging Sensor'
                                       */
  boolean_T HILWritePWM_Active;        /* Computed Parameter: HILWritePWM_Active
                                        * Referenced by: '<S19>/HIL Write PWM'
                                        */
  boolean_T Constant_Value_c;          /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S64>/Constant'
                                        */
  boolean_T Constant_Value_oc;         /* Computed Parameter: Constant_Value_oc
                                        * Referenced by: '<S65>/Constant'
                                        */
  boolean_T Constant_Value_a;          /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S66>/Constant'
                                        */
  boolean_T HILInitialize_Active;    /* Computed Parameter: HILInitialize_Active
                                      * Referenced by: '<S2>/HIL Initialize'
                                      */
  boolean_T HILInitialize_AOTerminate;
                                /* Computed Parameter: HILInitialize_AOTerminate
                                 * Referenced by: '<S2>/HIL Initialize'
                                 */
  boolean_T HILInitialize_AOExit;    /* Computed Parameter: HILInitialize_AOExit
                                      * Referenced by: '<S2>/HIL Initialize'
                                      */
  boolean_T HILInitialize_DOTerminate;
                                /* Computed Parameter: HILInitialize_DOTerminate
                                 * Referenced by: '<S2>/HIL Initialize'
                                 */
  boolean_T HILInitialize_DOExit;    /* Computed Parameter: HILInitialize_DOExit
                                      * Referenced by: '<S2>/HIL Initialize'
                                      */
  boolean_T HILInitialize_POTerminate;
                                /* Computed Parameter: HILInitialize_POTerminate
                                 * Referenced by: '<S2>/HIL Initialize'
                                 */
  boolean_T HILInitialize_POExit;    /* Computed Parameter: HILInitialize_POExit
                                      * Referenced by: '<S2>/HIL Initialize'
                                      */
  boolean_T HILInitialize_CKPStart;/* Computed Parameter: HILInitialize_CKPStart
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKPEnter;/* Computed Parameter: HILInitialize_CKPEnter
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKStart;  /* Computed Parameter: HILInitialize_CKStart
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_CKEnter;  /* Computed Parameter: HILInitialize_CKEnter
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AIPStart;/* Computed Parameter: HILInitialize_AIPStart
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AIPEnter;/* Computed Parameter: HILInitialize_AIPEnter
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOPStart;/* Computed Parameter: HILInitialize_AOPStart
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOPEnter;/* Computed Parameter: HILInitialize_AOPEnter
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOStart;  /* Computed Parameter: HILInitialize_AOStart
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AOEnter;  /* Computed Parameter: HILInitialize_AOEnter
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AOReset;  /* Computed Parameter: HILInitialize_AOReset
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOPStart;/* Computed Parameter: HILInitialize_DOPStart
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOPEnter;/* Computed Parameter: HILInitialize_DOPEnter
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOStart;  /* Computed Parameter: HILInitialize_DOStart
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOEnter;  /* Computed Parameter: HILInitialize_DOEnter
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOReset;  /* Computed Parameter: HILInitialize_DOReset
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_EIPStart;/* Computed Parameter: HILInitialize_EIPStart
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  boolean_T HILInitialize_EIPEnter;/* Computed Parameter: HILInitialize_EIPEnter
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  boolean_T HILInitialize_EIStart;  /* Computed Parameter: HILInitialize_EIStart
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_EIEnter;  /* Computed Parameter: HILInitialize_EIEnter
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POPStart;/* Computed Parameter: HILInitialize_POPStart
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POPEnter;/* Computed Parameter: HILInitialize_POPEnter
                                    * Referenced by: '<S2>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POStart;  /* Computed Parameter: HILInitialize_POStart
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POEnter;  /* Computed Parameter: HILInitialize_POEnter
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POReset;  /* Computed Parameter: HILInitialize_POReset
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_OOReset;  /* Computed Parameter: HILInitialize_OOReset
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOFinal;  /* Computed Parameter: HILInitialize_DOFinal
                                     * Referenced by: '<S2>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOInitial;
                                  /* Computed Parameter: HILInitialize_DOInitial
                                   * Referenced by: '<S2>/HIL Initialize'
                                   */
  boolean_T HILRead_Active;            /* Computed Parameter: HILRead_Active
                                        * Referenced by: '<S2>/HIL Read'
                                        */
  boolean_T StreamClient_Active;      /* Computed Parameter: StreamClient_Active
                                       * Referenced by: '<S1>/Stream Client'
                                       */
  boolean_T Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<S2>/Memory1'
                                  */
  boolean_T HILWriteDigital_Active;/* Computed Parameter: HILWriteDigital_Active
                                    * Referenced by: '<S2>/HIL Write Digital'
                                    */
  boolean_T HILWatchdog_Active;        /* Computed Parameter: HILWatchdog_Active
                                        * Referenced by: '<S56>/HIL Watchdog'
                                        */
  boolean_T Memory3_InitialCondition;
                                 /* Computed Parameter: Memory3_InitialCondition
                                  * Referenced by: '<S2>/Memory3'
                                  */
  boolean_T StreamServer_Active;      /* Computed Parameter: StreamServer_Active
                                       * Referenced by: '<S2>/Stream Server'
                                       */
  boolean_T RangingSensor_Active;    /* Computed Parameter: RangingSensor_Active
                                      * Referenced by: '<S2>/Ranging Sensor'
                                      */
  int8_T StreamClient_Optimize;     /* Computed Parameter: StreamClient_Optimize
                                     * Referenced by: '<S1>/Stream Client'
                                     */
  int8_T StreamClient_Implementation;
                              /* Computed Parameter: StreamClient_Implementation
                               * Referenced by: '<S1>/Stream Client'
                               */
  int8_T StreamServer_Optimize;     /* Computed Parameter: StreamServer_Optimize
                                     * Referenced by: '<S2>/Stream Server'
                                     */
  int8_T StreamServer_Implementation;
                              /* Computed Parameter: StreamServer_Implementation
                               * Referenced by: '<S2>/Stream Server'
                               */
  uint8_T StreamClient_URI;            /* Expression: uri_argument
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  uint8_T StreamClient_Endian;        /* Computed Parameter: StreamClient_Endian
                                       * Referenced by: '<S1>/Stream Client'
                                       */
  uint8_T ManualSwitchSelectCommandInput_;
                          /* Computed Parameter: ManualSwitchSelectCommandInput_
                           * Referenced by: '<S2>/Manual Switch -   Select Command Input'
                           */
  uint8_T ToHostFile_VarName[9];       /* Expression: variable_name_argument
                                        * Referenced by: '<S2>/To Host File'
                                        */
  uint8_T ToHostFile_FileFormat;    /* Computed Parameter: ToHostFile_FileFormat
                                     * Referenced by: '<S2>/To Host File'
                                     */
  uint8_T ToHostFile_file_name[71];    /* Expression: file_name_argument
                                        * Referenced by: '<S2>/To Host File'
                                        */
  uint8_T ToHostFile_VarName_m[16];    /* Expression: variable_name_argument
                                        * Referenced by: '<S4>/To Host File'
                                        */
  uint8_T ToHostFile_FileFormat_j;/* Computed Parameter: ToHostFile_FileFormat_j
                                   * Referenced by: '<S4>/To Host File'
                                   */
  uint8_T ToHostFile_file_name_p[78];  /* Expression: file_name_argument
                                        * Referenced by: '<S4>/To Host File'
                                        */
  uint8_T StreamServer_URI[36];        /* Expression: uri_argument
                                        * Referenced by: '<S2>/Stream Server'
                                        */
  uint8_T StreamServer_Endian;        /* Computed Parameter: StreamServer_Endian
                                       * Referenced by: '<S2>/Stream Server'
                                       */
  P_CoreSubsys_QD2_DroneStac_gm_T CoreSubsys_p;/* '<S16>/For Each Subsystem' */
  P_CoreSubsys_QD2_DroneStack_M_T CoreSubsys;
                    /* '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_QD2_DroneStack_Manual_T {
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
  real_T odeY[34];
  real_T odeF[2][34];
  ODE2_IntgData intgData;
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
extern P_QD2_DroneStack_Manual_2021a_T QD2_DroneStack_Manual_2021a_P;

/* Block signals (default storage) */
extern B_QD2_DroneStack_Manual_2021a_T QD2_DroneStack_Manual_2021a_B;

/* Continuous states (default storage) */
extern X_QD2_DroneStack_Manual_2021a_T QD2_DroneStack_Manual_2021a_X;

/* Disabled states (default storage) */
extern XDis_QD2_DroneStack_Manual_20_T QD2_DroneStack_Manual_2021_XDis;

/* Block states (default storage) */
extern DW_QD2_DroneStack_Manual_2021_T QD2_DroneStack_Manual_2021a_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_QD2_DroneStack_Manual_T QD2_DroneStack_Manual_2_PrevZCX;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Model entry point functions */
extern void QD2_DroneStack_Manual_2021a_initialize(void);
extern void QD2_DroneStack_Manual_2021a_output0(void);
extern void QD2_DroneStack_Manual_2021a_update0(void);
extern void QD2_DroneStack_Manual_2021a_output2(void);
extern void QD2_DroneStack_Manual_2021a_update2(void);
extern void QD2_DroneStack_Manual_2021a_output3(void);
extern void QD2_DroneStack_Manual_2021a_update3(void);
extern void QD2_DroneStack_Manual_2021a_output4(void);
extern void QD2_DroneStack_Manual_2021a_update4(void);
extern void QD2_DroneStack_Manual_2021a_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern QD2_DroneStack_Manual_2021a_rtModel *QD2_DroneStack_Manual_2021a(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_QD2_DroneStack_Manua_T *const QD2_DroneStack_Manual_2021a_M;

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
 * '<Root>' : 'QD2_DroneStack_Manual_2021a'
 * '<S1>'   : 'QD2_DroneStack_Manual_2021a/Communication'
 * '<S2>'   : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ'
 * '<S3>'   : 'QD2_DroneStack_Manual_2021a/Quanser'
 * '<S4>'   : 'QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2'
 * '<S5>'   : 'QD2_DroneStack_Manual_2021a/Communication/Detect Communication loss'
 * '<S6>'   : 'QD2_DroneStack_Manual_2021a/Communication/Detect Communication loss/MATLAB Function'
 * '<S7>'   : 'QD2_DroneStack_Manual_2021a/Communication/Detect Communication loss/Threshold'
 * '<S8>'   : 'QD2_DroneStack_Manual_2021a/Communication/Detect Communication loss/Threshold1'
 * '<S9>'   : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Attitude Estimate from IMU Data'
 * '<S10>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Choose Motor Telemetry'
 * '<S11>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Compare To Constant'
 * '<S12>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Compare To Constant1'
 * '<S13>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Construct ESC Speed'
 * '<S14>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Construct ESC Temperature'
 * '<S15>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Construct ESC Voltage'
 * '<S16>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Detect ESC Problems'
 * '<S17>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Discrete Second-Order Low-Pass Filter'
 * '<S18>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Discrete Second-Order Low-Pass Filter1'
 * '<S19>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Enabled Subsystem -  Write ESC Commands'
 * '<S20>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Force to percentage Mapping'
 * '<S21>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Generate LED Pattern'
 * '<S22>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/MATLAB Function'
 * '<S23>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Monitor Battery Level'
 * '<S24>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Radians to Degrees'
 * '<S25>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring'
 * '<S26>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Threshold'
 * '<S27>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Timing Monitors'
 * '<S28>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Attitude Estimate from IMU Data/For Each Subsystem - Iterate over IMU0 and IMU1'
 * '<S29>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Attitude Estimate from IMU Data/For Each Subsystem - Iterate over IMU0 and IMU1/Roll and Pitch Approximation from Accelerometer data'
 * '<S30>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Attitude Estimate from IMU Data/For Each Subsystem - Iterate over IMU0 and IMU1/Second-Order Low-Pass Filter'
 * '<S31>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Attitude Estimate from IMU Data/For Each Subsystem - Iterate over IMU0 and IMU1/Second-Order Low-Pass Filter1'
 * '<S32>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Choose Motor Telemetry/MATLAB Function'
 * '<S33>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Construct ESC Speed/For Each Subsystem -  Construct ESC Signal'
 * '<S34>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Construct ESC Temperature/For Each Subsystem -  Construct ESC Signal'
 * '<S35>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Construct ESC Voltage/For Each Subsystem -  Construct ESC Signal'
 * '<S36>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Detect ESC Problems/Compare To Constant'
 * '<S37>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Detect ESC Problems/For Each Subsystem'
 * '<S38>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Detect ESC Problems/MATLAB Function'
 * '<S39>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Detect ESC Problems/For Each Subsystem/Compare To Constant'
 * '<S40>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Monitor Battery Level/Greater than minimum expected voltage (Valid Battery Reading)'
 * '<S41>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Monitor Battery Level/Less than minimum threshold voltage (Battery level too low)'
 * '<S42>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Monitor Battery Level/Threshold'
 * '<S43>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Monitor Battery Level/Triggered Subsystem - Latching Flag'
 * '<S44>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold'
 * '<S45>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold1'
 * '<S46>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold10'
 * '<S47>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold11'
 * '<S48>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold2'
 * '<S49>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold3'
 * '<S50>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold4'
 * '<S51>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold5'
 * '<S52>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold6'
 * '<S53>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold7'
 * '<S54>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold8'
 * '<S55>'  : 'QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Sensor Failure Monitoring/Threshold9'
 * '<S56>'  : 'QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY'
 * '<S57>'  : 'QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/Radians to Degrees'
 * '<S58>'  : 'QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/Radians to Degrees1'
 * '<S59>'  : 'QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Communication'
 * '<S60>'  : 'QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop model'
 * '<S61>'  : 'QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop with Message'
 * '<S62>'  : 'QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop with Message1'
 * '<S63>'  : 'QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop with Message3'
 * '<S64>'  : 'QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop with Message/Compare'
 * '<S65>'  : 'QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop with Message1/Compare'
 * '<S66>'  : 'QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Stop with Message3/Compare'
 */
#endif                                 /* QD2_DroneStack_Manual_2021a_h_ */
