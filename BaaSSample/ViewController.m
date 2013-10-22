//
//  ViewController.m
//  BaaSSample
//
//  Created by 河野 智遵 on 2013/10/21.
//  Copyright (c) 2013年 河野 智遵. All rights reserved.
//

#import "ViewController.h"
#import <NCMB/NCMB.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onSignIn:(id)sender {
    [NCMBUser logInWithUsernameInBackground:self.userNameText.text password:self.passwordText.text
                                      block:^(NCMBUser *user, NSError *error) {
        if (user == nil) {
            [[[UIAlertView alloc] initWithTitle:@"Sign in" message:@"失敗！" delegate:nil cancelButtonTitle:nil otherButtonTitles:@"OK", nil] show];
            return;
        }
        [[[UIAlertView alloc] initWithTitle:@"Sign in"
                                    message:@"成功！"
                                   delegate:nil
                          cancelButtonTitle:nil
                          otherButtonTitles:@"OK", nil] show];
    }];
}

@end
