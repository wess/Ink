//
//  InkMarkdownAttributes.m
//  Ink
//
//  Created by Wess Cope on 5/6/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import "InkMarkdownAttributes.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@implementation InkMarkdownAttributes
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
        
        self.emphasisAttributes         = ^(NSString *text) {
            return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont italicSystemFontOfSize:12.0f] };
        };
        
        
        self.blockcodeAttributes        = ^(NSString *language, NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor cyanColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.blockquoteAttributes       = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.blockhtmlAttributes        = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.hruleAttributes            = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.listAttributes             = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.listitemAttributes         = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.paragraphAttributes        = ^(NSString *text) { return @{NSForegroundColorAttributeName: [UIColor purpleColor]}; };
        self.tableAttributes            = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.tableRowAttributes         = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.tableCellAttributes        = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.autolinkAttributes         = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.codespanAttributes         = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.doubleEmphasisAttributes   = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.imageAttributes            = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.linebreakAttributes        = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.linkAttributes             = ^(NSURL *link, NSString *title, NSString *content) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.rawHtmlTagAttributes       = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.tripleEmphasisAttributes   = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.strikethroughAttributes    = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.superscriptAttributes      = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.entityAttributes           = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.docHeaderAttributes        = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        self.docFooterAttributes        = ^(NSString *text) { return @{ NSForegroundColorAttributeName: [UIColor blackColor], NSFontAttributeName: [UIFont systemFontOfSize:12.0f] }; };
        
    }
    return self;
}
@end
