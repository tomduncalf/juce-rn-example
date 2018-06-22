/*
  ==============================================================================

   This file is part of the JUCE tutorials.
   Copyright (c) 2017 - ROLI Ltd.

   The code included in this file is provided under the terms of the ISC license
   http://www.isc.org/downloads/software-support-policy/isc-license. Permission
   To use, copy, modify, and/or distribute this software for any purpose with or
   without fee is hereby granted provided that the above copyright notice and
   this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES,
   WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR
   PURPOSE, ARE DISCLAIMED.

  ==============================================================================
*/


#pragma once

//==============================================================================
class NoiseGenerator : public juce::AudioSource
{
public:
    NoiseGenerator()
    {
        frequency = 440;
        
        deviceManager.addAudioCallback (&audioSourcePlayer);
        audioSourcePlayer.setSource (this);
        
        deviceManager.initialise (0, 2, nullptr, true);
    }

    ~NoiseGenerator()
    {
        audioSourcePlayer.setSource (nullptr);
        deviceManager.removeAudioCallback (&audioSourcePlayer);
    }
    
    void setFrequency (float f)
    {
        frequency = f;
        updateAngleDelta();
    }
    
    void setLevel (float l)
    {
        level = l;
    }
    
    void updateAngleDelta()
    {
        auto cyclesPerSample = frequency / currentSampleRate;
        angleDelta = cyclesPerSample * 2.0 * MathConstants<double>::pi;
    }

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        resetParameters();
        
        currentSampleRate = sampleRate;
        updateAngleDelta();
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        auto* leftBuffer  = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);
        auto* rightBuffer = bufferToFill.buffer->getWritePointer (1, bufferToFill.startSample);
        for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
            auto currentSample = (float) std::sin (currentAngle);
            currentAngle += angleDelta;
            leftBuffer[sample]  = currentSample * level;
            rightBuffer[sample] = currentSample * level;
        }
    }

    void releaseResources() override {}

    void resetParameters()
    {
    }

private:
    juce::AudioDeviceManager deviceManager;
    juce::AudioSourcePlayer audioSourcePlayer;

    double frequency, level = 0.0, currentSampleRate = 0.0, currentAngle = 0.0, angleDelta = 0.0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoiseGenerator)
};
