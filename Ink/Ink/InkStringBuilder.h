//
//  InkStringBuilder.h
//  Ink
//
//  Created by Jeremy Tregunna on 2013-05-03.
//  Copyright (c) 2013 Jeremy Tregunna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InkAttributes.h"

@interface InkStringBuilder : NSObject
@property (nonatomic, readonly, strong) NSMutableAttributedString* attributedString;
@property (strong, nonatomic) InkAttributes *attributes;
@property (copy, nonatomic) NSArray *listBulletCharacters;
@property (nonatomic) NSInteger orderedListIndex;
@property (nonatomic) NSInteger listDepth;
@end
