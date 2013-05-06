//
//  InkHTMLAttributes.m
//  Ink
//
//  Created by Wess Cope on 5/6/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import "InkHTMLAttributes.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@implementation InkHTMLAttributes

- (InkHeaderAttributesBlock) headerAttributes
{
    return ((InkHeaderAttributesBlock)^(NSString *text, NSInteger level) {
        return @{
                 NSForegroundColorAttributeName: [UIColor redColor],
                 NSFontAttributeName: [UIFont boldSystemFontOfSize:30.0f]
                 };
    });
}

- (InkAttributesBlock) paragraphAttributes
{
    return ((InkAttributesBlock)^(NSString *text)
    {
        return @{
                 NSForegroundColorAttributeName: [UIColor blueColor],
                 NSFontAttributeName: [UIFont systemFontOfSize:14.0f]
                 };
    });
}


@end
