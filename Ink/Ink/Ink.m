//
//  Ink.m
//  Ink
//
//  Created by Wess Cope on 5/2/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import "Ink.h"
#import "InkRenderer.h"

@interface Ink()
@property (strong, nonatomic) InkRenderer  *renderer;
@end

@implementation Ink

- (id)init
{
    self = [super init];
    if (self)
    {
        self.renderer = [[InkRenderer alloc] init];
    }
    return self;
}


- (NSAttributedString *)renderFromString:(NSString *)string
{
    return [self.renderer renderFromString:string];
}


@end
