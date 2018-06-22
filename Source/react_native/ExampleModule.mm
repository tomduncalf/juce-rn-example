#import "ExampleModule.h"

JuceRnExampleApplication* getJUCEApplication()
{
    return static_cast<JuceRnExampleApplication*>(JUCEApplication::getInstance());
}

@implementation ExampleModule

RCT_EXPORT_MODULE()

// MARK: methods exposed to JS

// Called from JS to allow us to capture a reference to this instance of the module
RCT_EXPORT_METHOD(setup)
{
    getJUCEApplication()->reactModule = self;
}

RCT_EXPORT_METHOD(setFrequency: (nonnull NSNumber *) frequency)
{
    getJUCEApplication()->generator.setFrequency ([frequency floatValue]);
}

RCT_EXPORT_METHOD(setLevel: (nonnull NSNumber *) level)
{
    getJUCEApplication()->generator.setLevel ([level floatValue]);
}

// MARK: methods to send events back to JS

- (NSArray<NSString *> *)supportedEvents
{
    return @[@"UPDATE_TIME"];
}

- (void) updateTime: (NSNumber *) time
{
    [self sendEventWithName:@"UPDATE_TIME" body:@{@"time": time}];
}

@end
