/*
 * QD2_MissionCtrl_Manual_2021a.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QD2_MissionCtrl_Manual_2021a".
 *
 * Model version              : 2.0
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Fri Aug 14 17:12:13 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef QD2_MissionCtrl_Manual_2021a_h_
#define QD2_MissionCtrl_Manual_2021a_h_
#ifndef QD2_MissionCtrl_Manual_2021a_COMMON_INCLUDES_
#define QD2_MissionCtrl_Manual_2021a_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "quanser_messages.h"
#include "quanser_string.h"
#include "quanser_host.h"
#include "extmode_support.h"
#include "quanser_host_game_controller.h"
#include "quanser_memory.h"
#include "quanser_section.h"
#include "quanser_start_time.h"
#include "quanser_extern.h"
#include "stream_server_block.h"
#endif                       /* QD2_MissionCtrl_Manual_2021a_COMMON_INCLUDES_ */

#include "QD2_MissionCtrl_Manual_2021a_types.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include <string.h>
#include "rt_nonfinite.h"
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
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ()
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ()
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
#define rtmGetOdeF(rtm)                ()
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ()
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
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
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
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
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
#define rtmIsContinuousTask(rtm, tid)  0
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
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
#define QD2_MissionCtrl_Manual_2021a_rtModel RT_MODEL_QD2_MissionCtrl_Manu_T

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion;           /* '<S14>/Data Type Conversion' */
  real_T ManualSwitch1[9];             /* '<S2>/Manual Switch1' */
  real_T MaxThrustis2044N;             /* '<S9>/Max Thrust is 20.44 N' */
  real_T u0915NmforRoll08984NmforPitch00[3];
  /* '<S9>/+//- 1.0915 Nm for Roll +//- 0.8984 Nm for Pitch +//- 0.0984 Nm for Yaw' */
  real_T pi4radforRollPitchpi2radsforYaw[3];
      /* '<S9>/+//- pi//4 rad for Roll//Pitch +//- pi//2 rad//s for Yaw Rate' */
  real_T StreamServer_o4[2];           /* '<S1>/Stream Server' */
  real_T DataTypeConversion_e;         /* '<S5>/Data Type Conversion' */
  real_T Product;                      /* '<S2>/Product' */
  real_T Subtract[2];                  /* '<S2>/Subtract' */
  real_T TmpSignalConversionAtToHostFile[14];
  real_T FixPtSum1;                    /* '<S18>/FixPt Sum1' */
  real_T DataTypeConversion2;          /* '<S12>/Data Type Conversion2' */
  real_T DataTypeConversion4;          /* '<S12>/Data Type Conversion4' */
  real_T OutportBufferForJoystickIssue01;/* '<S12>/Data Type Conversion4' */
  real_T Product_b[3];                 /* '<S12>/Product' */
  real_T Product1;                     /* '<S12>/Product1' */
  real_T Product2;                     /* '<S12>/Product2' */
  real_T Product3;                     /* '<S12>/Product3' */
  real_T DataTypeConversion_k;         /* '<S16>/Data Type Conversion' */
  real_T DiscreteTimeIntegrator;       /* '<S16>/Discrete-Time Integrator' */
  real_T Gain;                         /* '<S11>/Gain' */
  real_T Bias;                         /* '<S11>/Bias' */
  real_T y;                            /* '<S11>/y' */
  real_T z;                            /* '<S11>/z' */
  real_T DataTypeConversion_o;         /* '<S7>/Data Type Conversion' */
  int32_T HostInitialize_o2;           /* '<S8>/Host Initialize' */
  uint8_T HostInitialize_o1;           /* '<S8>/Host Initialize' */
  uint8_T ModelArgument[80];           /* '<S1>/Model Argument' */
  boolean_T HostGameController_o1;     /* '<S8>/Host Game Controller' */
  boolean_T LogicalOperator;           /* '<S14>/Logical Operator' */
  boolean_T LogicalOperator_k;         /* '<S7>/Logical Operator' */
  boolean_T Compare;                   /* '<S19>/Compare' */
  boolean_T Compare_n;                 /* '<S13>/Compare' */
  boolean_T Buttons[32];               /* '<S11>/Buttons' */
  boolean_T LogicalOperator_n;         /* '<S16>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S16>/Relational Operator' */
  boolean_T Compare_h;                 /* '<S15>/Compare' */
} B_QD2_MissionCtrl_Manual_2021_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  t_game_controller_states HostGameController_ControllerSt;/* '<S8>/Host Game Controller' */
  qthread_section_t HostGameController_Lock;/* '<S8>/Host Game Controller' */
  t_timeout Time_Timeout;              /* '<S5>/Time' */
  t_timeout Time_Timeout_p;            /* '<S2>/Time' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S14>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S7>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S17>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S16>/Discrete-Time Integrator' */
  real_T Memory_PreviousInput;         /* '<S10>/Memory' */
  t_pstream StreamServer_Stream;       /* '<S1>/Stream Server' */
  t_extmode_svr_connected_handle HostInitialize_ConnectedHandle;/* '<S8>/Host Initialize' */
  t_uint64 ToHostFile_PointsWritten;   /* '<S2>/To Host File' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S2>/Scope' */

  void *ToHostFile_PWORK[2];           /* '<S2>/To Host File' */
  int32_T sfEvent;                     /* '<S5>/MATLAB Function' */
  uint32_T ToHostFile_SamplesCount;    /* '<S2>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength; /* '<S2>/To Host File' */
  int_T StringDisplay_IWORK[2];        /* '<S1>/String Display ' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S14>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_b;/* '<S7>/Discrete-Time Integrator' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S2>/Triggered Subsystem' */
  int8_T pulsecount_SubsysRanBC;       /* '<S13>/pulse count ' */
  int8_T InitializationandConditioning_S;
                                    /* '<S8>/Initialization and Conditioning' */
  int8_T FrSKYMapping_SubsysRanBC;     /* '<S8>/FrSKYMapping' */
  int8_T DiscreteTimeIntegrator_PrevR_bf;/* '<S16>/Discrete-Time Integrator' */
  boolean_T HostGameController_NewData;/* '<S8>/Host Game Controller' */
  boolean_T Time_Owner;                /* '<S5>/Time' */
  boolean_T Time_Owner_o;              /* '<S2>/Time' */
  boolean_T StreamServer_Listening;    /* '<S1>/Stream Server' */
  boolean_T doneDoubleBufferReInit;    /* '<S5>/MATLAB Function' */
  boolean_T FrSKYMapping_MODE;         /* '<S8>/FrSKYMapping' */
} DW_QD2_MissionCtrl_Manual_202_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S2>/Triggered Subsystem' */
  ZCSigState pulsecount_Trig_ZCE;      /* '<S13>/pulse count ' */
} PrevZCX_QD2_MissionCtrl_Manua_T;

