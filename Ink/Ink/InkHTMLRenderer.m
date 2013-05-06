//
//  InkHTMLRenderer.m
//  Ink
//
//  Created by Wess Cope on 5/6/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import "InkHTMLRenderer.h"

@interface InkHTMLRenderer()
@end

@implementation InkHTMLRenderer

- (id)init
{
    self = [super init];
    if (self)
    {
        self.elements       = [[NSMutableArray alloc] init];
        self.stringBuilder  = [[InkStringBuilder alloc] init];
        self.attributes     = [[InkHTMLAttributes alloc] init];
    }
    return self;
}

- (NSArray *)nodes
{
    return nil;
}

- (NSAttributedString  *)renderFromString:(NSString *)string
{
    return nil;
}
@end
