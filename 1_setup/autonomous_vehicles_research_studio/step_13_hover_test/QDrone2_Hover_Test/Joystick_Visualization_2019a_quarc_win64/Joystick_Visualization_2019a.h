/*
 * Joystick_Visualization_2019a.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Joystick_Visualization_2019a".
 *
 * Model version              : 3.0
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Tue Aug  4 15:02:52 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Joystick_Visualization_2019a_h_
#define Joystick_Visualization_2019a_h_
#ifndef Joystick_Visualization_2019a_COMMON_INCLUDES_
#define Joystick_Visualization_2019a_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "quanser_visualization.h"
#include "quanser_messages.h"
#include "quanser_sigmoid.h"
#include "quanser_host_game_controller.h"
#include "quanser_memory.h"
#include "quanser_section.h"
#include "quanser_string.h"
#include "quanser_host.h"
#include "extmode_support.h"
#include "quanser_extern.h"
#endif                       /* Joystick_Visualization_2019a_COMMON_INCLUDES_ */

#include "Joystick_Visualization_2019a_types.h"
#include "rt_zcfcn.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
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
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
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
#define Joystick_Visualization_2019a_rtModel RT_MODEL_Joystick_Visualizati_T

/* Block signals for system '<S22>/Use des height  when enabled' */
typedef struct {
  real_T h_dm1;                        /* '<S28>/h_d (m) [1]' */
} B_Usedesheightwhenenabled_Joy_T;

/* Block states (default storage) for system '<S22>/Use des height  when enabled' */
typedef struct {
  int8_T Usedesheightwhenenabled_SubsysR;
                                      /* '<S22>/Use des height  when enabled' */
  boolean_T Usedesheightwhenenabled_MODE;
                                      /* '<S22>/Use des height  when enabled' */
} DW_Usedesheightwhenenabled_Jo_T;