/* Backward compatible GRT Identifiers */
#define rtB                            QD2_MissionCtrl_Manual_2021a_B
#define BlockIO                        B_QD2_MissionCtrl_Manual_2021_T
#define rtP                            QD2_MissionCtrl_Manual_2021a_P
#define Parameters                     P_QD2_MissionCtrl_Manual_2021_T
#define rtDWork                        QD2_MissionCtrl_Manual_2021a_DW
#define D_Work                         DW_QD2_MissionCtrl_Manual_202_T
#define rtPrevZCSigState               QD2_MissionCtrl_Manual__PrevZCX
#define PrevZCSigStates                PrevZCX_QD2_MissionCtrl_Manua_T

/* Parameters (default storage) */
struct P_QD2_MissionCtrl_Manual_2021_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S15>/Constant'
                                       */
  real_T CompareToConstant_const_f; /* Mask Parameter: CompareToConstant_const_f
                                     * Referenced by: '<S19>/Constant'
                                     */
  real_T StreamServer_default_value[2];
                                   /* Mask Parameter: StreamServer_default_value
                                    * Referenced by: '<S1>/Stream Server'
                                    */
  real_T Threshold_duration;           /* Mask Parameter: Threshold_duration
                                        * Referenced by: '<S16>/duration'
                                        */
  real_T Threshold_duration_d;         /* Mask Parameter: Threshold_duration_d
                                        * Referenced by: '<S14>/duration'
                                        */
  real_T Threshold_duration_b;         /* Mask Parameter: Threshold_duration_b
                                        * Referenced by: '<S7>/duration'
                                        */
  real_T Threshold_threshold;          /* Mask Parameter: Threshold_threshold
                                        * Referenced by: '<S16>/threshold'
                                        */
  real_T Threshold_threshold_h;        /* Mask Parameter: Threshold_threshold_h
                                        * Referenced by: '<S14>/threshold'
                                        */
  real_T Threshold_threshold_d;        /* Mask Parameter: Threshold_threshold_d
                                        * Referenced by: '<S7>/threshold'
                                        */
  uint8_T StringDisplay_alignment;    /* Mask Parameter: StringDisplay_alignment
                                       * Referenced by: '<S1>/String Display '
                                       */
  uint8_T StringDisplay_display_mode;
                                   /* Mask Parameter: StringDisplay_display_mode
                                    * Referenced by: '<S1>/String Display '
                                    */
  real_T Yaw_Y0;                       /* Computed Parameter: Yaw_Y0
                                        * Referenced by: '<S11>/Yaw (%)'
                                        */
  real_T Throttle_Y0;                  /* Computed Parameter: Throttle_Y0
                                        * Referenced by: '<S11>/Throttle (%)'
                                        */
  real_T Roll_Y0;                      /* Computed Parameter: Roll_Y0
                                        * Referenced by: '<S11>/Roll (%)'
                                        */
  real_T Pitch_Y0;                     /* Computed Parameter: Pitch_Y0
                                        * Referenced by: '<S11>/Pitch (%)'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S16>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S16>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Bias_Bias;                    /* Expression: 0.5
                                        * Referenced by: '<S11>/Bias'
                                        */
  real_T JoystickIssue01_Y0;           /* Expression: 0
                                        * Referenced by: '<S12>/Joystick Issue (0,1)'
                                        */
  real_T Triggers014_Y0;               /* Expression: 0
                                        * Referenced by: '<S12>/Triggers (0,1) [4]'
                                        */
  real_T Commands4_Y0;                 /* Expression: 0
                                        * Referenced by: '<S12>/Commands (%) [4]'
                                        */
  real_T DeadZone_Start;               /* Expression: -0.01
                                        * Referenced by: '<S12>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 0.01
                                        * Referenced by: '<S12>/Dead Zone'
                                        */
  real_T NumberofPulses_Y0;            /* Computed Parameter: NumberofPulses_Y0
                                        * Referenced by: '<S17>/Number of Pulses'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T FixPtConstant_Value;          /* Expression: 1
                                        * Referenced by: '<S18>/FixPt Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S17>/Unit Delay'
                                        */
  real_T PulseCheck_Value;             /* Expression: 1
                                        * Referenced by: '<S13>/Pulse Check'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S10>/Memory'
                                        */
  real_T Constant_Value_m[6];          /* Expression: -1*ones(1,6)
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                           * Referenced by: '<S14>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: 0
                                        * Referenced by: '<S14>/Discrete-Time Integrator'
                                        */
  real_T ManualFlightMode1TorqueMode0Ang;/* Expression: 1
                                          * Referenced by: '<S2>/Manual Flight Mode 1 - Torque Mode,   0 - Angle Mode'
                                          */
  real_T MaxThrustis2044N_Gain;        /* Expression: 20.44
                                        * Referenced by: '<S9>/Max Thrust is 20.44 N'
                                        */
  real_T u0915NmforRoll08984NmforPitch00[3];/* Expression: [1.0915 0.8984 0.0984]
                                             * Referenced by: '<S9>/+//- 1.0915 Nm for Roll +//- 0.8984 Nm for Pitch +//- 0.0984 Nm for Yaw'
                                             */
  real_T pi4radforRollPitchpi2radsforYaw[3];/* Expression: [pi/4 pi/4 pi/2]
                                             * Referenced by: '<S9>/+//- pi//4 rad for Roll//Pitch +//- pi//2 rad//s for Yaw Rate'
                                             */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_n;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                           * Referenced by: '<S7>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  int32_T HostInitialize_SendBufferSize;
                            /* Computed Parameter: HostInitialize_SendBufferSize
                             * Referenced by: '<S8>/Host Initialize'
                             */
  int32_T HostInitialize_ReceiveBufferSiz;
                          /* Computed Parameter: HostInitialize_ReceiveBufferSiz
                           * Referenced by: '<S8>/Host Initialize'
                           */
  int32_T HostInitialize_ThreadPriority;
                            /* Computed Parameter: HostInitialize_ThreadPriority
                             * Referenced by: '<S8>/Host Initialize'
                             */
  int32_T HostGameController_BufferSize;
                            /* Computed Parameter: HostGameController_BufferSize
                             * Referenced by: '<S8>/Host Game Controller'
                             */
  int32_T StreamServer_SndPriority;
                                 /* Computed Parameter: StreamServer_SndPriority
                                  * Referenced by: '<S1>/Stream Server'
                                  */
  int32_T StreamServer_RcvPriority;
                                 /* Computed Parameter: StreamServer_RcvPriority
                                  * Referenced by: '<S1>/Stream Server'
                                  */
  int32_T ToHostFile_Encoding;        /* Computed Parameter: ToHostFile_Encoding
                                       * Referenced by: '<S2>/To Host File'
                                       */
  uint32_T StreamServer_SndSize;     /* Computed Parameter: StreamServer_SndSize
                                      * Referenced by: '<S1>/Stream Server'
                                      */
  uint32_T StreamServer_RcvSize;     /* Computed Parameter: StreamServer_RcvSize
                                      * Referenced by: '<S1>/Stream Server'
                                      */
  uint32_T StreamServer_SndFIFO;     /* Computed Parameter: StreamServer_SndFIFO
                                      * Referenced by: '<S1>/Stream Server'
                                      */
  uint32_T StreamServer_RcvFIFO;     /* Computed Parameter: StreamServer_RcvFIFO
                                      * Referenced by: '<S1>/Stream Server'
                                      */
  uint32_T ToHostFile_Decimation;   /* Computed Parameter: ToHostFile_Decimation
                                     * Referenced by: '<S2>/To Host File'
                                     */
  uint32_T ToHostFile_BitRate;         /* Computed Parameter: ToHostFile_BitRate
                                        * Referenced by: '<S2>/To Host File'
                                        */
  boolean_T EmergencyAbortbool_Y0;  /* Computed Parameter: EmergencyAbortbool_Y0
                                     * Referenced by: '<S11>/Emergency Abort (bool)'
                                     */
  boolean_T ArmDisarmbool_Y0;          /* Computed Parameter: ArmDisarmbool_Y0
                                        * Referenced by: '<S11>/Arm//Disarm (bool) '
                                        */
  boolean_T TakeoffAutolandbool_Y0;/* Computed Parameter: TakeoffAutolandbool_Y0
                                    * Referenced by: '<S11>/Takeoff//Autoland (bool)'
                                    */
  boolean_T CommunicationIssue01_Y0;
                                  /* Computed Parameter: CommunicationIssue01_Y0
                                   * Referenced by: '<S10>/Communication Issue (0,1)'
                                   */
  boolean_T HostInitialize_RunClient;
                                 /* Computed Parameter: HostInitialize_RunClient
                                  * Referenced by: '<S8>/Host Initialize'
                                  */
  boolean_T HostInitialize_UseWindow;
                                 /* Computed Parameter: HostInitialize_UseWindow
                                  * Referenced by: '<S8>/Host Initialize'
                                  */
  boolean_T HostInitialize_Active;  /* Computed Parameter: HostInitialize_Active
                                     * Referenced by: '<S8>/Host Initialize'
                                     */
  boolean_T HostGameController_AutoCenter;
                            /* Computed Parameter: HostGameController_AutoCenter
                             * Referenced by: '<S8>/Host Game Controller'
                             */
  boolean_T HostGameController_Enabled;
                               /* Computed Parameter: HostGameController_Enabled
                                * Referenced by: '<S8>/Host Game Controller'
                                */
  boolean_T HostGameController_DebugMode;
                             /* Computed Parameter: HostGameController_DebugMode
                              * Referenced by: '<S8>/Host Game Controller'
                              */
  boolean_T StreamServer_Active;      /* Computed Parameter: StreamServer_Active
                                       * Referenced by: '<S1>/Stream Server'
                                       */
  int8_T HostGameController_Controller;
                            /* Computed Parameter: HostGameController_Controller
                             * Referenced by: '<S8>/Host Game Controller'
                             */
  int8_T StreamServer_Optimize;     /* Computed Parameter: StreamServer_Optimize
                                     * Referenced by: '<S1>/Stream Server'
                                     */
  int8_T StreamServer_Implementation;
                              /* Computed Parameter: StreamServer_Implementation
                               * Referenced by: '<S1>/Stream Server'
                               */
  int8_T ShowMessageonHost_MsgIcon;
                                /* Computed Parameter: ShowMessageonHost_MsgIcon
                                 * Referenced by: '<S2>/Show Message on Host'
                                 */
  int8_T ShowMessageonHost_MsgIcon_p;
                              /* Computed Parameter: ShowMessageonHost_MsgIcon_p
                               * Referenced by: '<S2>/Show Message on Host '
                               */
  uint8_T HostInitialize_URI;          /* Expression: uri_argument
                                        * Referenced by: '<S8>/Host Initialize'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S2>/Manual Switch1'
                              */
  uint8_T StreamServer_URI;            /* Expression: uri_argument
                                        * Referenced by: '<S1>/Stream Server'
                                        */
  uint8_T StreamServer_Endian;        /* Computed Parameter: StreamServer_Endian
                                       * Referenced by: '<S1>/Stream Server'
                                       */
  uint8_T ToHostFile_VarName[20];      /* Expression: variable_name_argument
                                        * Referenced by: '<S2>/To Host File'
                                        */
  uint8_T ToHostFile_FileFormat;    /* Computed Parameter: ToHostFile_FileFormat
                                     * Referenced by: '<S2>/To Host File'
                                     */
  uint8_T ToHostFile_file_name[80];    /* Expression: file_name_argument
                                        * Referenced by: '<S2>/To Host File'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_QD2_MissionCtrl_Manua_T {
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
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (default storage) */
extern P_QD2_MissionCtrl_Manual_2021_T QD2_MissionCtrl_Manual_2021a_P;

