//
//  ViewController.m
//  ios-app
//
//  Created by Mac on 16/5/23.
//  Copyright © 2016年 Mac. All rights reserved.
//

#import "ViewController.h"
#include <pthread.h>

@interface ViewController ()<UISearchBarDelegate>

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    UISearchBar *searchBar = [[UISearchBar alloc] initWithFrame:CGRectMake(100, 100, 100, 40)];
    searchBar.delegate = self;
    searchBar.returnKeyType = UIReturnKeyDone;
    [self.view addSubview:searchBar];

}

- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText
{
    NSLog(@"search -- txt %@",searchText);

    if ([searchText  isEqual: @"\n"])
    {
        NSLog(@"ls---");
    }



}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
