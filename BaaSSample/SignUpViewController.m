//
//  SignUpViewController.m
//  BaaSSample
//
//  Created by 河野 智遵 on 2013/10/22.
//  Copyright (c) 2013年 河野 智遵. All rights reserved.
//

#import "SignUpViewController.h"
#import <NCMB/NCMB.h>

@interface SignUpViewController ()

@end

@implementation SignUpViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onBack:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)register:(id)sender {
    if (self.passwordText.text != self.passwordConfirmationText.text) {
        [[[UIAlertView alloc] initWithTitle:@"Register"
                                   message:@"パスワードが一致しません。"
                                  delegate:nil
                         cancelButtonTitle:nil
                         otherButtonTitles:@"OK", nil] show];
        return;
    }
    
    NCMBUser *user = [NCMBUser user];
    user.userName = self.userNameText.text;
    user.password = self.passwordText.text;
}
@end
