//
//  IEAppDelegate.m
//  InkExample
//
//  Created by Wess Cope on 5/2/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import "IEAppDelegate.h"
#import <QuartzCore/QuartzCore.h>
#import <Ink/Ink.h>
#import <Ink/InkMarkdownRenderer.h>
#import <Ink/InkHTMLRenderer.h>
#import <Ink/UITextView+Ink.h>

@interface IEAppDelegate()
- (void)textViewClicked:(UITapGestureRecognizer *)gesture;
@end

@implementation IEAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window                     = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.rootViewController  = [[UIViewController alloc] initWithNibName:nil bundle:nil];
    self.window.backgroundColor     = [UIColor whiteColor];
    [self.window makeKeyAndVisible];

    UITextView *textView        = [[UITextView alloc] initWithFrame:CGRectInset([[UIScreen mainScreen] bounds], 30.0f, 30.0f)];
    textView.layer.borderColor  = [UIColor redColor].CGColor;
    textView.layer.borderWidth  = 2.0f;
    textView.editable           = NO;
    
    [self.window.rootViewController.view addSubview:textView];
    
    NSString *markdown = [NSString stringWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"example" ofType:@"md"] encoding:NSUTF8StringEncoding error:nil];
//    NSString *html = @"<html><head></head><body><h1>Hello World</h1><p>This is a paragraph</p></body></html>";

    Ink *ink = [[Ink alloc] initWithRenderer:[InkMarkdownRenderer class]];
    textView.attributedText = [ink renderFromString:markdown];
    
    UITapGestureRecognizer *tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(textViewClicked:)];
    [textView addGestureRecognizer:tapGesture];
    
    return YES;
}

- (void)textViewClicked:(UITapGestureRecognizer *)gesture
{
    UITextView *textView    = (UITextView *)gesture.view;
    CGPoint point           = [gesture locationInView:textView];

    NSLog(@"AAAAA: %@",     [textView.attributedText attribute:InkLinkAttribute atIndex:0 longestEffectiveRange:NULL inRange:[textView rangeOfTextAtPoint:point]]);

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
