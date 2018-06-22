/*
  ==============================================================================

    Main.h
    Created: 8 May 2018 8:32:23am
    Author:  Tom Duncalf

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "NoiseGenerator.h"

class JuceRnExampleApplication : public JUCEApplication,
                                 public Timer
{
public:
    JuceRnExampleApplication() {}

    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return false; }

    void initialise (const String& commandLine) override
    {
        startTimer(500);
    }

    void shutdown() override
    {
    }

    void suspended() override
    {
    }

    void resumed() override
    {
    }

    void systemRequestedQuit() override
    {
        quit();
    }
    
    void timerCallback() override;

    NoiseGenerator generator;
    // void* as it's an Objective C type - I'm sure there is a nicer way to do this!
    void* reactModule;
};
