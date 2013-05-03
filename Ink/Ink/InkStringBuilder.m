//
//  InkStringBuilder.m
//  Ink
//
//  Created by Jeremy Tregunna on 2013-05-03.
//  Copyright (c) 2013 Jeremy Tregunna. All rights reserved.
//

#import "InkStringBuilder.h"

@implementation InkStringBuilder

- (id)init
{
    if((self = [super init]))
        _attributedString = [NSMutableAttributedString new];
    return self;
}

@end
