//
//  InkAttributes.m
//  Ink
//
//  Created by Wess Cope on 5/3/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import "InkAttributes.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@implementation InkAttributes

- (id)init
{
    self = [super init];
    if (self)
    {
        self.normalTextAttributes = ^(NSString *text) {
            return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:14.0f] };
        };

        self.headerAttributes           = ^(NSString *text, NSInteger level) {
            CGFloat fontSize = 0.0f;
            
            switch (level)
            {
                case 1:
                    fontSize = 34.0f;
                    break;
                case 2:
                    fontSize = 22.0f;
                    break;
                    
                default:
                    fontSize = 16.0f;
                    break;
            }
            
            return @{
                     NSFontAttributeName: [UIFont boldSystemFontOfSize:fontSize],
                     NSForegroundColorAttributeName: [UIColor greenColor]
                    };
        };

        self.blockcodeAttributes        = ^(NSString *text) { return @{}; };
        self.blockquoteAttributes       = ^(NSString *text) { return @{}; };
        self.blockhtmlAttributes        = ^(NSString *text) { return @{}; };
        self.hruleAttributes            = ^(NSString *text) { return @{}; };
        self.listAttributes             = ^(NSString *text) { return @{}; };
        self.listitemAttributes         = ^(NSString *text) { return @{}; };
        self.paragraphAttributes        = ^(NSString *text) { return @{NSForegroundColorAttributeName: [UIColor purpleColor]}; };
        self.tableAttributes            = ^(NSString *text) { return @{}; };
        self.tableRowAttributes         = ^(NSString *text) { return @{}; };
        self.tableCellAttributes        = ^(NSString *text) { return @{}; };
        self.autolinkAttributes         = ^(NSString *text) { return @{}; };
        self.codespanAttributes         = ^(NSString *text) { return @{}; };
        self.doubleEmphasisAttributes   = ^(NSString *text) { return @{}; };
        self.emphasisAttributes         = ^(NSString *text) { return @{}; };
        self.imageAttributes            = ^(NSString *text) { return @{}; };
        self.linebreakAttributes        = ^(NSString *text) { return @{}; };
        self.linkAttributes             = ^(NSString *text) { return @{}; };
        self.rawHtmlTagAttributes       = ^(NSString *text) { return @{}; };
        self.tripleEmphasisAttributes   = ^(NSString *text) { return @{}; };
        self.strikethroughAttributes    = ^(NSString *text) { return @{}; };
        self.superscriptAttributes      = ^(NSString *text) { return @{}; };
        self.entityAttributes           = ^(NSString *text) { return @{}; };
        self.docHeaderAttributes        = ^(NSString *text) { return @{}; };
        self.docFooterAttributes        = ^(NSString *text) { return @{}; };

    }
    return self;
}

@end
