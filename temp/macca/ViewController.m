//
//  ViewController.m
//  macca
//
//  Created by Mac on 16/5/18.
//  Copyright © 2016年 Mac. All rights reserved.
//

#import "ViewController.h"



@interface ViewController()<NSTextFieldDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];


    NSTextField *textfiled = [[NSTextField alloc] initWithFrame:NSMakeRect(100, 100, 100, 30)];

    textfiled.delegate = self;


    

}

- (void)setTitleWithMnemonic:(null_unspecified NSString *)stringWithAmpersand
{
    NSLog(@"stringt --- %@",stringWithAmpersand);
}




- (void)textDidEndEditing:(NSNotification *)notification
{

}


- (void)textDidChange:(NSNotification *)notification
{
    NSLog(@"this is --- %@",notification.object);
}




- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

@end