/* Block signals (default storage) */
typedef struct {
  real_T ContinuousSigmoid_o1;         /* '<S22>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_o2;         /* '<S22>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_o3;         /* '<S22>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_o4;         /* '<S22>/Continuous Sigmoid' */
  real_T ContinuousSigmoid1_o1;        /* '<S22>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_o2;        /* '<S22>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_o3;        /* '<S22>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_o4;        /* '<S22>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid2_o1;        /* '<S22>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_o2;        /* '<S22>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_o3;        /* '<S22>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_o4;        /* '<S22>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid3_o1;        /* '<S22>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_o2;        /* '<S22>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_o3;        /* '<S22>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_o4;        /* '<S22>/Continuous Sigmoid3' */
  real_T m;                            /* '<S1>/  m//%  ' */
  real_T m_h;                          /* '<S1>/ m//% ' */
  real_T m_m;                          /* '<S1>/m//%' */
  real_T ManualSwitch1[8];             /* '<Root>/Manual Switch1' */
  real_T MatrixConcatenate[16];        /* '<S20>/Matrix Concatenate' */
  real_T MatrixConcatenate_j[16];      /* '<S21>/Matrix Concatenate' */
  real_T Product1[3];                  /* '<S18>/Product1' */
  real_T MatrixConcatenate_i[16];      /* '<S18>/Matrix Concatenate' */
  real_T MatrixConcatenate_f[16];      /* '<S16>/Matrix Concatenate' */
  real_T MatrixConcatenate_o[16];      /* '<S17>/Matrix Concatenate' */
  real_T Switch[4];                    /* '<S14>/Switch' */
  real_T HiddenBuf_InsertedFor_Usedeshei;/* '<S22>/MATLAB Function2' */
  real_T HiddenBuf_InsertedFor_Usedesyaw;/* '<S22>/MATLAB Function4' */
  real_T Memory[4];                    /* '<S22>/Memory' */
  real_T HiddenBuf_InsertedFor_Usedesire;/* '<S22>/MATLAB Function' */
  real_T HiddenBuf_InsertedFor_Usedesi_i;/* '<S22>/MATLAB Function1' */
  real_T rads;                         /* '<S1>/ rad//s//%' */
  real_T DataTypeConversion;           /* '<S7>/Data Type Conversion' */
  real_T sigmoid_type;                 /* '<S22>/Signmoid Type' */
  real_T enable;                       /* '<S22>/MATLAB Function4' */
  real_T yaw_ref;                      /* '<S22>/MATLAB Function4' */
  real_T max_yaw_vel;                  /* '<S22>/MATLAB Function4' */
  real_T max_yaw_accel;                /* '<S22>/MATLAB Function4' */
  real_T enable_f;                     /* '<S22>/MATLAB Function2' */
  real_T height_ref;                   /* '<S22>/MATLAB Function2' */
  real_T max_height_vel;               /* '<S22>/MATLAB Function2' */
  real_T max_height_accel;             /* '<S22>/MATLAB Function2' */
  real_T enable_j;                     /* '<S22>/MATLAB Function1' */
  real_T y_ref;                        /* '<S22>/MATLAB Function1' */
  real_T max_y_vel;                    /* '<S22>/MATLAB Function1' */
  real_T max_y_accel;                  /* '<S22>/MATLAB Function1' */
  real_T enable_m;                     /* '<S22>/MATLAB Function' */
  real_T x_ref;                        /* '<S22>/MATLAB Function' */
  real_T max_x_vel;                    /* '<S22>/MATLAB Function' */
  real_T max_x_accel;                  /* '<S22>/MATLAB Function' */
  real_T FixPtSum1;                    /* '<S11>/FixPt Sum1' */
  real_T DataTypeConversion2;          /* '<S5>/Data Type Conversion2' */
  real_T DataTypeConversion4;          /* '<S5>/Data Type Conversion4' */
  real_T Product[3];                   /* '<S5>/Product' */
  real_T Product1_e;                   /* '<S5>/Product1' */
  real_T Product2;                     /* '<S5>/Product2' */
  real_T Product3;                     /* '<S5>/Product3' */
  real_T DataTypeConversion_j;         /* '<S9>/Data Type Conversion' */
  real_T DiscreteTimeIntegrator;       /* '<S9>/Discrete-Time Integrator' */
  real_T Gain;                         /* '<S4>/Gain' */
  real_T Bias;                         /* '<S4>/Bias' */
  real_T y;                            /* '<S4>/y' */
  real_T z;                            /* '<S4>/z' */
  int32_T HostInitialize_o2;           /* '<S1>/Host Initialize' */
  uint8_T HostInitialize_o1;           /* '<S1>/Host Initialize' */
  boolean_T HostGameController_o1;     /* '<S1>/Host Game Controller' */
  boolean_T LogicalOperator;           /* '<S7>/Logical Operator' */
  boolean_T Compare;                   /* '<S6>/Compare' */
  boolean_T Buttons[32];               /* '<S4>/Buttons' */
  boolean_T LogicalOperator_j;         /* '<S9>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S9>/Relational Operator' */
  boolean_T Compare_j;                 /* '<S8>/Compare' */
  B_Usedesheightwhenenabled_Joy_T UsedesiredYwhenenabled;/* '<S22>/Use desired Y  when enabled' */
  B_Usedesheightwhenenabled_Joy_T UsedesiredXwhenenabled;/* '<S22>/Use desired X  when enabled' */
  B_Usedesheightwhenenabled_Joy_T Usedesyawwhenenabled;/* '<S22>/Use des yaw  when enabled' */
  B_Usedesheightwhenenabled_Joy_T Usedesheightwhenenabled;
                                      /* '<S22>/Use des height  when enabled' */
} B_Joystick_Visualization_2019_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  t_game_controller_states HostGameController_ControllerSt;/* '<S1>/Host Game Controller' */
  qthread_section_t HostGameController_Lock;/* '<S1>/Host Game Controller' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S10>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S9>/Discrete-Time Integrator' */
  real_T ContinuousSigmoid_Sigmoid[11];/* '<S22>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_Time;       /* '<S22>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_Target;     /* '<S22>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_PPos;       /* '<S22>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_PVel;       /* '<S22>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_MVel;       /* '<S22>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_MAcc;       /* '<S22>/Continuous Sigmoid' */
  real_T ContinuousSigmoid1_Sigmoid[11];/* '<S22>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_Time;      /* '<S22>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_Target;    /* '<S22>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_PPos;      /* '<S22>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_PVel;      /* '<S22>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_MVel;      /* '<S22>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid1_MAcc;      /* '<S22>/Continuous Sigmoid1' */
  real_T ContinuousSigmoid2_Sigmoid[11];/* '<S22>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_Time;      /* '<S22>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_Target;    /* '<S22>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_PPos;      /* '<S22>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_PVel;      /* '<S22>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_MVel;      /* '<S22>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid2_MAcc;      /* '<S22>/Continuous Sigmoid2' */
  real_T ContinuousSigmoid3_Sigmoid[11];/* '<S22>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_Time;      /* '<S22>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_Target;    /* '<S22>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_PPos;      /* '<S22>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_PVel;      /* '<S22>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_MVel;      /* '<S22>/Continuous Sigmoid3' */
  real_T ContinuousSigmoid3_MAcc;      /* '<S22>/Continuous Sigmoid3' */
  real_T VisualizationSetVariables_PrevT;/* '<S3>/Visualization Set Variables' */
  real_T Memory_PreviousInput[4];      /* '<S22>/Memory' */
  t_extmode_svr_connected_handle HostInitialize_ConnectedHandle;/* '<S1>/Host Initialize' */
  t_visualization VisualizationInitialize_Visuali;/* '<S3>/Visualization Initialize' */
  void *VisualizationInitialize_PWORK[2];/* '<S3>/Visualization Initialize' */
  void *VisualizationSetVariables_PWORK;/* '<S3>/Visualization Set Variables' */
  int32_T sfEvent;                     /* '<S22>/Signmoid Type' */
  int32_T sfEvent_d;                   /* '<S22>/MATLAB Function4' */
  int32_T sfEvent_g;                   /* '<S22>/MATLAB Function2' */
  int32_T sfEvent_i;                   /* '<S22>/MATLAB Function1' */
  int32_T sfEvent_n;                   /* '<S22>/MATLAB Function' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S7>/Discrete-Time Integrator' */
  int8_T pulsecount_SubsysRanBC;       /* '<S6>/pulse count ' */
  int8_T InitializationandConditioning_S;
                                    /* '<S1>/Initialization and Conditioning' */
  int8_T FrSKYMapping_SubsysRanBC;     /* '<S1>/FrSKYMapping' */
  int8_T DiscreteTimeIntegrator_PrevRe_j;/* '<S9>/Discrete-Time Integrator' */
  uint8_T ContinuousSigmoid_Flag;      /* '<S22>/Continuous Sigmoid' */
  uint8_T ContinuousSigmoid1_Flag;     /* '<S22>/Continuous Sigmoid1' */
  uint8_T ContinuousSigmoid2_Flag;     /* '<S22>/Continuous Sigmoid2' */
  uint8_T ContinuousSigmoid3_Flag;     /* '<S22>/Continuous Sigmoid3' */
  boolean_T HostGameController_NewData;/* '<S1>/Host Game Controller' */
  boolean_T doneDoubleBufferReInit;    /* '<S22>/Signmoid Type' */
  boolean_T doneDoubleBufferReInit_p;  /* '<S22>/MATLAB Function4' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S22>/MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_l;  /* '<S22>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_f;  /* '<S22>/MATLAB Function' */
  boolean_T FrSKYMapping_MODE;         /* '<S1>/FrSKYMapping' */
  DW_Usedesheightwhenenabled_Jo_T UsedesiredYwhenenabled;/* '<S22>/Use desired Y  when enabled' */
  DW_Usedesheightwhenenabled_Jo_T UsedesiredXwhenenabled;/* '<S22>/Use desired X  when enabled' */
  DW_Usedesheightwhenenabled_Jo_T Usedesyawwhenenabled;/* '<S22>/Use des yaw  when enabled' */
  DW_Usedesheightwhenenabled_Jo_T Usedesheightwhenenabled;
                                      /* '<S22>/Use des height  when enabled' */
} DW_Joystick_Visualization_201_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
} X_Joystick_Visualization_2019_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
} XDot_Joystick_Visualization_2_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
} XDis_Joystick_Visualization_2_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S1>/Integrator' */
  ZCSigState pulsecount_Trig_ZCE;      /* '<S6>/pulse count ' */
} PrevZCX_Joystick_Visualizatio_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            Joystick_Visualization_2019a_B
#define BlockIO                        B_Joystick_Visualization_2019_T
#define rtX                            Joystick_Visualization_2019a_X
#define ContinuousStates               X_Joystick_Visualization_2019_T
#define rtXdot                         Joystick_Visualization_201_XDot
#define StateDerivatives               XDot_Joystick_Visualization_2_T
#define tXdis                          Joystick_Visualization_201_XDis
#define StateDisabled                  XDis_Joystick_Visualization_2_T
#define rtP                            Joystick_Visualization_2019a_P
#define Parameters                     P_Joystick_Visualization_2019_T
#define rtDWork                        Joystick_Visualization_2019a_DW
#define D_Work                         DW_Joystick_Visualization_201_T
#define rtPrevZCSigState               Joystick_Visualization__PrevZCX
#define PrevZCSigStates                PrevZCX_Joystick_Visualizatio_T

