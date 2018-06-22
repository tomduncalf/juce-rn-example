#import "AppDelegate.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [juceDelegate applicationDidFinishLaunching:application];
    
    id<RCTBridgeDelegate> moduleInitialiser = [[BridgeDelegate alloc] init];
    
    auto bridge = [[RCTBridge alloc] initWithDelegate: moduleInitialiser launchOptions: launchOptions];
    
    RCTRootView *rootView = [[RCTRootView alloc] initWithBridge:bridge
                                                     moduleName:@"JuceRNExample"
                                              initialProperties:nil];
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *rootViewController = [UIViewController new];
    rootViewController.view = rootView;
    self.window.rootViewController = rootViewController;
    [self.window makeKeyAndVisible];
    return YES;
}

-(id) init
{
    self = [super init];
    juceDelegate = reinterpret_cast<NSObject<UIApplicationDelegate>*> ([[NSClassFromString (@"JuceAppStartupDelegate") alloc] init]);
    
    return self;
}

-(void)dealloc
{
    [juceDelegate release];
    [super dealloc];
}

- (void)forwardInvocation:(NSInvocation *)anInvocation
{
    if (juceDelegate != nullptr && [juceDelegate respondsToSelector:[anInvocation selector]])
        [anInvocation invokeWithTarget:juceDelegate];
    else
        [super forwardInvocation:anInvocation];
}

-(BOOL)respondsToSelector:(SEL)aSelector
{
    if (juceDelegate != nullptr && [juceDelegate respondsToSelector:aSelector])
        return YES;
    
    return [super respondsToSelector:aSelector];
}

@end
