//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//
// uspmessages.h: definition of USP messages that are exposed to users.
//
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <wchar.h>

typedef uint64_t UspOffsetType;
typedef uint64_t UspDurationType;

/**
 * Represents recognition status in speech phrase.
 */
typedef enum _UspRecognitionStatus
{
    USP_RECOGNITON_SUCCESS,
    USP_RECOGNITION_NO_MATCH,
    USP_RECOGNITION_INITIAL_SILENCE_TIMEOUT,
    USP_RECOGNITION_BABBLE_TIMEOUT,
    USP_RECOGNITION_ERROR
} UspRecognitionStatus;

/**
 * Represents speech.startDectected message
 */
typedef struct _UspMsgSpeechStartDetected
{
    UspOffsetType offset;
} UspMsgSpeechStartDetected;

/**
 * Represents speech.hypothesis message
 */
typedef struct _UspMsgSpeechHypothesis
{
    wchar_t* text;
    UspOffsetType offset;
    UspDurationType duration;
} UspMsgSpeechHypothesis;

/**
 * Represents speech.phrase message
 */
typedef struct _UspMsgSpeechPhrase
{
    UspRecognitionStatus recognitionStatus;
    wchar_t* displayText;
    UspOffsetType offset;
    UspDurationType duration;
} UspMsgSpeechPhrase;

/**
 * Represents speech.endDetected message
 */
typedef struct _UspMsgSpeechEndDetected
{
    UspOffsetType offset;
} UspMsgSpeechEndDetected;

/**
 * Represents turn.start message
 */
typedef struct _UspMsgTurnStart
{
    wchar_t* contextServiceTag;
} UspMsgTurnStart;

/**
 * Represents turn.end message
 * Note: Body is empty.
 */
typedef struct _UspMsgTurnEnd UspMsgTurnEnd;

#ifdef __cplusplus
}
#endif