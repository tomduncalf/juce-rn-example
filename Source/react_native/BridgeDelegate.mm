 #import "BridgeDelegate.h"

@implementation BridgeDelegate

- (NSURL *)sourceURLForBridge:(RCTBridge *)bridge
{
    NSURL *jsCodeLocation;

#if DEBUG
    NSString *url = @"http://127.0.0.1:8081/index.ios.bundle?platform=ios&dev=true";
    jsCodeLocation = [NSURL URLWithString:url];
#else
    jsCodeLocation = [[RCTBundleURLProvider sharedSettings] jsBundleURLForBundleRoot:@"index.ios" fallbackResource:nil];
#endif

    return jsCodeLocation;
}

@end

