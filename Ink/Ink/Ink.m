//
//  Ink.m
//  Ink
//
//  Created by Wess Cope on 5/2/13.
//  Copyright (c) 2013 Wess Cope. All rights reserved.
//

#import "Ink.h"


@interface Ink()
@property (strong, nonatomic) id renderer;
@end

@implementation Ink

- (instancetype)initWithRenderer:(Class)rendererClass
{
    self = [super init];
    if (self)
    {
        self.renderer = [[rendererClass alloc] init];
    }
    return self;
}


- (NSAttributedString *)renderFromString:(NSString *)string
{
    return [self.renderer renderFromString:string];
}


@end