/* Block signals (default storage) */
extern B_QD2_MissionCtrl_Manual_2021_T QD2_MissionCtrl_Manual_2021a_B;

/* Block states (default storage) */
extern DW_QD2_MissionCtrl_Manual_202_T QD2_MissionCtrl_Manual_2021a_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_QD2_MissionCtrl_Manua_T QD2_MissionCtrl_Manual__PrevZCX;

/* Model entry point functions */
extern void QD2_MissionCtrl_Manual_2021a_initialize(void);
extern void QD2_MissionCtrl_Manual_2021a_output(void);
extern void QD2_MissionCtrl_Manual_2021a_update(void);
extern void QD2_MissionCtrl_Manual_2021a_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern QD2_MissionCtrl_Manual_2021a_rtModel *QD2_MissionCtrl_Manual_2021a(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_QD2_MissionCtrl_Manu_T *const QD2_MissionCtrl_Manual_2021a_M;

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
 * '<Root>' : 'QD2_MissionCtrl_Manual_2021a'
 * '<S1>'   : 'QD2_MissionCtrl_Manual_2021a/Communication'
 * '<S2>'   : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT'
 * '<S3>'   : 'QD2_MissionCtrl_Manual_2021a/Powered by QUARC'
 * '<S4>'   : 'QD2_MissionCtrl_Manual_2021a/Quanser'
 * '<S5>'   : 'QD2_MissionCtrl_Manual_2021a/Communication/Detect Communication loss'
 * '<S6>'   : 'QD2_MissionCtrl_Manual_2021a/Communication/Detect Communication loss/MATLAB Function'
 * '<S7>'   : 'QD2_MissionCtrl_Manual_2021a/Communication/Detect Communication loss/Threshold'
 * '<S8>'   : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY'
 * '<S9>'   : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/Raw joystick to Throttle and Angular Commands'
 * '<S10>'  : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/Triggered Subsystem'
 * '<S11>'  : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/FrSKYMapping'
 * '<S12>'  : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Initialization and Conditioning'
 * '<S13>'  : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Pulse Check'
 * '<S14>'  : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Threshold'
 * '<S15>'  : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/FrSKYMapping/Compare To Constant'
 * '<S16>'  : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/FrSKYMapping/Threshold'
 * '<S17>'  : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Pulse Check/pulse count '
 * '<S18>'  : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Pulse Check/pulse count /Increment Stored Integer'
 * '<S19>'  : 'QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/Triggered Subsystem/Compare To Constant'
 */
#endif                                 /* QD2_MissionCtrl_Manual_2021a_h_ */
