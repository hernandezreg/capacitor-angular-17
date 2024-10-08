//
//  CYFMonitor.h
//  CyberFendSDK
//
//  Copyright (c) 2015 CyberFend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

	#if __has_feature(modules) 
	@import CoreTelephony; 
	@import SystemConfiguration; 
	@import CoreMotion; 
	@import Accelerate; 
    @import WebKit; 
    @import CoreLocation; 
	#endif
typedef NS_ENUM(NSInteger, CYFLogLevel) {
    CYFLogLevelInfo = 4,
    CYFLogLevelWarn,
    CYFLogLevelError,
    CYFLogLevelNone = 0xF
};

/*!
 Methods for managing the result of challenge action
 */
@protocol CYFChallengeActionDelegate<NSObject>

/*!
 Notifies the delegate that the challenge action was successful and the app can resubmit
 the HTTP request
 */
- (void)onChallengeActionSuccess;
@optional
/*!
 Notifies the delegate that the challenge action was cancelled by the user.
 */
- (void)onChallengeActionCancel;
/*!
 Notifies the delegate that an error has occurred and the challenge action has failed.
*/
- (void)onChallengeActionFailure:(NSString *)message;

@end


/*!
 Methods for managing the result of challenge action
 */
@protocol CYFSDKInitDelegate<NSObject>

/*!
 Notifies the delegate that the SDK  initialization is sucess
 */
- (void)onSDKInitSuccess;
/*!
 Notifies the delegate when the SDK initialization fails.
 */
- (void)onSDKInitFailure:(NSString *)message;

@end

@interface CYFMonitor : NSObject

/*!
 Call this method to initialize the SDK.
 */
+ (void)configure __attribute__((deprecated("Use configureSDK:(NSString *)url method to intialize the api")));


/*!
Call this method to initialize the SDK

@param url  Base URL of the protected endpoint
        For example, the base URL for the endpoint https://api.customer.com/app1/rest/v1/login
        would be https://api.customer.com
*/
+ (void)configureSDK:(NSString *)url;


/*!
Call this method to initialize the SDK with Proof of Work functionality

@param baseUrl Base URL of the protected endpoint
        For example, the base URL for the endpoint https://api.customer.com/app1/rest/v1/login
        would be https://api.customer.com
*/
+ (void)configureWithUrl:(NSString *)baseUrl __attribute__((deprecated("Use configureSDKWithPow:(NSString *)url method to intialize the SDK with proof of work functionality")));


/*!
Call this method to initialize the SDK with Proof of Work functionality

@param baseUrl Base URL of the protected endpoint
        For example, the base URL for the endpoint https://api.customer.com/app1/rest/v1/login
        would be https://api.customer.com
*/
+ (void)configureSDKWithPow:(NSString *)baseUrl; 


/*!
Call this method to enable Challenge Action functionality

@param baseUrl Base URL of the protected endpoint
        For example, the base URL for the endpoint https://api.customer.com/app1/rest/v1/login
        would be https://api.customer.com
*/
+ (void)configureChallengeAction:(NSString *)baseUrl;

/*!
Call this method to show challenge action dialog

@param context Akamai-BM-Challenge-Context response header value from the HTTP request
@param title Title for the challenge action dialog, use this to communicate the reason for the
action.
@param message Descriptive text that provides additional details about the reason for the action.
@param cancelButtonTitle Title for the cancel button in the dialog
@param delegate A delegate to execute and notify the result of challenge action, it must adopt the
            CYFChallengeActionDelegate protocol
 @return: Returns YES if the challenge action dialog is displayed, otherwise NO
*/
+ (BOOL)showChallengeAction:(NSString *)context
                      title:(NSString *)title
                    message:(NSString *)message
          cancelButtonTitle:(NSString *)cancelButtonTitle
                   delegate:(id<CYFChallengeActionDelegate>)delegate;

/*!
 Call this method to get the final sensor data string whenever you want to send this data along with
 your network requests.
 */
+ (NSString *)getSensorData;

/*! CyberFend SDK automatically starts collecting the touch events on application's key window as
 soon as application starts.

 Optionaly You can call this method if you want SDK to listen touch events for any
 additional window your application may create.Pass the window object as parameter

 Note: CyberFend SDK doesn't store the reference of this window object.
 */
+ (void)startCollectingTouchEventsOnWindow:(UIWindow *)window;

/*!
 Get the CyberFend SDK version
 */
+ (NSString *)getVersion;

/*!
 Set the log level used by the SDK.
 */
+ (void)setLogLevel:(CYFLogLevel)logLevel;

/*! CyberFend SDK automatically starts processing events on main thread
 
 Optionally, you can call this method if you want CyberFend SDK to process events on background thread
 
 Notes:
 1. Call this method before calling configure method
 2. By default, the events are processed on main thread
 3. The background processing value is retained for an app launch session
 */
+ (void)enableBackground;


/*!
 Method for testing the application
 */
+(NSDictionary *) collectTestData;

/*!
 Method for setting SDK init callback
 */
+ (void)setSDKInitCallBack:(id<CYFSDKInitDelegate>)delegate;

@end
