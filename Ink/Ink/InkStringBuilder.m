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
    self = [super init];
    if(self)
    {
        _attributedString       = [NSMutableAttributedString new];
        _attributes             = [InkMarkdownAttributes new];
        _listBulletCharacters   = @[@"•"];
        _orderedListIndex       = 0;
        _listDepth              = 0;
    }
    return self;
}

@end
