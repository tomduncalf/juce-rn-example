#include "Main.h"

#if JUCE_IOS
#include "ios/AppDelegate.h"
#endif

#include "react_native/ExampleModule.h"

void JuceRnExampleApplication::timerCallback()
{
    [(ExampleModule*)reactModule updateTime: [NSNumber numberWithDouble: juce::Time::currentTimeMillis()]];
}

START_JUCE_APPLICATION_WITH_CUSTOM_DELEGATE (JuceRnExampleApplication, AppDelegate)

