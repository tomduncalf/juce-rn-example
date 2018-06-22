#import <UIKit/UIKit.h>

#import <React/RCTBundleURLProvider.h>
#import <React/RCTRootView.h>

#import "../react_native/BridgeDelegate.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate> {
    NSObject<UIApplicationDelegate>* juceDelegate;
}

@property (nonatomic, strong) UIWindow *window;

@end
