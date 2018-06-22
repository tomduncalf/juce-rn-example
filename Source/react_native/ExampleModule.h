/*
  This class is automatically instantiated by React Native when it starts up, and acts as the
  communication point between JS code and native code.
 
  JS code can call the methods exported with the RCT_EXPORT_METHOD macro from here, and this class
  handles the actual emitting of events back to JS.
*/

#ifndef ExampleModule_h
#define ExampleModule_h

#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>

#import "../Main.h"

@interface ExampleModule : RCTEventEmitter <RCTBridgeModule>

- (void) updateTime: (NSNumber *) time;

@end

#endif