/* Parameters for system: '<S22>/Use des height  when enabled' */
struct P_Usedesheightwhenenabled_Joy_T_ {
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S28>/Out1'
                                        */
};

/* Parameters (default storage) */
struct P_Joystick_Visualization_2019_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S8>/Constant'
                                       */
  real_T Threshold_duration;           /* Mask Parameter: Threshold_duration
                                        * Referenced by: '<S9>/duration'
                                        */
  real_T Threshold_duration_h;         /* Mask Parameter: Threshold_duration_h
                                        * Referenced by: '<S7>/duration'
                                        */
  real_T Threshold_threshold;          /* Mask Parameter: Threshold_threshold
                                        * Referenced by: '<S9>/threshold'
                                        */
  real_T Threshold_threshold_d;        /* Mask Parameter: Threshold_threshold_d
                                        * Referenced by: '<S7>/threshold'
                                        */
  int32_T VisualizationInitialize_client_;
                              /* Mask Parameter: VisualizationInitialize_client_
                               * Referenced by: '<S3>/Visualization Initialize'
                               */
  int32_T VisualizationInitialize_clien_e;
                              /* Mask Parameter: VisualizationInitialize_clien_e
                               * Referenced by: '<S3>/Visualization Initialize'
                               */
  int32_T VisualizationInitialize_server_;
                              /* Mask Parameter: VisualizationInitialize_server_
                               * Referenced by: '<S3>/Visualization Initialize'
                               */
  int32_T VisualizationInitialize_serve_o;
                              /* Mask Parameter: VisualizationInitialize_serve_o
                               * Referenced by: '<S3>/Visualization Initialize'
                               */
  real32_T VisualizationInitialize_initial[48];
                              /* Mask Parameter: VisualizationInitialize_initial
                               * Referenced by: '<S3>/Visualization Initialize'
                               */
  uint32_T VisualizationInitialize_variabl[3];
                              /* Mask Parameter: VisualizationInitialize_variabl
                               * Referenced by: '<S3>/Visualization Initialize'
                               */
  boolean_T VisualizationInitialize_close_o;
                              /* Mask Parameter: VisualizationInitialize_close_o
                               * Referenced by: '<S3>/Visualization Initialize'
                               */
  real_T Yaw_Y0;                       /* Computed Parameter: Yaw_Y0
                                        * Referenced by: '<S4>/Yaw (%)'
                                        */
  real_T Throttle_Y0;                  /* Computed Parameter: Throttle_Y0
                                        * Referenced by: '<S4>/Throttle (%)'
                                        */
  real_T Roll_Y0;                      /* Computed Parameter: Roll_Y0
                                        * Referenced by: '<S4>/Roll (%)'
                                        */
  real_T Pitch_Y0;                     /* Computed Parameter: Pitch_Y0
                                        * Referenced by: '<S4>/Pitch (%)'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S9>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S9>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Bias_Bias;                    /* Expression: 0.5
                                        * Referenced by: '<S4>/Bias'
                                        */
  real_T JoystickIssue01_Y0;           /* Expression: 0
                                        * Referenced by: '<S5>/Joystick Issue (0,1)'
                                        */
  real_T Triggers014_Y0;               /* Expression: 0
                                        * Referenced by: '<S5>/Triggers (0,1) [4]'
                                        */
  real_T Commands4_Y0;                 /* Expression: 0
                                        * Referenced by: '<S5>/Commands (%) [4]'
                                        */
  real_T DeadZone_Start;               /* Expression: -0.01
                                        * Referenced by: '<S5>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 0.01
                                        * Referenced by: '<S5>/Dead Zone'
                                        */
  real_T NumberofPulses_Y0;            /* Computed Parameter: NumberofPulses_Y0
                                        * Referenced by: '<S10>/Number of Pulses'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T FixPtConstant_Value;          /* Expression: 1
                                        * Referenced by: '<S11>/FixPt Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S10>/Unit Delay'
                                        */
  real_T PulseCheck_Value;             /* Expression: 1
                                        * Referenced by: '<S6>/Pulse Check'
                                        */
  real_T Gain_Gain_f[4];               /* Expression: [1 -1 1 1]
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Constant_Value[16]; /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S19>/Constant'
                              */
  real_T Constant1_Value_l[12];      /* Expression: [1 0 0; 0 1 0; 0 0 1; 0 0 0]
                                      * Referenced by: '<S20>/Constant1'
                                      */
  real_T ContinuousSigmoid_XI;         /* Expression: initial_position
                                        * Referenced by: '<S22>/Continuous Sigmoid'
                                        */
  real_T ContinuousSigmoid_VI;         /* Expression: initial_velocity
                                        * Referenced by: '<S22>/Continuous Sigmoid'
                                        */
  real_T ContinuousSigmoid_Hold;       /* Expression: hold_off
                                        * Referenced by: '<S22>/Continuous Sigmoid'
                                        */
  real_T ContinuousSigmoid1_XI;        /* Expression: initial_position
                                        * Referenced by: '<S22>/Continuous Sigmoid1'
                                        */
  real_T ContinuousSigmoid1_VI;        /* Expression: initial_velocity
                                        * Referenced by: '<S22>/Continuous Sigmoid1'
                                        */
  real_T ContinuousSigmoid1_Hold;      /* Expression: hold_off
                                        * Referenced by: '<S22>/Continuous Sigmoid1'
                                        */
  real_T ContinuousSigmoid2_XI;        /* Expression: initial_position
                                        * Referenced by: '<S22>/Continuous Sigmoid2'
                                        */
  real_T ContinuousSigmoid2_VI;        /* Expression: initial_velocity
                                        * Referenced by: '<S22>/Continuous Sigmoid2'
                                        */
  real_T ContinuousSigmoid2_Hold;      /* Expression: hold_off
                                        * Referenced by: '<S22>/Continuous Sigmoid2'
                                        */
  real_T ContinuousSigmoid3_XI;        /* Expression: initial_position
                                        * Referenced by: '<S22>/Continuous Sigmoid3'
                                        */
  real_T ContinuousSigmoid3_VI;        /* Expression: initial_velocity
                                        * Referenced by: '<S22>/Continuous Sigmoid3'
                                        */
  real_T ContinuousSigmoid3_Hold;      /* Expression: hold_off
                                        * Referenced by: '<S22>/Continuous Sigmoid3'
                                        */
  real_T Constant_Value_a[6];          /* Expression: -1*ones(1,6)
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_k;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                           * Referenced by: '<S7>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_e;  /* Expression: 0
                                        * Referenced by: '<S7>/Discrete-Time Integrator'
                                        */
  real_T m_Gain;                       /* Expression: 1
                                        * Referenced by: '<S1>/  m//%  '
                                        */
  real_T m_Gain_o;                     /* Expression: 1
                                        * Referenced by: '<S1>/ m//% '
                                        */
  real_T m_Gain_n;                     /* Expression: 1
                                        * Referenced by: '<S1>/m//%'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant1_Value_h[12];      /* Expression: [1 0 0; 0 1 0; 0 0 1; 0 0 0]
                                      * Referenced by: '<S21>/Constant1'
                                      */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant_Value_g[16];
                             /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S15>/Constant'
                              */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<S18>/Constant6'
                                        */
  real_T Constant_Value_m[3];          /* Expression: [0 0 1]
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<S18>/Constant9'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<S18>/Constant8'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S18>/Constant7'
                                        */
  real_T Constant5_Value[4];           /* Expression: [0 0 0 1]
                                        * Referenced by: '<S18>/Constant5'
                                        */
  real_T Constant_Value_fm;            /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant6_Value_l;            /* Expression: 1
                                        * Referenced by: '<S16>/Constant6'
                                        */
  real_T Constant1_Value_c[3];         /* Expression: [0 1 0]
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Constant9_Value_f;            /* Expression: 0
                                        * Referenced by: '<S16>/Constant9'
                                        */
  real_T Constant8_Value_d;            /* Expression: 0
                                        * Referenced by: '<S16>/Constant8'
                                        */
  real_T Constant7_Value_e;            /* Expression: 0
                                        * Referenced by: '<S16>/Constant7'
                                        */
  real_T Constant5_Value_p[4];         /* Expression: [0 0 0 1]
                                        * Referenced by: '<S16>/Constant5'
                                        */
  real_T Constant6_Value_j;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant6'
                                        */
  real_T Constant2_Value[3];           /* Expression: [1 0 0]
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T Constant9_Value_j;            /* Expression: 0
                                        * Referenced by: '<S17>/Constant9'
                                        */
  real_T Constant8_Value_g;            /* Expression: 0
                                        * Referenced by: '<S17>/Constant8'
                                        */
  real_T Constant7_Value_g;            /* Expression: 0
                                        * Referenced by: '<S17>/Constant7'
                                        */
  real_T Constant5_Value_m[4];         /* Expression: [0 0 0 1]
                                        * Referenced by: '<S17>/Constant5'
                                        */
  real_T Constant_Value_ab;            /* Expression: 5
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Constant1_Value_p[2];         /* Expression: [0.5 4.5]
                                        * Referenced by: '<S22>/Constant1'
                                        */
  real_T Constant2_Value_d[2];         /* Expression: [0.5 4.5]
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T Constant3_Value[2];           /* Expression: [0.5 4.5]
                                        * Referenced by: '<S22>/Constant3'
                                        */
  real_T Constant4_Value[2];           /* Expression: [0.5 4.5]
                                        * Referenced by: '<S22>/Constant4'
                                        */
  real_T Constant5_Value_py[2];        /* Expression: [2 0.5]
                                        * Referenced by: '<S22>/Constant5'
                                        */
  real_T Constant6_Value_b[2];         /* Expression: [2 2]
                                        * Referenced by: '<S22>/Constant6'
                                        */
  real_T Constant8_Value_k[2];         /* Expression: [0.5 4.5]
                                        * Referenced by: '<S22>/Constant8'
                                        */
  real_T Constant9_Value_b[2];         /* Expression: [0.5 4.5]
                                        * Referenced by: '<S22>/Constant9'
                                        */
  real_T Defaultinput_Value[4];        /* Expression: [0 0 0 0]
                                        * Referenced by: '<S14>/Default input '
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S14>/Switch'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S22>/Memory'
                                        */
  real_T rads_Gain;                    /* Expression: 1
                                        * Referenced by: '<S1>/ rad//s//%'
                                        */
  int32_T HostGameController_BufferSize;
                            /* Computed Parameter: HostGameController_BufferSize
                             * Referenced by: '<S1>/Host Game Controller'
                             */
  int32_T HostInitialize_SendBufferSize;
                            /* Computed Parameter: HostInitialize_SendBufferSize
                             * Referenced by: '<S1>/Host Initialize'
                             */
  int32_T HostInitialize_ReceiveBufferSiz;
                          /* Computed Parameter: HostInitialize_ReceiveBufferSiz
                           * Referenced by: '<S1>/Host Initialize'
                           */
  int32_T HostInitialize_ThreadPriority;
                            /* Computed Parameter: HostInitialize_ThreadPriority
                             * Referenced by: '<S1>/Host Initialize'
                             */
  boolean_T EmergencyAbortbool_Y0;  /* Computed Parameter: EmergencyAbortbool_Y0
                                     * Referenced by: '<S4>/Emergency Abort (bool)'
                                     */
  boolean_T ArmDisarmbool_Y0;          /* Computed Parameter: ArmDisarmbool_Y0
                                        * Referenced by: '<S4>/Arm//Disarm (bool) '
                                        */
  boolean_T TakeoffAutolandbool_Y0;/* Computed Parameter: TakeoffAutolandbool_Y0
                                    * Referenced by: '<S4>/Takeoff//Autoland (bool)'
                                    */
  boolean_T VisualizationInitialize_OpenVie;
                          /* Computed Parameter: VisualizationInitialize_OpenVie
                           * Referenced by: '<S3>/Visualization Initialize'
                           */
  boolean_T HostGameController_AutoCenter;
                            /* Computed Parameter: HostGameController_AutoCenter
                             * Referenced by: '<S1>/Host Game Controller'
                             */
  boolean_T HostGameController_Enabled;
                               /* Computed Parameter: HostGameController_Enabled
                                * Referenced by: '<S1>/Host Game Controller'
                                */
  boolean_T HostGameController_DebugMode;
                             /* Computed Parameter: HostGameController_DebugMode
                              * Referenced by: '<S1>/Host Game Controller'
                              */
  boolean_T HostInitialize_RunClient;
                                 /* Computed Parameter: HostInitialize_RunClient
                                  * Referenced by: '<S1>/Host Initialize'
                                  */
  boolean_T HostInitialize_UseWindow;
                                 /* Computed Parameter: HostInitialize_UseWindow
                                  * Referenced by: '<S1>/Host Initialize'
                                  */
  boolean_T HostInitialize_Active;  /* Computed Parameter: HostInitialize_Active
                                     * Referenced by: '<S1>/Host Initialize'
                                     */
  int8_T HostGameController_Controller;
                            /* Computed Parameter: HostGameController_Controller
                             * Referenced by: '<S1>/Host Game Controller'
                             */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch1'
                              */
  uint8_T HostInitialize_URI;          /* Expression: uri_argument
                                        * Referenced by: '<S1>/Host Initialize'
                                        */
  P_Usedesheightwhenenabled_Joy_T UsedesiredYwhenenabled;/* '<S22>/Use desired Y  when enabled' */
  P_Usedesheightwhenenabled_Joy_T UsedesiredXwhenenabled;/* '<S22>/Use desired X  when enabled' */
  P_Usedesheightwhenenabled_Joy_T Usedesyawwhenenabled;/* '<S22>/Use des yaw  when enabled' */
  P_Usedesheightwhenenabled_Joy_T Usedesheightwhenenabled;
                                      /* '<S22>/Use des height  when enabled' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Joystick_Visualizatio_T {
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
  real_T odeF[1][1];
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
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Joystick_Visualization_2019_T Joystick_Visualization_2019a_P;

/* Block signals (default storage) */
extern B_Joystick_Visualization_2019_T Joystick_Visualization_2019a_B;

