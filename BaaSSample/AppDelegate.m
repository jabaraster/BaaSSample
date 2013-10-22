//
//  AppDelegate.m
//  BaaSSample
//
//  Created by 河野 智遵 on 2013/10/21.
//  Copyright (c) 2013年 河野 智遵. All rights reserved.
//

#import <NCMB/NCMB.h>
#import "AppDelegate.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [NCMB setApplicationKey:@"524dad28157666e9511105a0ff8850def201a9abf0962ff61e5cdf4438f0f031" clientKey:@"232ba8b39ad1808f0081c678c545f6726417a59a865684d7613b64d0bb4966b7"];
    NCMBQuery *query = [NCMBQuery queryWithClassName:@"TestClass"];
    [query whereKey:@"message" equalTo:@"test"];
    [query findObjectsInBackgroundWithBlock:^(NSArray *objects, NSError *error){
        if (error != nil) {
            NSLog(@"[ERROR] %@", error);
            return;
        }
        if ([objects count] > 0) {
            NSLog(@"[FIND] %@", [[objects objectAtIndex:0] objectForKey:@"message"]);
            return;
        }
        NSError *saveError;
        NCMBObject *obj = [NCMBObject objectWithClassName:@"TestClass"];
        [obj setObject:@"Hello, NCMB!" forKey:@"message"];
        [obj save:&saveError];
        if (saveError != nil ) {
            NSLog(@"[SAVE-ERROR] %@", saveError);
        }
        
        NSLog(@"[SAVE Done]");
        
    }];
    // Override point for customization after application launch.
    return YES;
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