/* Continuous states (default storage) */
extern X_Joystick_Visualization_2019_T Joystick_Visualization_2019a_X;

/* Disabled states (default storage) */
extern XDis_Joystick_Visualization_2_T Joystick_Visualization_201_XDis;

/* Block states (default storage) */
extern DW_Joystick_Visualization_201_T Joystick_Visualization_2019a_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Joystick_Visualizatio_T Joystick_Visualization__PrevZCX;

/* Model entry point functions */
extern void Joystick_Visualization_2019a_initialize(void);
extern void Joystick_Visualization_2019a_output(void);
extern void Joystick_Visualization_2019a_update(void);
extern void Joystick_Visualization_2019a_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Joystick_Visualization_2019a_rtModel *Joystick_Visualization_2019a(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Joystick_Visualizati_T *const Joystick_Visualization_2019a_M;

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
 * '<Root>' : 'Joystick_Visualization_2019a'
 * '<S1>'   : 'Joystick_Visualization_2019a/JOYSTICK_FRSKY'
 * '<S2>'   : 'Joystick_Visualization_2019a/Quanser'
 * '<S3>'   : 'Joystick_Visualization_2019a/Simple Drone  Visualization'
 * '<S4>'   : 'Joystick_Visualization_2019a/JOYSTICK_FRSKY/FrSKYMapping'
 * '<S5>'   : 'Joystick_Visualization_2019a/JOYSTICK_FRSKY/Initialization and Conditioning'
 * '<S6>'   : 'Joystick_Visualization_2019a/JOYSTICK_FRSKY/Pulse Check'
 * '<S7>'   : 'Joystick_Visualization_2019a/JOYSTICK_FRSKY/Threshold'
 * '<S8>'   : 'Joystick_Visualization_2019a/JOYSTICK_FRSKY/FrSKYMapping/Compare To Constant'
 * '<S9>'   : 'Joystick_Visualization_2019a/JOYSTICK_FRSKY/FrSKYMapping/Threshold'
 * '<S10>'  : 'Joystick_Visualization_2019a/JOYSTICK_FRSKY/Pulse Check/pulse count '
 * '<S11>'  : 'Joystick_Visualization_2019a/JOYSTICK_FRSKY/Pulse Check/pulse count /Increment Stored Integer'
 * '<S12>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Generate Angular Transformation'
 * '<S13>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Generate Position Transformation'
 * '<S14>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning'
 * '<S15>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Generate Angular Transformation/Identity  Transformation'
 * '<S16>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Generate Angular Transformation/Rotation Transformation - Pitch'
 * '<S17>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Generate Angular Transformation/Rotation Transformation - Roll'
 * '<S18>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Generate Angular Transformation/Rotation Transformation - Yaw'
 * '<S19>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Generate Position Transformation/Identity  Transformation'
 * '<S20>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Generate Position Transformation/Translation Transformation'
 * '<S21>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Generate Position Transformation/Translation Transformation1'
 * '<S22>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids'
 * '<S23>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/MATLAB Function'
 * '<S24>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/MATLAB Function1'
 * '<S25>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/MATLAB Function2'
 * '<S26>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/MATLAB Function4'
 * '<S27>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Signmoid Type'
 * '<S28>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Use des height  when enabled'
 * '<S29>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Use des yaw  when enabled'
 * '<S30>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Use desired X  when enabled'
 * '<S31>'  : 'Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Use desired Y  when enabled'
 */
#endif                                 /* Joystick_Visualization_2019a_h_ */
